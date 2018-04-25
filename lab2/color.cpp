#include "color.h"

float Color::fromSlider = 0;
bool Color::changes = true;

sf::Uint8 *colorArray(sf::Color (*convert) (const float, const float )){
    sf::Uint8 *newColor = new sf::Uint8[2*100*2*100*4];

    for(int i=0; i < 2*RADIUS; i++){
        for(int j=0; j < 2*RADIUS; j++){

            float angle = atan2(RADIUS - j, i - RADIUS);
            if(angle < 0) angle += 2*M_PI;

            float dist = sqrt((i - RADIUS)*(i - RADIUS) + (RADIUS - j)*(RADIUS - j));

            if(dist <= RADIUS){
                newColor[4 * (j * 2 * RADIUS + i) + 0] = convert (dist, angle).r;
                newColor[4 * (j * 2 * RADIUS + i) + 1] = convert (dist, angle).g;
                newColor[4 * (j * 2 * RADIUS + i) + 2] = convert (dist, angle).b;
                newColor[4 * (j * 2 * RADIUS + i) + 3] = 255;
            }
            else{
                for(int k=0; k<4; k++)
                    newColor[4 * (j * 2 * RADIUS + i) + k] = 0;
            }
        }
    }

    return newColor;
}

