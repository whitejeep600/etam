#include <iostream>
#include <cassert>
#include <iostream>

#include "EtamNetwork.h"
#include "utils.h"

EtamNetwork create_initial_for_dataset(const Dataset& dataset){
    auto network = EtamNetwork();
    for(uint32_t i = 0; i < IMAGE_SIZE; ++i){
        network.neurons.push_back(create_ith(dataset, i));
    }
    return network;
}

void EtamNetwork::create_patterns_mapping(const Dataset &dataset) {
    for(uint32_t applications = 0; applications < 10; ++applications){
        cout << "testing stability for " << applications << " applications\n";
        this->test_stability(dataset, applications);
    }
    for(const auto& p: dataset.patterns){
        const uint32_t MAX_APPLICATIONS = 2137;
        auto v = this->stabilize(p.image.pixels, MAX_APPLICATIONS);
        this->patterns_mapping.insert({v, p.label});
    }
}

EtamNetwork create_for_dataset(Dataset& dataset){
    auto network = create_initial_for_dataset(dataset);
    for(uint32_t i = 0; i < IMAGE_SIZE; ++i){
        cout << "starting neuron " << i << "\n";
        network.neurons[i].retrain(dataset, i);
    }
    network.create_patterns_mapping(dataset);
    return network;
}

vector<double> EtamNetwork::apply(const vector<double>& input) const {
    auto result = vector<double>();
    for(uint32_t i = 0; i < IMAGE_SIZE; ++i){
        result.push_back(this->neurons[i].apply(input));
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
        auto v = this->stabilize(p.image.pixels, applications);
        if(this->vector_stable(v)){
            // in any case might be worth experimenting with; no or almost no pattern is stable right away
            // but after two applications, stable 38428, unstable 21572.
            // after three, all of them, actually
            ++stable;
        }
        else{
            ++unstable;
        }
        //cout << hamming_distance(p.image.pixels, v) << "\n";
    }
    cout << "stable: " << stable << ", unstable: " << unstable << ".\n";
}

vector<double> EtamNetwork::stabilize(const vector<double> &vector1, uint32_t applications) const {
    auto v = vector<double>(vector1);
    uint32_t i = 0;
    while(not this->vector_stable(v) and i < applications){
        v = this->apply(v);
        ++i;
    }
    assert(this->vector_stable(v));
    return v;
}

Label EtamNetwork::recognize(const vector<double> &vector1) const {
    const uint32_t MAX_APPLICATIONS = 3;
    auto stabilized = this->stabilize(vector1, MAX_APPLICATIONS);
    try{
        return this->patterns_mapping.at(stabilized);
    }
    catch(out_of_range&){
        return NO_LABEL;
    }
}

void EtamNetwork::test_on_dataset(const Dataset &dataset) const {
    uint32_t unrecognized = 0;
    uint32_t correct = 0;
    uint32_t incorrect = 0;
    Label l;
    for(const auto& p: dataset.patterns){
        l = this->recognize(p.image.pixels);
        if(l == NO_LABEL){
            ++unrecognized;
        }
        else if(l == p.label){
            ++correct;
        }
        else ++incorrect;
    }
    cout << "correct: " << correct << ", incorrect: " << incorrect << ", unrecognized: " << unrecognized << ".\n";
}



