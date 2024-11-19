#include "snake.h"

Position8 head={0};
Position8 tail={0};
char map[MAPSIZE][MAPSIZE]={0};
char hitwall=1;
int gtime=0;
unsigned char score=0;
char lastgc=0,gc='N',input=0;

int change(){
	gtime++;
	Position8 newhead={0};
	Position8 newtail={0};

	newhead=pointmove(head);
	newtail=pointmove(tail);

	if (hitwall && (newhead.x<0 
		|| newhead.x>=MAPSIZE
		|| newhead.y<0
		|| newhead.y>=MAPSIZE))
		return 1;

	newhead.x=(newhead.x+MAPSIZE) % MAPSIZE;
	newhead.y=(newhead.y+MAPSIZE) % MAPSIZE;

	newtail.x=(newtail.x+MAPSIZE) % MAPSIZE;
	newtail.y=(newtail.y+MAPSIZE) % MAPSIZE;

	switch (map[newhead.x][newhead.y]){
		case '@':
			score++;
			setchar(newhead.x,newhead.y,map[head.x][head.y]);
			setpos_P(&head,newhead);
			if(score==MAPSIZE*MAPSIZE-1)
				return 2;
			genfood();
			break;
		case '^':
		case 'v':
		case '<':
		case '>':
			if (newhead.x!=tail.x || newhead.y!=tail.y)
				return 1;
			
			setchar(newhead.x,newhead.y,map[head.x][head.y]);
			setpos_P(&head,newhead);

			setpos_P(&tail,newtail);

			break;
		default :
			setchar(newhead.x,newhead.y,map[head.x][head.y]);
			setpos_P(&head,newhead);

			setchar(tail.x,tail.y,0);
			setpos_P(&tail,newtail);
	}

	return 0;
}

Position8 pointmove(Position8 point){
	Position8 result={0};

	switch (map[point.x][point.y]){
		case '^':
			setpos(&result,point.x,point.y-1);
			break;
		case 'v':
			setpos(&result,point.x,point.y+1);
			break;
		case '<':
			setpos(&result,point.x-1,point.y);
			break;
		case '>':
			setpos(&result,point.x+1,point.y);
			break;
	}

	return result;
}

int initHeadPos(unsigned char x,unsigned char y,char ch){
	setchar(x,y,ch);
	setpos(&head,x,y);
	setpos(&tail,x,y);
}
int initHeadPos_P(Position8 pos,char ch){
	setchar(pos.x,pos.y,ch);
	setpos(&head,pos.x,pos.y);
	setpos(&tail,pos.x,pos.y);
}

void setpos(Position8 *obj,char x,char y){
	obj->x=x;
	obj->y=y;
}

void setpos_P(Position8 *obj,Position8 trgit){
	obj->x=trgit.x;
	obj->y=trgit.y;
}

void setchar(char x,char y,char ch){
	map[x][y] = ch;
}

void setchar_P(Position8 pos,char ch){
	map[pos.x][pos.y] = ch;
}

int	setdirUP(){
	if (map[head.x][((head.y-1)+MAPSIZE)%MAPSIZE]=='v')
		return 1;
	setchar(head.x,head.y,'^');
	return 0;
}
int setdirDOWN(){
	if (map[head.x][(head.y+1)%MAPSIZE]=='^')
		return 1;
	setchar(head.x,head.y,'v');
	return 0;
}
int setdirLEFT(){
	if (map[((head.x-1)+MAPSIZE)%MAPSIZE][head.y]=='>')
		return 1;
	setchar(head.x,head.y,'<');
	return 0;
}
int setdirRIGHT(){
	if (map[((head.x+1)+MAPSIZE)%MAPSIZE][head.y]=='<')
		return 1;
	setchar(head.x,head.y,'>');
	return 0;
}

void genfood(){
	int x=0;
	int y=0;
	while(1){
		x=rand() % MAPSIZE;
		y=rand() % MAPSIZE;
		if (map[x][y] == 0)
			break;
	}
	setchar(x,y,'@');
}
