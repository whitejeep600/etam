
#include <cstdint>
#include <cmath>
#include <cassert>

#include "utils.h"

using namespace std;

double dot_product(const vector<double>& vec1, const vector<double>& vec2) {
    double res = 0;
    for(uint32_t i = 0; i < vec1.size(); ++i){
        res += vec1[i] * vec2[i];
    }
    return res;
}

double euclidean_norm(const vector<double>& vec){
    double res = 0.0;
    for(auto x: vec){
        res += x*x;
    }
    return sqrt(res);
}

void add_elementwise(vector<double>& this_one, const vector<double>& that_one){
    assert(this_one.size() == that_one.size());
    for(uint32_t i = 0; i < this_one.size(); ++i){
        this_one[i] += that_one[i];
    }
}

vector<double> multiply_elementwise(const vector<double>& vector1, double scalar) {
    auto result = vector<double>(vector1);
    for(double& i : result){
        i *= scalar;
    }
    return result;
}

void normalize(vector<double>& vector1) {
    auto norm = euclidean_norm(vector1);
    for(double& i : vector1){
        i /= norm;
    }
}

uint32_t hamming_distance(const vector<double>& vector1, const vector<double>& vector2){
    uint32_t result = 0;
    for(uint32_t i = 0; i < vector1.size(); ++i){
        if(vector1[i] != vector2[i]){
            ++result;
        }
    }
    return result;
}
