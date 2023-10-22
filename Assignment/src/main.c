#include <stdio.h>
#include <stdlib.h>
#include "diag/trace.h"

#include "timer.h"
#include "led.h"
//#include "fan.h"

// ----- Timing definitions -------------------------------------------------

// Keep the LED on for 2/3 of a second.
#define BLINK_ON_TICKS  (TIMER_FREQUENCY_HZ * 3 / 4)
#define BLINK_OFF_TICKS (TIMER_FREQUENCY_HZ - BLINK_ON_TICKS)

// ----- main() ---------------------------------------------------------------

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"

int
main(int argc, char* argv[])
{

  trace_puts("Hello Arm World!");


  puts("Standard output message.");
  fprintf(stderr, "Standard error message.\n");

  // At this stage the system clock should have already been configured
  // at high speed.
  trace_printf("System clock: %u Hz\n", SystemCoreClock);

  timer_start();

  blink_led_init();
  
  uint32_t seconds = 0;

  while (1)
  {
	  int temperature = rand() % (70 - 20 + 1) + 20;; // Khởi tạo ngẫu nhiên biến nhiệt độ từ 20 - 70 độ
    if (temperature > 40)
    {
      blink_led_on(); // Hiển thị led báo
//      fan_on(); // Bật quạt gió
      trace_printf("Nhiệt độ hiện tại: %d, Nhiệt độ đang quá mức cho phép, Bật quạt gió \n\n", temperature);
    }
    else
    {
    trace_printf("Nhiệt độ hiện tại: %d, Nhiệt độ phù hợp, Tắt quạt gió \n\n", temperature);
      blink_led_off();
//      fan_off(); // Tắt quạt gió
    }
    timer_sleep(TIMER_FREQUENCY_HZ); // Ngủ 1 giây
  }
}
#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
