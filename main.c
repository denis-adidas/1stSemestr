#include <stdio.h>

int isWord(char ch){
    return ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z';
}

int isSogl(char sym) {
    char alph[] = "AaEeIiOoUuYy";
    int k = 0; int j = 0;
    while (alph[k] != '\0') {
        if (sym != alph[k]) {
            j++;
        }
        else {
            j = 0;
            break;
        }
        k++;
    }
    if (j > 0) {
        return 1;
    }
    else {
        return 0;
    }
}

/* int isSogl(char symbol) {
    if ((symbol != 'A') || (symbol != 'a') || (symbol != 'E') || (symbol != 'e') || (symbol != 'I') || (symbol != 'i') || (symbol != 'O') || (symbol != 'o') || (symbol != 'u') || (symbol != 'U') || (symbol != 'Y') || (symbol != 'y') ) {
        return 1;
    }
    else {
        return 0;
    }
}
*/

int main() {
    char s[] = "eeeeee afdsksja sdfjs aaaaaa bbbbbb";
    int i = 0; int begin = 0;
    int end = 0;
    while (s[i] != '\0') {
        if (isWord(s[i])) {
            begin = i;
            end = 0;

            while (isWord(s[i])) {
                i++;
            }
            end = i - 1;

            if (isSogl(s[end])) {
                while (begin <= end) {
                    printf("%c", s[begin]);
                    begin++;
                }
            }
            printf(" ");

        }
        else ++i;
    }
    return 0;
}
