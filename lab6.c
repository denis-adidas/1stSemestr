#include <stdio.h>
#include <stdlib.h>

/* 1. Обработка файла
 * 2. Считывание все в массивы
 * 3. Сортировка
 * 4. Записать все в структуры
 * 5. Объединить структуры
 */
int sLen(char* string){
    int g = 0;
    for (int i = 0; string[i] != '\0'; i++){
        g++;
    }
    return (g);
}

int m2Len(char** words) {
    int i = 0;
    while (words[i] != NULL) {
        i++;
    }
    return i;
}

void swap(char **s1, char **s2) {
    char * tmp = * s1 ;
    *s1 = *s2 ;
    *s2 = tmp ;
}

void sort(char **words) {
    int i = 0, j = 0, min_idx = 0;
    int n = m2Len(words);
    for (i = 0; i < n; i++) {
        min_idx = i;
        for (j = i; j < n; j++) {
            if (sLen(words[j]) < sLen(words[min_idx])) min_idx = j;
        }
        swap(&words[i], &words[min_idx]);
    }
}


void copy_word( char* dst , char* src , int start , int end) {
    int j = 0, k = 0;
    for ( j = start ; j < end ; j++) {
        dst[k] = src[j];
        k++;
    }
    dst[k] = 0;
}

void mas_words(char *s1, char **words) {
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


//Все, что связанно со списками
struct node_s;

typedef struct {
    struct node_s* next;
    struct node_s* prev;
    char* word;
} node_t;

typedef struct {
    node_t* head;
    node_t* tail;
    size_t size;
}list_t;

void init(list_t* l) {
    l->head = NULL;
    l->head = NULL;
    l->size = 0;
}
void destroy(list_t* l) {
    if (l->head != NULL) {
        node_t* cur = l->head;
        node_t* prev = NULL;
        while (cur != NULL) {
            prev = cur;
            cur = cur->next;
            free(prev);
        }
    }
    return;
}
void push_back(list_t* l, char* str) {
    node_t *n, *cur;
    n = (node_t*)malloc(sizeof(node_t));
    n->word = str; n->next = NULL;
    if (l->head == NULL) {
        n->prev = NULL;
        l->head = n;
    }
    else {
        cur = l->head;
        while (cur->next != NULL)
            cur = cur->next;
        cur->next = n;
        n->prev = cur;
    }
    l->size++;
}
void print(list_t* l) {
    node_t *cur = l->head ;
    while (cur != NULL ) {
        printf("%s ", cur->word);
        cur = cur->next;
    }
    printf("\n");
}
void union_l(list_t* l1, list_t* l4) {
    node_t* cur = l1->head;
    while (cur != NULL) {
        push_back(l4, cur->word);
        cur = cur->next;
    }
}


int main() {
    FILE *f1;
    f1 = fopen("/Users/denis_adidas/CLionProjects/untitled/file1.txt", "r");
    FILE *f2;
    f2 = fopen("/Users/denis_adidas/CLionProjects/untitled/file2.txt", "r");
    FILE *f3;
    f3 = fopen("/Users/denis_adidas/CLionProjects/untitled/file3.txt", "r");
    //Проверка на ошибку
    if (f1 == NULL) {
        printf("File 1 couldn't be opened!\n");
    }
    else {
        printf("File 1 was opened correctly \n");
    }
    if (f2 == NULL) {
        printf("File 2 couldn't be opened!\n");
    }
    else {
        printf("File 2 was opened correctly \n");
    }
    if (f3 == NULL) {
        printf("File 2 couldn't be opened!\n");
    }
    else {
        printf("File 3 was opened correctly \n");
    }
    int str_idx = 0, len_str = 20;
    //Подготовка к обработке
    char* str1 = (char*)malloc(sizeof(char) * len_str);
    char** words1 = (char**)malloc(sizeof(char**) * len_str);

    char* str2 = (char*)malloc(sizeof(char) * len_str);
    char** words2 = (char**)malloc(sizeof(char**) * len_str);

    char* str3 = (char*)malloc(sizeof(char) * len_str);
    char** words3 = (char**)malloc(sizeof(char**) * len_str);
    //Обработка данных из файла
    char c = ' ';
    while (((c = fgetc(f1)) != EOF)) {
        if (str_idx >= len_str) {
            str1 = realloc(str1, len_str *= 2);
        }
        str1[str_idx++] = c;
    }
    str_idx = 0;
    while (((c = fgetc(f2)) != EOF)) {
        if (str_idx >= len_str) {
            str2 = realloc(str2, len_str *= 2);
        }
        str2[str_idx++] = c;
    }
    str_idx = 0;
    while (((c = fgetc(f3)) != EOF)) {
        if (str_idx >= len_str) {
            str3 = realloc(str3, len_str *= 2);
        }
        str3[str_idx++] = c;
    }
//    printf("Test 1.1: %c \n", str2[10]);
//    printf("Test 1.2: %c \n", str3[10]);

    /* Разбиение на двумерный массив слов
     * и сортировка выбором */

    mas_words(str1, words1);
    mas_words(str2, words2);
    mas_words(str3, words3);
//    printf("Test 2: %s\n", words2[5]);

    sort(words1);
    sort(words2);
    sort(words3);
//    printf("Test 3: %s\n", words3[0]);

    int i = 0;
    list_t l1;   //Первый список
    init(&l1);
    int n = m2Len(words1);
    for (i = 0; i < n; i++) {
        push_back(&l1, words1[i]);
    } //Заполнили первый список словами
//    print(&l1);

    list_t l2; //Второй список
    init(&l2);
    n = m2Len(words2);
//    printf("Test 4: %d \n", n);
    for (i = 0; i < n; i++) {
        push_back(&l2, words2[i]);
    } //Заполнили второй список
//    print(&l2);

    list_t l3; //Третий список
    init(&l3);
    n = m2Len(words3);
    for (i = 0; i < n; i++) {
        push_back(&l3, words3[i]);
    } //Заполнили третий список
//    print(&l3);

    list_t l4;
    init(&l4);

    union_l(&l1, &l4);
    union_l(&l2, &l4);
    union_l(&l3, &l4);

    print(&l4);

    fclose(f1);
    fclose(f2);
    fclose(f3); //закрытие файлов

    destroy(&l1);
    destroy(&l2);
    destroy(&l3);
    destroy(&l4); //освобождение памяти от списков

    free(str1);
    free(str2);
    free(str3);
    free(words1);
    free(words2);
    free(words3); //освобождение памяти от маллоков
    return 1;
}