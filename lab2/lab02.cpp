
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

    fromSlider = 0.5;
    sf::Vector2f clickPos;
    sf::Font font;
    font.loadFromMemory(font_data, font_data_size);

    sf::CircleShape hsl (100);
    sf::Texture *hslTexture = getHSL();
    hsl.setPosition(20, 40);
    hsl.setTexture(hslTexture);

    sf::Text *hslTitle = new sf::Text ("HSL", font, 12);
    hslTitle->setOutlineColor(sf::Color::Black);
    hslTitle->setFillColor(sf::Color::Black);
    hslTitle->setPosition(20,40);

    sf::Text *hslText = new sf::Text ("L= ", font, 12);
    hslText->setOutlineColor(sf::Color::Black);
    hslText->setFillColor(sf::Color::Black);
    hslText->setPosition(200,230);

    sf::CircleShape hsv (100);
    sf::Texture *hsvTexture = getHSV();
    hsv.setPosition(320, 40);
    hsv.setTexture(hsvTexture);

    sf::Text *hsvTitle = new sf::Text ("HSV", font, 12);
    hsvTitle->setOutlineColor(sf::Color::Black);
    hsvTitle->setFillColor(sf::Color::Black);
    hsvTitle->setPosition(320,40);

    sf::Text *hsvText = new sf::Text ("V= ", font, 12);
    hsvText->setOutlineColor(sf::Color::Black);
    hsvText->setFillColor(sf::Color::Black);
    hsvText->setPosition(200+300,230+40-40);

    sf::CircleShape rgb (100);
    sf::Texture *rgbTexture = getRGB();
    rgb.setPosition(320, 340);
    rgb.setTexture(rgbTexture);

    sf::Text *rgbTitle = new sf::Text ("RGB", font, 12);
    rgbTitle->setOutlineColor(sf::Color::Black);
    rgbTitle->setFillColor(sf::Color::Black);
    rgbTitle->setPosition(320,340);

    sf::Text *rgbText = new sf::Text ("B= ", font, 12);
    rgbText->setOutlineColor(sf::Color::Black);
    rgbText->setFillColor(sf::Color::Black);
    rgbText->setPosition(200+320-20,230+340-40);

    sf::CircleShape cmy (100);
    sf::Texture *cmyTexture = getCMY();
    cmy.setPosition(20, 340);
    cmy.setTexture(cmyTexture);

    sf::Text *cmyTitle = new sf::Text ("CMY", font, 12);
    cmyTitle->setOutlineColor(sf::Color::Black);
    cmyTitle->setFillColor(sf::Color::Black);
    cmyTitle->setPosition(20,340);

    sf::Text *cmyText = new sf::Text ("Y= ", font, 12);
    cmyText->setOutlineColor(sf::Color::Black);
    cmyText->setFillColor(sf::Color::Black);
    cmyText->setPosition(200+20-20,230+340-40);

    sf::RectangleShape slider (sf::Vector2f (40,300));
    sf::Texture *sliderTexture = getSlider(40,300);
    slider.setPosition(670,70);
    slider.setTexture(sliderTexture);
    slider.setOutlineColor(sf::Color::Black);
    slider.setOutlineThickness(1);

    sf::Text *sliderText = new sf::Text (" FPS", font, 12);
    sliderText->setOutlineColor(sf::Color::Black);
    sliderText->setFillColor(sf::Color::Black);
    sliderText->setPosition(670, 400);

    sf::VertexArray marker (sf::Lines, 2);
    updateMarker(marker, 150);

    //inicjalizacja
    clock.restart().asMilliseconds();
    while (window.isOpen()) {
        sf::Event event;
        window.clear(sf::Color::White);

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            if (event.key.code == sf::Keyboard::Escape) window.close();
            if (event.type == sf::Event::MouseButtonPressed){
                clickPos.x = event.mouseButton.x;
                clickPos.y = event.mouseButton.y;
                if (clickPos.x > 670 && clickPos.x < 710 && clickPos.y > 70 && clickPos.y < 370){
                    updateMarker(marker, clickPos.y-70);
                }
            }
        }
        //tu wyrysować wszystko na
        window.draw(*hslTitle);
        hslText->setString("L= " + std::to_string(fromSlider));
        window.draw(*hslText);

        window.draw(*hsvTitle);
        hsvText->setString("V= " + std::to_string(fromSlider));
        window.draw(*hsvText);

        window.draw(*rgbTitle);
        rgbText->setString("B= " + std::to_string((int)(fromSlider*255)));
        window.draw(*rgbText);

        window.draw(*cmyTitle);
        cmyText->setString("Y= " + std::to_string((int)(fromSlider*100)) + "%");
        window.draw(*cmyText);

        sliderText->setString(std::to_string(FPS) + " FPS");
        window.draw(*sliderText);

        hslTexture = getHSL();
        hsvTexture = getHSV();
        rgbTexture = getRGB();
        cmyTexture = getCMY();

        hsl.setTexture(hslTexture);
        hsv.setTexture(hsvTexture);
        rgb.setTexture(rgbTexture);
        cmy.setTexture(cmyTexture);

        window.draw(hsl);
        window.draw(hsv);
        window.draw(rgb);
        window.draw(cmy);
        window.draw(slider);
        window.draw(marker);



        //tu wypisać na ekran wartość FPS
        if (clock.getElapsedTime().asSeconds() >= 1.0f) {
            FPS = (unsigned int) ((float) frame_counter / clock.getElapsedTime().asSeconds());
            clock.restart();
            frame_counter = 0;
        }
        frame_counter++;

        window.display();
    }

    delete sliderTexture;
    delete cmyTexture;
    delete rgbTexture;
    delete hslTexture;
    delete hsvTexture;

    delete hslText;
    delete hslTitle;
    delete hsvText;
    delete hsvTitle;
    delete rgbText;
    delete rgbTitle;
    delete cmyText;
    delete cmyTitle;
    delete sliderText;

    return 0;
}
