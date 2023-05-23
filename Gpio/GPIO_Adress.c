/**
 * GPIO_Adress.c
 *
 *  Created on: Tue Apr 11 2023
 *  Author    : Saad Mustafa
 */

#include "GPIO_Address.h"

#include "Gpio_Private.h"
#include "Utils.h"

void Gpio_ConfigPin(uint8 PortName, uint8 PinNum, uint8 PinMode,uint8 DefaultState) {
  switch (PortName) {
    case GPIO_A:
      
      GPIOA_MODER &= ~(0x03 << (PinNum * 2));
      GPIOA_MODER |= (PinMode << (PinNum * 2));
      if (PinMode){
        GPIOA_OTYPER &= ~(0x01 << PinNum);
        GPIOA_OTYPER |= (DefaultState << PinNum);
      }
      else {
        GPIOA_PUPDR &= ~(0x03 << PinNum * 2);
        GPIOA_PUPDR |= (DefaultState << PinNum * 2);
      }
      break;

    case GPIO_B:
      GPIOB_MODER &= ~(0x03 << (PinNum * 2));
      GPIOB_MODER |= (PinMode << (PinNum * 2));

      if (PinMode)
      {
        GPIOB_OTYPER &= ~(0x01 << PinNum);
        GPIOB_OTYPER |= (DefaultState << PinNum);
      }
      else
      {
        GPIOB_PUPDR &= ~(0x03 << PinNum * 2);
        GPIOB_PUPDR |= (DefaultState << PinNum * 2);
      }
      break;

    case GPIO_C:
      GPIOC_MODER &= ~(0x03 << (PinNum * 2));
      GPIOC_MODER |= (PinMode << (PinNum * 2));

      if (PinMode)
      {
        GPIOC_OTYPER &= ~(0x01 << PinNum);
        GPIOC_OTYPER |= (DefaultState << PinNum);
      }
      else
      {
        GPIOC_PUPDR &= ~(0x03 << PinNum * 2);
        GPIOC_PUPDR |= (DefaultState << PinNum * 2);
      }
      break;
      
    case GPIO_D:
      GPIOD_MODER &= ~(0x03 << (PinNum * 2));
      GPIOD_MODER |= (PinMode << (PinNum * 2));

      if (PinMode)
      {
        GPIOD_OTYPER &= ~(0x01 << PinNum);
        GPIOD_OTYPER |= (DefaultState << PinNum);
      }
      else
      {
        GPIOD_PUPDR &= ~(0x03 << PinNum * 2);
        GPIOD_PUPDR |= (DefaultState << PinNum * 2);
      }
      break;
    default:
      break;
  }
}

uint8 Gpio_WritePin(uint8 PortName, uint8 PinNum, uint8 Data) {

  uint8 status;


  switch (PortName) {
    case GPIO_A:
      if ((GPIOA_MODER & (0x03 << PinNum *2)) >> PinNum*2 == 0){
        status = NOK;
      }
      else {
        GPIOA_ODR &= ~(0x1 << PinNum);
        GPIOA_ODR |= (Data << PinNum);
        status = OK;
      }

      break;
    case GPIO_B:
      if ((GPIOB_MODER & (0x03 << PinNum * 2)) >> PinNum * 2 == 0)
      {
        status = NOK;
      }
      else
      {
        GPIOB_ODR &= ~(0x1 << PinNum);
        GPIOB_ODR |= (Data << PinNum);
        status = OK;
      }
      break;
    case GPIO_C:
      if ((GPIOC_MODER & (0x03 << PinNum * 2)) >> PinNum * 2 == 0)
      {
        status = NOK;
      }
      else
      {
        GPIOC_ODR &= ~(0x1 << PinNum);
        GPIOC_ODR |= (Data << PinNum);
        status = OK;
      }
      break;
    case GPIO_D:
      if ((GPIOD_MODER & (0x03 << PinNum * 2)) >> PinNum * 2 == 0)
      {
        status = NOK;
      }
      else
      {
        GPIOD_ODR &= ~(0x1 << PinNum);
        GPIOD_ODR |= (Data << PinNum);
        status = OK;
      }
      break;
    default:
      break;
  }

  return status;
}

uint8 Gpio_ReadPin(uint8 PortName, uint8 PinNum){
  uint8 value;
  switch (PortName){
    case GPIO_A:
      value = READ_BIT(GPIOA_IDR, PinNum);
      break;
    case GPIO_B:
      value = READ_BIT(GPIOB_IDR, PinNum);
      break;
    case GPIO_C:
      value = READ_BIT(GPIOC_IDR, PinNum);
      break;
    case GPIO_D:
      value = READ_BIT(GPIOD_IDR, PinNum);
      break;
    
  }
  return value;
}