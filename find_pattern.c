#include <stdio.h>
#include <stdlib.h>
#include <iostream>




int main(int argc, char *argv[]) {
    unsigned char buffer[100];
    unsigned char pattern[] = "war";

    FILE *ptr;
    ptr = fopen("memdump_1", "rb");
    if (!ptr) {
        std::cout << "File not found!\n";
        return 0;
    }

    std::cout << "Pattern size: " << sizeof(pattern) - 1 << "\n";


    unsigned long int pos = 0;
    unsigned long int c = 0;
    unsigned long int cur = 0;
    do {
        c = fread(buffer, 1, sizeof(buffer), ptr);
        pos += c;
        if (pos % 1000000 == 0)
            std::cout << "\rRead " << (pos / 1000000) << " Mb";

        for (int i = 0; i < sizeof(buffer); ++i) {
            if (buffer[i] == pattern[cur]) {
                cur++;
            } else {
                cur = 0;
            }
            
            if (cur == (sizeof(pattern) - 1)) {
                cur = 0;
                std::cout << "\n\nFound at: " << pos << "\n";
            }
        }
        
    } while (c != 0);
    std::cout << "\n\n";

    fclose(ptr);
    return 0;
};
