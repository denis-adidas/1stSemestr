#include <stdio.h>
int main() {
int f, s, t, k;
scanf("%d%d%d", &f, &s, &t);
while (t - s > 0) {
    t -= s;
    k++;
}
printf("Result: %d", t);
    
    
    return 0;
}