// File che avvia il gioco, gestisce l'inizializzazione e la terminazione
// del programma e coordina il flusso di esecuzione principale.

#include <ncurses.h>
#include "gestione_grafica.c"

int main () {
    // Inizializza ncurses
    init_ncurses();

    // Prova di disegno degli elementi grafici
    draw_grid();
    draw_frog(5, 5);
    draw_crocodile(20, 40);
    draw_plant(5, 35);
    draw_bullet(15, 15);

    // Aggiorna lo schermo
    refresh();

    // Attendi un input dall'utente prima di uscire
    getch();

    // Termina ncurses
    endwin();

    return 0;
}