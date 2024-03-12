#include "menu.h"

int main() {
    ScreenSize screen;

    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, true);

    getmaxyx(stdscr, screen.y, screen.x);

    menu(screen);

    refresh();
    endwin();
    return 0;
}