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

Pattern *Dataset::get_nearest(const Hyperplane &h, bool above) {
    struct key
    {
        Hyperplane target_hyperplane;
        explicit key(Hyperplane hyperplane1): target_hyperplane(std::move(hyperplane1)){}
        bool operator() (const Pattern& pattern1, const Pattern& pattern2) const
        {
            return (target_hyperplane.distance_to_point(pattern1.image.pixels) <
                    target_hyperplane.distance_to_point(pattern2.image.pixels));
        }
    };
    auto sort_key = key(h);
    sort(patterns.begin(), patterns.end(), sort_key);
    uint32_t index = 0;
    while(index < patterns.size() and (above == h.on_positive_side(patterns[index].image.pixels))){
        ++index;
    }
    if(index == patterns.size()){
        return nullptr;
    }
    else{
        return &(patterns[index]);
    }
}


