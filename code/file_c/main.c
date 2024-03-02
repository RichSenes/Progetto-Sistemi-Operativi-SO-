// File che avvia il gioco, gestisce l'inizializzazione e la terminazione
// del programma e coordina il flusso di esecuzione principale.

#include <ncurses.h>
#include <stdlib.h>
#include "gestione_grafica.c"

int main () {
    // Modifica delle impostazioni di sistema per le dimensioni del font
    system("gsettings set org.gnome.desktop.interface monospace-font-name 'Monospace 2'");

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

    // Attendi un input dall'utente prima di uscire [tasto e]
    while (getch() != 'e') { }

    // Termina ncurses
    endwin();

    // Ridimensionamento delle dimensioni del font
    system("gsettings set org.gnome.desktop.interface monospace-font-name 'Monospace 10'");

    return 0;
}