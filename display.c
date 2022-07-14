#include "display.h"
#include "ncurses.h"

#define BLACK 1
#define WHITE 2
#define BLUE 3
#define GREEN 4
#define RED 5
#define MAGENTA 6

int open_display(void){
    int exit = initscr() ? 1 : 0;
    start_color();
    init_pair(BLACK, COLOR_BLACK, COLOR_BLACK);
    init_pair(WHITE, COLOR_WHITE, COLOR_WHITE);
    init_pair(BLUE, COLOR_BLUE, COLOR_BLUE);
    init_pair(GREEN, COLOR_GREEN, COLOR_GREEN);
    init_pair(RED, COLOR_RED, COLOR_RED);
    init_color(MAGENTA, 0, 0, 0);
    init_pair(MAGENTA, COLOR_MAGENTA, COLOR_MAGENTA);
    refresh();
    return exit;
}

void display_colons(void){
    attron(COLOR_PAIR(WHITE));
    move(1,2);
    for (int col = 0; col<2; ++col){addch('#');}

    move(2,2);
    for (int col = 0; col<2; ++col){addch('#');}

    move(4,2);
    for (int col = 0; col<2; ++col){addch('#');}

    move(5,2);
    for (int col = 0; col<2; ++col){addch('#');}

    move(1,5);
    for (int col = 0; col<2; ++col){addch('#');}

    move(2,5);
    for (int col = 0; col<2; ++col){addch('#');}

    move(4,5);
    for (int col = 0; col<2; ++col){addch('#');}

    move(5,5);
    for (int col = 0; col<2; ++col){addch('#');}

    refresh();
}

void display_hours(int hours){
    attron(COLOR_PAIR(BLUE));
    int setHours = hours;
    while(setHours != 0){
        if ((setHours % 16) != setHours){
            move(2, 1);
            for (int col = 0; col<1; ++col){addch('#');}
            setHours = setHours % 16;
        }
        if ((setHours % 8) != setHours){
            move(3, 1);
            addch('#');
            setHours = setHours % 8;
        }
        if ((setHours % 4) != setHours){
            move(4, 1);
            addch('#');
            setHours = setHours % 4;
        }
        if ((setHours % 2) != setHours){
            move(5, 1);
            addch('#');
            setHours = setHours % 2;
        }
        if ((setHours % 1) != setHours){
            move(6, 1);
            addch('#');
            setHours = setHours % 1;
        }
        refresh();
    }
}

void display_minutes(int minutes){
    attron(COLOR_PAIR(GREEN));
    int setMin = minutes;
    while(setMin != 0){
        if ((setMin % 32) != setMin){
            move(1, 4);
            addch('#');
            setMin = setMin % 32;
        }
        if ((setMin % 16) != setMin){
            move(2, 4);
            addch('#');
            setMin = setMin % 16;
        }
        if ((setMin % 8) != setMin){
            move(3, 4);
            addch('#');
            setMin = setMin % 8;
        }
        if ((setMin % 4) != setMin){
            move(4, 4);
            addch('#');
            setMin = setMin % 4;
        }
        if ((setMin % 2) != setMin){
            move(5, 4);
            addch('#');
            setMin = setMin % 2;
        }
        if ((setMin % 1) != setMin){
            move(6, 4);
            addch('#');
            setMin = setMin % 1;
        }
        refresh();
    }
}

void display_seconds(int seconds){
    attron(COLOR_PAIR(RED));
    int setSec = seconds;
    while(setSec != 0){
        if ((setSec % 32) != setSec){
            move(1, 7);
            addch('#');
            setSec = setSec % 32;
        }
        if ((setSec % 16) != setSec){
            move(2, 7);
            addch('#');
            setSec = setSec % 16;
        }
        if ((setSec % 8) != setSec){
            move(3, 7);
            addch('#');
            setSec = setSec % 8;
        }
        if ((setSec % 4) != setSec){
            move(4, 7);
            addch('#');
            setSec = setSec % 4;
        }
        if ((setSec % 2) != setSec){
            move(5, 7);
            addch('#');
            setSec = setSec % 2;
        }
        if ((setSec % 1) != setSec){
            move(6, 7);
            addch('#');
            setSec = setSec % 1;
        }
        refresh();
    }
}

void display_time(int hours, int minutes, int seconds){
    display_hours(hours);
    display_minutes(minutes);
    display_seconds(seconds);
}

void close_display(void){
    endwin();
}
