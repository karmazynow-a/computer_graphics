#include "menu.cpp"
#include <cmath>

int main()
{
 sf::RenderWindow window(sf::VideoMode(800, 650), "GFK Lab 01",sf::Style::Titlebar | sf::Style::Close);
 sf::Event event;
 Menu menu;

 window.setFramerateLimit(60);

    bool onCanvas = false;
    bool onColor = false;
    bool mousePressed = false;
    bool mouseReleased = true;
    bool keyPressed = false;

    sf::Image image;

    sf::Vector2f currPos;
    sf::Vector2f clickPos;
    sf::Keyboard::Key key = sf::Keyboard::Num0;
    sf::Color drawingColor = sf::Color::White;
    sf::Color fillingColor = sf::Color::White;
    sf::Texture texture;

    sf::RectangleShape rect;
    sf::CircleShape circ;
    sf::VertexArray line (sf::LinesStrip, 2);

    std::vector <sf::Drawable*> shapes;


 while (window.isOpen()) {
     window.clear(sf::Color::Black);

     while (window.pollEvent(event)) {
       switch (event.type) {
           case sf::Event::Closed:
               window.close();
               break;

           case sf::Event::MouseButtonPressed:
               mousePressed = true;
               mouseReleased = false;
               clickPos.x = event.mouseButton.x;
               clickPos.y = event.mouseButton.y;
               if (clickPos.x < 764 && clickPos.y < 60) onColor = true;
               else onColor = false;
               onCanvas = isOnCanvas(clickPos.x, clickPos.y);
               break;

           case sf::Event::MouseButtonReleased:
               mouseReleased = true;
               break;

           case sf::Event::MouseMoved:
               if (isOnCanvas(event.mouseMove.x, event.mouseMove.y)) {
                   currPos.x = event.mouseMove.x;
                   currPos.y = event.mouseMove.y;
                   mouseReleased = false;
               }
               break;

           case sf::Event::KeyPressed:
               if (event.key.code == sf::Keyboard::B
                   || event.key.code == sf::Keyboard::Escape
                   || event.key.code == sf::Keyboard::F
                   || event.key.code == sf::Keyboard::L
                   || event.key.code == sf::Keyboard::R
                   || event.key.code == sf::Keyboard::D
                   || event.key.code == sf::Keyboard::C
                   || event.key.code == sf::Keyboard::W
                   || event.key.code == sf::Keyboard::O){
                   key = event.key.code;
                   keyPressed = true;
               }
           default:
               break;
       }
     }

     for (int i=0; i<shapes.size(); i++) window.draw(shapes[i][0]);

     if (onColor) {
          switch (key) {
              case sf::Keyboard::B:
                  menu.setAction('b');
                  fillingColor = menu.pickColor(clickPos.x, clickPos.y);
                  menu.fillingColor(fillingColor);
                  break;

              case sf::Keyboard::F:
                  menu.setAction('f');
                  drawingColor = menu.pickColor(clickPos.x, clickPos.y);
                  menu.drawingColor(drawingColor);
                  break;

              default:
                  break;
          }
     }

     if (onCanvas && mousePressed) {
          switch (key) {
              case sf::Keyboard::L:
                  menu.setAction('l');
                  line[0].position = clickPos;
                  line[1].position = currPos;

                  line[0].color = drawingColor;
                  line[1].color = fillingColor;

                  window.draw(line);
                  if(mouseReleased){
                      shapes.push_back(new sf::VertexArray(line));
                      mousePressed = false;
                  }
                  break;

              case sf::Keyboard::R:
                  menu.setAction('r');

                  rect.setSize(currPos - clickPos);
                  rect.setPosition(clickPos);
                  rect.setOutlineColor(drawingColor);
                  rect.setOutlineThickness(1);
                  rect.setFillColor(sf::Color::Transparent);

                  window.draw(rect);
                  if(mouseReleased) {
                      shapes.push_back(new sf::RectangleShape(rect));
                      mousePressed = false;
                  }
                  break;

              case sf::Keyboard::D:
                  menu.setAction('d');

                  rect.setSize(currPos - clickPos);
                  rect.setPosition(clickPos);
                  rect.setOutlineColor(drawingColor);
                  rect.setOutlineThickness(1);
                  rect.setFillColor(fillingColor);

                  window.draw(rect);
                  if(mouseReleased){
                      shapes.push_back(new sf::RectangleShape(rect));
                      mousePressed = false;
                  }
                  break;

              case sf::Keyboard::C:
                  menu.setAction('c');

                  float radius = sqrt(pow(currPos.x - clickPos.x, 2) + pow(currPos.y - clickPos.y, 2)) / 2;
                  float angle = atan2(currPos.y - clickPos.y, currPos.x - clickPos.x) * (180 / M_1_PI) - 45;

                  circ.setPosition(clickPos);
                  circ.setRadius(radius);
                  circ.setOrigin(radius, radius);
                   //circ.rotate(angle);
                   //circ.move(sf::Vector2f((radius - radius * sqrt(2)) * cos((angle + 45) * M_1_PI / 180),
                      //                    (radius - radius * sqrt(2)) * sin((angle + 45) * M_1_PI / 180)));
                  circ.setOutlineColor(drawingColor);
                  circ.setOutlineThickness(1);
                  circ.setFillColor(sf::Color::Transparent);

                  window.draw(circ);
                  if(mouseReleased) {
                      shapes.push_back(new sf::CircleShape(circ));
                      mousePressed = false;
                  }
                  break;

              //default:
                 // break;
          }

     }
     if(keyPressed){
         switch (key){
             case sf::Keyboard::Escape:
                 window.close();
                 break;

             case sf::Keyboard::W:
                 menu.setAction ('w');

                 menu.save ("image.jpg", window);
                 keyPressed = false;
                 break;

             case sf::Keyboard::O:
                 menu.setAction ('o');
                 freeShapes(shapes);
                 sf::Sprite sprite = menu.updateTexture ("image.jpg", texture);
                 shapes.push_back(new sf::Sprite (sprite));
                 break;

                 //default:
                 //   break;
         }
     }

     //std::cout<< "yes" <<std::endl;


     window.draw(menu);
     window.display();
/*
     if(mouseReleased){
         image = menu.image();
         image.saveToFile("background.jpg");
         menu.updateTexture("background.jpg");
     }
*/
 }
    freeShapes(shapes);
  return 0;
}