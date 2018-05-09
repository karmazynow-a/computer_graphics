
#include "HSL.h"
#include "HSV.h"
#include "CMY.h"
#include "RGB.h"
#include "Slider.h"


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 650), "GFK Lab 02", sf::Style::Titlebar | sf::Style::Close);

    sf::Clock clock;
    sf::Time time = sf::Time::Zero;
    unsigned int FPS = 0, frame_counter = 0;


    Color::fromSlider = 0.5;
    sf::Vector2f clickPos;
    sf::Font font;
    font.loadFromFile("arial.ttf");

    HSL hsl;
    HSV hsv;
    CMY cmy;
    RGB rgb;
    Slider slider;

    clock.restart().asMilliseconds();
    while (window.isOpen()) {
        sf::Event event;
        window.clear(sf::Color::White);

        slider.display(window);
        hsl.display(window);
        hsv.display(window);
        cmy.display(window);
        rgb.display(window);

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            if (event.key.code == sf::Keyboard::Escape) window.close();
            if (event.type == sf::Event::MouseButtonPressed){
                Color::changes = true;
                clickPos.x = event.mouseButton.x;
                clickPos.y = event.mouseButton.y;
                if (clickPos.x > 670 && clickPos.x < 710 && clickPos.y > 70 && clickPos.y < 370){
                    slider.updateMarker(clickPos.y-70);
                }
            }
        }
        if (Color::changes){
            hsl.update(window);
            hsv.update(window);
            rgb.update(window);
            cmy.update(window);
            Color::changes = false;
        }

        slider.update(window, FPS);

        if (clock.getElapsedTime().asSeconds() >= 1.0f) {
            FPS = (unsigned int) ((float) frame_counter / clock.getElapsedTime().asSeconds());
            clock.restart();
            frame_counter = 0;
        }
        frame_counter++;

        window.display();
        }

    return 0;
}
