// File che gestira' la parte grafica del gioco, inclusa la rappresentazione visiva
// dei personaggi, degli oggetti e della schermata di gioco.

#include <ncurses.h>
#include <curses.h>
#include "strutture_dati.h"

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
    // disegno della pianta
    char *plant [] = {
        "               __/) ",
        "            .-(__(=: ",
        "            |    \\) ",
        "      (\\__  | ",
        "     :=)__)-|  __/) ",
        "      (/    |-(__(=: ",
        "    ______  |  _ \\) ",
        "   /      \\ | / \\ ",
        "        ___\\|/___\\ "
    };

    int i;
    int plant_height = sizeof(plant)/sizeof(plant[0]);

    // disegna una pianta nella posizione specifica
    for(i = 0; i < plant_height; i++) {
        mvprintw(x+i, y, "%s", plant[i]);
    }
}

// Funzione per disegnare un proiettile sulla griglia
void draw_bullet (int x, int y) {
    // disegno del proiettile
    char *bullet [] = {
        " ____",
        "|____| ",
        "||  || ",
        "||  || ",
        "\\\\  // ",
        " \\\\// ",
        "  \\/"
    };

    int i;
    int bullet_height = sizeof(bullet)/sizeof(bullet[0]);

    // disegna un proiettile nella posizione specifica
    for(i = 0; i < bullet_height; i++) {
        mvprintw(x+i, y, "%s", bullet[i]);
    }
}

// Funzione per disegnare il bordo
void draw_border () {
    int x, y, maxX, maxY;

    // Ottieni le dimensioni della finestra corrente
    getmaxyx(stdscr, maxY, maxX);

    // Disegna il bordo superiore
    mvhline(0, 0, '-', maxX);

    // Disegna il bordo inferiore
    mvhline(maxY - 1, 0, '-', maxX);

    // Disegna il bordo sinistro
    for (int i = 1; i < maxY - 1; i++) {
        mvaddch(i, 0, '|');   
    }

    // Disegna il bordo destro
    for (int i = 1; i < maxY; i++) {
        mvaddch(i, maxY * 3.97 - 1, '|');   
    }

    // Disegna gli angoli
    mvaddch(0, 0, '+');
    mvaddch(0, maxX - 1, '+');
    mvaddch(maxY - 1, 0, '+');
    mvaddch(maxY - 1, maxX - 1, '+');
}