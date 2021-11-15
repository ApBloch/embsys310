#includue "stack.h"

/*
Design Criteria:
  i. The stack should have a predefined size 
  ii. The stack supports “int” data types. 
  iii. Provide a function to initialize the stack internals. 
  iv. Provide a function to push an element onto the stack 
  v. Provide a function to pop an element off the stack. 
  vi. Provide a function that returns 1 if stack is empty. 
  vii. Provide a function that returns 1 if stack is full. 
  viii. Return (-1) for error conditions 
*/

struct Stack{
    int size;
    int* array;
    int counter;
};

struct Stack* setupStack(int size)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->size = size;
    stack->array = (int*)malloc(stack->size * sizeof(int));
    stack->counter = -1;
    return stack;
}

//if the counter is equal to the size of the array then return 1 else 0
int isFull(struct Stack* stack)
{
    if((stack->size-1) == stack->counter)
    {
        return 1;
    }
    return 0;
}

//if counter value is -1 then its empty return 1 return 0 not empty
int isEmpty(struct Stack* stack)
{
    return stack->counter == -1;
}

int push(struct Stack* stack, int value)
{
    if(isFull(stack))
        return -1;
    stack->counter++;
    stack->array[stack->counter] = value;
    return 0;
}

int pop(struct Stack* stack)
{
    if(isEmpty(stack))
        return -1;
    int value = stack->array[stack->counter];
    stack->counter--;
    return value;
}


