#include <SFML/Graphics.hpp>
#include <iostream>
#include "raycasting.h"
#include "data.h"
#include "draw.h"
#include "delay.h"
#include "control.h"
#include "sfml_draw.h"

#define color_coef 4
#define speed 1


int r;
int timer;

int main() {
    sf::RenderWindow window(sf::VideoMode(sizeXdis, sizeYdis), "SFML Window");

    playerPos.x = 50;
    playerPos.y = 50;

    int fps=60;
    float msize= sizeYdis;

    while (true){
        timer++;

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //sleep
        print("step calc to: "+std::to_string(timer));
        sleepMS(fps);
        int angle = r*FOV+sizeYdis*FOV;

        float step_x = cos(angle*PI/180)*speed;
        float step_y = sin(angle*PI/180)*speed;
        print("step calc done to: "+std::to_string(timer));

        print("input work to: "+std::to_string(timer));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            r-=30;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            r+=30;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            playerPos.x+=step_x;
            playerPos.y+=step_y;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            playerPos.x-=step_x;
            playerPos.y-=step_y;
        }
        print("input work done to: "+std::to_string(timer));


            //raycast
        int cent = sizeYdis/2;
        print("raycast to: "+std::to_string(timer));
        window.clear(sf::Color(34, 40, 49));
        window.draw(Rectangle(sf::Color(8, 217, 214),0, 0,sizeXdis,cent));

        //std::cout << "| test window | " << get_move() << " | " << fps << " FPS |" << "Yes..." << "\n";
        for(int i = 0; i < sizeXdis; i++){
            int rotate = (i+r)*FOV;
            rotate%360;
            ray rc = RayCast(rotate,map);
            print(std::to_string(rc.dist));
            meshr[i]=rc.pos;
            if(rc.dist > 0) {
                float sizes = sizeYdis/rc.dist*5;
                for (int p = 0; p < sizes * 2; p++) {
                    sf::Color c = sf::Color(255 - rc.dist * color_coef, 255 - rc.dist * color_coef,
                                            255 - rc.dist * color_coef, 255);
                    window.draw(setPixel(c, i, cent - (sizes) + p));
                }
            }
        }
        draw_mini_map(window,10,sf::Color(0, 173, 181),sf::Color(238, 238, 238), step_x, step_y);
        window.display();
        print("raycast done to: "+ std::to_string(timer));
    }
    return 0;
}



