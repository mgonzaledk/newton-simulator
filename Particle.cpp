#include "Particle.h"

Particle::Particle() :
    location(.0, .0, .0), velocity(.0, .0, .0), mass(.0), charge(.0) {}

Particle::Particle(const Vector3 &location) :
    location(location), velocity(.0, .0, .0), mass(.0), charge(.0) {}

Particle::Particle(const Vector3 &location, const Vector3 &velocity,
    double mass, double charge, const Vector3 &color) :
    location(location), velocity(velocity), mass(mass), charge(charge),
    color(color) {}

Vector3 Particle::GetColor() const {
    return color;
}

Vector3 Particle::GetLocation() const {
    return location;
}

Vector3 Particle::GetVelocity() const {
    return velocity;
}

double Particle::GetMass() const {
    return mass;
}

double Particle::GetCharge() const {
    return charge;
}

Particle Particle::ApplyAcceleration(Vector3 acceleration) {
    return Particle(velocity, acceleration, .0, .0, color);
}

Particle Particle::operator*(double constant) {
    return Particle(
        location * constant,
        velocity * constant,
        mass * constant,
        charge * constant,
        color
    );
}

Particle Particle::operator+(const Particle &particle) {
    return Particle(
        location + particle.location,
        velocity + particle.velocity,
        mass + particle.mass,
        charge + particle.charge,
        color
    );
}
