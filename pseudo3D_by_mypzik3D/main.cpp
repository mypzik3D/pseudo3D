#include <iostream>
#include "raycasting.h"
#include "draw.h"
#include "data.h"
#include "delay.h"
int r;

int main() {
    playerPos.x = 25;
    playerPos.y = 25;

    int fps;
    std::cout << "Input fps => ";
    std::cin >> fps;


    while (true){
        //sleep
        sleepMS(fps);

        //rotate
        r++;
        if(r >= 360)
            r=0;

        //raycast
        clearMap();
        std::cout << "| test window | " << " | " << fps << " FPS |" << "Yes..." << "\n";
        for(int i = 0; i < sizeX; i++){
            float rotate = (i+r)*FOV;
            float rc = RayCast(rotate,map);
            int cent = sizeY/2;
            int sizes = 150/rc;
            for(int p = 0; p < sizes*2; p++){
                if(rc < 20)
                    setPixel(5,i,cent-(sizes)+p);
                if(rc >= 10 && rc < 20)
                    setPixel(4,i,cent-(sizes)+p);
                if(rc >= 20 && rc < 40)
                    setPixel(3,i,cent-(sizes)+p);
                if(rc >= 40 && rc < 60)
                    setPixel(2,i,cent-(sizes)+p);
                if(rc >= 60)
                    setPixel(1,i,cent-(sizes)+p);
            }
        }
        draw();
    }
    return 0;
}



