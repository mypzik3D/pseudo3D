#pragma once
#include "string"

//display
#define sizeX 60
#define sizeY 30

#define FOV 3

std::string objects[8]{"  ", "░░","▒▒","▓▓","██"};
int worldMap[sizeX][sizeY];


//classs
class vector2{
public:
    float x;
    float y;
};