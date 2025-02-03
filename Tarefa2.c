#include "pico/stdlib.h"
#include <stdio.h>

const uint LED_AZUL = 11;    // LED RGB
const uint LED_VERMELHO = 12;
const uint LED_VERDE = 13;
const uint BOTAO = 5;        // Botão A (GPIO 5)

volatile bool botao_liberado = true;

bool turn_off_callback_1(struct repeating_timer *t) {
    gpio_put(LED_AZUL, 0);   // Desliga primeiro LED
    printf("Dois LEDs acesos\n");
    return false;
}

bool turn_off_callback_2(struct repeating_timer *t) {
    gpio_put(LED_VERMELHO, 0);  // Desliga segundo LED
    printf("Um LED aceso\n");
    return false;
}

bool turn_off_callback_3(struct repeating_timer *t) {
    gpio_put(LED_VERDE, 0);    // Desliga último LED
    printf("Todos LEDs apagados\n");
    botao_liberado = true;     // Libera o botão
    return false;
}

int main() {
    stdio_init_all();

    // Inicialização dos pinos
    gpio_init(LED_AZUL);
    gpio_init(LED_VERMELHO);
    gpio_init(LED_VERDE);
    gpio_init(BOTAO);

    gpio_set_dir(LED_AZUL, GPIO_OUT);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_set_dir(LED_VERDE, GPIO_OUT);
    gpio_set_dir(BOTAO, GPIO_IN);
    gpio_pull_up(BOTAO);

    while(1) {
        if (!gpio_get(BOTAO) && botao_liberado) {
            botao_liberado = false;  // Trava o botão
            
            // Liga todos os LEDs
            gpio_put(LED_AZUL, 1);
            gpio_put(LED_VERMELHO, 1);
            gpio_put(LED_VERDE, 1);
            printf("Todos LEDs acesos\n");

            // Configura os timers para desligar os LEDs sequencialmente
            add_alarm_in_ms(3000, turn_off_callback_1, NULL, true);
            add_alarm_in_ms(6000, turn_off_callback_2, NULL, true);
            add_alarm_in_ms(9000, turn_off_callback_3, NULL, true);
        }
        sleep_ms(100); // Debounce simples
    }
}