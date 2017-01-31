/*******************************************************
Dalton Polhill          0930905
Linked List ADT 
June 2016
********************************************************/
#include <stdlib.h>

#include "stack.h"

Stack * createStack(int (* destroy)(void *), void (* print)(void *), int capacity)
{
    //VAR declaration
    Stack * theStack;
    theStack = malloc(sizeof(Stack));
    if (theStack == NULL)
    {
        return NULL; //malloc failed
    }
    //VAR INIT
    theStack->theList = createList(destroy, print, capacity);
    theStack->top = NULL;
    theStack->size = 0;
    theStack->capacity = capacity;
    theStack->destroy = (*destroy);
    theStack->print = (*print);    

    return theStack;
}

int destroyStack(Stack * theStack)
{
    if(theStack == NULL)
    {
        return 0; //nothing to free stack is empty
    }
    //VAR DECLARATION
    int listFlag;

    //VAR INIT
    listFlag = destroyList(theStack->theList); //destroy the list first
    if (listFlag != 1) //the list was freed successfully
    {
        free(theStack);
        return 0; //success
    }
    else
    {
        free(theStack);
        return 1; //failure
    }
}

Stack * push(Stack * theStack, void * data)
{   
    if (theStack == NULL || data == NULL || theStack->capacity == 0)
    {
        return NULL;
    }
    else if (theStack->size >= theStack->capacity)
    {
        return theStack; //return an unchanged list because its full
    }
    else //the size is less than the capacity
    {
        //add element to the top of the list
        theStack->theList = insertFront(theStack->theList, data);
        theStack->size++; //increase the size pointer
        theStack->top = theStack->theList->head; //move top pointer
        return theStack;
    }
    return theStack;
}

Node * pop(Stack * theStack)
{
    if (theStack == NULL || theStack->size == 0)
    {
        return NULL;
    }
    else if (theStack->size == 1)
    {
        Node * popped;
        popped = theStack->theList->head;
        theStack->theList->head = NULL;
        theStack->top = NULL; //move the top pointer to the next node
        theStack->size--;
        theStack->theList->size--;
        return popped;
    }
    else 
    {
        Node * popped;
        popped = theStack->theList->head;
        theStack->theList = removeHead(theStack->theList); //remove the head, return that node
        theStack->top = theStack->theList->head; //move the top pointer to the next node
        theStack->size--;
        return popped;
    }
}

Node * peek(Stack * theStack)
{
    if (theStack == NULL || theStack->size == 0 || theStack->theList->head)
    {
        return NULL;
    }
    else 
    {
        return theStack->theList->head;        
    }
}

bool isEmpty(Stack * theStack)
{
    if (theStack == NULL)
    {
        return NULL;
    }
    else if (theStack->size == 0)//the stack is initialized but the list is empty
    {
        return true; //the stack is empty
    }
    else
    {
        return false;
    }
}

bool isFull(Stack * theStack)
{
    if (theStack == NULL)
    {
        return NULL;
    }
    else if (theStack->size == theStack->capacity)//the stack is the same size as the max size
    {
        return true; //the stack is full 
    }
    else
    {
        return false;
    }
}

int length(Stack * theStack)
{
    if (theStack == NULL)
    {
        return 0;//there is no stack therefore the list is 0 elements long
    }
    else
    {
        return theStack->size;
    }
}



