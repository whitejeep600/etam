#include "Dataset.h"

#include <cassert>

Dataset::Dataset(const vector<Image>& images, const vector<label>& labels)
        :
        patterns()
{
    assert(images.size() == labels.size());
    for(uint32_t i = 0; i < images.size(); ++i){
        patterns.emplace_back(images[i], labels[i]);
    }
}


