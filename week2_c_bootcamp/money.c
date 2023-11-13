#include <stdio.h>
int main() {
    
    float principal, rate, time, interest;

    printf("type principal:");
    scanf("%f", &principal);

    printf("type rate:");
    scanf("%f", &rate);

    printf("type time:");
    scanf("%f", &time);
    
    interest = (principal * rate * time) / 100;
    
    printf("Interest: %.2f\n", interest);
    
    return 0;
}