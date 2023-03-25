#include "image.h"

Image::Image(string path, int x, int y, int w, int h)
{
    image = NULL;
    image = IMG_Load(path.c_str()); 
    _x=x;
    _y=y;
    _w=w;
    _h=h;
}

SDL_Surface* Image::getImage()
{
    return image;
}

void Image::setX(int x){_x=x;}
void Image::setY(int y){_y=y;}
void Image::setWidth(int w){_w=w;}
void Image::setHeight(int h){_h=h;}

int Image::getX(){return _x;}
int Image::getY(){return _y;}
int Image::getWidth(){return _w;}
int Image::getHeight(){return _h;}
