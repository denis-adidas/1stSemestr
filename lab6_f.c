#include <stdio.h>
#include <stdlib.h>

int isSymb(char ch)
{
    return ((('a' <= ch) && (ch <= 'z')) || (('A' <= ch) && (ch <= 'Z')));
}
int sLen(char* string){
    int g = 0;
    for (int i = 0; string[i] != '\0'; i++){
        g++;
    }
    return (g);
}
void copy_word( char* dst , char* src , int start , int end) {
    int j = 0, k = 0;
    for ( j = start ; j < end ; j++) {
        dst[k] = src[j];
        k++;
    }
    dst[k] = 0;
}
void mas2(char *s1, char **words) {
    int i = 0, in_word = 0;
    int start_w = 0, end_w = 0;
    int word_count = 0;
    while (s1[i] != 0) {
        if (s1[i] != ' ') {
            if (in_word == 0) start_w = i;
            in_word = 1;
        }
        else {
            if (in_word == 1) {
                end_w = i;
                words[word_count] = (char*)malloc(end_w - start_w + 2);
                copy_word(words[word_count], s1, start_w, end_w);
                word_count++;
            }
            in_word = 0;
        }
        i++;
    }
    if (in_word == 1) {
        end_w = i;
        words[word_count] = (char*)malloc(end_w - start_w + 2);
        copy_word(words[word_count], s1, start_w, end_w);
        word_count++;
    }
}
void swap(char** s1, char** s2) {
    char* tmp = *s1;
    *s1 = *s2;
    *s2 = tmp;
}
void sort(char **words) {
    int min_idx = 0, i = 0, j = 0;
    for (i = 0; i <= sLen(words); i++) {
        min_idx = i;
        for (j = i; j <= sLen(words); j++) {
            if (sLen(words[j]) <= sLen(words[min_idx])) {
                min_idx = j;
            }
            swap(&words[i], &words[min_idx]);
        }
    }
}

int main() {
    char f_src[] = "/Users/denis_adidas/CLionProjects/lab6_v2/in1.txt"; //44
    char s1[100];
    char* words[100];
    int i = 0, in_word = 0, word_count = 0;
    int start_w = 0, end_w = 0;
    FILE *fin;
    fin = fopen(f_src, "r");
    if (NULL != fgets(s1, 100, fin)) {
        printf("File #1 has been open correctly \n");
    }
    mas2(s1, &words);
    sort(&words);
    printf("Test1: %s\n", words[0]);
};