#include <stdio.h>
#include <math.h>

int main() {
    float radius, side, length, width, base, height;
    float area_circle, area_square, area_rectangle, area_triangle;

    // Input for Circle
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);
    area_circle = 3.14* radius * radius;  // Using M_PI from math.h
    printf("Area of the circle: %.2f\n", area_circle);

    // Input for Square
    printf("Enter the side length of the square: ");
    scanf("%f", &side);
    area_square = side * side;
    printf("Area of the square: %.2f\n", area_square);

    // Input for Rectangle
    printf("Enter the length and width of the rectangle: ");
    scanf("%f %f", &length, &width);
    area_rectangle = length * width;
    printf("Area of the rectangle: %.2f\n", area_rectangle);

    // Input for Triangle
    printf("Enter the base and height of the triangle: ");
    scanf("%f %f", &base, &height);
    area_triangle = 0.5 * base * height;
    printf("Area of the triangle: %.2f\n", area_triangle);

    return 0;
}

