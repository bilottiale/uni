#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

float zeta(float s){
    float z = 0, zo;
    for (int n = 1; n < 1000000; n++) {
        zo = 1.0f / (n * n);
        z += zo;
        if(zo < 1e-6f) {
            break;
        }
    }
    return z;
}

int main(void) {
    int x = 5, y = 10;
    int result = max(x, y);
    printf("Max of %d and %d is %d\n", x, y, result);
    float zeta_value = zeta(2.0f);
    printf("Zeta(2.0) = %f\n", zeta_value);
}