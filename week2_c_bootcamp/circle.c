#include <stdio.h>
int main() {
    float radius;
    float area;
    printf("Type the r:");
    scanf("%f", &radius);
    area = 3.14159 * radius * radius;
    printf("Area: %.4f\n", area);
    return 0;
}