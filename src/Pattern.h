#ifndef ETAM_PATTERN_H
#define ETAM_PATTERN_H

#include "Image.h"

class Pattern{
public:
    Image image;
    label l;
    explicit Pattern(Image  image, label l);
    bool operator==(const Pattern& that) const;
};



#endif //ETAM_PATTERN_H
