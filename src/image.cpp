#include "image.h"

Image::Image(string path, int x, int y, int w, int h)
{
    image = NULL;
    image = IMG_Load(path.c_str()); 
    this->x=x;
    this->y=y;
    this->w=w;
    this->h=h;
}

SDL_Surface* Image::getImage()
{
    return image;
}

void Image::setX(int x){this->x=x;}
void Image::setY(int y){this->y=y;}
void Image::setWidth(int w){this->w=w;}
void Image::setHeight(int h){this->h=h;}

int Image::getX(){return x;}
int Image::getY(){return y;}
int Image::getWidth(){return w;}
int Image::getHeight(){return h;}
