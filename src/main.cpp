#include <iostream>

#include "readers.h"

int main() {
    auto train_dataset = read_train_dataset();

    // apply training procedure
    // monitor the number of false positives / negatives, and whether the pattern
    // indeed remains stable.
    // remember which stable states contain patterns and what patterns those are

    //
    // testing
    // read test datasets
    // preprocess
    // feed patterns to the network. for each pattern see if it reaches a stable state.
    // if it does, see if it contained a patterns. if so, see if it's the correct label.
    // if a stable cycle without a pattern is reached, pattern remains unrecognized.
    // there might also be a very long cycle. Probably best to stop after a given number of
    // steps. Increase this number until the number of errors does not decrease anymore,
    // i.e. there are no non-cycles that we untimely terminated, assuming they are cycles.
    return 0;
}
