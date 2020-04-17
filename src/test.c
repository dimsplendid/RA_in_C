#include <stdio.h>
#include <string.h>

int add(int x, int y) {
    return x+y;
}

#ifdef TEST

int main(int argc, char ** argv) {
    char * test_function = argv[1];
    if (strcmp("testAdd", test_function) == 0) {
        if(add(1,1) == 2)
            return 1;
        else
            return 0;
    }
    else
        return 0;
}

#endif