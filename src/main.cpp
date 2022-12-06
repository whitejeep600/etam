#include <iostream>

#include "readers.h"
#include "EtamNetwork.h"

// todo zobaczyc czy da sie ustabilizowac, jak tak to przetestowac, jak bedzie trzeba to tez z tą drugą heurą
int main() {
    auto train_dataset = read_train_dataset();
    auto network = create_for_dataset(train_dataset);

    auto test_dataset = read_test_dataset();
    network.test_on_dataset(test_dataset);
    // initial result without retraining: correct: 2099, incorrect: 7901, unrecognized: 0

    // training according to the algorithm, most unrecognized

    // correct: 99, incorrect: 713, unrecognized: 9188.

    // training with choosing closest patterns above/below:
    // correct: 973, incorrect: 9027, unrecognized: 0.

    // lr 1 /128: correct: 407, incorrect: 505, unrecognized: 9088


    //network.test_stability(train_dataset, 3);
    // all stable for 3, hamming distances mostly in range 80-200, most about 120 I'd say

    // auto test_dataset = read_test_dataset();
    // network.test_stability(test_dataset, 3);
    // actually also stable for 3

    // apply training procedure
    // monitor the number of false positives / negatives, and whether the pattern
    // indeed remains stable.
    // remember which stable states contain patterns and what patterns those are

    // so we can try to change choosing the min(max)imal distance patterns so that they are really separated
    return 0;
}
