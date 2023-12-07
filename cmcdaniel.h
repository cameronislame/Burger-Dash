#ifndef _Cameron_M_
#define _Cameron_M_
#include <time.h>
#include <math.h>
#include "jbaltazarrob.h"
#include "cestes.h"
//Cameron's project files

extern class Global {
    public:
        int xres, yres;
        unsigned int keys[65536];
        int score;
        bool show_border;
        bool display_credits;
        bool CheckCollision2;
        double delay;
        bool display_statistics;
        bool display_options;
        time_t begin;
        time_t key_checker;
        Global() {
            show_border = false;
            display_credits = false;
            display_statistics = false;
            display_options = false;
            xres = 1200;
            yres = 415;
            score = 0;
            delay = 0.1;
            time(&begin);
            time(&key_checker);
        }
} gl; 


//extern void display_name(int, int);
//extern void display_border(int xres, int yres);
extern void display_credits(int xres, int yres);
extern int total_running_time(time_t begin);
extern int time_since_mouse_move(const bool get);
extern void renderLevel(Level lev, Global gl, double* camera);
extern void renderBurger(Square burger, Level lev,  Global gl, bool shieldState);
extern void renderFire(Square burger, Level lev);
extern void renderKnife(Square burger, Level lev);
extern void renderTramp(Square burger, Level lev);
extern void renderKnifeBlock(Square burger, Level lev);
extern void renderTitleArt(Square burger, Level lev);
extern void renderHealth(Square burger, Level lev);
extern void renderShieldArt(Square burger, Level lev);
extern void renderExitArt(Square burger, Level lev);
extern void renderVictoryArt(Square burger, Level lev);
extern void renderGameOverArt(Square burger, Level lev);
extern void renderSquare(Square burger, int j, int i, Flt dd, Flt offy, int tx, int ty);
class cameron{
	int abc;
};

#endif
