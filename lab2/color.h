#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "font.h"

#define RADIUS 100

float fromSlider;
/*
class Color {
public:
    sf::Uint8 *colorArray(sf::Color (*convert) (float, float ));
};


sf::Uint8 *Color::colorArray(sf::Color (*convert) (float, float )){
    sf::Uint8 *newColor = new sf::Uint8[2*100*2*100*4];

    for(int pixelX=0; pixelX < 2*RADIUS; pixelX++){
        for(int pixelY=0; pixelY < 2*RADIUS; pixelY++){
            float xVec = pixelX - static_cast<int>(RADIUS);
            float yVec = static_cast<int>(RADIUS) - pixelY;

            float angle = atan2(yVec, xVec);
            if(angle < 0) angle += 2*M_PI;

            float dist = sqrt(xVec*xVec + yVec*yVec);

            if(dist <= RADIUS){
                newColor[4 * (pixelY * 2 * RADIUS + pixelX) + 0] = convert (dist, angle).r;
                newColor[4 * (pixelY * 2 * RADIUS + pixelX) + 1] = convert (dist, angle).g;
                newColor[4 * (pixelY * 2 * RADIUS + pixelX) + 2] = convert (dist, angle).b;
                newColor[4 * (pixelY * 2 * RADIUS + pixelX) + 3] = 255;
            }
            else{
                for(int i=0; i<4; i++)
                    newColor[4 * (pixelY * 2 * RADIUS + pixelX) + i] = 0;
            }
        }
    }

    return newColor;
}
*/
sf::Uint8 *colorArray(sf::Color (*convert) (const float, const float ));

sf::Uint8 *colorArray(sf::Color (*convert) (const float, const float )){
    sf::Uint8 *newColor = new sf::Uint8[2*100*2*100*4];

    for(int pixelX=0; pixelX < 2*RADIUS; pixelX++){
        for(int pixelY=0; pixelY < 2*RADIUS; pixelY++){
            float xVec = pixelX - static_cast<int>(RADIUS);
            float yVec = static_cast<int>(RADIUS) - pixelY;

            float angle = atan2(yVec, xVec);
            if(angle < 0) angle += 2*M_PI;

            float dist = sqrt(xVec*xVec + yVec*yVec);

            if(dist <= RADIUS){
                newColor[4 * (pixelY * 2 * RADIUS + pixelX) + 0] = convert (dist, angle).r;
                newColor[4 * (pixelY * 2 * RADIUS + pixelX) + 1] = convert (dist, angle).g;
                newColor[4 * (pixelY * 2 * RADIUS + pixelX) + 2] = convert (dist, angle).b;
                newColor[4 * (pixelY * 2 * RADIUS + pixelX) + 3] = 255;
            }
            else{
                for(int i=0; i<4; i++)
                    newColor[4 * (pixelY * 2 * RADIUS + pixelX) + i] = 0;
            }
        }
    }

    return newColor;
}
