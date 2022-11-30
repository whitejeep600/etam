#ifndef ETAM_PATTERN_H
#define ETAM_PATTERN_H

#include "Image.h"

class Pattern{
public:
    Image image;
    Label label;
    explicit Pattern(Image  image, Label l);
    bool operator==(const Pattern& that) const;
};



#endif //ETAM_PATTERN_H
