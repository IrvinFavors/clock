#include "display.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

int main(void){
    open_display();
    display_colons();
    char time[8];
    int hours, minutes, seconds;

    while(1){
        scanf("%s", time);
        hours = atoi(time);
        minutes = atoi(&time[3]);
        seconds = atoi(&time[6]);

        if (hours > 23 || hours < 0){break;}
        if (minutes > 59 || minutes < 0){break;}
        if (seconds > 59 || minutes < 0){break;}
        clear();
        display_colons();
        refresh();
        display_time(hours,minutes,seconds);
    }
    close_display();
    return 0;
}
