#pragma once

#include "color.h"

sf::Color HSVtoRGB (const float distance, const float angle);

class HSV : public Color{
public:
    HSV();
    void getTexture();
    void update (sf::RenderWindow &window);
    void display (sf::RenderWindow &window);
    ~HSV();
};


HSV::HSV(){
    font.loadFromMemory(font_data, font_data_size);

    newColor = new sf::Uint8;
    texture = new sf::Texture;
    texture->create(2*RADIUS, 2*RADIUS);
    getTexture();

    circ.setRadius(RADIUS);
    circ.setPosition(320, 40);
    circ.setTexture(texture);

    title = new sf::Text ("HSV", font, 12);
    title->setOutlineColor(sf::Color::Black);
    title->setFillColor(sf::Color::Black);
    title->setPosition(320,40);

    text = new sf::Text ("V= ", font, 12);
    text->setOutlineColor(sf::Color::Black);
    text->setFillColor(sf::Color::Black);
    text->setPosition(200+300,230+40-40);
}

HSV::~HSV(){
    delete text;
    delete title;
    delete texture;
    delete newColor;
}

void HSV::getTexture(){
    newColor = colorArray(HSVtoRGB);
    texture->update(newColor);
}

void::HSV::update (sf::RenderWindow &window){
    text->setString("V= " + std::to_string(fromSlider));
    getTexture();
    display(window);
}

void HSV::display (sf::RenderWindow &window) {
    if (changes){
        text->setString("V= " + std::to_string(fromSlider));
        getTexture();
    }
    window.draw(*text);
    window.draw(*title);
    window.draw(circ);
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