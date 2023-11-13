#include <stdio.h>
int main(){
    int a;
    int b;
    int c;

    printf("Hello, please enter a:");
    scanf("%d", &a);

    printf("Hello, please enter b:");
    scanf("%d", &b);

    c = a + b;

    printf ("The sum of adding %d and %d is %d\n", a , b, c);

    return 0;
}