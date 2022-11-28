#ifndef ETAM_UTILS_H
#define ETAM_UTILS_H

#include <vector>

using namespace std;


double dot_product(const vector<double>& vec1, const vector<double>& vec2);

double euclidean_norm(const vector<double>& vec);

void add_elementwise(vector<double>& this_one, const vector<double>& that_one);

vector<double> multiply_elementwise(const vector<double>& vector1, double scalar);

void normalize(vector<double>& vector1);


#endif //ETAM_UTILS_H
