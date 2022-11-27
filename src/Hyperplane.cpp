#include <valarray>
#include <cassert>

#include "Hyperplane.h"

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
    auto dupa = dot_product(coefficients_vector, vec);
    return dupa > constant_term;
}

double Hyperplane::distance_to_point(const vector<double> &vec) const {
    return abs(dot_product(coefficients_vector, vec) + constant_term) /
           euclidean_norm(coefficients_vector);
}
