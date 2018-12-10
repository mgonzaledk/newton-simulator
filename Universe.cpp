#include <algorithm>
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
    *this = Universe(600, 600);
}

Universe::Universe(unsigned int width, unsigned int height) {
    minAxisX = minAxisY = 0;
    maxAxisX = maxAxisY = 0;
    minAxisZ = -.1, maxAxisZ = .1;

    this->width = width;
    this->height = height;
}

void Universe::Init() {
    std::function<void(void)> callback =
        std::bind(&Universe::Loop, this);

    Graphics::Init<void(void)>(width, height, callback);
}

void Universe::AddParticle(const Particle &particle) {
    particles.push_back(particle);
    UpdateAxisView();
}

void Universe::UpdateParticles() {
    std::vector<Vector3> acceleration;

    for(size_t i = 0; i < particles.size(); ++i) {
        acceleration.push_back(Vector3());

        for(size_t j = 0; j < particles.size(); ++j) {
            if(i == j) continue;

            Vector3 t1 = particles[j].GetLocation() - particles[i].GetLocation();
            double t2 = std::pow(
                (particles[i].GetLocation() - particles[j].GetLocation()).Module(),
                1.5
            );

            acceleration[i] += t1 * (((1 / particles[i].GetMass()) * (1 / (4 * C_PI * C_K)) * particles[i].GetCharge() * particles[j].GetCharge()) / t2);
            acceleration[i] += t1 * (C_G * particles[j].GetMass() / t2);
        }
    }

    for(size_t i = 0; i < particles.size(); ++i) {
        Particle sum[4];

        sum[0] = particles[i].ApplyAcceleration(acceleration[i]);
        sum[1] = (particles[i] + sum[0]).ApplyAcceleration(acceleration[i]);
        sum[2] = (particles[i] + sum[1]).ApplyAcceleration(acceleration[i]);
        sum[3] = (particles[i] + sum[2]).ApplyAcceleration(acceleration[i]);
        
        particles[i] = particles[i] + (sum[0] + sum[1] * 2 + sum[2] * 2 + sum[3]);
    }

    UpdateAxisView();
}

void Universe::Loop() {
    auto begin = std::chrono::high_resolution_clock::now();

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

    UpdateParticles();

    auto end = std::chrono::high_resolution_clock::now();
}
