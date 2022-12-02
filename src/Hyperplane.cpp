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
    return dot_product(coefficients_vector, vec) + constant_term /
           euclidean_norm(coefficients_vector);
}

Hyperplane rotate(const Hyperplane &h, const Pattern &positive, const Pattern &negative) {
    Hyperplane new_hyperplane = Hyperplane(h);
    for(uint32_t i = 0; i < IMAGE_SIZE; ++i){
        new_hyperplane.coefficients_vector[i] += ALPHA * (positive.image.pixels[i] - negative.image.pixels[i]);
    }
    normalize(new_hyperplane.coefficients_vector);
    return new_hyperplane;
}
