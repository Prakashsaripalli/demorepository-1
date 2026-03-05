#include <stdio.h>

int main() {
    float speed, time, distance;

    // Reading input
    printf("Enter speed (in meters per second): ");
    scanf("%f", &speed);

    printf("Enter time (in seconds): ");
    scanf("%f", &time);

    // Calculating distance
    distance = speed * time;

    // Displaying the result
    printf("Distance traveled: %.2f meters\n", distance);

    return 0;
}

