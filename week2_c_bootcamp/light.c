
#include <stdio.h>
int main() {
double speed = 299792458;
// speed of light in meters/second 
long long int time;
// time in seconds
double distance;
    printf("Enter time in days: ");
    scanf("%lld", &time);
time = time * 24 * 60 * 60;
// Convert days to seconds distance = speed * time;
    printf("Distance: %.2e meters\n", distance);
return 0; }