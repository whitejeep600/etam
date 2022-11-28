#include <iostream>
#include "EtamNetwork.h"
#include "utils.h"

EtamNetwork create_for_dataset(const Dataset& dataset){
    auto network = EtamNetwork();
    for(uint32_t i = 0; i < IMAGE_SIZE; ++i){
        network.neurons.push_back(create_ith(dataset, i));
    }
    return network;
}

vector<double> EtamNetwork::apply(const vector<double>& input) const {
    auto result = vector<double>();
    for(uint32_t i = 0; i < IMAGE_SIZE; ++i){
        result.push_back(neurons[i].apply(input));
    }
    return result;
}

bool EtamNetwork::vector_stable(const vector<double> &vector1) const {
    return vector1 == this->apply(vector1);
}

void EtamNetwork::test_stability(const Dataset &dataset, uint32_t applications) const {
    uint32_t stable = 0;
    uint32_t unstable = 0;
    for(const auto& p: dataset.patterns) {
        auto v = vector<double>(p.image.pixels);
        for(uint32_t i = 0; i < applications; ++i){
            v = this->apply(v);
        }
        if(this->vector_stable(v)){
            // in any case might be worth experimenting with; no or almost no pattern is stable right away
            // but after two applications, stable 38428, unstable 21572.
            ++stable;
        }
        else{
            ++unstable;
        }
    }
    cout << "stable: " << stable << ", unstable: " << unstable << ".\n";
}
