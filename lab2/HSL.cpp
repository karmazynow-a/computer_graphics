#include "HSL.h"


HSL::HSL(): Color() {
    font.loadFromFile("arial.ttf");

    newColor = new sf::Uint8;
    texture = new sf::Texture;
    texture->create(2*RADIUS, 2*RADIUS);
    getTexture();

    circ.setRadius(RADIUS);
    circ.setPosition(20, 40);
    circ.setTexture(texture);

    title = new sf::Text ("HSL", font, 12);
    title->setOutlineColor(sf::Color::Black);
    title->setFillColor(sf::Color::Black);
    title->setPosition(20,40);

    text = new sf::Text ("L= ", font, 12);
    text->setOutlineColor(sf::Color::Black);
    text->setFillColor(sf::Color::Black);
    text->setPosition(200,230);
}


HSL::~HSL(){
    delete text;
    delete title;
    delete texture;
    delete newColor;
}

void HSL::getTexture(){
    newColor = colorArray(HSLtoRGB);
    texture->update(newColor);
}

void HSL::update (sf::RenderWindow &window){
    text->setString("L= " + std::to_string(Color::fromSlider));
    getTexture();
    display(window);
}

void HSL::display (sf::RenderWindow &window) {
    window.draw(*text);
    window.draw(*title);
    window.draw(circ);
}

sf::Color HSLtoRGB (const float distance, const float angle){
    float d = distance/RADIUS;
    float a = angle * 180.0/M_PI;

    float c = (1 - fabs(2*Color::fromSlider - 1)) *d;
    float x = c * (1 - fabs (fmod(a/60,2) - 1));
    float m = Color::fromSlider - c/2;
    float r,g,b;

    if (a < 60.0) {r=c; g=x; b=0;}
    else if (a < 120.) {r=x; g=c; b=0;}
    else if (a < 180.) {r=0; g=c; b=x;}
    else if (a < 240.) {r=0; g=x; b=c;}
    else if (a < 300.) {r=x; g=0; b=c;}
    else {r=c; g=0; b=x;}


    return sf::Color ((r+m)*255, (g+m)*255, (b+m)*255);
}