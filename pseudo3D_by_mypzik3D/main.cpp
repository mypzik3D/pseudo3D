#include <SFML/Graphics.hpp>
#include "raycasting.h"
#include "data.h"
#include "draw.h"
#include "sfml_draw.h"



int r;
int timer;

int main() {
    sf::RenderWindow window(sf::VideoMode(sizeXdis, sizeYdis), "SFML Window");

    playerPos.x = 50;
    playerPos.y = 50;

    window.setFramerateLimit(FPS);

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
        int angle = r*FOV+sizeYdis*FOV;

        float step_x = cos(angle*PI/180)*speed;
        float step_y = sin(angle*PI/180)*speed;
        print("step calc done to: "+std::to_string(timer));

        print("input work to: "+std::to_string(timer));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            r-=speed_rotate;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            r+=speed_rotate;
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
        window.clear(ground);
        window.draw(Rectangle(sky,0, 0,sizeXdis,cent));

        //std::cout << "| test window | " << get_move() << " | " << fps << " FPS |" << "Yes..." << "\n";
        for(int i = 0; i < sizeXdis; i++){
            int rotate = (i+r)*FOV;
            rotate%180;
            ray rc = RayCast(rotate,map);
            if(i == sizeXdis/2)
                print(std::to_string(rc.dist));
            meshr[i]=rc.pos;
            if(rc.dist > 0) {
                float dst = rc.dist;
                if(dst * color_coef>=unbrightness)
                    dst = unbrightness/color_coef;
                float sizes = sizeYdis/rc.dist*size_coef;
                sf::Color c = sf::Color(255 - dst * color_coef, 255 - dst * color_coef,255 - dst * color_coef, 255);
                window.draw(vertLine(c,i,cent-sizes,sizes*2));
            }
        }
        draw_mini_map(window,sizeMiniMap,color_walls,color_player, step_x, step_y);
        window.display();
        print("raycast done to: "+ std::to_string(timer));
    }
    return 0;
}