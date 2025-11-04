#include <stdio.h>
#include <math.h>  // Include math.h for the sqrt() function

int main() {
    double num, result;

    // Reading input
    printf("Enter a number: ");
    scanf("%lf", &num);

    // Calculating the square root
    result = sqrt(num);

    // Displaying the result
    printf("Square root of %.2f is %.2f\n", num, result);

    return 0;
}

