#include <stdio.h>
#include <stdlib.h>

//Ввести строку и слово. Вставить введенное
//слово вместо самого короткого слова в строке.

int isSymb(char ch) {
    return ((('a' <= ch) && (ch <= 'z')) || (('A' <= ch) && (ch <= 'Z')));
}
int w_Len(char* string) {
    int g = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        g++;
    }
    return g;
}
int min_word_index(char* s) {
    int len, mlen, g = 0, id = 0;

    for (int i = 0; s[i] != '\0' && s[i] != '\n'; i++) {
        g++;
    }
    for (int i = 0; i <= g; i++) {
        if (isSymb(s[i])) {
            len++;
        }
        else {
            if (mlen == 0) {
                mlen = len;
            }
            else if (len <= mlen) {
                mlen = len;
                id = i;
            }
        }
        if (!isSymb(s[i])) {
            len = 0;
        }
    }
    if (id == 0) {
        id = mlen;
    }
    return (id, mlen);
}

int main() {
    int lenStr = 20, stridx = 0;

    char* str = (char*) malloc(sizeof(char) * lenStr);
    char* word =(char*) malloc(sizeof(char) * lenStr);

    printf("Enter a string: ");
    char c = ' ';
    while (c != '\n') {
        c =  getchar();
        if (stridx >= lenStr) {
            str = realloc(str, lenStr *= 2);
        }
        str[stridx++] = c;
    }

    printf("Enter a word: ");
    stridx = 0;
     c = ' ';
    while (c != '\n') {
        c =  getchar();
        if (stridx >= lenStr) {
            str = realloc(str, lenStr *= 2);
        }
        word[stridx++] = c;
    }

    int idx = min_word_index(str);
    printf("idx: %d \n", idx);

    int wlen = w_Len(word);
    int slen = w_Len(str);
    printf("slen: %d \n", slen);
    printf("wordlen: %d \n", wlen);

    for (int i = 0; i <= (idx - wlen - 1) && str[i] != '\n'; i++) {
        printf("%c", str[i]);
    }
    printf(" ");
    for (int k = 0; k <= wlen && word[k] != '\n'; k++){
        printf("%c", word[k]);
    }
    for (int j = idx; j <= slen && str[j] != '\n'; j++) {
        printf("%c", str[j]);
    }
}
