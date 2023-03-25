#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

using namespace std;

class Image
{
    public:
        Image(string path, int x, int y, int w, int h);
        SDL_Surface* getImage();
        int getX();
        int getY();
        int getWidth();
        int getHeight();

        void setX(int x);
        void setY(int y);
        void setWidth(int w);
        void setHeight(int h);

    private:
        SDL_Surface *image; 
        int _x;
        int _y;
        int _w;
        int _h;
        
};

#pragma once