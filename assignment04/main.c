#include "stack.h"


#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4c)))

#define GPIO_BASE 0x48000000
#define GPIO_MODER (*((unsigned int*)(GPIO_BASE)))

#define GPIOA_ODR (*((unsigned int*)(GPIO_BASE + 0x14)))

#define ODR5 (1<<5)

void delay(int unit);
void func1(int a, int b, int c, int d, int e);
void func2();
void test1();
void test2();
void test3();

int main()
{
    //Create Stack
    //struct Stack* stack = createStack(4);
    test1();
    test2();
    test3();
    //Run function 2
    func2();
  
    //Enable the clock for PortA
   //RCC_AHB2ENR |= 0x1;
    //change bit 0 of RCC_AHB2ENR to 1
    *((unsigned int*)(0x42000000+(0x2104C *32) + (0*4))) = 0x1;
  
   //Setup the GPIO port to become an output
   GPIO_MODER |= (1 << 10); //set bit 10
   GPIO_MODER &= ~(1<<11); //reset bit 11
   
   while(1)
   {
      GPIOA_ODR ^= ODR5;          //toggle LED
      delay(200000);
   }
   
  return 0;
}

//test if stack ignores and indicates too many push commands
void test1()
{
    struct Stack* stack = setupStack(3);
    printf("Pushing 1 into stack. Error = %d\n", push(stack,1));
    printf("Pushing 2 into stack. Error = %d\n", push(stack,2));
    printf("Pushing 3 into stack. Error = %d\n", push(stack,3));
    printf("Pushing 4 into stack. Error = %d\n", push(stack,4));
    printf("Popping last value. Value should be 3. Value = %d\n", pop(stack));
}

//test pop if nothing in stack
void test2()
{
    struct Stack* stack = setupStack(3);
    printf("Pop with nothing in stack. Should be -1. Value = %d\n", pop(stack));
}

//test if push will store a float
//should change value to a int ie 14.3 -> 14
void test3()
{
  struct Stack* stack = setupStack(3);
  printf("Try to store a float 14.3 in stack\n", push(stack,14.3));
  printf("Popping last value. Value should be 14. Value = %d\n", pop(stack));
}



void func1(int a, int b, int c, int d, int e)
{
  
}

void func2()
{
    //func1(1,2,3,4,5);
}

void delay(int unit)
{
  for(int count = 0;count<unit;count++){}
}