#pragma once
#include "string"

//defines---------------------------

//colors
#define ground sf::Color(34, 40, 49)
#define sky sf::Color(8, 217, 214)

//world size
#define sizex 10
#define sizey 10

//world scale
#define scale 10

//disctance ray
#define distance 100
#define PI 3.14159265

//size display
#define sizeXdis 800
#define sizeYdis 600
#define size_coef 10
#define color_coef 4

//minimap
#define sizeMiniMap 10
#define color_walls sf::Color(0, 173, 181)
#define color_player sf::Color(238, 238, 238)

//player
#define FOV 0.1
#define speed_rotate 30
#define speed 1

#define FPS 60

//classs-----------------------------

class vector2{
public:
    float x;
    float y;
};

class ray{
public:
    float dist;
    vector2 pos;
};

//data-------------------------------
int map[sizey][sizex]{
        {1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,1,1,0,0,0,0,1},
        {1,0,0,1,1,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,1,1,1},
        {1,0,0,0,0,0,0,1,1,1},
        {1,1,1,1,1,1,1,1,1,1}
};
vector2 playerPos;

int worldMap[sizeXdis][sizeYdis];

vector2 meshr[sizeXdis];
