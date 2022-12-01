#include <cassert>
#include <iostream>
#include <cmath>

#include "Neuron.h"
#include "utils.h"

Neuron create_ith(const Dataset& dataset, uint32_t i){
    auto coefficients_vector = vector<double>(IMAGE_SIZE, 0);
    for(const auto& p: dataset.patterns){
        if(p.image.pixels[i] == 1.0){
            add_elementwise(coefficients_vector, p.image.pixels);
        }
        else{
            add_elementwise(coefficients_vector, multiply_elementwise(p.image.pixels, -1.0));
        }
    }
    normalize(coefficients_vector);
    assert(0.98 < euclidean_norm(coefficients_vector));
    assert(1.02 > euclidean_norm(coefficients_vector));
    return Neuron(Hyperplane{coefficients_vector, 0});
}

double Neuron::apply(const vector<double> &input) const {
    return h.on_positive_side(input) ? 1 : -1;
}

void Neuron::retrain(Dataset &dataset, uint32_t i) {
    if(dataset.ith_bit_the_same_for_all(i, -1.0)){
        h.constant_term = (double) IMAGE_HEIGHT;
        return;
    }
    if(dataset.ith_bit_the_same_for_all(i, 1.0)){
        h.constant_term = -1.0 * (double) IMAGE_HEIGHT;
        return;
    }
    auto positive = dataset.get_positive_minimal_distance_pattern(this->h, i);
    auto negative = dataset.get_negative_maximal_distance_pattern(this->h, i);
    double dp = this->h.distance_to_point(positive->image.pixels);
    double dn = this->h.distance_to_point(negative->image.pixels);
    double new_minimal_distance;
    if(dp > dn) new_minimal_distance = (dp - dn) / 2.0;
    else new_minimal_distance = (dn - dp) / 2.0;
    double minimal_distance;
    uint32_t run_iterations = 0;
    do{
        minimal_distance = new_minimal_distance;
        this->h.constant_term += (dp + dn) / 2.0;
        auto new_hyperplane = rotate(this->h, *positive, *negative);
        positive = dataset.get_positive_minimal_distance_pattern(this->h, i);
        negative = dataset.get_negative_maximal_distance_pattern(this->h, i);
        dp = new_hyperplane.distance_to_point(positive->image.pixels);
        dn = new_hyperplane.distance_to_point(negative->image.pixels);
        if(dp > dn) new_minimal_distance = (dp - dn) / 2.0;
        else new_minimal_distance = (dn - dp) / 2.0;
        if(new_minimal_distance > minimal_distance and run_iterations < 10){
            this->h = new_hyperplane;
            ++run_iterations;
        }
        else{
            cout << "ran " << run_iterations << " iterations.\n";
            break;
        }
    }
    while(2137);
}
