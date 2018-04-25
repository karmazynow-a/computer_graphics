#pragma once

#include "color.h"

sf::Color toRGB (const float distance, const float angle);

class RGB : public Color{
public:
    RGB();
    void getTexture();
    void update (sf::RenderWindow &window);
    void display (sf::RenderWindow &window);
    ~RGB();
};

