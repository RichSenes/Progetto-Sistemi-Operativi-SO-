// File che avvia il gioco, gestisce l'inizializzazione e la terminazione
// del programma e coordina il flusso di esecuzione principale.

#include "gestione_grafica.c"
#include "utility.c"

int main () {
    // Salvataggio delle dimensioni attuali del font
    char *initialDPI = getFontDimensions();

    // Modifica delle impostazioni di sistema per le dimensioni del font
    system("gsettings set org.gnome.desktop.interface monospace-font-name 'Monospace 3'");

    // Inizializza ncurses
    init_ncurses();

    resize_term(LINES, COLS);   // imposta la finestra a schermo intero

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
    updateFontDimensions(initialDPI);
    free(initialDPI);

    return 0;
}