
#include "led.h"

// ----------------------------------------------------------------------------

void
blink_led_init()
{
  // Enable GPIO Peripheral clock
  SET_BIT(RCC->AHB1ENR, BLINK_RCC_MASKx(BLINK_PORT_NUMBER));

  GPIO_InitTypeDef GPIO_InitStructure;

  // Configure pin in output push/pull mode
  GPIO_InitStructure.Pin = BLINK_PIN_MASK(BLINK_PIN_NUMBER);
  GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStructure.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(BLINK_GPIOx(BLINK_PORT_NUMBER), &GPIO_InitStructure);

  // Start with led turned off
  blink_led_off();
}

void
blink_led_on(void)
{
#if (BLINK_ACTIVE_LOW)
  HAL_GPIO_WritePin(BLINK_GPIOx(BLINK_PORT_NUMBER),
    BLINK_PIN_MASK(BLINK_PIN_NUMBER), GPIO_PIN_RESET);
#else
  HAL_GPIO_WritePin(BLINK_GPIOx(BLINK_PORT_NUMBER),
    BLINK_PIN_MASK(BLINK_PIN_NUMBER), GPIO_PIN_SET);
#endif
}

void
blink_led_off(void)
{
#if (BLINK_ACTIVE_LOW)
  HAL_GPIO_WritePin(BLINK_GPIOx(BLINK_PORT_NUMBER),
    BLINK_PIN_MASK(BLINK_PIN_NUMBER), GPIO_PIN_SET);
#else
  HAL_GPIO_WritePin(BLINK_GPIOx(BLINK_PORT_NUMBER),
    BLINK_PIN_MASK(BLINK_PIN_NUMBER), GPIO_PIN_RESET);
#endif
}

// ----------------------------------------------------------------------------
