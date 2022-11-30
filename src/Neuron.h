#ifndef ETAM_NEURON_H
#define ETAM_NEURON_H

#include <utility>

#include "Hyperplane.h"
#include "Dataset.h"

class Neuron {
    Hyperplane h;
public:
    explicit Neuron(Hyperplane h): h(std::move(h)) {}
    double apply(const vector<double>& input) const;
    void retrain(Dataset& dataset, uint32_t i);
};

Neuron create_ith(const Dataset& dataset, uint32_t i);


#endif //ETAM_NEURON_H
