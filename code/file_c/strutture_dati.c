// File per la definizione di strutture dati da utilizzare nel gioco,
// come lo stato della partita e le informazioni di gioco.

// Struttura rappresentante la rana
struct Frog {
    int x; // coordinata x della posizione
    int y; // coordinata y della posizione
    int lifes; // numero di vite rimaste
    int points; // punteggio del giocatore
};

// Struttura rappresentante un coccodrillo
struct Crocodile {
    int x; // coordinata x della posizione
    int y; // coordinata y della posizione
    int direction; // direzione del movimento
    int type; // tipo di coccodrillo (buono o cattivo)
};

// Struttura rappresentante una piante
struct Plant {
    int x; // coordinata x della posizione
    int y; // coordinata y della posizione
    int shoot_frequency; // frequenza di sparo dei proiettili
};

// Struttura rappresentante un proiettile
struct Bullet {
    int x; // coordinata x della posizione
    int y; // coordinata y della posizione
    int direction; // direzione del movimento
    int speed; // velocita' del movimento
};

// Struttura rappresentante la griglia di gioco
#define GRID_DIM_X 80 // dimensione della griglia - asse x
#define GRID_DIM_Y 50 // dimensione della griglia - asse y
struct Grid {
    // matrice bidimensionale di caratteri per la griglia di gioco
    char cells[GRID_DIM_X] [GRID_DIM_Y];
};
