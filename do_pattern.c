#include <stdio.h>
#include <stdlib.h>
#include <iostream>


int main() {
    unsigned char pattern[] = "aaaabbbb";
    std::cout << "Using pattern of size " << sizeof(pattern) << " bytes\n";
    while (1) {
        unsigned char *ptr = (unsigned char *)malloc(1000000 * sizeof(pattern));
        for (int i = 0; i < 1000000 * sizeof(pattern); ++i)
            ptr[i] = pattern[i % sizeof(pattern)];
    }

    return 0;
};
