#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
//potrzebe przy konstruktorze
#include <iostream>

class Menu : public sf::Drawable
{
private:
    sf::Font font;
    sf::Text *text;
    sf::RectangleShape *rectangle;

    sf::Texture *canvas_texture;
    sf::Texture *colors_texture;
    sf::Sprite *colors_sprite;
    sf::Sprite *canvas_sprite;
    sf::Uint8 *colors_pixels;

    const unsigned int colors_size_x = 765;
    const unsigned int colors_size_y = 60;
    const unsigned int canvas_size_x = 796;
    const unsigned int canvas_size_y = 536-60;

    inline void draw_to_color_pixels(unsigned int x, unsigned int y,unsigned char r, unsigned char g, unsigned char b){
        colors_pixels[4 * (y * colors_size_x + x) + 0] = r;
        colors_pixels[4 * (y * colors_size_x + x) + 1] = g;
        colors_pixels[4 * (y * colors_size_x + x) + 2] = b;
        colors_pixels[4 * (y * colors_size_x + x) + 3] = 255;
    }

    char key;
    sf::RectangleShape fillingRect;
    sf::RectangleShape drawingRect;

public:
    Menu();

    void outtextxy(sf::RenderTarget& target, float x, float y, const char *str) const;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::Color pickColor (unsigned int x, unsigned int y);

    sf::Image image() {return canvas_texture->copyToImage();}

    void save (const std::string file, sf::RenderWindow &window);

    sf::Sprite updateTexture (const std::string file, sf::Texture &texture);

    void setAction (char action) {key = action;}

    void drawingColor (sf::Color color) {drawingRect.setFillColor(color);}

    void fillingColor (sf::Color color) {fillingRect.setFillColor(color);}

    ~Menu();
};

bool isOnCanvas (unsigned x, unsigned y);

void freeShapes (std::vector <sf::Drawable*> &shapes);