#ifndef ETAM_DATASET_H
#define ETAM_DATASET_H


#include "Pattern.h"
#include "Hyperplane.h"

class Dataset{
public:
    vector<Pattern> patterns;
    explicit Dataset(const vector<Image>& images, const vector<Label>& labels);
    Pattern* get_positive_minimal_distance_pattern(const Hyperplane& h, uint32_t i);
    Pattern* get_negative_maximal_distance_pattern(const Hyperplane& h, uint32_t i);
    bool ith_bit_the_same_for_all(uint32_t i, double value) const;
};


#endif //ETAM_DATASET_H
