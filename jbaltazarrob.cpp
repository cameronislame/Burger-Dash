#include "jbaltazarrob.h"
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
        char line[100];
        while (fgets(line, 100, fpi) != NULL) {
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
    hp_pack.pos[0] = 1650.0;
    hp_pack.pos[1] = 350;
    hp_pack.width = 20.0;
    hp_pack.vel[0] = -5.0;
    hp_pack.height = 20.0;
    hp_pack.active = true;

}
