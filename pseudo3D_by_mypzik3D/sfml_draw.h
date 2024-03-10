#pragma once
#include <SFML/Graphics.hpp>

sf::RectangleShape setPixel(sf::Color color, int x, int y){
    sf::RectangleShape shp;
    shp.setSize(sf::Vector2f (1,1));
    shp.setPosition(x,y);
    shp.setFillColor(color);
    return (shp);
}
sf::RectangleShape setPixel_size(sf::Color color, float x, float y,int size){
    sf::RectangleShape shp;
    shp.setSize(sf::Vector2f(size,size));
    shp.setPosition(x,y);
    shp.setFillColor(color);
    return (shp);
}
sf::CircleShape setRound_size(sf::Color color, float x, float y,int size){
    sf::CircleShape shp(size/2);
    shp.setPosition(x,y);
    shp.setFillColor(color);
    return (shp);
}
sf::RectangleShape Rectangle(sf::Color color, float x, float y,int sizeX,int sizeY){
    sf::RectangleShape shp;
    shp.setSize(sf::Vector2f(sizeX,sizeY));
    shp.setPosition(x,y);
    shp.setFillColor(color);
    return (shp);
}

void draw_mini_map(sf::RenderWindow& window,int scale_map, sf::Color color,sf::Color player_color,float spx,float spy){
    window.draw(Rectangle(sf::Color(45, 64, 89),0,0,scale_map*sizex,scale_map*sizey));
    for(int y = 0; y < sizey; y++){
        for(int x = 0; x < sizex; x++){
            if(map[y][x] >= 1){
                window.draw(setPixel_size(color,x*scale_map,y*scale_map,scale_map));
            }
        }
    }
    sf::ConvexShape shp;
    shp.setPointCount(sizeXdis+1);
    shp.setPoint(0,sf::Vector2f(playerPos.x,playerPos.y));
    for(int i=0;i<sizeXdis;i++){
        shp.setPoint(i+1,sf::Vector2f(meshr[i].x,meshr[i].y));
    }
    shp.setPosition(0,0);
    shp.setOutlineColor(player_color);
    shp.setOutlineThickness(2);
    shp.setFillColor(sf::Color(0,0,0,0));
    window.draw(shp);

    window.draw(setRound_size(player_color,playerPos.x/scale*scale_map-scale_map/2,playerPos.y/scale*scale_map-scale_map/2,scale_map));
    //window.draw(setRound_size(player_color,(playerPos.x/scale+spx)*scale_map-scale_map/4,(playerPos.y/scale+spy)*scale_map-scale_map/4,scale_map/2));
}