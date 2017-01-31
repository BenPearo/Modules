/*********************************************************
Dalton Polhill     0930905
Stack ADT
June 2016
**********************************************************/
#ifndef _STACK_H
#define _STACK_H

#include <stdbool.h>

#include "list.h"

/*struct stackNode
{
    struct stackNode * next;
    void * data;
};
typedef struct stackNode Element;
*/
struct stack
{
    Node * top;
    List * theList;
    int size;
    int capacity;
    int (* destroy)(void *);
    void (* print)(void *);
};
typedef struct stack Stack;

/*
Stack * createStack(int (* destroy)(void *), void (* print)(Stack *), int capacity);
Input: (* destroy)(void *), (* print)(List *), int
Output: Stack * 
Preconditions: destroy and print functions are defined by the module using this adt
Postconditions: a stack is created and initialized to null and returned
*/
Stack * createStack(int (* destroy)(void *), void (* print)(void *), int capacity);

/*
int destroyStack(Stack *);
Input: Stack *
Output: 
Preconditions: an initialized stack is passed in
Postconditions: all data associated with the stack is freed 
                returns 0 on clean exit, 1 otherwise
*/
int destroyStack(Stack * theStack);

/*
Stack * push(Stack * theStack, Element * theElement);
Input: Stack *, Element *
Output: Stack *
Preconditions: an initialized stack is passed in, the Element * is not null
Postconditions: the element pointer is added to the top of the stack and the new stack is returned, 
                the top pointer is moved and size increased by one
*/
Stack * push(Stack * theStack, void * data);

/*
Element * pop(Stack * theStack);
Input: Stack *
Output: Element *
Preconditions: an initialized stack is passed in
Postconditions: the top element of the stack is removed, size is reduced by one and the top pointer is moved to the second element in the stack
                the top element is returned
*/
Node * pop(Stack * theStack); 

/*
Element * peek(Stack * theStack);
Input: Stack *
Output: Element *
Preconditions: an initialized stack is passed in
Postconditions: returned a pointer to the top element on the stack
*/
Node * peek(Stack * theStack);

/* 
bool isEmpty(Stack * theStack);
Input: Stack * 
Output: bool
Preconditions: an initialized stack is passed in 
Postconditions: returns true if theStack is empty
                returns false otherwise
*/
bool isEmpty(Stack * theStack);

/* 
bool isFull(Stack * theStack);
Input: Stack *
Output: bool
Preconditions: an initialized stack is passed in
Postconditions: returns true if the stack is full
                returns false otherwise
*/
bool isFull(Stack * theStack);

/*
int length(Stack * theStack);
Input: Stack *
Output: int
Preconditions: an initialized stack is passed in
Postconditions: the length of the stack list is returned
*/
int length(Stack * theStack);

#endif
