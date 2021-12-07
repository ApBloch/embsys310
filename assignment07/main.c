
#include "stm32l475xx.h"


#define SYS_CLOCK_HZ 4000u   // Value for 1ms cycles
                                // Section 3.11 in STM32L475 datasheet DS10969

uint32_t g_delay = 0;           //my global delay value

void SysTick_Initialize(void);
void delay(unsigned int iteration);

int main()
{
  
  RCC->AHB2ENR |= 0x01;                 //enable Port A clock
  
  //Setup the GPIO port to become an output
  GPIOA->MODER |= GPIO_MODER_MODE5_0;     //set bit 0      
  GPIOA->MODER &= ~GPIO_MODER_MODE5_1;    //reset bit 1 
  
  SysTick_Initialize();
  
  while(1)   
  {
    
    GPIOA->ODR ^= GPIO_ODR_OD5;         //toggle pin5 
    delay(500);
  }
  
  return 0;
} 


void delay(uint32_t iteration)
{
    g_delay = iteration;
    while(g_delay > 0)
    {//decrease g_delay in sysTick
    }
}

void SysTick_Initialize(void)
{
    SysTick->LOAD = SYS_CLOCK_HZ - 1;       // 0xE000E014 - Counts down to 0.
    SysTick->VAL = 0x0;                     // 0xE000E018 - Clears initial value
    SysTick->CTRL = 0x7;                    // 0xE000E010 - Enable interrupts
}

void SysTick_Handler(void)
{
    g_delay--;
}


