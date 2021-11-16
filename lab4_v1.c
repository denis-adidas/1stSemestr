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
    int n = 0;
    int in_word = 0, i = 0, word_count = 0;
    int start_w, end_w, N;

    printf("Enter count of words: ");
    scanf("%d", &N);

    printf("Enter symb count: ");
    scanf("%d", &n);

    char* str = (char*)malloc(sizeof(char) * n + 1);

    printf("Enter string: ");
    for (int i = 0; i <= n; i++) {
        scanf("%c", &str[i], sizeof(char));
    }


    char** words = (char**)malloc(N * sizeof(char*));
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
                char* words = (char*)malloc(end_w - start_w + 1);
                copy_word(words[word_count], str, start_w, end_w);
                word_count++;
            }
            in_word = 0;
        }
        i++;
    }
if (in_word == 1) {
    end_w = i;
    char *words = (char *) malloc(end_w - start_w + 1);
    copy_word(words[word_count], str, start_w, end_w);
    word_count++;
    }
printf("%c", str[1]);
}
