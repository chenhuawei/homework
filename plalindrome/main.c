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


int isPalindromic(char * input) {
    SqStack * sqStack = createSqStack();
    char * pos = input;
    while (*pos) {
        push(sqStack, *pos ++);
    }
    char data;
    while (*input) {
        pop(sqStack, &data);
        if (*input++ != data) {
            destroySqStack(sqStack);
            return 0;
        }
    }
    destroySqStack(sqStack);
    return 1;
}


int main() {

    char input[100] = {0};
    while (1) {
        printf("\nplease input a string:\n");
        scanf("%s", input);
        if (strlen(input) == 0)
            break;

        if (strcmp("exit", input) == 0) {
            break;
        }
        if (isPalindromic(input)) {
            printf("Right\n");

        } else {
            printf("Wrong\n");

        }
    }
    return 0;
}