#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>
#include "color.h"


sf::Uint8 *colorSlider(unsigned x, unsigned y);
sf::Texture *getSlider(unsigned x, unsigned y);
void updateMarker (sf:: VertexArray &marker, unsigned y);


sf::Texture *getSlider(unsigned x, unsigned y){
    sf::Texture * newTexture = new sf::Texture;
    newTexture->create(x,y);

    sf::Uint8 * color = colorSlider(x,y);
    newTexture->update(color);
    delete color;

    return newTexture;
}


sf::Uint8 *colorSlider(unsigned x, unsigned y){
    sf::Uint8 * color = new sf::Uint8[2*x*2*y*4];

    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            if(x == 0 || y == 0 || x == x-1 || y == y-1){
                color [4 * (j * x + i) + 0] = 255;
                color [4 * (j * x + i) + 1] = 255;
                color [4 * (j * x + i) + 2] = 255;
                color [4 * (j * x + i) + 3] = 255;
            }
            else{
                color [4 * (j * x + i) + 0] = j*255/y;
                color [4 * (j * x + i) + 1] = j*255/y;
                color [4 * (j * x + i) + 2] = j*255/y;
                color [4 * (j * x + i) + 3] = 255;
            }
        }
    }
    return color;
}

void updateMarker (sf:: VertexArray &marker, unsigned y){
    marker[0] = sf::Vertex(sf::Vector2f(670 - 10, 70 + y), sf::Color::Black);
    marker[1] = sf::Vertex(sf::Vector2f(670 + 40 + 10, 70 + y), sf::Color::Black);

    fromSlider = y/300.0;
}
