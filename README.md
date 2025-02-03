# Controle LED com Botão e Temporizador - Tarefa 2

Sistema de controle de LEDs usando Raspberry Pi Pico W com temporização após acionamento por botão.

## Funcionalidades
- Controle de 3 LEDs via botão pushbutton
- Sequência temporizada de desligamento dos LEDs
- Timer de 3s entre estados
- Proteção contra múltiplos acionamentos

## Hardware
- Raspberry Pi Pico W
- 3 LEDs (azul, vermelho, verde)
- 3 Resistores 1kΩ
- 1 Pushbutton

## Pinos
- LED Azul: GPIO11
- LED Vermelho: GPIO12
- LED Verde: GPIO13  
- Botão: GPIO5

## Estados
1. Botão pressionado: todos LEDs acendem
2. Após 3s: dois LEDs permanecem acesos
3. Após 6s: um LED permanece aceso
4. Após 9s: todos LEDs apagam

## Compilação
```bash
mkdir build
cd build
cmake ..
make
