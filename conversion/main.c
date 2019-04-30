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



void conversion(int input, int radix, char * result) {
    int q = input;
    SqStack * sqStack = createSqStack();
    do {
        push(sqStack, q % radix);
        q = q / radix;
    } while (q);
    char * str = result;
    SElemType data;
    while (!isEmpty(sqStack)){
        pop(sqStack, &data);
        sprintf(str++, "%X", data);
    }
    destroySqStack(sqStack);
}

int main() {
    int input = 0;
    int radix = 0;
    char result[100] = {0};
    while (1) {
        printf("\nplease input a number(-1 exit):\n");
        scanf("%d", &input);
        if (input < 0)
            break;
        printf("please input radix(-1 exit):\n");
        scanf("%d", &radix);
        if (radix < 0)
            break;

        conversion(input, radix, result);
        printf("%d conversion to radix %d:\n%s\n", input, radix, result);
    }
    return 0;
}