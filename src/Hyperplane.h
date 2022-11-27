#ifndef ETAM_HYPERPLANE_H
#define ETAM_HYPERPLANE_H

#include <vector>

using namespace std;

class Hyperplane{
public:
    vector<double> coefficients_vector;
    double constant_term;
    Hyperplane(const vector<double>& coefficients_vector, double constant_term);
    Hyperplane();
    bool on_positive_side(const vector<double>& vec) const;
    double distance_to_point(const vector<double>& vec) const;
};


#endif //ETAM_HYPERPLANE_H
