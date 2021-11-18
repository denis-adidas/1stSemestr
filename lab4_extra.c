#include <stdio.h>
#include <stdlib.h>
int inWord(char c) {
    return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z';
}
int is_pld(char *s, start, end) {
    int j, k, n, l = 0;
    n = start - end;
    j = start;
    k = end;
    while (start <= end) {
        if ((s[j] == s[k])) {
            l++;
        }
        j++;
        k--;
        start++;
    }
    if ((n % 2 == 0) && ((n / 2) == l)) return 1;
    if ((n % 2 != 0) && ((n / 2) == l - 1)) return 1;
}


int main() {
    int n; int b = 0;
    int in_word, word_count;
    int start_m, end_m;

    printf("Enter symb count: ");
    scanf("%d", &n);


    char* str = (char*)malloc((sizeof(char) * n) + 2);

    printf("Enter string: ");
    for (int i = 0; i <= n; i++) {
        scanf("%c", &str[i], sizeof(char));
    }

//    printf("%d \n", is_pld(str, 1, n ));
    // основной алгоритм работы
    for (int i = 0; i <= n; i++) {   //идем по строке
        if (inWord(str[i]) != 0) {   //смотрим слова
            in_word = 1;
            start_m = i;
            printf("%c", str[i]);
        }
        else {                       // если пробел
            if (in_word == 1) {
                end_m = i - 1;
                word_count++;
                b = word_count;
                if (is_pld(str, start_m, end_m) == 1) {
                    while (b != 0) {
                        printf("!");
                        b--;
                    }
                }
                in_word = 0;
            }

        }

    }
    // решает проблему, когда знак не выводится, если на конце пробел
    if ((str[n] != ' ')) {
        word_count++;
        b = word_count;
        in_word = 0;
        while (b != 0) {
            printf("!");
            b--;
        }
    }
}

