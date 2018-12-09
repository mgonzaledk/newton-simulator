#include "Graphics.h"

#include "Universe.h"

Universe::Universe() {
    Universe(600, 600);
}

Universe::Universe(unsigned int width, unsigned int height) {
    Graphics::Init(width, height);

    minAxisX = minAxisY = 0;
    maxAxisX = maxAxisY = 0;
    minAxisZ = -.1, maxAxisZ = .1;
}

void Universe::Loop() {
    while(1) {
        Graphics::Update();
    }
}
