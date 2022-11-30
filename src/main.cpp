#include <iostream>

#include "readers.h"
#include "EtamNetwork.h"

// todo no to sprobujmy jakos juz to przetestowac bez retrenowania. tam porozpoznawac jakies patterny

// mapowac patterny na ich stabilne odpowiedniki po retrenowaniu

int main() {
    auto train_dataset = read_train_dataset();
    auto network = create_for_dataset(train_dataset);

    auto test_dataset = read_test_dataset();
    network.test_on_dataset(test_dataset);
    // initial result without retraining: correct: 2099, incorrect: 7901, unrecognized: 0

    //network.test_stability(train_dataset, 3);
    // all stable for 3, hamming distances mostly in range 80-200, most about 120 I'd say

    // auto test_dataset = read_test_dataset();
    // network.test_stability(test_dataset, 3);
    // actually also stable for 3

    // apply training procedure
    // monitor the number of false positives / negatives, and whether the pattern
    // indeed remains stable.
    // remember which stable states contain patterns and what patterns those are

    //
    // testing
    // read test datasets
    // preprocess
    // feed patterns to the network. for each pattern see if it reaches a stable state.
    // if it does, see if it contained a patterns. if so, see if it's the correct Label.
    // if a stable cycle without a pattern is reached, pattern remains unrecognized.
    // there might also be a very long cycle. Probably best to stop after a given number of
    // steps. Increase this number until the number of errors does not decrease anymore,
    // i.e. there are no non-cycles that we untimely terminated, assuming they are cycles.
    return 0;
}
