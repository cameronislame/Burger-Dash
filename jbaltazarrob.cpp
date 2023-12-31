#include "jbaltazarrob.h"
#include <GL/glx.h>
#include "cmcdaniel.h"
#include "cestes.h"
#include <iostream>
#include <cstddef>
#include <cstring>
#include <cstdio>
#include <string>
/**
 * Auhtor: Jesus Baltazar Robles
 * Date: 9/29/2023
 */
/*LEVEL CLASS INITIALIZATION
 * CODE COMES FROM GORDON WALK2*/
float render_val_count = 0;
Square hp_pack;
Square knife1;
Square knife2;
Square knife3;
Level::Level() {
    //Log("Level constructor\n");
    tilesize[0] = 8;
    tilesize[1] = 8;
    ftsz[0] = (Flt)tilesize[0];
    ftsz[1] = (Flt)tilesize[1];
    tile_base = 0.0;
    imageName = "final-kitchen.xpm";
    //read level
    FILE *fpi = fopen(imageName.c_str(), "r");
    if (fpi) {
        nrows=0;
        char line[1000];
        while (fgets(line, 1000, fpi) != NULL) {
            removeCrLf(line);
            int slen = strlen(line);
            ncols = slen;
            //Log("line: %s\n", line);
            for (int j=0; j<slen; j++) {
                arr[nrows][j] = line[j];
            }
            ++nrows;
        }
        fclose(fpi);
        //printf("nrows of background data: %i\n", nrows);
    }
    /*
    for (int i=0; i<nrows; i++) {
        for (int j=0; j<ncols; j++) {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    } */
}

Level::Level(int tileSizeX, int tileSizeY, std::string fileName) {
    
    tilesize[0] = tileSizeX;
    tilesize[1] = tileSizeY;
    ftsz[0] = (Flt)tilesize[0];
    ftsz[1] = (Flt)tilesize[1];
    tile_base = 0.0;
    imageName = fileName;
    //read level
    FILE *fpi = fopen(imageName.c_str(), "r");
    if (fpi) {
        nrows=0;
        char line[120];
        while (fgets(line, 120, fpi) != NULL) {
            removeCrLf(line);
            int slen = strlen(line);
            ncols = slen;
            //Log("line: %s\n", line);
            for (int j=0; j<slen; j++) {
                if (imageName == "burger.xpm")
                    burgerArr[nrows][j] = line[j];
                if (imageName == "titleSprite.xpm")
                    titleArtArr[nrows][j] = line[j];
                if (imageName == "knife.xpm")
                    knifeArtArr[nrows][j] = line[j];
                if (imageName == "fire.xpm")
                    fireArtArr[nrows][j] = line[j];
                if (imageName == "trampoline.xpm")
                    trampArtArr[nrows][j] = line[j];
                if (imageName == "knifeBlock.xpm")
                    knifeBlockArtArr[nrows][j] = line[j];
                if (imageName == "health.xpm")
                    healthArtArr[nrows][j] = line[j];
                if (imageName == "gameOver.xpm")
                    gameOverArtArr[nrows][j] = line[j];
                if (imageName == "exit.xpm")
                    exitArtArr[nrows][j] = line[j];
                if (imageName == "shield.xpm")
                    shieldArtArr[nrows][j] = line[j];
                if (imageName == "victory.xpm")
                    victoryArtArr[nrows][j] = line[j];
            }
            ++nrows;
        }
        fclose(fpi);
        //printf("nrows of background data: %i\n", nrows);
    }
}

void Level::removeCrLf(char *str) {
    //remove carriage return and linefeed from a Cstring
    char *p = str;
    while (*p) {
        if (*p == 10 || *p == 13) {
            *p = '\0';
            break;
        }
        ++p;
    }
}
void render_calls(){
    render_val_count = render_val_count + 1;
}
float total_render_function_calls(){
    return render_val_count;
}
void init_hpPack()
{
    hp_pack.pos[0] = 1635.0;
    hp_pack.pos[1] = 350;
    hp_pack.width = 20.0;
    hp_pack.vel[0] = lvlspeed;
    hp_pack.height = 20.0;
    hp_pack.active = true;

}
void initObj()
{
    //initialize knives in the air
    knife1.pos[0] = gl.xres + burger.pos[0];
    knife1.pos[1] = gl.yres / 4.0;
    knife1.width = 13.0;
    knife1.vel[0] = -35;
    knife1.height = 5.0;
    knife1.active = true;


    knife2.pos[0] = gl.xres + burger.pos[0] + 40;
    knife2.pos[1] = (gl.yres / 4.0) + 20.0;
    knife2.width = 13.0;
    knife2.vel[0] = -35;
    knife2.height = 5.0;
    knife2.active = true;

    knife3.pos[0] = gl.xres + burger.pos[0] + 40;
    knife3.pos[1] = (gl.yres / 4.0) - 20.0;
    knife3.width = 13.0;
    knife3.vel[0] = -35;
    knife3.height = 5.0;
    knife3.active = true;
    // Initialize shield power-up
}
