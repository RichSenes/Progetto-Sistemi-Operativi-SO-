// File per la definizione di strutture dati da utilizzare nel gioco,
// come lo stato della partita e le informazioni di gioco.

// Struttura rappresentante la rana
typedef struct {
    int x; // coordinata x della posizione
    int y; // coordinata y della posizione
    int lifes; // numero di vite rimaste
    int points; // punteggio del giocatore
} Frog;

// Struttura rappresentante un coccodrillo
typedef struct {
    int x; // coordinata x della posizione
    int y; // coordinata y della posizione
    int direction; // direzione del movimento
    int type; // tipo di coccodrillo (buono o cattivo)
} Crocodile;

// Struttura rappresentante una piante
typedef struct {
    int x; // coordinata x della posizione
    int y; // coordinata y della posizione
    int shoot_frequency; // frequenza di sparo dei proiettili
} Plant;

// Struttura rappresentante un proiettile
typedef struct {
    int x; // coordinata x della posizione
    int y; // coordinata y della posizione
    int direction; // direzione del movimento
    int speed; // velocita' del movimento
} Bullet;

// Struttura rappresentante la griglia di gioco
#define GRID_DIM_X 20 // dimensione della griglia - asse x
#define GRID_DIM_Y 10 // dimensione della griglia - asse y
typedef struct {
    // matrice bidimensionale di caratteri per la griglia di gioco
    char cells[GRID_DIM_X] [GRID_DIM_Y];
} Grid;
