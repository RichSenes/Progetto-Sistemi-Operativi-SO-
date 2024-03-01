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
            mvprintw (j, i, " ");
        }
    }
}

// Funzione per disegnare la rana sulla griglia
void draw_frog (int x, int y) {
    // disegno della rana
    char *frog [] = {
        "            _     _" ,
        "           (')-=-(') " ,
        "         __(   '   )__ " ,
        "        / _|'-----'|_ \\ " ,
        "     ___\\\\ \\\\     // //___ " ,
        "     >____)|_|---|_|(____< "
    };

    int i;
    int frog_height = sizeof(frog)/sizeof(frog[0]);

    // disegna la rana nella posizione specifica
    for(i = 0; i < frog_height; i++) {
        mvprintw(x+i, y, "%s", frog[i]);
    }
}

// Funzione per disegnare un coccodrillo sulla griglia
void draw_crocodile (int x, int y) {
    // disegno del coccodrillo
    char *crocodile [] = {
        "            .-._   _ _ _ _ _ _ _ _ ",
        " .-''-.__.-'00  '-' ' ' ' ' ' ' ' '-. ",
        "'.___ '    .   .--_'-' '-' '-' _'-' '._ ",
        " V: V 'vv-'   '_   '.       .'  _..' '.'. ",
        "   '=.____.=_.--'   :_.__.__:_   '.   : : ",
        "           (((____.-'        '-.  /   : : ",
        "                             (((-'\\ .' / ",
        "                           _____..'  .' ",
        "                          '-._____.-' "
    };

    int i;
    int crocodile_height = sizeof(crocodile)/sizeof(crocodile[0]);

    // disegna un coccodrillo nella posizione specifica
    for(i = 0; i < crocodile_height; i++) {
        mvprintw(x+i, y, "%s", crocodile[i]);
    }
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