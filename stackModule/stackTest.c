/*******************************************************
Dalton Polhill          0930905
Linked List ADT 
June 2016
********************************************************/
#include "stack.h"

#include <stdio.h>

#define CAPACITY 10 

int destroy(void * data);
void printList(void * theList);

int main (void)
{
    //VAR DECL
    FILE * file;
    Stack * theStack;
    int capacity;
    int size;
    int flag;

    //VAR INIT
    file = fopen("testOutput.txt", "w");
    capacity = CAPACITY;

    //TESTING_CREATESTACK
    fprintf(file, "testing createStack()\n");
    theStack = createStack(&destroy, &printList, capacity);
    if (theStack == NULL)
    {
        fprintf(file, "->theList was returned NULL, the malloc failed\n");
    }
    else
    {
        fprintf(file, "theStack->capacity == %d\n", theStack->capacity);
    }

    //TESTING_PUSH()
    fprintf(file, "\nTesting Push()\n");
    int data = 10;
    theStack = push(theStack, (void*) &data);

    if (theStack != NULL)
    {
        size = getSize(theStack->theList);
        fprintf(file, "inserting %d\nsize of list = %d\n", data, size); 
        fprintf(file, "head : %p <-\ntop :  %p <- these two address must be the same \n", (void*)theStack->theList->head, (void *)theStack->top);
    }
    int dataTwo = 6;
    theStack = push(theStack, (void*) &dataTwo);
    if (theStack != NULL)
    {
        size = getSize(theStack->theList);
        fprintf(file, "inserting %d\nsize of list = %d\n", dataTwo, size); 
        fprintf(file, "head : %p <-\ntop :  %p <- these two address must be the same \n", (void*)theStack->theList->head, (void *)theStack->top);
    }
    int dataThree = 16;
    theStack = push(theStack, (void*) &dataThree);
    if (theStack != NULL)
    {
        size = getSize(theStack->theList);
        fprintf(file, "inserting %d\nsize of list = %d\n", dataThree, size); 
        fprintf(file, "head : %p <-\ntop :  %p <- these two address must be the same \n", (void*)theStack->theList->head, (void *)theStack->top);
    }
    int dataFour = 32;
    theStack = push(theStack, (void*) &dataFour);
    if (theStack != NULL)
    {
        size = getSize(theStack->theList);
        fprintf(file, "inserting %d\nsize of list = %d\n", dataFour, size); 
        fprintf(file, "head : %p <-\ntop :  %p <- these two address must be the same \n", (void*)theStack->theList->head, (void *)theStack->top);
    }
    fprintf(file, "stack->size = %d\n", theStack->size);
    printList(theStack->theList);

    //TESTING_POP()
    fprintf(file, "\nTesting Pop()\n");
    Node * popped = NULL;
    popped = pop(theStack);
    if (popped != NULL)
    {
        fprintf(file, "popped data = %d\n", *(int *)popped->data);
        if (theStack->theList->head != NULL)
        {
            fprintf(file, "newHead->data = %d\n", *(int *)theStack->theList->head->data);
            fprintf(file, "head : %p <-\ntop :  %p <- these two address must be the same \n", (void*)theStack->theList->head, (void *)theStack->top);
        }
    }
    Node * poppedTwo = NULL;
    poppedTwo = pop(theStack);
    if (poppedTwo != NULL)
    {
        fprintf(file, "poppedTwo data = %d\n", *(int *)poppedTwo->data);
        if (theStack->theList->head != NULL)
        {
            fprintf(file, "newHead->data = %d\n", *(int *)theStack->theList->head->data);
            fprintf(file, "head : %p <-\ntop :  %p <- these two address must be the same \n", (void*)theStack->theList->head, (void *)theStack->top);
        }
    }
    Node * poppedThree = NULL;
    poppedThree = pop(theStack);
    if (poppedThree != NULL)
    {
        fprintf(file, "poppedThree data = %d\n", *(int *)poppedThree->data);
        if (theStack->theList->head != NULL)
        {
            fprintf(file, "newHead->data = %d\n", *(int *)theStack->theList->head->data);
            fprintf(file, "head : %p <-\ntop :  %p <- these two address must be the same \n", (void*)theStack->theList->head, (void *)theStack->top);
        }
    }
    fprintf(file, "stack->size = %d\n", theStack->size);
    printList(theStack->theList);

    //TESTING_PEEK()
    fprintf(file, "\nTesting Peek()\n");
    Node * peeked = NULL;
    peeked = peek(theStack);
    if (peeked != NULL)
    {
        fprintf(file, "peeked should be: %d\nactual: peeked->data = %d\n",*(int *)theStack->theList->head->data, *(int *)peeked->data);
    }
    else
    {
        fprintf(file, "an empty list was peeked at\n");
    }

    //TESTING_ISEMPTY()
    fprintf(file, "\nTesting isEmpty()\n");
    bool ans;
    ans = isEmpty(theStack);
    if (ans == true)
    {
        fprintf(file, "ans = true\n");
    }
    if (ans == false)
    {
        fprintf(file, "ans = false\n");
    }

    //TESTING_ISFULL()
    fprintf(file, "\nTesting isFull()\n");
    bool ansTwo;
    ansTwo = isFull(theStack);
    if (ansTwo == true)
    {
        fprintf(file, "ans = true\n");
    }
    if (ansTwo == false)
    {
        fprintf(file, "ans = false\n");
    }
    
    //TESTING_LENGTH()
    fprintf(file, "\nTesting length()\n");
    int theLength = 0;
    theLength = length(theStack);
    fprintf(file, "theLength = %d\n", theLength);

    //TESTING_DESTROYSTACK()
    fprintf(file, "\nTesting destroyStack()\n");
    flag = destroyStack(theStack);
    fprintf(file, "the destroyFlag = %d  (0 is success)\n", flag);

    fclose(file);
    return 0;
}

//returns 0 on success, 1 on failure
int destroy(void * data)
{
    //there is nothing to free because the data was never malloced for therefore, simply return 0 (success code)
    return 0; //success
}

void printList(void * theList)
{
    if (theList == NULL)
    {
        return;
    }
    List * list;
    list = (List *)theList;

    Node * temp;
    temp = list->head;
 
    //loop through until reach the tail
    printf("\nTHE_LIST\n");
    printf("list->size = %d\n", list->size);
    printf("list->capacity = %d\n\n", list->capacity);
    if (list->size == 0)
    {
        printf("No list (list->size = 0)\n");
    }
    else if (list->size == 1)
    {
        printf("Head->data: %d\n", *(int *)temp->data);
        return;
    }
    else    
    {
        printf("Head->data: %d\n", *(int *)temp->data);
        temp = temp->next;
        while (temp->next != NULL)
        {
            printf("Node->data: %d\n", *(int *)temp->data);
            temp = temp->next;
        }
        printf("Tail->data: %d\n", *(int *)temp->data); //print the tail
        printf("\n");
        return;
    }
}

