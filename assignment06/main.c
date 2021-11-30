
#include "stm32l475xx.h"

void delay(int unit);


int main()
{
  
  RCC->AHB2ENR |= 0x01;                 //enable Port A clock
  
  //Setup the GPIO port to become an output
  GPIOA->MODER |= GPIO_MODER_MODE5_0;     //set bit 0      
  GPIOA->MODER &= ~GPIO_MODER_MODE5_1;    //reset bit 1 
  
  while(1)   
  {
    
    GPIOA->ODR ^= GPIO_ODR_OD5;         //toggle pin5 
    delay(500000);
    
  }
  
  return 0;
}


void delay(int unit)
{
  while(unit > 1)
  {
    unit--;
  }
}