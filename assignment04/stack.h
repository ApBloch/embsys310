#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>

struct Stack;
struct Stack* setupStack(int size);
int isFull(struct Stack* stack);
int isEmpty(struct Stack* stack);
int push(struct Stack* stack, int value);
int pop(struct Stack* stack);

#endif