#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define eleType int

struct SequencialList{
    eleType *elements;
    int size;
    int capacity;

    void initializeList(struct SequencialList *list, int capacity);
    void destroyList(struct SequencialList *list);
    int getsize(struct SequencialList *list);
    bool isEmepty(struct SequencialList *list);
    void insert(struct SequencialList *list, int index, int element);
};

void initializeList(struct SequencialList *list, int capacity)
{
    list->capacity = capacity;
    list->size = 0;
    list->elements = (eleType*)calloc(capacity, sizeof(eleType));
}

void destroyList(struct SequencialList *list)
{
    free(list->elements);
    list->elements = NULL;
}

int getsize(struct SequencialList *list)
{
    return list->size;
}

bool isEmepty(struct SequencialList *list)
{
    return list->size == 0;
}

void insert(struct SequencialList *list, int index, int element)
{
    if (index < 0 || index > list->size) {
        
    }
}

int main()
{   
    struct SequencialList mylist;
    initializeList(&mylist, 10);

    destroyList(&mylist);
    printf("666");
}