#ifndef _MJIMENEZ_H_
#define _MJIMENEZ_H_
/**
 * Author: Mario Jimenez
 * Created: 09/27/2023
 * File: mjimenez.h
 * Description: Mario Jimenez Header File 
 **/
#include "cestes.h"
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include "X11_wrapper.h"
class Global;

class ShieldPowerUp {
public:
    float pos[2];
    float vel[2];
    float width;
    float height;
    bool activated;
    bool active;
    time_t activationTime;
    void activate();
    bool isActivated();
    ShieldPowerUp() {
        init();
    }
    void init();

};
bool Check4(Square burger, ShieldPowerUp shieldPowerUp);
// called from main program
//extern void display_name(int, int);
extern void renderStartScreen(int xres, int yres, X11_wrapper& x11, Global& gl);
extern int time_since_key_press(time_t key_checker);
extern void display_border(int xres, int yres);

#endif
