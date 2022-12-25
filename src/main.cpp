#include "readers.h"
#include "EtamNetwork.h"

int main() {
    create_for_dataset(read_train_dataset()).test_on_dataset(read_test_dataset());  // :)
    return 0;
}
