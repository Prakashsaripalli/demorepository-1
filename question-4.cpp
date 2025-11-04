#include <stdio.h>

int main() {
    float temperature, convertedTemperature;
    int choice;

    // Displaying menu
    printf("Temperature Conversion menu:\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Celsius to Fahrenheit\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        // Fahrenheit to Celsius
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &temperature);
        convertedTemperature = (temperature - 32) * 5.0 / 9.0;
        printf("Temperature in Celsius: %.2f\n", convertedTemperature);
    } else if (choice == 2) {
        // Celsius to Fahrenheit
        printf("Enter temperature in Celsius: ");
        scanf("%f", &temperature);
        convertedTemperature = (temperature * 9.0 / 5.0) + 32;
        printf("Temperature in Fahrenheit: %.2f\n", convertedTemperature);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}

