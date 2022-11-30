#include "Pattern.h"

#include <utility>


Pattern::Pattern(Image image, Label l):
        image(std::move(image)),
        label(l)
{}

bool Pattern::operator==(const Pattern& that) const {
    return this->image == that.image and this->label == that.label;
}
