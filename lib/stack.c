#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// FELIPE REZENDE

tStack *createStack() {
    tStack *stack;
    stack->array = NULL;
    stack->indexChangeArea = -1;
    stack->sizeArray = 0;

    printf("[CREATE] \n");
    return stack;
}

void showStack(tStack *stack) {
    int i = 0;
    printf("\n------------------\n");
    while (i < stack->sizeArray && i != stack->indexChangeArea)
    {
        printf("[VALUE] - %d\n", stack->array[i]);
        i++;
    }
    printf("------------------\n");
}


void initializeStack(tStack *stack, int sizeArray) {
    stack->sizeArray = 5;
    stack->indexChangeArea = 0;
    stack->array = malloc(sizeof(int) * sizeArray);
}

int addElement(tStack *stack, int value){
    if (stack == NULL) return 0;
    
    if (stack->indexChangeArea < stack->sizeArray) {
        stack->array[stack->indexChangeArea] = value;
        stack->indexChangeArea++;

        return 1;
    }

    return 0;
}

int removeElement(tStack *stack){
    if (stack == NULL) return 0;

    if (stack->indexChangeArea >= 0) {
        stack->indexChangeArea--;
        return 1;
    }

    return 0;
}
