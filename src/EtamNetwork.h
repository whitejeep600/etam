#ifndef ETAM_ETAMNETWORK_H
#define ETAM_ETAMNETWORK_H

#include <vector>

#include "Dataset.h"
#include "Neuron.h"

using namespace std;

class EtamNetwork {
public:
    vector<Neuron> neurons;
    EtamNetwork(): neurons() {};
    vector<double> apply(const vector<double>& input) const;
    bool vector_stable(const vector<double>& vector1) const;
    void test_stability(const Dataset& dataset, uint32_t applications) const;
};

EtamNetwork create_for_dataset(const Dataset& dataset);


#endif //ETAM_ETAMNETWORK_H
