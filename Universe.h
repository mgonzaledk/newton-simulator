#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <vector>

#include "Vector3.h"
#include "Particle.h"
#include "Constants.h"

class Universe {
    private:
        std::vector<Particle> particles;

        double minAxisX, minAxisY, minAxisZ;
        double maxAxisX, maxAxisY, maxAxisZ;

        void UpdateAxisView();

    public:
        Universe();
        Universe(unsigned int width, unsigned int height);

        void AddParticle(const Particle &particle);

        void UpdateParticles(double multiplier = 1);
        void Loop();
};

#endif
