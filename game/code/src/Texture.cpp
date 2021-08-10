#include "../include/local/Texture.hpp"

Texture::Texture(){
    mTexture = nullptr;
    mWidth = 0;
    mHeight = 0;
}

Texture::~Texture(){
    Free();
}

void Texture::Free(){
    if (mTexture != nullptr){
        mTexture = nullptr;
        mWidth = 0;
        mHeight = 0;
    }
}

bool Texture::LoadFromFile(std::string path, SDL_Renderer* pRenderer){
    // Deallocate just in case
    Free();

    // Parameter fillers
    int width, height, orig_format;
    int req_format = STBI_rgb_alpha;

    // Loading data to imageSurfaceData
    unsigned char* imageSurfaceData = stbi_load(path.c_str(), &width, &height, &orig_format, req_format);
    if (imageSurfaceData == nullptr){
        std::cerr << "Image Surface Data couldn't load, STBI error function: " << stbi_failure_reason() << std::endl;
    }

    // More parameter fillers
    int pitch, depth;
    unsigned int pixel_format;
    if (req_format == STBI_rgb_alpha){
        pitch = 4*width;
        depth = 32;
        pixel_format = SDL_PIXELFORMAT_RGBA32;
    }

    // Put imageSurfaceData onto imageSurface
    SDL_Surface* imageSurface = SDL_CreateRGBSurfaceWithFormatFrom(static_cast<void*>(imageSurfaceData), width, height, depth, pitch, pixel_format);
    if (imageSurface == nullptr){
        std::cerr << "Image Surface couldn't be created from Image Surface Data, SDL error function: " << SDL_GetError() << std::endl;
    }

    // Put imageSurface onto imageTexture
    SDL_Texture* imageTexture = SDL_CreateTextureFromSurface(pRenderer, imageSurface);
    if (imageTexture == nullptr){
        std::cerr << "Image Texture couldn't be created from Image Surface, SDL error function: " << SDL_GetError() << std::endl;
    } 
    else {
        // Get the width and height of the imageSurface
        mWidth = imageSurface->w;
        mHeight = imageSurface->h;
    }

    // Free imageSurface
    SDL_FreeSurface(imageSurface);

    // Set member texture equal to imageTexture
    mTexture = imageTexture;

    return mTexture != nullptr;
}

void Texture::Render(int x, int y, SDL_Renderer* pRenderer, SDL_Rect* clip, double angle,
                     SDL_Point* centre, SDL_RendererFlip flip, double enlargement){
    SDL_Rect renderArea = {x, y, mWidth * (int)enlargement, mHeight * (int)enlargement};
    SDL_RenderCopyEx(pRenderer, mTexture, clip, &renderArea, angle, centre, flip);
}

int Texture::GetWidth(){
    return mWidth;
}

int Texture::GetHeight(){
    return mHeight;
}