#pragma once

#include "color.h"

sf::Color RGB (float distance, float angle);

sf::Texture *getRGB();

sf::Texture *getRGB(){
    sf::Texture * newTexture = new sf::Texture;
    newTexture->create(2*RADIUS, 2*RADIUS);

    sf::Uint8 *newColor = colorArray(RGB);
    newTexture->update(newColor);
    delete newColor;

    return newTexture;
}


sf::Color RGB (const float distance, const float angle){
    float d = distance/RADIUS;
    return sf::Color((d)*255, (angle/(2*M_PI))*255, fromSlider*255);
}
