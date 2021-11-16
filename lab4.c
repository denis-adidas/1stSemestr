#include <stdio.h>
#include <stdlib.h>
int inWord(char c) {
    return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z';
}

int main() {
    int n; int b = 0;
    int in_word, word_count;
    printf("Enter symb count: ");
    scanf("%d", &n);

    char* str = (char*)malloc((sizeof(char) * n) + 2);

    printf("Enter string: ");
    for (int i = 0; i <= n; i++) {
        scanf("%c", &str[i], sizeof(char));
    }

    for (int i = 0; i <= n; i++) {
        if (inWord(str[i]) != 0) {
            in_word = 1;
            printf("%c", str[i]);
        }
        else {
            if (in_word == 1) {
                word_count++;
                b = word_count;
                while (b != 0) {
                    printf("!");
                    b--;
                }
            in_word = 0;
            }

        }

    }
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

