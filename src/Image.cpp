#include <cstdint>

#include "Image.h"

Image::Image(const uint8_t* bytes)
:
pixels{IMAGE_SIZE, 0}
{
    for(uint32_t row = 0; row < IMAGE_HEIGHT; ++row){
        for(uint32_t column = 0; column < IMAGE_WIDTH; ++column){
            auto new_element = (double) bytes[IMAGE_WIDTH * row + column];
            if(new_element == 0){
                pixels[IMAGE_WIDTH * row + column] = -1;
            }
            else{
                pixels[IMAGE_WIDTH * row + column] = 1;
            }
        }
    }
}

bool Image::operator==(const Image& that) const{
    for(uint32_t i = 0; i < IMAGE_SIZE; ++i){
        if(this->pixels[i] != that.pixels[i]) return false;
    }
    return true;
}

