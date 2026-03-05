#include <stdio.h>

int main() {
    unsigned int a = 5;   // 5 in binary is 0101
    unsigned int b = 4;   // 9 in binary is 1001
    unsigned int result;

    // Bitwise AND
    result = a & b;       // 0101 & 1001 = 0001 (1 in decimal)
    printf("a & b = %u\n", result);

    // Bitwise OR
    result = a | b;       // 0101 | 1001 = 1101 (13 in decimal)
    printf("a | b = %u\n", result);

    // Bitwise XOR
    result = a ^ b;       // 0101 ^ 1001 = 1100 (12 in decimal)
    printf("a ^ b = %u\n", result);

    
    return 0;
}

