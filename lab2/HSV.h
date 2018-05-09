#pragma once

#include "color.h"

sf::Color HSVtoRGB (const float distance, const float angle);

class HSV : public Color{
public:
    HSV();
    void getTexture();
    void update (sf::RenderWindow &window);
    void display (sf::RenderWindow &window);
    ~HSV();
};