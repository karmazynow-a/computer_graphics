#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>
#include "color.h"

class Slider {
public:
    Slider();
    ~Slider();
    void getTexture();
    void display (sf::RenderWindow &window);
    void updateMarker (unsigned y);
    void update (sf::RenderWindow &window, unsigned int FPS);
private:
    sf::RectangleShape slider;
    sf::Texture *texture;
    sf::Text *text;
    sf::VertexArray marker;
    sf::Uint8 * color;
    sf::Font font;
    unsigned x;
    unsigned y;
};

