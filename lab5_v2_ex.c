#include <stdio.h>
#include <stdlib.h>

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
int my_strcmp (char* s1 , char* s2 ) {
    while ((*s1 != 0) && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}
void swap(char** s1, char** s2) {
    char* tmp = *s1;
    *s1 = *s2;
    *s2 = tmp;
}

int main() {
    int stridx = 0, lenstr = 20;
    char* str = (char*)malloc(sizeof(char) * lenstr);
    char** words = (char**)malloc(sizeof(char**) * lenstr);
    char* word = (char*)malloc(sizeof(char) * lenstr);
    char* word2 = (char*)malloc(sizeof(char) * lenstr);

    printf("Enter a string: ");
    char c = ' ';
    while ((c = getchar()) != '\n') {
        if (stridx >= lenstr) {
            str = realloc(str, lenstr *= 2);
        }
        str[stridx++] = c;
    }

    printf("Enter a word1: ");
    stridx = 0;
    c = ' ';
    while ((c = getchar()) != '\n') {
        if (stridx >= lenstr) {
            word = realloc(word, lenstr *= 2);
        }
        word[stridx++] = c;
    }
    printf("Enter a word2: ");
    stridx = 0;
    c = ' ';
    while ((c = getchar()) != '\n') {
        if (stridx >= lenstr) {
            word2 = realloc(word2, lenstr *= 2);
        }
        word2[stridx++] = c;
    }
    //Ввод окончен


    mas2(str, words);

    int words_count = 0;
    while (words[words_count] != NULL) {
        words_count++;
    }

    for (int i = 0; i < words_count; i++) {
       if (my_strcmp(words[i], word) == 0)
       {
           words[i] = word2;
       }
    }

    for (int i = 0; i < words_count; i++) {
        printf("%s", words[i]);
        printf(" ");
    }

}