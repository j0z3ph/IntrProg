#include <stdio.h>
#include <dos.h>
#include <graphics.h>
#include <conio.h>

#define MOUSE 0X33
#define DOWN 80
#define UP 72
#define LEFT 75
#define RIGHT 77
#define BARSPACE 32

#define FPS 60
#define GRAVITY 5
#define VELOCITY 10
#define JUMP -200

#define true 1
#define false 0

union REGS in, out;


int main() {
    int gd=DETECT, gm;
    char c = 0;
    int x1,y1,x2,y2;
    int maxx, maxy;
    int right = false;
    int left = false;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    maxx = getmaxx();
    maxy = getmaxy();

    x1 = 0;
    x2 = 50;
    y1 = maxy-50;
    y2 = maxy;

    in.x.ax = 1;
    int86(MOUSE, &in, &out);
    setbkcolor(GREEN);
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    bar(x1,y1,x2,y2);
    //outtextxy(100,100,"HOLA");
    while(c!=27) {
	y1 += GRAVITY;
	y2 += GRAVITY;
	x1 += (right - left) * VELOCITY;
	x2 += (right - left) * VELOCITY;

	if(kbhit()) {
	    c=getch();
	    if(c == 0) {
		c=getch();
		if(c==RIGHT) {
		    right = true;
		}
		if(c==LEFT) {
		    left = true;
		}

		/*if(c==DOWN) {
		    y1+=10;
		    y2+=10;
		    if(y2 > maxy) {
			y2 = maxy;
			y1 = maxy-50;
		    }
		}
		if(c==UP) {
		    y1-=10;
		    y2-=10;
		    if(y1 < 0) {
			y1 = 0;
			y2 = 50;
		    }
		} */

	    } else if(c == BARSPACE) {
		y1 += JUMP;
		y2 += JUMP;
	    }
	} else {
	    left = false;
	    right = false;
	}

	if(x2 > maxx) {
	    x2 = maxx;
	    x1 = maxx - 50;
	}
	if(x1 < 0) {
	    x1 = 0;
	    x2 = 50;
	}
	if(y2 > maxy) {
	    y2 = maxy;
	    y1 = maxy-50;
	}
	if(y1 < 0) {
	    y1 = 0;
	    y2 = 50;
	}

	cleardevice();
	bar(x1,y1,x2,y2);
	delay(1000/FPS);
    }
    closegraph();
    return 0;

}