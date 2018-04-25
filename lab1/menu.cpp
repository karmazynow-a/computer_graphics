#include "menu.h"

Menu::Menu() {
    font.loadFromFile("arial.ttf");
    text = new sf::Text;
    text->setFont(font);
    text->setCharacterSize(12);
    text->setFillColor(sf::Color::White);

    rectangle = new sf::RectangleShape(sf::Vector2f(796, 536));
    rectangle->setFillColor(sf::Color::Transparent);
    rectangle->setOutlineColor(sf::Color::White);
    rectangle->setOutlineThickness(1.0f);
    rectangle->setPosition(2, 62);

    unsigned int x, y;
    colors_pixels = new sf::Uint8[colors_size_x * colors_size_y * 4];
    for (x = 0; x<255; x++)
        for (y = 0; y < 30; y++) {
            draw_to_color_pixels(x, y, x, 255, 0);
            draw_to_color_pixels(x+255, y, 255, 255-x, 0);
            draw_to_color_pixels(x + 510, y, 255, 0, x);
            draw_to_color_pixels(254 - x, y+30, 0, 255, 255-x);
            draw_to_color_pixels(509 - x, y + 30, 0, x, 255 );
            draw_to_color_pixels(764 - x, y + 30, 255-x, 0, 255);
        }

    colors_texture = new sf::Texture();
    colors_texture->create(colors_size_x, colors_size_y);
    colors_texture->update(colors_pixels);

    canvas_texture = new sf::Texture();
    canvas_texture->create(canvas_size_x, canvas_size_y);

    colors_sprite = new sf::Sprite();
    colors_sprite->setTexture(*colors_texture);
    colors_sprite->setPosition(1, 1);

    canvas_sprite = new sf::Sprite();
    canvas_sprite->setTexture(*canvas_texture);
    canvas_sprite->setPosition(1, 61);

    key = ' ';

    drawingRect =  sf::RectangleShape(sf::Vector2f(32,29));
    drawingRect.setPosition(sf::Vector2f(767, 1));
    drawingRect.setFillColor(sf::Color::Black);

    fillingRect = sf::RectangleShape(sf::Vector2f(32,29));
    fillingRect.setPosition(sf::Vector2f(767, 31));
    fillingRect.setFillColor(sf::Color::Black);

}

void Menu::outtextxy(sf::RenderTarget& target, float x, float y, const char *str) const {
    text->setPosition(x, y);
    text->setString(str);
    target.draw(*text);
}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    outtextxy(target,5, 600, "f - wybor koloru rysowania");
    outtextxy(target, 5, 615, "b - wybor koloru wypelniania");
    outtextxy(target, 5, 630, "l - rysowanie linii");

    outtextxy(target, 200, 600, "r - rysowanie prostokata");
    outtextxy(target, 200, 615, "d - rysowanie wypelnionego prostokata");
    outtextxy(target, 200, 630, "c - rysowanie okregu");

    outtextxy(target, 470, 600, "w - zapis do pliku");
    outtextxy(target, 470, 615, "o - odczyt z pliku");
    outtextxy(target, 470, 630, "esc - wyjscie");

    outtextxy(target, 650, 615, "Aktualne:");

    text->setPosition(710, 615);
    text->setString(key);
    target.draw(*text);

    target.draw(*rectangle);
    target.draw(*colors_sprite);
    target.draw(*canvas_sprite);

    target.draw(drawingRect);
    target.draw(fillingRect);
}


sf::Color Menu::pickColor (unsigned int x, unsigned int y){
    sf::Image image = colors_texture->copyToImage();
    return image.getPixel(x, y);
}

void Menu::save (const std::string file, sf::RenderWindow &window){
    sf::Texture texture;
    texture.create(window.getSize().x,window.getSize().y );
    texture.update(window);
    sf::Image image = texture.copyToImage();
    image.saveToFile(file);
}

sf::Sprite Menu::updateTexture (const std::string file, sf::Texture &texture){
    texture.loadFromFile(file);
    sf::Sprite sprite (texture);
    sprite.setPosition(sf::Vector2f(2,62));
    return sprite;
}

Menu::~Menu(){
    delete text;
    delete rectangle;

    delete canvas_texture;
    delete colors_texture;
    delete colors_sprite;
    delete canvas_sprite;
    delete colors_pixels;
}


bool isOnCanvas (unsigned x, unsigned y){
    if (x > 0 && x < 796 && y > 60 && y < 536+32) return true;
    return false;
}

void freeShapes (std::vector <sf::Drawable*> &shapes){
    for (int i = 0; i != shapes.size(); i++) delete shapes[i];
    shapes.clear();
}

