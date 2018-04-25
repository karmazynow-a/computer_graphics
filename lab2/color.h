#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

#define RADIUS 100

//float Color::fromSlider;


sf::Uint8 *colorArray(sf::Color (*convert) (const float, const float ));

class Color {
public:
    static float fromSlider;
    static bool changes;
protected:
    sf::CircleShape circ;
    sf::Texture *texture;
    sf::Text *title;
    sf::Text *text;
    sf::Font font;
    sf::Uint8 *newColor;
};