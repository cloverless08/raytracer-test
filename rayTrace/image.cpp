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