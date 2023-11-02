#include <stdio.h>

// Define
#define sz 27

int main(void)
{
    int freq[sz];
    char alphabet[sz] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < sz; i++){
        freq[i] = alphabet[i];
    }
    printf("%s\n", alphabet);
    ;
}
