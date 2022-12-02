#include <valarray>
#include <cassert>

#include "Hyperplane.h"
#include "utils.h"

Hyperplane::Hyperplane(const vector<double>& coefficients_vector, double constant_term)
        :
        coefficients_vector(coefficients_vector),
        constant_term(constant_term)
{}

Hyperplane::Hyperplane()
        :
        coefficients_vector(),
        constant_term(0)
{}

bool Hyperplane::on_positive_side(const vector<double>& vec) const {
    return dot_product(coefficients_vector, vec) > constant_term;
}

double Hyperplane::distance_to_point(const vector<double> &vec) const {
    assert(0.98 < euclidean_norm(coefficients_vector));
    assert(1.02 > euclidean_norm(coefficients_vector));
    // it is assumed that the coefficients vector is normalized to length 1, so no division
    return dot_product(coefficients_vector, vec) - constant_term;
}

Hyperplane rotate(const Hyperplane &h, const Pattern &positive, const Pattern &negative) {
    Hyperplane new_hyperplane = Hyperplane(h);
    for(uint32_t i = 0; i < IMAGE_SIZE; ++i){
        new_hyperplane.coefficients_vector[i] += ALPHA * (positive.image.pixels[i] - negative.image.pixels[i]);
    }
    new_hyperplane.constant_term /= euclidean_norm(new_hyperplane.coefficients_vector);
    normalize(new_hyperplane.coefficients_vector);
    return new_hyperplane;
}
