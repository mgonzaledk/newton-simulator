#include "Particle.h"

Particle::Particle() :
    location(.0, .0, .0), velocity(.0, .0, .0), mass(.0), charge(.0),
    color(.0, .0, .0), size(.1) {}

Particle::Particle(const Vector3 &location) :
    location(location), velocity(.0, .0, .0), mass(.0), charge(.0),
    color(.0, .0, .0), size(.1) {}

Particle::Particle(const Vector3 &location, const Vector3 &velocity,
    double mass, double charge, const Vector3 &color, double size) :
    location(location), velocity(velocity), mass(mass), charge(charge),
    color(color), size(size) {}

Vector3 Particle::GetColor() const {
    return color;
}

double Particle::GetSize() const {
    return size;
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
    return Particle(velocity, acceleration, .0, .0, color, size);
}

Particle Particle::operator*(double constant) {
    return Particle(
        location * constant,
        velocity * constant,
        mass * constant,
        charge * constant,
        color,
        size
    );
}

Particle Particle::operator+(const Particle &particle) {
    return Particle(
        location + particle.location,
        velocity + particle.velocity,
        mass + particle.mass,
        charge + particle.charge,
        color,
        size
    );
}
