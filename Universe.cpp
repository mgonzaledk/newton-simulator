#include <chrono>
#include <cmath>

#include "Graphics.h"

#include "Universe.h"

void Universe::UpdateAxisView() {
    for(size_t i = 0; i < particles.size(); ++i) {
        for(size_t j = 0; j < 3; ++j) {
            if(std::fabs(particles[i].GetLocation()[j]) > maxAxisX) {
                maxAxisX = 1.2 * std::fabs(particles[i].GetLocation()[j]);
            }
        }
    }

    minAxisX = -maxAxisX;
    minAxisY = minAxisX;
    maxAxisY = maxAxisX;
    minAxisZ = minAxisX;
    maxAxisZ = maxAxisX;
}

Universe::Universe() {
    Universe(600, 600);
}

Universe::Universe(unsigned int width, unsigned int height) {
    Graphics::Init(width, height);

    minAxisX = minAxisY = 0;
    maxAxisX = maxAxisY = 0;
    minAxisZ = -.1, maxAxisZ = .1;
}

void Universe::AddParticle(const Particle &particle) {
    particles.push_back(particle);
    UpdateAxisView();
}

void Universe::UpdateParticles(double multiplier) {
    std::vector<Vector3> acceleration;

    for(size_t i = 0; i < particles.size(); ++i) {
        acceleration.push_back(Vector3());

        for(size_t j = 0; j < particles.size(); ++j) {
            if(i == j) continue;

            acceleration[i] += 
                (particles[j].GetLocation() - particles[j].GetLocation()) *
                (
                    ((1 / particles[i].GetMass()) * (1 / (4 * C_PI * C_K)) *
                    particles[i].GetCharge() * particles[j].GetCharge()
                ) / std::pow(
                    (particles[i].GetLocation() - particles[j].GetLocation()).Module(),
                    1.5
                ));
            
            acceleration[i] +=
                (particles[j].GetLocation() - particles[i].GetLocation()) *
                (C_G * particles[j].GetMass() / std::pow((particles[i].GetLocation() - particles[j].GetLocation()).Module(), 1.5));
        }
    }

    for(size_t i = 0; i < particles.size(); ++i) {
        Particle sum[4];

        sum[0] = particles[i].ApplyAcceleration(acceleration[i]);
        sum[1] = (particles[i] + sum[0] * (multiplier / 2)).ApplyAcceleration(acceleration[i]);
        sum[2] = (particles[i] + sum[1] * (multiplier / 2)).ApplyAcceleration(acceleration[i]);
        sum[3] = (particles[i] + sum[2] * multiplier).ApplyAcceleration(acceleration[i]);
        
        particles[i] = particles[i] + (sum[0] + sum[1] * 2 + sum[2] * 2 + sum[3]) * (multiplier / 6);
    }

    UpdateAxisView();
}

void Universe::Loop() {
    std::chrono::duration<int, std::milli> waitTime =
        std::chrono::duration<int, std::milli>(15);

    std::chrono::system_clock::time_point currentTime;
    std::chrono::system_clock::time_point beforeTime =
        std::chrono::system_clock::now();

    do {
        currentTime = std::chrono::system_clock::now();

        if(currentTime - beforeTime > waitTime) {
            beforeTime = currentTime;

            Graphics::Clear();

            for(const Particle &particle : particles) {
                Vector3 location = particle.GetLocation();
                location['x'] = 2. * ((location['x'] - minAxisX) / (maxAxisX - minAxisX)) - 1.;
                location['y'] = 2. * ((location['y'] - minAxisY) / (maxAxisY - minAxisY)) - 1.;
                location['z'] = 2. * ((location['z'] - minAxisZ) / (maxAxisZ - minAxisZ)) - 1.;

                Vector3 color = particle.GetColor();

                Graphics::AddPoint(
                    Graphics::Point(
                        location['x'], location['y'], location['z'],
                        color[0], color[1], color[2]
                    )
                );
            }

            Graphics::Update();
        }

        UpdateParticles();
    } while(1);
}
