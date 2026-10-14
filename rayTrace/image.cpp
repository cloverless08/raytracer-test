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


}