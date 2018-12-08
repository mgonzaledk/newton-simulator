#ifndef PARTICLE_H
#define PARTICLE_H

#include "Vector3.h"

class Particle {
    private:
        Vector3 location;
        Vector3 velocity;

        double mass;
        double charge;

    public:
        Particle();
        Particle(const Vector3 &location);
        Particle(const Vector3 &location, const Vector3 &velocity, double mass,
            double charge);

        void ApplyAcceleration(Vector3 acceleration);
};

#endif
