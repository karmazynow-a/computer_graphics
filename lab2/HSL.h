#pragma once

#include "color.h"

sf::Color HSLtoRGB (const float distance, const float angle);

class HSL : public Color{
public:
    HSL();
    void getTexture();
    void display (sf::RenderWindow &window);
    void update (sf::RenderWindow &window);
    ~HSL();
};

