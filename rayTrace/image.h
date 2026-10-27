//
// Created by cdemin on 10/14/26.
//

#pragma once

#include <string>
#include <vector>
#include "SDL2/SDL.h"

namespace raytrace {
    class Image {
    public:
        // default constructor
        Image();

        // default destructor
        ~Image();

        void Init(const int sizeX, const int sizeY, SDL_Renderer *pRenderer);

        // function to set color of a pixel
        void SetPixel(const int x, const int y, const double red, const double green, const double blue); // i completely disagree with this implementation and will be doing something different in the sim

        // handles displaying image
        void Display(const int WIDTH, const int HEIGHT);

        Uint32 ConvertColor(const double red, const double green, const double blue); // wait omg this is how im doing it in the sim :0

        // getter functions
        int GetSizeX();
        int GetSizeY();


    private:

        void InitTexture();

        // not a typical pixel buffer, just color channels for the pixels
        std::vector<std::vector<double>> m_rChannel;
        std::vector<std::vector<double>> m_gChannel;
        std::vector<std::vector<double>> m_bChannel;

        // image resolution
        int m_sizeX;
        int m_sizeY;


        SDL_Renderer *m_pRenderer;
        SDL_Texture *m_pTexture;
    };
}