#include "ra_in_c.h"

int main(int argc, char **argv) {
    user_input = argv[1];
    if (argc != 2) {
        error("Wrong argument number.");
        return 1;
    }

    // tokenized
    token = tokenize(argv[1]);

    while (!at_eof()) {
        printf("-%d\n", expect_number());
    }
    return 0;
}