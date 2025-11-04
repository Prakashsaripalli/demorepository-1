#include <stdio.h>

int main() {
    int N, M;
    float discounted_N;

    // Reading the costs of online order and dining at the restaurant
    scanf("%d %d", &N, &M);

    // Applying the 10% discount to the online order cost
    discounted_N = N * 0.9;

    // Comparing the costs and printing the appropriate result
    if (discounted_N < M) {
        printf("ONLINE\n");
    } else if (discounted_N > M) {
        printf("DINING\n");
    } else {
        printf("EITHER\n");
    }

    return 0;
}

