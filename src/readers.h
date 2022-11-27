#ifndef ETAM_READERS_H
#define ETAM_READERS_H

#include <cstdint>
#include <vector>

#include "constants.h"

using namespace std;

vector<label> read_labels(const char* filename, uint32_t expected_num_labels);

#endif // ETAM_READERS_H