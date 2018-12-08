#include "Particle.h"

Particle::Particle() :
    location(.0, .0, .0), velocity(.0, .0, .0), mass(.0), charge(.0) {}

Particle::Particle(const Vector3 &location) :
    location(location), velocity(.0, .0, .0), mass(.0), charge(.0) {}

Particle::Particle(const Vector3 &location, const Vector3 &velocity,
    double mass, double charge) :
    location(location), velocity(velocity), mass(mass), charge(charge) {}

void Particle::ApplyAcceleration(Vector3 acceleration) {
    
}
