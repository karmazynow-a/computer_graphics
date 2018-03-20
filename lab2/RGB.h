#pragma once

#include "color.h"

sf::Color toRGB (const float distance, const float angle);

class RGB : public Color{
public:
    RGB();
    void getTexture();
    void update (sf::RenderWindow &window);
    void display (sf::RenderWindow &window);
    ~RGB();
};


RGB::RGB(){
    font.loadFromMemory(font_data, font_data_size);

    newColor = new sf::Uint8;
    texture = new sf::Texture;
    texture->create(2*RADIUS, 2*RADIUS);
    getTexture();

    circ.setRadius(RADIUS);
    circ.setPosition(320, 340);
    circ.setTexture(texture);

    title = new sf::Text ("RGB", font, 12);
    title->setOutlineColor(sf::Color::Black);
    title->setFillColor(sf::Color::Black);
    title->setPosition(320, 340);

    text = new sf::Text ("B= ", font, 12);
    text->setOutlineColor(sf::Color::Black);
    text->setFillColor(sf::Color::Black);
    text->setPosition(200+320-20,230+340-40);
}

RGB::~RGB(){
    delete text;
    delete title;
    delete texture;
    delete newColor;
}

void RGB::getTexture(){
    newColor = colorArray(toRGB);
    texture->update(newColor);
}

void RGB::update (sf::RenderWindow &window){
    text->setString("B= " + std::to_string(static_cast<int>(fromSlider*255)));
    getTexture();
    display(window);
}

void RGB::display (sf::RenderWindow &window) {
    window.draw(*text);
    window.draw(*title);
    window.draw(circ);
}

sf::Color toRGB (const float distance, const float angle){
    float d = distance/RADIUS;
    return sf::Color((d)*255, (angle/(2*M_PI))*255, fromSlider*255);
}
