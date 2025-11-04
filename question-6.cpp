#include <stdio.h>
#include <math.h>  // Include math.h for the pow() function

int main() {
    float principal, rate, time, simpleInterest, compoundInterest;

    // Reading input
    printf("Enter the principal amount: ");
    scanf("%f", &principal);

    printf("Enter the annual interest rate (in percentage): ");
    scanf("%f", &rate);

    printf("Enter the time period (in years): ");
    scanf("%f", &time);

    // Calculating Simple Interest
    simpleInterest = (principal * rate * time) / 100;
    printf("Simple Interest: %.2f\n", simpleInterest);

    // Calculating Compound Interest
    compoundInterest = principal * pow((1 + rate / 100), time) - principal;
    printf("Compound Interest: %.2f\n", compoundInterest);

    return 0;
}

