#ifndef ETAM_IMAGE_H
#define ETAM_IMAGE_H

#include <vector>

#include "constants.h"

using namespace std;

class Image{
public:
    vector<double> pixels;
    explicit Image(const uint8_t* bytes);
    bool operator==(const Image& that) const;
};

#endif // ETAM_IMAGE_H