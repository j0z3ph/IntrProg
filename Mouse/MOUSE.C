#include<stdio.h>
#include<dos.h>
#include<conio.h>

#define MOUSE 0X33
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

union REGS in, out;

int mouse_available() {
    in.x.ax = 0;
    int86(MOUSE, &in, &out);
    return out.x.ax;
}

void mouse_show() {
    in.x.ax = 1;
    int86(MOUSE, &in, &out);
}

void mouse_data(int *x, int *y, int *b) {
    in.x.ax = 3;
    int86(MOUSE, &in, &out);
    *x = out.x.cx;
    *y = out.x.dx;
    *b = out.x.bx;
}

int main() {
    int x = 1,y = 1,b;
    char c=0;
    clrscr();
    _setcursortype(_SOLIDCURSOR);
    textcolor(RED);
    textbackground(WHITE);
    if(mouse_available() == 0) {
	printf("No disponible");
    } else {
	//mouse_show();

	while(c!=27) {
	    //mouse_data(&x, &y, &b);
	    gotoxy(x,y);
	    putc(' ', stdout);
	    if(kbhit) {
		c = getch();
		if(c==0) {
		    c = getch();
		    if(c == RIGHT) x++;
		    if(c == LEFT) x--;
		    if(c == DOWN) y++;
		    if(c == UP) y--;
		    clrscr();
		    gotoxy(x,y);
		    putc(' ', stdout);
		    //printf("%i", c);
		}

	    }
	    //printf("X: %5i, Y: %5i, B: %5i", x, y, b);
	}
    }
    return 0;
}