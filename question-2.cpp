#include <stdio.h>

int main() {
    int num1, num2, sum, difference;

    // Reading input
    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Calculating sum and difference
    sum = num1 + num2;
    difference = num1 - num2;

    // Displaying the results
    printf("Sum: %d\n", sum);
    printf("Difference: %d\n", difference);

    return 0;
}

