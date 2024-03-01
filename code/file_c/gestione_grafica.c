// File che gestira' la parte grafica del gioco, inclusa la rappresentazione visiva
// dei personaggi, degli oggetti e della schermata di gioco.

#include <ncurses.h>
#include "strutture_dati.c"

// Funzione per inizializzare la finestra di ncurses
void init_ncurses () {
    initscr();              // inizializza la finestra ncurses
    cbreak();               // disabilita il buffering della finestra (legge un carattere alla volta)
    noecho();               // non mostrare i caratteri digitati dall'utente
    curs_set(0);            // nascondi il cursore
    keypad(stdscr, TRUE);   // abilita la lettura dei tasti speciali (es. frecce)
}

// Funzione per disegnare la griglia di gioco
void draw_grid () {
    for (int i = 0; i < GRID_DIM_X; ++i) {
        for (int j = 0; j < GRID_DIM_Y; ++j) {
            // disegna un quadrato per ogni cella della griglia
            mvprintw (j, i, "[]");
        }
    }
}

// Funzione per disegnare la rana sulla griglia
void draw_frog (int x, int y) {
    // disegna la rana nella posizione specifica
    mvprintw(y, x, "R");
}

// Funzione per disegnare un coccodrillo sulla griglia
void draw_crocodile (int x, int y) {
    // disegna un coccodrillo nella posizione specifica
    mvprintw(y, x, "C");
}

// Funzione per disegnare una pianta sulla griglia
void draw_plant (int x, int y) {
    // disegna una pianta nella posizione specifica
    mvprintw(y, x, "P");
}

// Funzione per disegnare un proiettile sulla griglia
void draw_bullet (int x, int y) {
    // disegna un proiettile nella posizione specifica
    mvprintw(y, x, "o");
}