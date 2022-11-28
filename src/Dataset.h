#ifndef ETAM_DATASET_H
#define ETAM_DATASET_H


#include "Pattern.h"
#include "Hyperplane.h"

class Dataset{
public:
    vector<Pattern> patterns;
    explicit Dataset(const vector<Image>& images, const vector<label>& labels);
    Pattern* get_nearest(const Hyperplane& h, bool above);
};


#endif //ETAM_DATASET_H
