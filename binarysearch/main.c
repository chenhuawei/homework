#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


int binarySearch(int array[], int len, int target, int * counter) {
    int low = 0;
    int high = len - 1;
    *counter = 0;
    while (low <= high) {
        int middle = (low + high) / 2;
        int value = array[middle];
        if (value < target) {
            low = middle + 1;
        } else if (value > target) {
            high = middle - 1;
        } else {
            return middle;
        }
        (*counter) ++;
    }
    return -1;
}

int main() {
    int len;
    int target;
    int * array;
    int index;
    int counter;
    while (1) {
        printf("\nplease input length of array:\n");
        scanf("%d", &len);
        if (len <= 0)
            break;



        printf("\nplease input target:\n");
        scanf("%d", &target);
        if (target <= 0)
            break;

        array = malloc(sizeof(int) * len);
        for (int i = 0; i < len; i ++) {
            array[i] = i + 1;
        }

        index = binarySearch(array, len, target, &counter);
        if (index < 0) {
            printf("not found, cost %d times\n", counter);
        } else {
            printf("found target value %d, the index is %d, cost %d times\n", array[index], index, counter);
        }

        free(array);

    }
    return 0;
}