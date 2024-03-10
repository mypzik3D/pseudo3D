#pragma once
#include "string"

//display
#define sizeXdis 600
#define sizeYdis 400

#define FOV 0.1

std::string objects[8]{"  ", "░░","▒▒","▓▓","██"};
int worldMap[sizeXdis][sizeYdis];


//classs
class vector2{
public:
    float x;
    float y;
};