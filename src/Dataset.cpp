#include "Dataset.h"

#include <cassert>

Dataset::Dataset(const vector<Image>& images, const vector<Label>& labels)
        :
        patterns()
{
    assert(images.size() == labels.size());
    for(uint32_t i = 0; i < images.size(); ++i){
        patterns.emplace_back(images[i], labels[i]);
    }
}

bool Dataset::ith_bit_the_same_for_all(uint32_t i, double value) const {
    for(const auto& p: this->patterns){
        if(p.image.pixels[i] == value){
            return false;
        }
    }
    return true;
}

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

Pattern *Dataset::get_positive_minimal_distance_pattern(const Hyperplane &h, uint32_t i) {
    auto sort_key = key(h);
    sort(patterns.begin(), patterns.end(), sort_key);
    uint32_t index = 0;
    while(1.0 != patterns[index].image.pixels[i]){
        ++index;
    }
    return &(patterns[index]);
}

Pattern *Dataset::get_negative_maximal_distance_pattern(const Hyperplane &h, uint32_t i) {
    auto sort_key = key(h);
    sort(patterns.begin(), patterns.end(), sort_key);
    uint32_t index = patterns.size() - 1;
    while(-1.0 != patterns[index].image.pixels[i]){
        --index;
    }
    return &(patterns[index]);
}


