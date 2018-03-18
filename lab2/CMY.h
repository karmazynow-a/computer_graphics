#pragma once

#include "color.h"

sf::Color CMYtoRGB (float distance, float angle);

sf::Texture *getCMY();

sf::Texture *getCMY(){
    sf::Texture * newTexture = new sf::Texture;
    newTexture->create(2*RADIUS, 2*RADIUS);

    sf::Uint8 *newColor = colorArray(CMYtoRGB);
    newTexture->update(newColor);
    delete newColor;

    return newTexture;
}


sf::Color CMYtoRGB (float distance, float angle){
    float d = distance/RADIUS;
    return sf::Color((1-(d))*255, (1-(angle/(2*M_PI)))*255, (1-fromSlider)*255);
}
