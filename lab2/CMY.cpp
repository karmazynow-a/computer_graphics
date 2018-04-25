#include "CMY.h"

CMY::CMY(){
    font.loadFromFile("arial.ttf");

    newColor = new sf::Uint8;
    texture = new sf::Texture;
    texture->create(2*RADIUS, 2*RADIUS);
    getTexture();

    circ.setRadius(RADIUS);
    circ.setPosition(20, 340);
    circ.setTexture(texture);

    title = new sf::Text ("CMY", font, 12);
    title->setOutlineColor(sf::Color::Black);
    title->setFillColor(sf::Color::Black);
    title->setPosition(20,340);

    text = new sf::Text ("Y= ", font, 12);
    text->setOutlineColor(sf::Color::Black);
    text->setFillColor(sf::Color::Black);
    text->setPosition(200+20-20,230+340-40);
}

CMY::~CMY(){
    delete text;
    delete title;
    delete texture;
    delete newColor;
}

void CMY::getTexture(){
    newColor = colorArray(CMYtoRGB);
    texture->update(newColor);
}

void CMY::update (sf::RenderWindow &window){
    text->setString("Y= " + std::to_string(static_cast<int>(Color::fromSlider*100)) + "%");
    getTexture();
    display(window);
}

void CMY::display (sf::RenderWindow &window) {
    window.draw(*text);
    window.draw(*title);
    window.draw(circ);
}

sf::Color CMYtoRGB (const float distance, const float angle){
    float d = distance/RADIUS;
    return sf::Color((1-(d))*255, (1-(angle/(2*M_PI)))*255, (1-Color::fromSlider)*255);
}

