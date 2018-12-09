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

    /* Añadir partícula: MERCURIO. */
    universe.AddParticle(
        Particle(
            Vector3(C_SUN_RADIUS + C_MERCURY_RADIUS, .0, .0),
            Vector3(.0, C_SUN_RADIUS + C_MERCURY_VELOCITY, .0),
            C_MERCURY_MASS,
            0,
            Vector3(.0, .0, .0)
        )
    );

    /* Añadir partícula: VENUS. */
    universe.AddParticle(
        Particle(
            Vector3(C_SUN_RADIUS + C_VENUS_RADIUS, .0, .0),
            Vector3(.0, C_SUN_VELOCITY + C_VENUS_VELOCITY, .0),
            C_VENUS_MASS,
            0,
            Vector3(.0, .0, .0)
        )
    );

    /* Añadir partícula: TIERRA. */
    universe.AddParticle(
        Particle(
            Vector3(C_SUN_RADIUS + C_EARTH_RADIUS, .0, .0),
            Vector3(.0, C_SUN_VELOCITY + C_EARTH_VELOCITY, .0),
            C_EARTH_MASS,
            0,
            Vector3(.0, 1., 1.)
        )
    );

    /* Añadir partícula: LUNA. */
    universe.AddParticle(
        Particle(
            Vector3(C_SUN_RADIUS + C_EARTH_RADIUS + C_MOON_RADIUS, .0, .0),
            Vector3(.0, C_SUN_VELOCITY + C_EARTH_VELOCITY + C_MOON_VELOCITY, .0),
            C_MOON_MASS,
            0,
            Vector3(.0, .0, .5)
        )
    );

    /* Añadir partícula: MARTE. */
    universe.AddParticle(
        Particle(
            Vector3(C_SUN_RADIUS + C_MARS_RADIUS, .0, .0),
            Vector3(.0, C_SUN_VELOCITY + C_MARS_VELOCITY, .0),
            C_MARS_MASS,
            0,
            Vector3(.0, .0, .0)
        )
    );

    /* Añadir partícula: JUPITER. */
    universe.AddParticle(
        Particle(
            Vector3(C_SUN_RADIUS + C_JUPITER_RADIUS, .0, .0),
            Vector3(.0, C_SUN_VELOCITY + C_JUPITER_VELOCITY, .0),
            C_JUPITER_MASS,
            0,
            Vector3(.0, .0, .0)
        )
    );

    /* Añadir partícula: SATURNO. */
    universe.AddParticle(
        Particle(
            Vector3(C_SUN_RADIUS + C_SATURN_RADIUS, .0, .0),
            Vector3(.0, C_SUN_VELOCITY + C_SATURN_VELOCITY, .0),
            C_SATURN_MASS,
            0,
            Vector3(.0, .0, .0)
        )
    );

#if 0

    /* Añadir partícula: URANO. */
    universe.AddParticle(
        Particle(
            Vector3(C_SUN_RADIUS + C_URANUS_RADIUS, .0, .0),
            Vector3(.0, C_SUN_VELOCITY + C_URANUS_VELOCITY, .0),
            C_URANUS_MASS,
            0,
            Vector3(.0, .0, .0)
        )
    );

    /* Añadir partícula: NEPTUNO. */
    universe.AddParticle(
        Particle(
            Vector3(C_SUN_RADIUS + C_NEPTUNE_RADIUS, .0, .0),
            Vector3(.0, C_SUN_VELOCITY + C_NEPTUNE_VELOCITY, .0),
            C_NEPTUNE_MASS,
            0,
            Vector3(.0, .0, .0)
        )
    );

    /* Añadir partícula: PLUTON. */
    universe.AddParticle(
        Particle(
            Vector3(C_SUN_RADIUS + C_PLUTO_RADIUS, .0, .0),
            Vector3(.0, C_SUN_VELOCITY + C_PLUTO_VELOCITY, .0),
            C_PLUTO_MASS,
            0,
            Vector3(.0, .0, .0)
        )
    );

#endif

    universe.Loop();
    return 0;
}
