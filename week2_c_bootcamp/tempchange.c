#include <stdio.h>
int main() {
    float fahrenheit, celsius;
    printf("type f:");
    scanf("%f", &fahrenheit);
    celsius = (fahrenheit - 32) * 5 / 9;
    printf("Celsius: %.2f\n", celsius);
    return 0;
}