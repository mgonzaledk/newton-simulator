[![Build Status](https://travis-ci.com/mgonzaledk/newton-simulator.svg?branch=master)](https://travis-ci.com/mgonzaledk/newton-simulator)

# newton-simulator
Newtonian celestial bodies simulator.

## Introduction
> In physics and astronomy, an N-body simulation is a simulation of a dynamical system of particles, usually under the influence of physical forces, such as gravity (see n-body problem). N-body simulations are widely used tools in astrophysics, from investigating the dynamics of few-body systems like the Earth-Moon-Sun system to understanding the evolution of the large-scale structure of the universe. In physical cosmology, N-body simulations are used to study processes of non-linear structure formation such as galaxy filaments and galaxy halos from the influence of dark matter. Direct N-body simulations are used to study the dynamical evolution of star clusters.
>
> -- <cite>[N-body simulation. (2018, June 13). In Wikipedia, The Free Encyclopedia. Retrieved 16:20, December 9, 2018][1]</cite>

[1]:https://en.wikipedia.org/wiki/N-body_simulation

## How to compile?
You need install next libraries: ```sudo apt install -y mesa-utils freeglut3-dev```
- GL
- GLUT

Clone repository:
```git clone https://github.com/mgonzaledk/newton-simulator```

Create build directory:
```cd newton-simulator && mkdir -p Build```

Create Makefile and compile:
```cd Build/ && cmake .. && make -j4```

## How to execute?
Just do it:
```./newton-simulator```

## Other considerations
Please, follow code of conduct and read guidelines. If you have a trouble, consider opening an issue and fill template card.
