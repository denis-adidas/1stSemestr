#include <stdio.h>
int main() {
    int f, s, t, x, res; /* f, s, t - вводимые числа */
    scanf("%d%d%d", &f, &s, &t);
    printf("Result: %d", t % s);

    return 0;
}