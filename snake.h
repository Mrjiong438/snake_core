#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAPSIZE 8
#define HITWALL
#define GAMEWIN 2
#define GAMEFAIL 1

typedef struct {
	char x;
	char y;
} Position8;

extern char hitwall;
extern Position8 head;
extern Position8 tail;
extern Position8 food;
extern char map[MAPSIZE][MAPSIZE];
extern int gtime;
extern unsigned char score;
extern char lastgc,gc,input;


extern int initHeadPos(unsigned char x,unsigned char y,char ch);
extern int initHeadPos_P(Position8 pos,char ch);

extern void setpos(Position8 *obj,char x,char y);
extern void setpos_P(Position8 *obj,Position8 trgit);

extern void setchar(char x,char y,char ch);
extern void setchar_P(Position8 pos,char ch);

extern void genfood();

extern int setdirUP();
extern int setdirDOWN();
extern int setdirLEFT();
extern int setdirRIGHT();

extern Position8 pointmove(Position8 point);

extern int change();
extern int resetgame();
