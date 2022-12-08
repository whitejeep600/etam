#include <iostream>

#include "readers.h"
#include "EtamNetwork.h"

// todo zobaczyc czy da sie ustabilizowac, jak tak to przetestowac, jak bedzie trzeba to tez z tą drugą heurą
int main() {
    auto train_dataset = read_train_dataset();
    auto network = create_for_dataset(train_dataset);

    auto test_dataset = read_test_dataset();
//    cout << "testing stability on test patterns\n";

//    uint32_t applications = 0;
//    for(; applications < 10; ++applications){
//        cout << "testing stability for " << applications << " applications\n";
//        if(network.test_stability(test_dataset, applications)){
//            cout << "stable after " << applications << " applications.\n";
//            break;
//        }
//    }
    network.test_on_dataset(test_dataset);
    // initial result without retraining: correct: 2099, incorrect: 7901, unrecognized: 0

    // training according to the algorithm, most unrecognized

    // correct: 99, incorrect: 713, unrecognized: 9188.

    // training with choosing closest patterns above/below:
    // correct: 973, incorrect: 9027, unrecognized: 0.

    // lr 1 /128: correct: 407, incorrect: 505, unrecognized: 9088

    // noo to może jest nie do końca miarodajne, bo przecież nie była sprawdzana stabilność. zobaczymy czy
    // będzie jakiś zadowalający wynik po ustabilizowaniu, z lr 1/128


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

    // testing stability for 5 applications
    //stable: 33458, unstable: 26542.
    //testing stability for 6 applications
    //stable: 44508, unstable: 15492.
    //testing stability for 7 applications
    //stable: 51734, unstable: 8266.
    //testing stability for 8 applications
    //stable: 55292, unstable: 4708.
    //testing stability for 9 applications
    //stable: 57673, unstable: 2327.
    //not stable after 10 applications.

    //testing stability on test patterns
    //testing stability for 0 applications
    //stable: 7366, unstable: 2634.
    //testing stability for 7 applications
    //stable: 8575, unstable: 1425.
    //testing stability for 8 applications
    //stable: 9155, unstable: 845.
    //testing stability for 9 applications
    //stable: 9533, unstable: 467.
    //correct: 553, incorrect: 1247, unrecognized: 8200.


    // stable: 59965, unstable: 35.
    //testing stability for 14 applications
    //stable: 59985, unstable: 15.

    //testing stability on test patterns
    //testing stability for 0 applications
    //stable: 0, unstable: 10000.
    //testing stability for 1 applications
    //testing stability for 10 applications
    //stable: 9784, unstable: 216.
    //testing stability for 11 applications
    //stable: 9926, unstable: 74.
    //testing stability for 12 applications
    //stable: 9977, unstable: 23.
    //testing stability for 13 applications
    //stable: 9993, unstable: 7.
    //testing stability for 14 applications
    //stable: 9996, unstable: 4.
    return 0;
}
