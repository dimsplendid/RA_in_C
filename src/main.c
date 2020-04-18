#include "ra_in_c.h"

int main(int argc, char **argv) {
    user_input = argv[1];
    if (argc != 2) {
        error("Wrong argument number.");
        return 1;
    }

    // Load config files.

    // Run command loop.
    // lsh_loop();

    // Perform any shutdown/cleanup.

    return EXIT_SUCCESS;
}