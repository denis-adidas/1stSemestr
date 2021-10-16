#include <stdio.h>
#include <stdlib.h>
int abs(num) {
    if (num >= 0) {
        return num;
    }
    if (num < 0) {
        return -num;
    }
}
int max2(int *numbers, int n) {
    int k = 0; int max = 0;
    while (k < n) {
        if (abs(numbers[k]) > max) {
            max = abs(numbers[k]);
        }
        k++;
    }
    return max;
}
//int test(int m[]) {
//
//}
int main() {
    int n;
    printf("Введите кол-во чисел в массиве: ");
    scanf("%d", &n);

    int *mas = NULL;
    mas = malloc(sizeof(int) * n);
    int i = 0;
    int max = 0;
    // int *pmax = max;
    for (i; i < n; i++) {
        scanf("%d", &mas[i]);
    }
    /* i = 0;
    while (i < n) {
        if (abs(numbers[i]) > max) {
            max = abs(numbers[i]);
        }
        i++;
        } */
    max = max2(mas, n);
    printf("%d", max);
}
//работа с динамической памятью малл лок фри