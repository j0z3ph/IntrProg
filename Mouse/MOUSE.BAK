#include<stdio.h>
#include<dos.h>
#include<conio.h>

#define MOUSE 0X33

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
    int x,y,b;
    clrscr();
    if(mouse_available() == 0) {
	printf("No disponible");
    } else {
	mouse_show();
	while(!kbhit()) {
	    mouse_data(&x, &y, &b);
	    gotoxy(1,1);
	    printf("X: %5i, Y: %5i, B: %5i", x, y, b);
	}
    }
    return 0;
}