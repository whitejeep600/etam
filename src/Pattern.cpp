#include "Pattern.h"

#include <utility>


Pattern::Pattern(Image image, label l):
        image(std::move(image)),
        l(l)
{}

bool Pattern::operator==(const Pattern& that) const {
    return this->image == that.image and this->l == that.l;
}
