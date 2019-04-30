#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAXSTACK 100
typedef int SElemType;

typedef struct{
    SElemType Data[MAXSTACK];
    int top;
} SqStack;

SqStack * createSqStack() {
    SqStack * sqStack = malloc(sizeof(SqStack));
    memset(sqStack, 0, sizeof(SqStack));

    return sqStack;
}

void destroySqStack(SqStack * sqStack) {
    free(sqStack);
}

int isFull(SqStack * sqStack) {
    return sqStack->top == MAXSTACK - 1;
}

int isEmpty(SqStack * sqStack) {
    return sqStack->top == 0;
}

int pop(SqStack * sqStack, SElemType * data) {
    if (isEmpty(sqStack))
        return -1;
    sqStack->top --;
    *data = sqStack->Data[sqStack->top];
    return 0;
}

int push(SqStack * sqStack, SElemType data) {
    if (isFull(sqStack))
        return -1;
    sqStack->Data[sqStack->top] = data;
    sqStack->top ++;
    return 0;
}

int main() {
    SqStack * sqStack = createSqStack();
    printf("push 10 items:\n");

    for (int i = 1; i <= 10; i ++) {
        push(sqStack, i);
        printf("\tpush %2d\n",i);

    }
    printf("pop 10 items:\n");

    SElemType data;
    for (int i = 1; i <= 10; i ++) {
        pop(sqStack, &data);
        printf("\tpop %2d. %2d\n", i, data);
    }
    destroySqStack(sqStack);
}