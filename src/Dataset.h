#ifndef ETAM_DATASET_H
#define ETAM_DATASET_H


#include "Pattern.h"

class Dataset{
public:
    vector<Pattern> patterns;
    explicit Dataset(const vector<Image>& images, const vector<label>& labels);
};


#endif //ETAM_DATASET_H
