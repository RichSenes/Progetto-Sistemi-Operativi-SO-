// File che gestira' l'input da tastiera per controllare 
// il movimento della rana e le altre interazioni utente.

#include "gestione_grafica.c"

void move_character (int direction, int *y, int *x) {
    int maxX, maxY;
    getmaxyx(stdscr, maxY, maxX);

    switch (direction) {
        case KEY_RIGHT:
            *(y) += 1;

            if (*y >= (maxY * 4) - 1) { *y = (maxY * 4) - 1; }

            clear();
            draw_border();
            draw_frog(*x, *y);
            refresh();
        break;

        case KEY_LEFT:
            *(y) -= 1;

            if (*y <= 1) { *y = 1; }

            clear();
            draw_border();
            draw_frog(*x, *y);
            refresh();
        break;

        case KEY_DOWN:
            *(x) += 1;

            if (*x >= maxX/4.7 - 1) { *x = maxX/4.7 - 1; }

            clear();
            draw_border();
            draw_frog(*x - 1, *y);
            refresh();
        break;

        case KEY_UP:
            *(x) -= 1;

            if (*x <= 1) { *x = 1; }

            clear();
            draw_border();
            draw_frog(*x + 1, *y);
            refresh();
        break;
    }
}