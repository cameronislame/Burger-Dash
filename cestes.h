// Conner Estes header file

#include <time.h>
#include "X11_wrapper.h"
#include <stdio.h>
#include <unistd.h>
#include <AL/alut.h>

// cestes.h
#ifndef _CESTES_H_
#define _CESTES_H_
class Global;
const float lvlspeed = -8.0f;


class Oil {
    public:
        float pos[2];
        float vel[2];
        float width;
        float height;
        Oil(){
            init();
        }
        void init(){
            width = 12.0f;
            height = 8.0f;
            pos[0] = 1500.0f;
            pos[1] = 1.0f;
            vel[0] = lvlspeed;
        }
};

extern Oil oil;


class Enemy {
public:
    float pos[2];
    float vel[2];
    float width;
    float height;
    Enemy() {
        init();
    }
    void init() {
        width = 18.0f;
        height = 32.0f;
        pos[0] = 1200.0f;
        pos[1] = 0.0f;
        vel[0] = lvlspeed;
        //pos[0] += vel[0];
    }
};

extern Enemy enemy;

// ... other declarations ...


class Health {
    public:
        int health;
        float pos[2];
        //loat verts[4][2];
        float width;
        float height;
        Health() {
            init();
        }
        void init() {
            health = 255;
            pos[0] = 1000;
            width = health/2;
            height = 30.0f;
            pos[1] = 370;
        }
};

extern Health healthbar;




class Square {
    public:
        float pos[2];
        float vel[2];
        float verts[4][2];
        float width;
        float height;
        float active;
        Square() {
            init();

        }
        void init() {
            vel[0] = 0.0f;
            vel[1] = 0;
            width =  5.0f;
            height = 5.0f;
            pos[0] = 500.0f;
            pos[1] = 0.0f + height;
            active = true;
        }
};

extern Square burger;


int total_physics_function_calls();
void renderEnemy();

// cestes.h



//extern void display_border(int xres, int yres);
extern void display_name(int, int);
void renderHealth();
bool Check2(Square burger, Enemy enemy);
void renderOil();
bool Check3(Square burger,Oil oil);
void renderGameOver( int xres, int yres, X11_wrapper& x11, Global& gl);
bool playOpenALSound(const char* soundFilePath);
void stopOpenALSound();
#endif
