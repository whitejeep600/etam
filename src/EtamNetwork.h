#ifndef ETAM_ETAMNETWORK_H
#define ETAM_ETAMNETWORK_H

#include <vector>
#include <map>

#include "Dataset.h"
#include "Neuron.h"

using namespace std;

class EtamNetwork {
public:
    vector<Neuron> neurons;
    map<vector<double>, Label> patterns_mapping;
    EtamNetwork(): neurons(), patterns_mapping() {};
    vector<double> apply(const vector<double>& input) const;
    bool vector_stable(const vector<double>& vector1) const;
    bool test_stability(const Dataset& dataset, uint32_t applications) const;
    void create_patterns_mapping(const Dataset& dataset);
    vector<double> stabilize(const vector<double>& vector1, uint32_t applications) const;
    Label recognize(const vector<double>& vector1) const;
    void test_on_dataset(const Dataset& dataset) const;

};

EtamNetwork create_for_dataset(Dataset&& dataset);


#endif //ETAM_ETAMNETWORK_H
