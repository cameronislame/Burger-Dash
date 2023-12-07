#ifndef _JESUS_H_
#define _JESUS_H_
#include <string>
#include "cestes.h"
/**
 * Author:    Jesus Baltazar Robles
 * Created:   9/29/2023
 * 
 **/
/*Header files that will define level design and objects implementation*/
typedef double Flt;
extern float render_val_count;
class Level {
    public:
    unsigned char arr[52][304];
    unsigned char burgerArr[14][13];
    unsigned char titleArtArr[45][83];
    unsigned char fireArtArr[13][16];
    unsigned char trampArtArr[8][12];
    unsigned char knifeArtArr[5][13];
    unsigned char knifeBlockArtArr[18][32];
    unsigned char healthArtArr[9][9];
    unsigned char gameOverArtArr[35][58];
    unsigned char exitArtArr[29][13];
    std::string imageName;
    int nrows, ncols;
    int tilesize[2];
    Flt ftsz[2];
    Flt tile_base;
    Level();
    Level(int tileSizeX, int tileSizeY, std::string fileName);
    void removeCrLf(char *str);
};
//Create health powerup
extern Square hp_pack;
void init_hpPack();
void render_calls();
float total_render_function_calls();
#endif
