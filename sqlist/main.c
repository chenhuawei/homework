#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assert.h"
typedef int ElemType;

typedef struct {
    ElemType *elem; //存储空间基址
    int length; //当前长度
    int maxLength;
} SqList;


void initSqList(SqList *list, int maxLength) {
    list->elem = malloc(sizeof(ElemType) * maxLength);
    list->length = 0;
    list->maxLength = maxLength;
}

ElemType * addItem(SqList *list, ElemType *ptr) {
    if (list->length >= list->maxLength) {
        return NULL;
    }
    memcpy(list->elem + list->length * sizeof(ElemType), ptr, sizeof(ElemType));
    list->length ++;
}

int removeItem(SqList * list, ElemType * ptr) {
    int offset = ptr - list->elem;
    int end = list->length * sizeof(ElemType);
    if (offset < 0 || offset > end) {
        return -1;
    }
    while (ptr < list->elem + end) {
        memmove(ptr, ptr + sizeof(ElemType), sizeof(ElemType));
        ptr += sizeof(ElemType);
    }
    list->length --;
    return 0;
}

ElemType * getItem(SqList *list, int index) {
    if (index >= list->length) {
        return NULL;
    }
    return list->elem + index * sizeof(ElemType);
}

void destroySqList(SqList *list) {
    list->maxLength = 0;
    list->length = 0;
    free(list->elem);
}

void printAllItems(SqList *list) {
    for (int i = 0; i < list->length; i ++) {
        ElemType * item = getItem(list, i);
        printf("\tindex %d value %d\n", i, *item);
    }
}


int main() {
    SqList sqList;
    SqList * sqListPtr = &sqList;
    ElemType * item;
    ElemType data;
    int max = 13;
    int index;

    initSqList(sqListPtr, max);

    printf("add %d items\n", max);
    for (int i = 1; i <= max; i ++) {
        addItem(sqListPtr, &i);
    }
    printAllItems(sqListPtr);

    item = getItem(sqListPtr, max - 1);
    assert(*item == max);
    // test overflow
    item = addItem(sqListPtr, &data);
    assert(item == NULL);

    // test remove first
    printf("test remove first item\n");
    item = getItem(sqListPtr, 0);
    assert(*item == 1);
    removeItem(sqListPtr, item);
    assert(sqListPtr->length == max - 1);
    item = getItem(sqListPtr, 0);
    assert(*item == 2);
    printAllItems(sqListPtr);

    // test remove last
    index = sqList.length - 1;
    printf("test remove last item, index = %d\n", index);
    item = getItem(sqListPtr, index);
    assert(*item == max);
    removeItem(sqListPtr, item);
    item = getItem(sqListPtr, index);
    assert(item == NULL);
    assert(sqListPtr->length == max - 2);
    item = getItem(sqListPtr, sqList.length - 1);
    assert(*item == max - 1);
    printAllItems(sqListPtr);

    // test remove middle
    index = sqList.length/2;
    printf("test remove middle item, index =  %d\n", index);
    item = getItem(sqListPtr, index);
    assert(*item == index + 2);
    removeItem(sqListPtr, item);
    item = getItem(sqListPtr, index);
    assert(*item == index + 3);
    assert(sqListPtr->length == max - 3);
    printAllItems(sqListPtr);

    destroySqList(sqListPtr);
    return 0;
}