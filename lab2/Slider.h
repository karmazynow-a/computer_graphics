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


Slider::Slider() {
    x = 40;
    y = 300;

    font.loadFromMemory(font_data, font_data_size);

    texture = new sf::Texture;
    color = new sf::Uint8[2*x*2*y*4];
    text = new sf::Text ("FPS ", font, 12);
    texture->create(40,300);
    getTexture();

    slider = sf::RectangleShape (sf::Vector2f (40,300));
    slider.setPosition(670,70);
    slider.setTexture(texture);
    slider.setOutlineColor(sf::Color::Black);
    slider.setOutlineThickness(1);


    text->setOutlineColor(sf::Color::Black);
    text->setFillColor(sf::Color::Black);
    text->setPosition(670, 400);

    marker = sf::VertexArray (sf::Lines, 2);
    updateMarker(150);
}

Slider::~Slider() {
    delete texture;
    delete color;
    delete text;
}

void Slider::getTexture(){

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
    texture->update(color);
}

void Slider::updateMarker (unsigned y){
    marker[0] = sf::Vertex(sf::Vector2f(670 - 10, 70 + y), sf::Color::Black);
    marker[1] = sf::Vertex(sf::Vector2f(670 + 40 + 10, 70 + y), sf::Color::Black);

    fromSlider = y/300.0;
}

void Slider::update (sf::RenderWindow &window, unsigned int FPS){
    text->setString(std::to_string(FPS) + " FPS");
    window.draw(*text);
    window.draw(marker);
}

void Slider::display (sf::RenderWindow &window){
    window.draw(*text);
    window.draw(slider);
    window.draw(marker);
}
