/**
 * Author: Mario Jimenez
 * Created: 09/27/2023
 * File: mjimenez.cpp
 * Description: Mario Jimenez Source File 
 **/
#include "cmcdaniel.h"
#include "mjimenez.h"
#include "fonts.h"
#include "X11_wrapper.h"
#include <time.h>
#include <GL/glx.h>

int time_since_key_press(time_t begin) {
        return time(NULL) - begin;
}

void renderStartScreen(int xres, int yres, X11_wrapper& x11, Global& gl) {
    glClear(GL_COLOR_BUFFER_BIT);
    // Calculate the center of the screen
    int centerX = xres / 2;
    int centerY = yres / 2;
    // Calculate the position of the yellow square relative to the center
    int squareWidth = 500; // Increase the size as needed
    int squareHeight = 300;
    int squareX = centerX - (squareWidth / 2);
    int squareY = centerY - (squareHeight / 2);
    /*
    // Draw the larger yellow square in the center
    glColor3ub(255, 255, 0);
    glPushMatrix();
    glTranslatef(squareX, squareY, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(0, squareHeight);
    glVertex2f(squareWidth, squareHeight);
    glVertex2f(squareWidth, 0);
    glEnd();
    glPopMatrix();
    // Text Color
    unsigned int c = 0xf0f00044; // Color
    Rect r;
    r.bot = squareY + (squareHeight / 2); // Center vertically
    r.left = squareX + (squareWidth / 2); // Center horizontally
    r.center = 1;
    ggprint8b(&r, 16, c, "Burger Dash");

    r.bot = squareY - 20;
    r.left = centerX;
    r.center = 1;
    ggprint8b(&r, 16, c, "Press Enter to Start");
    */
    Level titleArtSprite(5.0f, 5.0f, "titleSprite.xpm");
    Square titleArt;
    titleArt.pos[0] = squareX;
    titleArt.pos[1] = squareY;
    titleArt.width = 5.0f;
    titleArt.height = 5.0f;
    renderTitleArt(titleArt, titleArtSprite);

    x11.swapBuffers();
}

void display_border(int xres, int yres)
{
    // Draw a border around the window

    int b = 50;
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glColor4f(0.0f, 1.0f, 1.0f, 0.5f);
    glPushMatrix();
    glBegin(GL_TRIANGLE_STRIP);
        glVertex2i(0,      0);
        glVertex2i(0+b,    0+b);
        glVertex2i(0,      0+yres);
        glVertex2i(0+b,    0+yres-b);
        glVertex2i(xres,   0+yres);
        glVertex2i(xres-b, 0+yres-b);
        glVertex2i(xres,   0);
        glVertex2i(xres-b, b);
        glVertex2i(0,      0);
        glVertex2i(0+b,      0+b);
    glEnd();
    glPopMatrix();
    glDisable(GL_BLEND);
}

void ShieldPowerUp::init() {
    // Initial position
    pos[0] = 2550.0f;
    // y-position
    pos[1] = 100.0f + height;

    // Initial velocity
    // x-velocity
    vel[0] = -20.0f;
    vel[1] = 0.0f;

    // Set width and height of the power-up
    width = 10.0f;
    height = 10.0f;

    // power-up inactive initially
    active = false;
    activated = false;
    // Initialize to zero
    activationTime = 0;
}

void ShieldPowerUp::activate() {
    active = true;
    activationTime = time(nullptr);
}

bool ShieldPowerUp::isActivated() {
    if (active && (time(nullptr) - activationTime) < 10) {
        return true;
    } else {
        active = false;
        return false;
    }
}

bool Check4(Square burger, ShieldPowerUp shieldPowerUp) {
    int leftBurger = burger.pos[0] - burger.width;
    int rightBurger = burger.pos[0] + burger.width;
    int topBurger = burger.pos[1] - burger.height;
    int bottomBurger = burger.pos[1] + burger.height;

    int leftShield = shieldPowerUp.pos[0] - shieldPowerUp.width;
    int rightShield = shieldPowerUp.pos[0] + shieldPowerUp.width;
    int topShield = shieldPowerUp.pos[1] - shieldPowerUp.height;
    int bottomShield = shieldPowerUp.pos[1] + shieldPowerUp.height;

    int tolerance = 20;
    leftShield -= tolerance;
    rightShield += tolerance;
    topShield -= tolerance;
    bottomShield += tolerance;

    if (rightBurger < leftShield || rightShield < leftBurger)
        return false;

    if (bottomBurger < topShield || bottomShield < topBurger)
        return false;

    return true;
}

/*
void display_name(int x, int y)
{
    Rect r;
    r.bot = y;
    r.left = x;
    r.center = 0;
    ggprint8b(&r, 0, 0x00000000, "Mario");

}
*/

/*
int time_since_key_press(const bool get) {
    static int check_keys = 1;
    static int start_time;
    if (check_keys) {
        start_time = time(NULL);
        check_keys = 0;
    }
    if (get) {
        return time(NULL) - start_time;
    }
    return 0;
}
*/
