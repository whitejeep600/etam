#include <cassert>
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
