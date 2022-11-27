#ifndef ETAM_READERS_H
#define ETAM_READERS_H
#include <cstdint>
#include <vector>

#include "constants.h"
#include "Dataset.h"

using namespace std;

Dataset read_train_dataset();

Dataset read_test_dataset();

#endif // ETAM_READERS_H