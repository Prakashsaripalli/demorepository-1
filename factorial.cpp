#include <stdio.h>




int main() {
    int num, fact,factorial(num);

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Factorial of negative numbers is not defined.\n");
    } else {
        fact = factorial(num);
        printf("Factorial of %d is %d\n", num, fact);
    }

    return 0;
}
