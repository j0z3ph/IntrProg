#include <stdio.h>
#include <dos.h>
#include <graphics.h>
#include <conio.h>

union REGS in, out;


int main() {
    int gd=DETECT, gm;
    char c = 0;
    int x1=100,y1=100,x2=20,y2=20;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    in.x.ax = 1;
    int86(0X33, &in, &out);
    setbkcolor(GREEN);
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    bar(100,100,20,20);
    outtextxy(100,100,"HOLA");
    while(c!=27) {
	if(kbhit()) {
	    c=getch();
	    if(c == 0) {
		c=getch();
		if(c==77) {
		    x1+=10;
		    x2+=10;
		}
		if(c==75) {
		    x1-=10;
		    x2-=10;
		}
		if(c==80) {
		    y1+=10;
		    y2+=10;
		}
		if(c==72) {
		    y1-=10;
		    y2-=10;
		}
		cleardevice();
		bar(x1,y1,x2,y2);
	    }
	}
    }
    closegraph();
    return 0;

}