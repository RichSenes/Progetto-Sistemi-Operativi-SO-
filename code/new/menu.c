#include "menu.h"

void menu(ScreenSize screen) {
    char game_mode = 'P';

    // Forza l'utente ad avere la schermata di una dimensione minima
    do {
        mvprintw(screen.y/2 - 2, screen.x/2 - 15, "La schermata e' troppo piccola!\n");
        mvprintw(screen.y/2 - 1, screen.x/2 - 13, "Dimensioni minime: %d x %d\n", MIN_WIDTH, MIN_HEIGHT);

        if (screen.y >= MIN_HEIGHT) {
            if (screen.x < MIN_WIDTH) mvprintw(screen.y/2, screen.x/2 - 16.2, "Aumenta la larghezza dello schermo.\n");
        } 
        else if (screen.x >= MIN_WIDTH) {
            if (screen.y < MIN_HEIGHT) mvprintw(screen.y/2, screen.x/2 - 16, "Aumenta l'altezza dello schermo.\n");
        }
        else {
            mvprintw(screen.y/2, screen.x/2 - 16, "Aumenta l'altezza dello schermo.\n");
            mvprintw(screen.y/2 + 1, screen.x/2 - 16.2, "Aumenta la larghezza dello schermo.\n");
        }

        getmaxyx(stdscr, screen.y, screen.x);
        refresh();
        clear();
        napms(200);
    } while (screen.x < MIN_WIDTH || screen.y < MIN_HEIGHT); 
    
    // Menu del gioco
    do {
        clear();

        // Stampa del titolo
        draw_game_title(screen);

        // Modalita'
        mvprintw(screen.y / 2 + 5, screen.x / 2 - (20 / 2), "1 - NUOVA PARTITA");
        mvprintw(screen.y / 2 + 6, screen.x / 2 - (20 / 2), "2 - ESCI DAL GIOCO");

        refresh();

        timeout(100);
        game_mode = getch();
        getmaxyx (stdscr, screen.y, screen.x);

        switch(game_mode) {
            case '1':
                timeout(-1);
                //start_game();
                break;

            case '2':
            case 'q':
            case 'Q':
                break;

            default:
                break;
        } 
    } while (game_mode != '2');
}