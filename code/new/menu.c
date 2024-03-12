#include "menu.h"

void menu(ScreenSize screen) {
    char game_mode = 'P';

    // Forza l'utente ad avere la schermata di una dimensione minima
    /*
    do {
        mvprintw(screen.y/2, screen.x/2, "La schermata e' troppo piccola!\nDimensioni minime: %d x %d", MIN_WIDTH, MIN_HEIGHT);

        if (screen.y >= MIN_HEIGHT) {
            if (screen.x < MIN_WIDTH) mvprintw(screen.y/2 + 1, screen.x/2, "Aumenta la larghezza dello schermo.");
        } 
        else if (screen.x >= MIN_WIDTH) {
            if (screen.x < MIN_WIDTH) mvprintw(screen.y/2 + 1, screen.x/2, "Aumenta l'altezza dello schermo.");
        }
        else {
            mvprintw(screen.y/2 + 1, screen.x/2, "Aumenta la larghezza e l'altezza dello schermo.");
        }

        refresh();
        clear();
        napms(200);
    } while (screen.x < MIN_WIDTH || screen.y < MIN_HEIGHT); */
    
    // Menu del gioco
    do {
        clear();

        // Stampa del titolo
        draw_game_title(screen);

        // Modalita'
        mvprintw(screen.y / 2 + 2, screen.x / 2 - (12 / 2), "1 - NUOVA PARTITA");
        mvprintw(screen.y / 2 + 4, screen.x / 2 - (12 / 2), "2 - ESCI DAL GIOCO");

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