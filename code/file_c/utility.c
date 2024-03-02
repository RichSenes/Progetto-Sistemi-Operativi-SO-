

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

// Funzione per inizializzare la finestra di ncurses
void init_ncurses () {
    initscr();                  // inizializza la finestra ncurses
    cbreak();                   // disabilita il buffering della finestra (legge un carattere alla volta)
    noecho();                   // non mostrare i caratteri digitati dall'utente
    curs_set(0);                // nascondi il cursore
    keypad(stdscr, TRUE);       // abilita la lettura dei tasti speciali (es. frecce)
}

char *getFontDimensions () {
    FILE *fp;
    char buffer[MAX_BUFFER_SIZE];
    char *result;

    // Apre una pipe in lettura con il comando per leggere le dimensioni del font
    fp = popen("xrdb -query | grep 'Xft.dpi'", "r");
    if (fp == NULL) {
        printf("Errore nell'esecuzione del comando per il salvataggio delle dimensioni del font.\n");
        exit(EXIT_FAILURE);
    }

    // Legge l'output dalla pipe e lo salva nel buffer
    result = fgets(buffer, MAX_BUFFER_SIZE, fp);

    // Chiude la pipe
    pclose(fp);

    // Restituisce una copia dell'output
    return strdup(buffer);
}

void changeFontDimensions (char *dpi) {
    char command[MAX_BUFFER_SIZE];

    // Costruisce il comando per cambiare le dimensioni del font
    snprintf(command, MAX_BUFFER_SIZE, "gsettings set org.gnome.desktop.interface monospace-font-name 'Monospace %s'", dpi);

    // Esegue il comando
    system(command);
}

void updateFontDimensions () {
    char *result = getFontDimensions();

    if (result != NULL) {
        // Esreae il valore dpi da result
        char *dpi = strchr(result, ':');

        if (dpi != NULL) {
            dpi = strtok (dpi, ": ");
            dpi = strtok (NULL, ": ");

            // Utilizza il valore dpi per cambiare le dimensioni del font
            if (dpi != NULL) {
                changeFontDimensions(dpi);
            }
        }

        // Libera la memoria allocata da strdup
        free(result);
    }
}