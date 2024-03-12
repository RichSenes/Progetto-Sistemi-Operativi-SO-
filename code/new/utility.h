#ifndef UTILITY
#define UTILITY

#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MIN_WIDTH 140
#define MIN_HEIGHT 140

typedef struct {
    int x_left, x_right, y_up, y_down;
} Position;

typedef struct {
    Position pos, old_pos;
    int id, pid;
    char sprite[5];
    bool shoot;
} Player;

typedef struct enemy {
    Player enemy;
    struct enemy *next, *prev;
    int lifes;
    char enemy_type;
} Enemy;

typedef struct {
    int x, y;
} ScreenSize;

extern ScreenSize screen, hud_screen;
extern int enemy_rows;

#endif
