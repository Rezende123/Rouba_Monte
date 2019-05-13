#ifndef STACK_H   // guardas de cabeçalho, impedem inclusões cíclicas
#define STACK_H

typedef struct Stack
{
   int *array;
   int indexChangeArea;
   int sizeArray;
} tStack;

tStack *createStack();
void showStack(tStack *stack);
void initializeStack(tStack *stack, int sizeArray);
int addElement(tStack *stack, int value);
int removeElement(tStack *stack);

#endif