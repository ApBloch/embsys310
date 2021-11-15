#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4c)))

#define GPIO_BASE 0x48000000
#define GPIO_MODER (*((unsigned int*)(GPIO_BASE)))

#define GPIOA_ODR (*((unsigned int*)(GPIO_BASE + 0x14)))

#define ODR5 (1<<5)

void delay(int unit);
void func1(int a, int b, int c, int d, int e);
void func2();

int main()
{
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