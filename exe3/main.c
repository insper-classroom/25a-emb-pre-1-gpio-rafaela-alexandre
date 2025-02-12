#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int LED_PIN_R = 4;
const int LED_PIN_G = 6;

const int BTN_PIN_R = 28;
const int BTN_PIN_G = 26;

int main() {
  stdio_init_all();

  gpio_init(LED_PIN_R);
  gpio_init(LED_PIN_G);

  gpio_init(BTN_PIN_R);
  gpio_init(BTN_PIN_G);

  gpio_set_dir(LED_PIN_R, GPIO_OUT);
  gpio_set_dir(LED_PIN_G, GPIO_OUT);

  gpio_set_dir(BTN_PIN_R, GPIO_IN);
  gpio_set_dir(BTN_PIN_G, GPIO_IN);

  gpio_pull_up(BTN_PIN_G); // Botão igual a 1
  gpio_pull_up(BTN_PIN_R);

  int ligado = 0;
  while (true) {

    if (!gpio_get(BTN_PIN_G)) {
        if (ligado == 0){
          printf("Botao Green Ligou\n");
          gpio_put(LED_PIN_G, 1);
          ligado = 1;
          sleep_ms(10);

        }
        else if(ligado == 1 ) {
          printf("Botao Green Desligou\n");
          gpio_put(LED_PIN_G, 0);
          ligado = 0;
          sleep_ms(10);
        }

        while (!gpio_get(BTN_PIN_G)) {
        
        }
    }

    if (!gpio_get(BTN_PIN_R)) {
        if (ligado == 0){
          printf("Botao Red Ligou\n");
          gpio_put(LED_PIN_R, 1);
          ligado = 1;
          sleep_ms(10);

        }
        else if(ligado == 1 ) {
          printf("Botao Red Desligou\n");
          gpio_put(LED_PIN_R, 0);
          ligado = 0;
          sleep_ms(10);
        }

        while (!gpio_get(BTN_PIN_R)) {
        
        }

      
    }
  }

}
