/******
Demo for ssd1306 i2c driver for  Raspberry Pi 
******/
#include <stdio.h>
#include "st7735.h"
#include <unistd.h>
#include <time.h>

bool is_within_5s_of_minute() {
    time_t now;
    struct tm *tm_info;

    time(&now);
    tm_info = localtime(&now);

    return tm_info->tm_sec >= 55;
}


void wait_until_top_of_minute() {
    time_t now;
    time(&now);
    struct tm *tm_info = localtime(&now);

    int seconds_to_wait = 60 - tm_info->tm_sec;
    sleep(seconds_to_wait);
}

int main(void) {
    uint8_t symbol = 0;

    if (lcd_begin()) //LCD Screen initialization
    {
        return 0;
    }
    sleep(1);

    while (1) {
        wait_until_top_of_minute(); // synchronize to top of minute
        bool first_pass = true;

        while (1) {
            if (is_within_5s_of_minute()) break;
            lcd_display_ip(first_pass);
            first_pass = false;

            if (is_within_5s_of_minute()) break;
            lcd_display_cpuLoad();
            sleep(2);

            if (is_within_5s_of_minute()) break;
            lcd_display_ram();
            sleep(2);

            if (is_within_5s_of_minute()) break;
            lcd_display_temp();
            sleep(2);

            if (is_within_5s_of_minute()) break;
            lcd_display_disk();
            sleep(2);
        }
    }
    return 0;
}
