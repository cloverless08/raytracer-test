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

void Image::Display(const int WIDTH, const int HEIGHT) {   // pixel buffer goes here actually (PIXEL BUFFER MENTIONED)

    // allocate inital memory
    Uint32 *tempPixels = new Uint32[m_sizeX * m_sizeY];

    // clear buffer
    memset(tempPixels, 0, m_sizeX * m_sizeY * sizeof(Uint32));

    // populate pixel buffer with color data
    for (int x = 0; x < m_sizeX; ++x) { // inefficient
        for (int y = 0; y < m_sizeY; ++y) {
            tempPixels[(y*m_sizeX) + x] = ConvertColor(m_rChannel.at(x).at(y), m_gChannel.at(x).at(y), m_bChannel.at(x).at(y));
        }
    }

    // update texture from pixel buffer
    SDL_UpdateTexture(m_pTexture, nullptr, tempPixels, m_sizeX * sizeof(Uint32));

    delete[] tempPixels; // have to use C-style allocation because of SDL2


    // copy texture to renderer
    SDL_Rect srcRect, bounds;
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = WIDTH; // could also be m_sizeX
    srcRect.h = HEIGHT; // could also be m_sizeY

    bounds = srcRect;
    SDL_RenderCopy(m_pRenderer, m_pTexture, &srcRect, &bounds);
}

void Image::InitTexture() {

    Uint32 rmask;
    Uint32 gmask;
    Uint32 bmask;
    Uint32 amask;

    #if SDL_BYTEORDER == SDL_BIG_ENDIAN
        rmask = 0xff000000;
        gmask = 0x00ff0000;
        bmask = 0x0000ff00;
        amask = 0x000000ff;
    #else
        rmask = 0x000000ff;
        gmask = 0x0000ff00;
        bmask = 0x00ff0000;
        amask = 0xff000000;
    #endif

    // delete previous texture (if any)
    if (m_pTexture != nullptr) {
        SDL_DestroyTexture(m_pTexture);
    }

    // create working texture to store image
    SDL_Surface *tmpSurface = SDL_CreateRGBSurface(0 , m_sizeX, m_sizeY, 32 , rmask, gmask, bmask, amask);
    m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);

}

Uint32 Image::ConvertColor(const double red, const double green, const double blue) {
    // conver to unsigned integers
    unsigned char r = static_cast<unsigned char>(red);
    unsigned char g = static_cast<unsigned char>(green);
    unsigned char b = static_cast<unsigned char>(blue);

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
    Uint32 pixelColor = (r << 24) + (g << 16) + (b << 8) + 255;
#else
    Uint32 pixelColor = (255 << 24) + (r << 16) + (g << 8) + b;
#endif

    return pixelColor;

}

// getter getter functions
int GetSizeX() {
    return
}