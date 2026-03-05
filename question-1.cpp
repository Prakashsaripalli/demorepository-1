#include <stdio.h>

int main() {
    int myInt;
    float myFloat;
    char myChar;
    char myString[5];

    // Reading input
    printf("Enter an integer: ");
    scanf("%d", &myInt);

    printf("Enter a float: ");
    scanf("%f", &myFloat);

    printf("Enter a character: ");
    scanf(" %c", &myChar); // Notice the space before %c to consume any leftover whitespace

    printf("Enter a string: ");
    scanf("%s", myString); // Note: this will read a single word (string without spaces)

    // Displaying the input
    printf("\nYou entered the integer: %d\n", myInt);
    printf("You entered the float: %.2f\n", myFloat);
    printf("You entered the character: %c\n", myChar);
    printf("You entered the string: %s\n", myString);

    return 0;
}

