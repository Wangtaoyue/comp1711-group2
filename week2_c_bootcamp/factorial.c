#include <stdio.h>
int main() {
    int n, i, factorial = 1;
    printf("type number:");
    scanf("%d", &n);
for (i = 1; i <= n; i++) {
        factorial *= i;
    }
    printf("Factorial: %d\n", factorial);
return 0;
}
