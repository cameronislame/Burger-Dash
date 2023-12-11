/***************************************************
 * Copyright    : 2023 Cameron McDaniel
 * File Name    : cmcdaniel.cpp
 * Description   : individual project source file
 ***************************************************/


#include "fonts.h"
#include "cmcdaniel.h"
#include "jbaltazarrob.h"
#include <iostream>
#include <GL/glx.h>
#include <time.h>

void display_credits(int xres, int yres) 
{
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glColor4f(0.0f, 0.0f, 0.0f, 0.5f);
    glPushMatrix();
    glBegin(GL_QUADS);
    glVertex2i(0,      0);
    glVertex2i(0,      0+yres);
    glVertex2i(xres,   0+yres);
    glVertex2i(xres,   0);


    glEnd();
    glPopMatrix();
    glDisable(GL_BLEND);

    Rect r;
    r.bot = yres * 2 / 3;
    r.left = xres / 2;
    r.center = 100;
    ggprint16(&r, 16, 0x00ffff00, "CREDITS:");
    ggprint8b(&r, 16, 0x00ffff00, "Cameron McDaniel");
    ggprint8b(&r, 16, 0x00ffff00, "Conner Estes");
    ggprint8b(&r, 16, 0x00ffff00, "Jesus Baltazar");
    ggprint8b(&r, 16, 0x00ffff00, "Mario Jimenez");

}

int total_running_time(time_t begin)
{
    return time(NULL) - begin;    
}

int time_since_mouse_move(const bool get)
{
    static time_t mouse_timer;
    if(get) {
        time(&mouse_timer);
    }
    return time(NULL) - mouse_timer;
}

void renderVictoryArt(Square burger, Level lev) 
{
    int tx = lev.tilesize[0];
    int ty = lev.tilesize[1];
    Flt dd = lev.ftsz[0];
    Flt offy = lev.tile_base;

    for (int j = 0; j < lev.ncols; j++) {
        for (int i = 0; i < lev.nrows; i++) {
            int row = lev.nrows - 1 - i; 
            int col = j;
            if (lev.victoryArtArr[row][col] == '.') {
                glColor3ub(55, 28, 59); // Converted from hex 371C3B
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }

            if (lev.victoryArtArr[row][col] == '+') {
                glColor3ub(204, 76, 80); // Converted from hex CC4C50
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }

            if (lev.victoryArtArr[row][col] == '@') {
                glColor3ub(207, 125, 122); // Converted from hex CF7D7A
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }

            if (lev.victoryArtArr[row][col] == '#') {
                glColor3ub(159, 44, 92); // Converted from hex 9F2C5C
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }

            if (lev.victoryArtArr[row][col] == '$') {
                glColor3ub(208, 80, 134); // Converted from hex D05086
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }

            if (lev.victoryArtArr[row][col] == '%') {
                glColor3ub(101, 54, 100); // Converted from hex 653664
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }

            if (lev.victoryArtArr[row][col] == '&') {
                glColor3ub(165, 92, 165); // Converted from hex A55CA5
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }

            if (lev.victoryArtArr[row][col] == '*') {
                glColor3ub(165, 112, 58); // Converted from hex A5703A
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }

            if (lev.victoryArtArr[row][col] == '=') {
                glColor3ub(186, 134, 80); // Converted from hex BA8650
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }

            if (lev.victoryArtArr[row][col] == '-') {
                glColor3ub(212, 208, 137); // Converted from hex D4D089
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }

            if (lev.victoryArtArr[row][col] == ';') {
                glColor3ub(182, 176, 54); // Converted from hex B6B036
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }

            if (lev.victoryArtArr[row][col] == '>') {
                glColor3ub(143, 90, 36); // Converted from hex 8F5A24
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }

            if (lev.victoryArtArr[row][col] == ',') {
                glColor3ub(203, 55, 55); // Converted from hex CB3737
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }

            if (lev.victoryArtArr[row][col] == '\'') {
                glColor3ub(172, 50, 50); // Converted from hex AC3232
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }

            if (lev.victoryArtArr[row][col] == ')') {
                glColor3ub(95, 55, 36); // Converted from hex 5F3724
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }

            if (lev.victoryArtArr[row][col] == '!') {
                glColor3ub(78, 134, 40); // Converted from hex 4E8628
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }

            if (lev.victoryArtArr[row][col] == '~') {
                glColor3ub(103, 177, 52); // Converted from hex 67B134
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
        }
    }
}

void renderShieldArt(Square burger, Level lev) 
{
    int tx = lev.tilesize[0];
    int ty = lev.tilesize[1];
    Flt dd = lev.ftsz[0];
    Flt offy = lev.tile_base;

    for (int j = 0; j < lev.ncols; j++) {
        for (int i = 0; i < lev.nrows; i++) {
            int row = lev.nrows - 1 - i; 
            int col = j;
            if (lev.shieldArtArr[row][col] == '.') {
                glColor3ub(0, 0, 0);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.shieldArtArr[row][col] == '+') {
                glColor3ub(255, 255, 255);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.shieldArtArr[row][col] == '@') {
                glColor3ub(95, 205, 228); // Converted from hex 5FCDE4
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.shieldArtArr[row][col] == '#') {
                glColor3ub(80, 142, 184); // Converted from hex 508EB8
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.shieldArtArr[row][col] == '$') {
                glColor3ub(155, 173, 183); // Converted from hex 9BADB7
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
        }
    }
}

void renderHealth(Square burger, Level lev) 
{
    int tx = lev.tilesize[0];
    int ty = lev.tilesize[1];
    Flt dd = lev.ftsz[0];
    Flt offy = lev.tile_base;

    for (int j = 0; j < lev.ncols; j++) {
        for (int i = 0; i < lev.nrows; i++) {
            int row = lev.nrows - 1 - i; 
            int col = j;
            if (lev.healthArtArr[row][col] == '.') {
                glColor3ub(0, 0, 0);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.healthArtArr[row][col] == '+') {
                glColor3ub(255, 255, 255);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.healthArtArr[row][col] == '@') {
                glColor3ub(217, 87, 99);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.healthArtArr[row][col] == '#') {
                glColor3ub(172, 50, 50);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.healthArtArr[row][col] == '$') {
                glColor3ub(155, 173, 183);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
        }
    }
}

void renderKnifeBlock(Square burger, Level lev) 
{
    int tx = lev.tilesize[0];
    int ty = lev.tilesize[1];
    Flt dd = lev.ftsz[0];
    Flt offy = lev.tile_base;

    for (int j = 0; j < lev.ncols; j++) {
        for (int i = 0; i < lev.nrows; i++) {
            int row = lev.nrows - 1 - i; 
            int col = j;
            if (lev.knifeBlockArtArr[row][col] == '.') {
                glColor3ub(0, 0, 0);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.knifeBlockArtArr[row][col] == '+') {
                glColor3ub(134, 134, 134); 
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.knifeBlockArtArr[row][col] == '@') {
                glColor3ub(105, 106, 106);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.knifeBlockArtArr[row][col] == '#') {
                glColor3ub(91, 9, 9); 
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.knifeBlockArtArr[row][col] == '$') {
                glColor3ub(164, 17, 17); 
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.knifeBlockArtArr[row][col] == '%') {
                glColor3ub(102, 57, 49); 
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.knifeBlockArtArr[row][col] == '&') {
                glColor3ub(55, 31, 27); 
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.knifeBlockArtArr[row][col] == '*') {
                glColor3ub(138, 77, 66);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
        }
    }
}

void renderTramp(Square burger, Level lev) 
{
    int tx = lev.tilesize[0];
    int ty = lev.tilesize[1];
    Flt dd = lev.ftsz[0];
    Flt offy = lev.tile_base;

    for (int j = 0; j < lev.ncols; j++) {
        for (int i = 0; i < lev.nrows; i++) {
            int row = lev.nrows - 1 - i; 
            int col = j;
            if (lev.trampArtArr[row][col] == '.') {
                glColor3ub(0, 0, 0);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.trampArtArr[row][col] == '+') {
                glColor3ub(91, 110, 225); 
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.trampArtArr[row][col] == '@') {
                glColor3ub(56, 56, 56); 
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.trampArtArr[row][col] == '#') {
                glColor3ub(73, 73, 73); 
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.trampArtArr[row][col] == '$') {
                glColor3ub(58, 73, 164); 
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
        }
    }
}

void renderKnife(Square burger, Level lev) 
{
    int tx = lev.tilesize[0];
    int ty = lev.tilesize[1];
    Flt dd = lev.ftsz[0];
    Flt offy = lev.tile_base;

    for (int j = 0; j < lev.ncols; j++) {
        for (int i = 0; i < lev.nrows; i++) {
            int row = lev.nrows - 1 - i; 
            int col = j;
            if (lev.knifeArtArr[row][col] == '.') {
                glColor3ub(0, 0, 0);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.knifeArtArr[row][col] == '+') {
                glColor3ub(134, 134, 134); 
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.knifeArtArr[row][col] == '@') {
                glColor3ub(105, 106, 106); 
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.knifeArtArr[row][col] == '#') {
                glColor3ub(91, 9, 9); 
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.knifeArtArr[row][col] == '$') {
                glColor3ub(164, 17, 17);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
        }
    }
}

void renderFire(Square burger, Level lev) 
{
    int tx = lev.tilesize[0];
    int ty = lev.tilesize[1];
    Flt dd = lev.ftsz[0];
    Flt offy = lev.tile_base;

    for (int j = 0; j < lev.ncols; j++) {
        for (int i = 0; i < lev.nrows; i++) {
            int row = lev.nrows - 1 - i; // Invert row index
            int col = j;
            if (lev.fireArtArr[row][col] == '.') {
                glColor3ub(0, 0, 0);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.fireArtArr[row][col] == '+') {
                glColor3ub(225, 79, 54);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.fireArtArr[row][col] == '@') {
                glColor3ub(255, 124, 55);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.fireArtArr[row][col] == '#') {
                glColor3ub(253, 178, 63);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.fireArtArr[row][col] == '$') {
                glColor3ub(245, 226, 132);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
        }
    }
}


void renderGameOverArt(Square burger, Level lev) 
{
    int tx = lev.tilesize[0];
    int ty = lev.tilesize[1];
    Flt dd = lev.ftsz[0];
    Flt offy = lev.tile_base;

    for (int j = 0; j < lev.ncols; j++) {
        for (int i = 0; i < lev.nrows; i++) {
            int row = lev.nrows - 1 - i; // Invert row index
            int col = j;
            if (lev.gameOverArtArr[row][col] == '.') {
                glColor3ub(55, 28, 29); // Converted from hex 371C3B
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.gameOverArtArr[row][col] == '+') {
                glColor3ub(204, 76, 80); // Converted from hex CC4C50
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.gameOverArtArr[row][col] == '@') {
                glColor3ub(207, 125, 122); // Converted from hex CF7D7A
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.gameOverArtArr[row][col] == '#') {
                glColor3ub(159, 44, 92); // Converted from hex 9F2C5C
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.gameOverArtArr[row][col] == '$') {
                glColor3ub(208, 80, 134); // Converted from hex D05086
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.gameOverArtArr[row][col] == '%') {
                glColor3ub(101, 54, 100); // Converted from hex 653664
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.gameOverArtArr[row][col] == '&') {
                glColor3ub(165, 92, 165); // Converted from hex A55CA5
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }

        }
    }
}

void renderExitArt(Square burger, Level lev) 
{
    int tx = lev.tilesize[0];
    int ty = lev.tilesize[1];
    Flt dd = lev.ftsz[0];
    Flt offy = lev.tile_base;

    for (int j = 0; j < lev.ncols; j++) {
        for (int i = 0; i < lev.nrows; i++) {
            int row = lev.nrows - 1 - i; // Invert row index
            int col = j;
            if (lev.exitArtArr[row][col] == '.') {
                glColor3ub(0, 0, 0);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.exitArtArr[row][col] == '+') {
                glColor3ub(138, 77, 66); // Converted from hex 8A4D42
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.exitArtArr[row][col] == '@') {
                glColor3ub(160, 86, 73); // Converted from hex A05649
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.exitArtArr[row][col] == '#') {
                glColor3ub(102, 57, 49); // Converted from hex 663931
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.exitArtArr[row][col] == '$') {
                glColor3ub(112, 63, 54); // Converted from hex 703F36
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.exitArtArr[row][col] == '%') {
                glColor3ub(255, 255, 255); // Converted from hex FFFFFF
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.exitArtArr[row][col] == '&') {
                glColor3ub(212, 208, 137); // Converted from hex D4D089
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
        }
    }
}

void renderTitleArt(Square burger, Level lev) 
{
    int tx = lev.tilesize[0];
    int ty = lev.tilesize[1];
    Flt dd = lev.ftsz[0];
    Flt offy = lev.tile_base;

    for (int j = 0; j < lev.ncols; j++) {
        for (int i = 0; i < lev.nrows; i++) {
            int row = lev.nrows - 1 - i; // Invert row index
            int col = j;
            if (lev.titleArtArr[row][col] == '.') {
                glColor3ub(55, 28, 29);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.titleArtArr[row][col] == '+') {
                glColor3ub(204, 76, 80);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.titleArtArr[row][col] == '@') {
                glColor3ub(207, 125, 122);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.titleArtArr[row][col] == '#') {
                glColor3ub(159, 44, 92);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.titleArtArr[row][col] == '$') {
                glColor3ub(208, 80, 134);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.titleArtArr[row][col] == '%') {
                glColor3ub(101, 54, 100);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.titleArtArr[row][col] == '&') {
                glColor3ub(165, 92, 165);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.titleArtArr[row][col] == '*') {
                glColor3ub(165, 112, 58);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.titleArtArr[row][col] == '=') {
                glColor3ub(186, 134, 80);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.titleArtArr[row][col] == '-') {
                glColor3ub(212, 208, 137);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.titleArtArr[row][col] == ';') {
                glColor3ub(182, 176, 54);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.titleArtArr[row][col] == '>') {
                glColor3ub(143, 90, 36);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.titleArtArr[row][col] == ',') {
                glColor3ub(203, 55, 55);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.titleArtArr[row][col] == '\'') {
                glColor3ub(172, 50, 50);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.titleArtArr[row][col] == ')') {
                glColor3ub(95, 55, 36);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.titleArtArr[row][col] == '!') {
                glColor3ub(78, 134, 40);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.titleArtArr[row][col] == '~') {
                glColor3ub(103, 177, 52);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
        }
    }
}


void renderBurger(Square burger, Level lev, Global gl, bool shieldState) 
{
    int tx = lev.tilesize[0];
    int ty = lev.tilesize[1];
    Flt dd = lev.ftsz[0];
    Flt offy = lev.tile_base;

    for (int j = 0; j < lev.ncols; j++) {
        for (int i = 0; i < lev.nrows; i++) {
            int row = lev.nrows - 1 - i; // Invert row index
            int col = j;

            if (lev.burgerArr[row][col] == '.') {
                if (shieldState) {
                    glColor3ub(95, 205, 228);
                    renderSquare(burger, j, i, dd, offy, tx, ty);    
                } else {
                    glColor3ub(0, 0, 0);
                    renderSquare(burger, j, i, dd, offy, tx, ty);
                }
            }
            if (lev.burgerArr[row][col] == '+') {
                glColor3ub(165,112,58);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.burgerArr[row][col] == '@') {
                glColor3ub(186,134,80);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.burgerArr[row][col] == '#') {
                glColor3ub(212,208,137);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.burgerArr[row][col] == '$') {
                glColor3ub(182,176,54);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.burgerArr[row][col] == '%') {
                glColor3ub(143,90,36);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.burgerArr[row][col] == '&') {
                glColor3ub(203,55,55);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.burgerArr[row][col] == '*') {
                glColor3ub(172,50,50);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.burgerArr[row][col] == '=') {
                glColor3ub(95,55,36);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.burgerArr[row][col] == '-') {
                glColor3ub(78,134,40);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
            if (lev.burgerArr[row][col] == ';') {
                glColor3ub(103,177,52);
                renderSquare(burger, j, i, dd, offy, tx, ty);
            }
        }
    }
}


void renderSquare(Square burger, int j, int i, Flt dd, Flt offy, int tx, int ty) 
{
    glPushMatrix();
    glTranslated((Flt)j * dd + burger.pos[0], (Flt)i * ty + offy + burger.pos[1], 0);
    glBegin(GL_QUADS);
    glVertex2f(-burger.width / 2.0, -burger.height / 2.0);  // Adjusted for centering
    glVertex2f(-burger.width / 2.0, burger.height / 2.0);
    glVertex2f(burger.width / 2.0, burger.height / 2.0);
    glVertex2f(burger.width / 2.0, -burger.height / 2.0);
    glEnd();
    glPopMatrix();
}



void renderLevel(Level lev, Global gl, double* camera) 
{
    int tx = lev.tilesize[0];
    int ty = lev.tilesize[1];
    Flt dd = lev.ftsz[0];
    Flt offy = lev.tile_base;
    int ncols_to_render = gl.xres / lev.tilesize[0] + 2;
    int col = (int)(camera[0] / dd);
    col = col % lev.ncols;
    //Partial tile offset must be determined here.
    //The leftmost tile might be partially off-screen.
    //cdd: camera position in terms of tiles.
    Flt cdd = camera[0] / dd;
    //flo: just the integer portion
    Flt flo = floor(cdd);
    //dec: just the decimal portion
    Flt dec = (cdd - flo);
    //offx: the offset to the left of the screen to start drawing tiles
    Flt offx = -dec * dd;
    //Log("gl.camera[0]: %lf   offx: %lf\n",gl.camera[0],offx);
    for (int j=0; j<ncols_to_render; j++) {
        int row = lev.nrows-1;
        for (int i=0; i<lev.nrows; i++) {
            if (lev.arr[row][col] == ' ') {
                glColor3ub(75, 105, 47);
                glPushMatrix();
                glTranslated((Flt)j*dd+offx, (Flt)i*lev.ftsz[1]+offy, 0);
                glBegin(GL_QUADS);
                glVertex2i( 0,  0);
                glVertex2i( 0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx,  0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == '.') {
                glColor3ub(0, 0, 0);
                glPushMatrix();
                glTranslated((Flt)j*dd+offx, (Flt)i*lev.ftsz[1]+offy, 0);
                glBegin(GL_QUADS);
                glVertex2i( 0,  0);
                glVertex2i( 0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx,  0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == '+') {
                glColor3ub(138, 77, 66);
                glPushMatrix();
                glTranslated((Flt)j*dd+offx, (Flt)i*lev.ftsz[1]+offy, 0);
                glBegin(GL_QUADS);
                glVertex2i( 0,  0);
                glVertex2i( 0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx,  0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == '@') {
                glColor3ub(102, 57, 49);
                glPushMatrix();
                glTranslated((Flt)j*dd+offx, (Flt)i*lev.ftsz[1]+offy, 0);
                glBegin(GL_QUADS);
                glVertex2i( 0,  0);
                glVertex2i( 0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx,  0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == '#') {
                glColor3ub(84, 47, 41);
                glPushMatrix();
                glTranslated((Flt)j*dd+offx, (Flt)i*lev.ftsz[1]+offy, 0);
                glBegin(GL_QUADS);
                glVertex2i( 0,  0);
                glVertex2i( 0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx,  0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == '$') {
                glColor3ub(129, 92, 86);
                glPushMatrix();
                glTranslated((Flt)j*dd+offx, (Flt)i*lev.ftsz[1]+offy, 0);
                glBegin(GL_QUADS);
                glVertex2i( 0,  0);
                glVertex2i( 0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx,  0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == '%') {
                glColor3ub(156, 151, 48);
                glPushMatrix();
                glTranslated((Flt)j*dd+offx, (Flt)i*lev.ftsz[1]+offy, 0);
                glBegin(GL_QUADS);
                glVertex2i( 0,  0);
                glVertex2i( 0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx,  0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == '&') {
                glColor3ub(182, 176, 54);
                glPushMatrix();
                glTranslated((Flt)j*dd+offx, (Flt)i*lev.ftsz[1]+offy, 0);
                glBegin(GL_QUADS);
                glVertex2i( 0,  0);
                glVertex2i( 0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx,  0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == '*') {
                glColor3ub(164, 17, 17);
                glPushMatrix();
                glTranslated((Flt)j*dd+offx, (Flt)i*lev.ftsz[1]+offy, 0);
                glBegin(GL_QUADS);
                glVertex2i( 0,  0);
                glVertex2i( 0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx,  0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == '=') {
                glColor3ub(40, 56, 26);
                glPushMatrix();
                glTranslated((Flt)j*dd+offx, (Flt)i*lev.ftsz[1]+offy, 0);
                glBegin(GL_QUADS);
                glVertex2i( 0,  0);
                glVertex2i( 0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx,  0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == '-') {
                glColor3ub(22, 31, 14);
                glPushMatrix();
                glTranslated((Flt)j*dd+offx, (Flt)i*lev.ftsz[1]+offy, 0);
                glBegin(GL_QUADS);
                glVertex2i( 0,  0);
                glVertex2i( 0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx,  0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == ';') {
                glColor3ub(91, 9, 9);
                glPushMatrix();
                glTranslated((Flt)j*dd+offx, (Flt)i*lev.ftsz[1]+offy, 0);
                glBegin(GL_QUADS);
                glVertex2i( 0,  0);
                glVertex2i( 0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx,  0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == '>') {
                glColor3ub(162, 163, 146);
                glPushMatrix();
                glTranslated((Flt)j*dd+offx, (Flt)i*lev.ftsz[1]+offy, 0);
                glBegin(GL_QUADS);
                glVertex2i( 0,  0);
                glVertex2i( 0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx,  0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == ',') {
                glColor3ub(224, 225, 202);
                glPushMatrix();
                glTranslated((Flt)j*dd+offx, (Flt)i*lev.ftsz[1]+offy, 0);
                glBegin(GL_QUADS);
                glVertex2i( 0,  0);
                glVertex2i( 0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx,  0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == '\'') {
                glColor3ub(105, 106, 106);
                glPushMatrix();
                glTranslated((Flt)j*dd+offx, (Flt)i*lev.ftsz[1]+offy, 0);
                glBegin(GL_QUADS);
                glVertex2i( 0,  0);
                glVertex2i( 0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx,  0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == ')') {
                glColor3ub(134, 134, 134);
                glPushMatrix();
                glTranslated((Flt)j*dd+offx, (Flt)i*lev.ftsz[1]+offy, 0);
                glBegin(GL_QUADS);
                glVertex2i( 0,  0);
                glVertex2i( 0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx,  0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == '!') {
                glColor3ub(63, 65, 65);
                glPushMatrix();
                glTranslated((Flt)j*dd+offx, (Flt)i*lev.ftsz[1]+offy, 0);
                glBegin(GL_QUADS);
                glVertex2i( 0,  0);
                glVertex2i( 0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx,  0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == '~') {
                glColor3ub(84, 86, 86);
                glPushMatrix();
                glTranslated((Flt)j*dd+offx, (Flt)i*lev.ftsz[1]+offy, 0);
                glBegin(GL_QUADS);
                glVertex2i( 0,  0);
                glVertex2i( 0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx,  0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == '{') {
                glColor3ub(50, 50, 50);
                glPushMatrix();
                glTranslated((Flt)j*dd+offx, (Flt)i*lev.ftsz[1]+offy, 0);
                glBegin(GL_QUADS);
                glVertex2i( 0,  0);
                glVertex2i( 0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx,  0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == ']') {
                glColor3ub(88, 89, 89);
                glPushMatrix();
                glTranslated((Flt)j*dd+offx, (Flt)i*lev.ftsz[1]+offy, 0);
                glBegin(GL_QUADS);
                glVertex2i( 0,  0);
                glVertex2i( 0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx,  0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == '^') {
                glColor3ub(48, 48, 48);
                glPushMatrix();
                glTranslated((Flt)j*dd+offx, (Flt)i*lev.ftsz[1]+offy, 0);
                glBegin(GL_QUADS);
                glVertex2i( 0,  0);
                glVertex2i( 0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx,  0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == '/') {
                glColor3ub(171, 173, 157);
                glPushMatrix();
                glTranslated((Flt)j*dd+offx, (Flt)i*lev.ftsz[1]+offy, 0);
                glBegin(GL_QUADS);
                glVertex2i( 0,  0);
                glVertex2i( 0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx,  0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == '(') {
                glColor3ub(125, 125, 125);
                glPushMatrix();
                glTranslated((Flt)j*dd+offx, (Flt)i*lev.ftsz[1]+offy, 0);
                glBegin(GL_QUADS);
                glVertex2i( 0,  0);
                glVertex2i( 0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx,  0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == '_') {
                glColor3ub(73, 73, 73);
                glPushMatrix();
                glTranslated((Flt)j*dd+offx, (Flt)i*lev.ftsz[1]+offy, 0);
                glBegin(GL_QUADS);
                glVertex2i( 0,  0);
                glVertex2i( 0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx,  0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == ':') {
                glColor3ub(251, 249, 222);
                glPushMatrix();
                glTranslated((Flt)j*dd+offx, (Flt)i*lev.ftsz[1]+offy, 0);
                glBegin(GL_QUADS);
                glVertex2i( 0,  0);
                glVertex2i( 0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx,  0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == '<') {
                glColor3ub(43, 43, 39);
                glPushMatrix();
                glTranslated((Flt)j*dd+offx, (Flt)i*lev.ftsz[1]+offy, 0);
                glBegin(GL_QUADS);
                glVertex2i( 0,  0);
                glVertex2i( 0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx,  0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == '[') {
                glColor3ub(255, 255, 255);
                glPushMatrix();
                glTranslated((Flt)j*dd+offx, (Flt)i*lev.ftsz[1]+offy, 0);
                glBegin(GL_QUADS);
                glVertex2i( 0,  0);
                glVertex2i( 0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx,  0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == '}') {
                glColor3ub(181, 193, 170);
                glPushMatrix();
                glTranslated((Flt)j*dd+offx, (Flt)i*lev.ftsz[1]+offy, 0);
                glBegin(GL_QUADS);
                glVertex2i( 0,  0);
                glVertex2i( 0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx,  0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == '|') {
                glColor3ub(225, 230, 220);
                glPushMatrix();
                glTranslated((Flt)j*dd+offx, (Flt)i*lev.ftsz[1]+offy, 0);
                glBegin(GL_QUADS);
                glVertex2i( 0,  0);
                glVertex2i( 0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx,  0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == '1') {
                glColor3ub(119, 121, 109);
                glPushMatrix();
                glTranslated((Flt)j*dd+offx, (Flt)i*lev.ftsz[1]+offy, 0);
                glBegin(GL_QUADS);
                glVertex2i( 0,  0);
                glVertex2i( 0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx,  0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == '2') {
                glColor3ub(137, 138, 124);
                glPushMatrix();
                glTranslated((Flt)j*dd+offx, (Flt)i*lev.ftsz[1]+offy, 0);
                glBegin(GL_QUADS);
                glVertex2i( 0,  0);
                glVertex2i( 0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx,  0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == '3') {
                glColor3ub(220, 220, 220);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == '4') {
                glColor3ub(203, 203, 185);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == '5') {
                glColor3ub(117, 117, 117);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == '6') {
                glColor3ub(184, 185, 166);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == '7') {
                glColor3ub(98, 98, 98);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == '8') {
                glColor3ub(147, 147, 147);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == '9') {
                glColor3ub(78, 186, 165);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == '0') {
                glColor3ub(182, 182, 182);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == 'a') {
                glColor3ub(143, 90, 36);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == 'b') {
                glColor3ub(186, 134, 80);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == 'c') {
                glColor3ub(39, 39, 39);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == 'd') {
                glColor3ub(21, 61, 52);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == 'e') {
                glColor3ub(21, 21, 21);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == 'f') {
                glColor3ub(56, 56, 56);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == 'g') {
                glColor3ub(95, 95, 95);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == 'h') {
                glColor3ub(151, 151, 151);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == 'i') {
                glColor3ub(213, 213, 213);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == 'j') {
                glColor3ub(36, 95, 83);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == 'k') {
                glColor3ub(180, 180, 180);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == 'l') {
                glColor3ub(120, 120, 108);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == 'm') {
                glColor3ub(65, 65, 65);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == 'n') {
                glColor3ub(59, 143, 127);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == 'o') {
                glColor3ub(242, 242, 233);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == 'p') {
                glColor3ub(249, 250, 246);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == 'q') {
                glColor3ub(112, 63, 54);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == 'r') {
                glColor3ub(23, 23, 21);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == 's') {
                glColor3ub(147, 105, 62);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == 't') {
                glColor3ub(74, 42, 36);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == 'u') {
                glColor3ub(60, 34, 29);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == 'v') {
                glColor3ub(160, 86, 73);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == 'w') {
                glColor3ub(134, 133, 119);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == 'x') {
                glColor3ub(141, 142, 129);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == 'y') {
                glColor3ub(207, 207, 207);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == 'z') {
                glColor3ub(26, 26, 26);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == 'A') {
                glColor3ub(233, 233, 233);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == 'B') {
                glColor3ub(78, 60, 42);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == 'C') {
                glColor3ub(111, 111, 111);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == 'D') {
                glColor3ub(134, 104, 73);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == 'E') {
                glColor3ub(36, 36, 32);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == 'F') {
                glColor3ub(64, 64, 60);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == 'G') {
                glColor3ub(121, 94, 66);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == 'H') {
                glColor3ub(78, 78, 73);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == 'I') {
                glColor3ub(147, 115, 82);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == 'J') {
                glColor3ub(14, 14, 14);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            if (lev.arr[row][col] == 'K') {
                glColor3ub(60, 60, 60);
                glPushMatrix();
                glTranslated((Flt)j * dd + offx, (Flt)i * lev.ftsz[1] + offy, 0);
                glBegin(GL_QUADS);
                glVertex2i(0, 0);
                glVertex2i(0, ty);
                glVertex2i(tx, ty);
                glVertex2i(tx, 0);
                glEnd();
                glPopMatrix();
            }
            --row;
        }
        col = (col+1) % lev.ncols;
    }
    glColor3f(1.0, 1.0, 0.1);
    glPushMatrix();
}
