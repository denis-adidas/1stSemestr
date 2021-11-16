#include <stdio.h>
#include <stdlib.h>

void copy_word(char* dst, char* src, int start, int end) {
    int j = 0;
    int k = 0;
    for (j = start; j < end; j++) {
        dst[k] = src[j];
        k++;
    }
    dst[k] = 0;
}

int main() {
    int n, in_word, i, word_count;
    int start_w, end_w;

    printf("Enter symb count: ");
    scanf("%d", &n);

    char* str = (char*)malloc(sizeof(char) * n + 1);

    printf("Enter a string: ");
    for (int i = 0; i <= n; i++) {
        scanf("%c", &str[i], sizeof(char));
    }
    i = 0;
    while (str[i] != 0) {
        if (str[i] != ' ') {
            if (in_word == 0)
                start_w = i;
        in_word = 1;
        }
        else {
            if (in_word == 1) {
                end_w = i;
                word_count++;
                char* words = (char*)malloc(end_w - start_w + 2);
                copy_word(words[word_count], str, start_w, end_w);
            }
            in_word = 0;
        }
        i++;
    }
}
