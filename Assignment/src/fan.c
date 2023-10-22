//// Thêm định nghĩa cho GPIO của quạt gió
//#define FAN_PORT_NUMBER               (6)
//#define FAN_PIN_NUMBER                (14)
//#define FAN_GPIOx(_N)                 ((GPIO_TypeDef *)(GPIOA_BASE + (GPIOB_BASE-GPIOA_BASE)*(_N)))
//#define FAN_PIN_MASK(_N)              (1 << (_N))
//#define FAN_RCC_MASKx(_N)             (RCC_AHB1ENR_GPIOAEN << (_N))
//
//// Thêm hàm khởi tạo GPIO cho quạt gió
//void fan_init()
//{
//  // Enable GPIO Peripheral clock
//  SET_BIT(RCC->AHB1ENR, FAN_RCC_MASKx(FAN_PORT_NUMBER));
//
//  GPIO_InitTypeDef GPIO_InitStructure;
//
//  // Configure pin in output push/pull mode
//  GPIO_InitStructure.Pin = FAN_PIN_MASK(FAN_PIN_NUMBER);
//  GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
//  GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
//  GPIO_InitStructure.Pull = GPIO_PULLUP;
//  HAL_GPIO_Init(FAN_GPIOx(FAN_PORT_NUMBER), &GPIO_InitStructure);
//
//  // Start with fan turned off
//  fan_off();
//}
//
//// Thêm hàm bật quạt gió
//void fan_on(void)
//{
//  HAL_GPIO_WritePin(FAN_GPIOx(FAN_PORT_NUMBER),
//    FAN_PIN_MASK(FAN_PIN_NUMBER), GPIO_PIN_SET);
//}
//
//// Thêm hàm tắt quạt gió
//void fan_off(void)
//{
//  HAL_GPIO_WritePin(FAN_GPIOx(FAN_PORT_NUMBER),
//    FAN_PIN_MASK(FAN_PIN_NUMBER), GPIO_PIN_RESET);
//}
//
//// Sửa lại vòng lặp vô hạn trong file main.c
//while (1)
//{
//  // Sinh ra một số nguyên ngẫu nhiên từ 0 đến 50 và gán cho biến threshold
//  int threshold = rand() % 51;
//  if (threshold > 30) // Nếu threshold lớn hơn 30
//  {
//    blink_led_toggle(); // Đảo trạng thái LED
//    fan_on(); // Bật quạt gió
//    trace_printf("LED is blinking, fan is on, threshold = %d\n", threshold); // In ra thông báo LED đang nháy, quạt gió đang bật và giá trị của threshold
//  }
//  else // Nếu threshold nhỏ hơn hoặc bằng 30
//  {
//    blink_led_off(); // Tắt LED
//    fan_off(); // Tắt quạt gió
//    trace_printf("LED is off, fan is off, threshold = %d\n", threshold); // In ra thông báo LED tắt, quạt gió tắt và giá trị của threshold
//  }
//  timer_sleep(TIMER_FREQUENCY_HZ); // Ngủ một giây
//}
