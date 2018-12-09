#include <iostream>

#include "Universe.h"

int main(int argc, char **argv) {
    Universe universe;
    (void)argc, (void)argv;

    /* Añadir partícula: SOL. */
    universe.AddParticle(
        Particle(
            Vector3(C_SUN_RADIUS, .0, .0),
            Vector3(.0, C_SUN_VELOCITY, .0),
            C_SUN_MASS,
            0,
            Vector3(1., .0, .0)
        )
    );

    /* Añadir partícula: TIERRA. */
    universe.AddParticle(
        Particle(
            Vector3(C_SUN_RADIUS + C_EARTH_RADIUS, .0, .0),
            Vector3(.0, C_SUN_RADIUS + C_EARTH_VELOCITY, .0),
            C_EARTH_MASS,
            0,
            Vector3(.0, 1., 1.)
        )
    );

    /* Añadir partícula: LUNA. */
    universe.AddParticle(
        Particle(
            Vector3(C_SUN_RADIUS + C_EARTH_RADIUS + C_MOON_RADIUS, .0, .0),
            Vector3(.0, C_SUN_RADIUS + C_EARTH_VELOCITY + C_MOON_VELOCITY, .0),
            C_MOON_MASS,
            1,
            Vector3(.0, .0, .5)
        )
    );

    universe.Loop();
    return 0;
}
