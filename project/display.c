/******
Demo for ssd1306 i2c driver for  Raspberry Pi 
******/
#include <stdio.h>
#include "st7735.h"
#include <unistd.h>


int main(void) {
    uint8_t symbol = 0;

    if (lcd_begin()) //LCD Screen initialization
    {
        return 0;
    }
    sleep(1);

    lcd_fill_screen(ST7735_BLACK);
    lcd_fill_rectangle(0, 20, ST7735_WIDTH, 5, ST7735_BLUE);

    while (1) {
        lcd_display(symbol);
        sleep(2);
        symbol++;
        if (symbol == 4) {
            symbol = 0;
        }
    }
    return 0;
}
