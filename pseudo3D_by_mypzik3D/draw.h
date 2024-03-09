#pragma once
#include "data.h"
#include "string"
#include <iostream>

void draw(){
    for(int y = 0; y < sizeY;y++){
        for(int x = 0; x < sizeX;x++){
            std::cout << objects[worldMap[x][y]];
        }
        std::cout << "\n";
    }
}
void clearMap(){
    for(int p = 0; p < sizeX;p++){
        for(int n = 0; n <sizeY;n++){
            worldMap[p][n]=0;
        }
    }
}
void setPixel(int intObject, int posX, int posY){
    worldMap[posX][posY] = intObject;
}
