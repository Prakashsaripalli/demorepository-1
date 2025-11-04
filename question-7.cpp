#include<stdio.h>
int main()
{
/*	int a = 10, b = 2;
float c = 2.5;
double d = 4.0;
double result;

result = a/b*c - b + a*d/3;
printf("Result: %.2f\n", result);  // Example output based on the provided values*/
int i = 5;
int j;

j = (i++) + (++i);

// Step by step:
// (i++) returns 5 (and then i becomes 6)
// (++i) increments i to 7 and returns 7
// j = 5 + 7 -> j = 12

printf("j = %d, i = %d\n", j, i);  // Output: j = 12, i = 7


	return 0;
}
