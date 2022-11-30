#ifndef ETAM_CONSTANTS_H
#define ETAM_CONSTANTS_H

#include <cstdint>

using Label = uint8_t;

const Label NO_LABEL = 42;  // arbitrary value greater than 9

const uint32_t IMAGE_HEIGHT = 28;
const uint32_t IMAGE_WIDTH = 28;
const uint32_t IMAGE_SIZE =  IMAGE_HEIGHT * IMAGE_WIDTH;

const double ALPHA = 1.0 / 16;

#endif // ETAM_CONSTANTS_H
