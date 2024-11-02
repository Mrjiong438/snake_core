#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAPSIZE 8

#define HITWALL

typedef struct {
	char x;
	char y;
} Position8;

extern char hitwall;
extern Position8 head;
extern Position8 tail;
extern char map[MAPSIZE][MAPSIZE];
extern int gtime;
extern unsigned char socre;
extern char lastgc,gc,input;


int initHeadPos(unsigned char x,unsigned char y,char ch);
int initHeadPos_P(Position8 pos,char ch);

void setpos(Position8 *obj,char x,char y);
void setpos_P(Position8 *obj,Position8 trgit);

void setchar(char x,char y,char ch);
void setchar_P(Position8 pos,char ch);

void genfood();

int setdirUP();
int setdirDOWN();
int setdirLEFT();
int setdirRIGHT();

Position8 pointmove(Position8 point);

int change();

