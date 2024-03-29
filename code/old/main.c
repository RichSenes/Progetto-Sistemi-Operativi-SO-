// File che avvia il gioco, gestisce l'inizializzazione e la terminazione
// del programma e coordina il flusso di esecuzione principale.

#include "gestione_input.c"
#include "utility.c"

int main () {
    // Salvataggio delle dimensioni attuali del font
    // char *initialDPI = getFontDimensions(); [SEGMENTATION FAULT]

    // Variabili di gioco
    int x = 1, y = 1, input = '0';

    // Modifica delle impostazioni di sistema per le dimensioni del font
    // Cambia le dimensioni del font solo del terminale da cui si esegue
    system("gsettings set org.gnome.desktop.interface monospace-font-name 'Monospace 4'");

    // Scala le dimensioni del font in generale (ovunque) (direi che non va bene)
    //system("gsettings set org.gnome.desktop.interface text-scaling-factor 0.5");

    // Inizializza ncurses
    init_ncurses();

    // Aggiorna lo schermo
    refresh();

    // Attendi un input dall'utente prima di uscire [tasto e]
    while ((input = getch()) != 'q') { 
        move_character(input, &y, &x);
    }

    // Termina ncurses
    clear();
    endwin();

    // Ridimensionamento delle dimensioni del font
    // updateFontDimensions(initialDPI);
    // free(initialDPI);

    system("gsettings set org.gnome.desktop.interface monospace-font-name 'Monospace 10'");

    return 0;
}