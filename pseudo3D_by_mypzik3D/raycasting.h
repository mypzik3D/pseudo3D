#pragma once
#include "cmath"
#include "data.h"

ray RayCast(float angle,int mapc[sizey][sizex]){
    ray Ray;
    Ray.dist=0;
    bool flag = false;
    float step_x = cos(angle*PI/180);
    float step_y = sin(angle*PI/180);
    vector2 pos;
    pos.x = playerPos.x;
    pos.y = playerPos.y;
    for(int i = 0; i < distance; i++){
        for(int y = 0; y < sizex; y++){
            for(int x = 0; x < sizex; x++){
                if(mapc[y][x]>=1) {
                    if (pos.x >= (float)x*scale && pos.x <= ((float)x+1)*scale && pos.y >= (float)y*scale && pos.y <= ((float)y+1)*scale) {
                        Ray.dist=sqrt(pow(pos.x-playerPos.x+scale/2, 2) + pow(pos.y-playerPos.y+scale/2, 2));
                        flag= true;
                    }
                }
            }
        }
        pos.x += step_x;
        pos.y += step_y;
        if(flag)
            break;
    }
    Ray.pos = pos;
    return (Ray);
}
