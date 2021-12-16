#include <stdio.h>
#include <stdlib.h>

void printw(char* word) {
    for (int j = 0; word[j] != '\0'; j++) {
        printf("%c", word[j]);
    }
}

int len(char* word) {
    int len = 0;
    while (word[len] != '\0') {
        len++;
    }
    return len;
}

void* mem(int size) {
    void* temp = malloc(size);
    if (temp == NULL) {
        printf("No memory!!!");
        exit(1);
    }
    return temp;
}

void* resize(void* mem, int newSize) {
    void* temp = realloc(mem, newSize);
    if (temp == NULL) {
        printf("No memory!!!");
        free(mem);
        exit(1);
    }
    return temp;
}

int main() {

    char c = '\0';

    printf("Enter string:\n");

    int wordsSize = 20, wordsIndex = 0;
    char** words = (char**)mem(sizeof(char*) * wordsSize);

    int tempWordSize = 10, tempWordInd = 0;
    char* tempWord = (char*)mem(sizeof(char)*tempWordSize);

    while((c = getchar()) != '\0') {

        if (c == ' ' || c == '\n') {
            if (tempWordInd >= tempWordSize) {
                tempWord = (char*)resize(tempWord, tempWordSize+=1);
            }

            tempWord[tempWordInd++] = '\0';

            if (wordsIndex >= wordsSize) {
                words = (char**)resize(words, sizeof(char*) * (wordsSize*=2));
            }

            words[wordsIndex++] = tempWord;
            tempWord = (char*)mem(sizeof(char) * (tempWordSize=10));
            tempWordInd = 0;

            if (c == '\n') {
                break;//string end
            }

            continue; //skip
        }

        if (tempWordInd >= tempWordSize) {
            tempWord = (char*)resize(tempWord, tempWordSize *= 2);
        }

        tempWord[tempWordInd++] = c;

    }

    printf("Enter word:\n");

    int wordSize = 10, wordInd = 0;
    char* word = (char*)mem(sizeof(char) * wordSize);

    while ((c = getchar()) != '\n') {
        if (wordInd + 1 >= wordSize) {
            word = (char*)resize(word, wordSize *= 2);
        }
        word[wordInd++] = c;
    }

    if (wordInd + 1 >= wordSize) {
        word = (char*)resize(word, wordSize *= 2);
    }
    word[wordInd++] = '\0';

    wordSize = wordInd;

    int min = len(words[0]), ii = 0;

    for (int i = 0; i < wordsIndex; i++) {
        if (len(words[i]) < min) {
            min = len(words[i]);
            ii = i;
        }
    }

    for (int i = 0; i < wordsIndex; i++) {
        if (i == ii) {
            printf("%s", word);
            printf(" ");
            i++;
        }
        printw(words[i]);
        printf(" ");
    }

    return 0;
}