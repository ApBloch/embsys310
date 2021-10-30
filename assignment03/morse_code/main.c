#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4c)))

#define GPIO_BASE 0x48000000
#define GPIO_MODER (*((unsigned int*)(GPIO_BASE)))

#define GPIOA_ODR (*((unsigned int*)(GPIO_BASE + 0x14)))

#define ODR5 (1<<5)

#define DOT 400000

#define DASH (DOT*3)

void delay(int unit);
void morseA();
void morseR();
void morseO();
void morseN();

int main()
{
  
    //Enable the clock for PortA
   RCC_AHB2ENR |= 0x1;
  
   //Setup the GPIO port to become an output
   GPIO_MODER |= (1 << 10); //set bit 10
   GPIO_MODER &= ~(1<<11); //reset bit 11
   
   morseA();
   morseA();
   morseR();
   morseO();
   morseN();
   
  return 0;
}

void delay(int unit)
{
  for(int count = 0;count<unit;count++){}
}       

void morseA()
{
    GPIOA_ODR |= ODR5;          //set ODR5 first
    delay(DOT);                 //DOT
    GPIOA_ODR ^= ODR5;          //turn off LED
    delay(DOT);
    
    GPIOA_ODR ^= ODR5;          //turn on LED
    delay(DASH);                //DASH
    GPIOA_ODR ^= ODR5;          //turn off LED
    
    delay(DASH);  
}
void morseR()
{
    GPIOA_ODR |= ODR5;          //set ODR5 first
    delay(DOT);                 //DOT
    GPIOA_ODR ^= ODR5;          //turn off LED
    delay(DOT);
    
    GPIOA_ODR ^= ODR5;           //turn on LED
    delay(DASH);                  //DASH
    GPIOA_ODR ^= ODR5;           //turn off LED
    delay(DOT);
    
    GPIOA_ODR ^= ODR5;           //turn on LED
    delay(DOT);                 //DOT
    GPIOA_ODR ^= ODR5;           //turn off LED
    
    delay(DASH);
}

void morseO()
{
    GPIOA_ODR |= ODR5;          //set ODR5 first
    delay(DASH);                //DASH
    GPIOA_ODR ^= ODR5;          //turn off LED
    delay(DOT);
    
    GPIOA_ODR ^= ODR5;          //turn on LED
    delay(DASH);                //DASH
    GPIOA_ODR ^= ODR5;          //turn off LED
    delay(DOT);
    
    GPIOA_ODR ^= ODR5;          //turn on LED
    delay(DASH);                //DASH
    GPIOA_ODR ^= ODR5;          //turn off LED
    
    delay(DASH);
}      

void morseN()
{
    GPIOA_ODR |= ODR5;          //set ODR5 first
    delay(DASH);                //DASH
    GPIOA_ODR ^= ODR5;          //turn off LED
    delay(DOT);
    
    GPIOA_ODR ^= ODR5;           //turn on LED
    delay(DOT);                  //DOT
    GPIOA_ODR ^= ODR5;           //turn off LED
    
    delay(DASH);
    
    
}