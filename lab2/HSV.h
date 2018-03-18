#pragma once

#include "color.h"

sf::Color HSVtoRGB (const float distance, const float angle);

sf::Texture *getHSV();

sf::Texture *getHSV(){
    sf::Texture * newTexture = new sf::Texture;
    newTexture->create(2*RADIUS, 2*RADIUS);

    sf::Uint8 *newColor = colorArray(HSVtoRGB);
    newTexture->update(newColor);
    delete newColor;

    return newTexture;
}

sf::Color HSVtoRGB (const float distance, const float angle){
    float d = distance/RADIUS;
    float a = angle * 180.0/M_PI;

    float c = fromSlider * d ;
    float x = c * (1 - fabs (fmod(a/60,2) - 1));
    float m = fromSlider - c;
    float r,g,b;

    if (a < 60.0) {r=c; g=x; b=0;}
    else if (a < 120.0) {r=x; g=c; b=0;}
    else if (a < 180.0) {r=0; g=c; b=x;}
    else if (a < 240.0) {r=0; g=x; b=c;}
    else if (a < 300.0) {r=x; g=0; b=c;}
    else {r=c; g=0; b=x;}

    return sf::Color ((r+m)*255, (g+m)*255, (b+m)*255);
}

