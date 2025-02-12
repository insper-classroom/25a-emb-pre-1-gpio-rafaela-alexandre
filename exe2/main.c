#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN_G= 26;
const int BTN_PIN_B= 7;


int main() {
  stdio_init_all();

  gpio_init(BTN_PIN_G);
  gpio_init(BTN_PIN_B);

  gpio_set_dir(BTN_PIN_G, GPIO_IN);
  gpio_set_dir(BTN_PIN_B, GPIO_IN);

  gpio_pull_up(BTN_PIN_G);
  gpio_pull_up(BTN_PIN_B);


  while (true) {

    if (!gpio_get(BTN_PIN_G)) {
      printf("Botao Green\n");
      while (!gpio_get(BTN_PIN_G)) {
        sleep_ms(10);
      }
    }
    if (!gpio_get(BTN_PIN_B)) {
      printf("Botao Azul\n");
      while (!gpio_get(BTN_PIN_B)) {
        sleep_ms(10);
      }
    }
  }
}
