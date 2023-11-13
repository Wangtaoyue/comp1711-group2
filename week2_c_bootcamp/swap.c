#include <stdio.h>
int main() {

    int a, b, temp;

    printf("type a:");
    scanf("%d", &a);

    printf("type b:");
    scanf("%d", &b);

    temp = a;
    a = b;
    b = temp;
    printf("a: %d, b: %d\n", a, b);
return 0; 
}