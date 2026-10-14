//
// Created by cdemin on 10/14/26.
//

#include "image.h"

// default constructor
Image::Image() {
    m_sizeX = 0;
    m_sizeY = 0;
    m_pTexture = nullptr;
}

// default destructor
Image::~Image() {
    if (m_pTexture != nullptr) {
        SDL_DestroyTexture(m_pTexture);
    }
}

// init function
void Image::Init(const int sizeX, const int sizeY, SDL_Renderer *pRenderer) {
    // resize image arrays
    m_rChannel.resize(sizeX, std::vector<double>(sizeY, 0.0));
    m_gChannel.resize(sizeX, std::vector<double>(sizeY, 0.0));
    m_bChannel.resize(sizeX, std::vector<double>(sizeY, 0.0));

    m_sizeX = sizeX;
    m_sizeY = sizeY;

    // store the pointer to the renderer
    m_pRenderer = pRenderer;

    InitTexture();
}

void Image::SetPixel(const int x, const int y, const double red, const double green, const double blue) {
    m_rChannel.at(x).at(y) = red;
    m_gChannel.at(x).at(y) = green;
    m_bChannel.at(x).at(y) = blue;
}

void Image::Display() {   // pixel buffer goes here actually (PIXEL BUFFER MENTIONED)

    // allocate inital memory
    Uint32 *tempPixels = new Uint32[m_sizeX * m_sizeY];

    // clear buffer
    memset(tempPixels, 0, m_sizeX * m_sizeY * sizeof(Uint32));


}