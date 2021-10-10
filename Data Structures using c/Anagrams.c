#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct name{
    char* str;
    int i;
};
struct temp {
    struct name* array;
    int size;
};

struct temp* createTempArray(char* str[], int size)
{
    struct temp* temp = (struct temp*)malloc(sizeof(struct temp));
    temp->size = size;
    temp->array = (struct name*)malloc(temp->size * sizeof(struct name));
    int i;
    for (i = 0; i < size; ++i) {
        temp->array[i].i = i;
        temp->array[i].str = (char*)malloc(strlen(str[i]) + 1);
        strcpy(temp->array[i].str, str[i]);
    }
    return temp;
}
int strmatch(const void* a, const void* b)
{
    struct name* a1 = (struct name*)a;
    struct name* b1 = (struct name*)b;
    return strcmp(a1->str, b1->str);
}
int compare(const void* a, const void* b)
{
    return *(char*)a-*(char*)b;
}
void Display(char* str[], int size)
{
    struct temp* temp = createTempArray(str, size);
    int i;
    for (i = 0; i < size; ++i)
        qsort(temp->array[i].str,strlen(temp->array[i].str), sizeof(char), compare);
    qsort(temp->array, size, sizeof(temp->array[0]), strmatch);
    for (i = 0; i < size; ++i)
        printf("%s ", str[temp->array[i].i]);
}

int main()
{
    char* str[] = { "cat", "dog", "tac", "god", "act" };
    int size = sizeof(str) / sizeof(str[0]);
    Display(str,size);
    return 0;
}
