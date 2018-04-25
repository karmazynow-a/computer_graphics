#pragma once

#include "color.h"

sf::Color CMYtoRGB (const float distance, const float angle);

class CMY : public Color{
public:
    CMY();
    void getTexture();
    void display (sf::RenderWindow &window);
    void update (sf::RenderWindow &window);
    ~CMY();
};

