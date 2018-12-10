#ifndef PARTICLE_H
#define PARTICLE_H

#include "Vector3.h"

class Particle {
    private:
        Vector3 location;
        Vector3 velocity;

        double mass;
        double charge;
    
        Vector3 color;

    public:
        Particle();
        Particle(const Vector3 &location);
        Particle(const Vector3 &location, const Vector3 &velocity, double mass,
            double charge, const Vector3 &color);

        Vector3 GetColor() const;
        Vector3 GetLocation() const;
        Vector3 GetVelocity() const;
        double GetMass() const;
        double GetCharge() const;

        Particle ApplyAcceleration(Vector3 acceleration);

        Particle operator*(double constant);
        Particle operator+(const Particle &particle);
};

#endif
