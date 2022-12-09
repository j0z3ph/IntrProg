#include<stdio.h>
#include<dos.h>
#include<conio.h>

#define MOUSE 0X33

union REGS in, out;

void detect_mouse() {
    in.x.ax = 0;
    int86(MOUSE, &in, &out);
    if(out.x.ax == 0)
	printf("Mouse no disponible");
}
void show_mouse() {
    in.x.ax = 1;
    int86(MOUSE, &in, &out);
}
void get_data(int *x, int *y, int *b) {
    in.x.ax = 3;
    int86(MOUSE, &in, &out);
    *x = out.x.cx;
    *y = out.x.dx;
    *b = out.x.bx;
}

int main() {
    int x, y, b;
    clrscr();

    detect_mouse();
    show_mouse();
    while(!kbhit()) {
	get_data(&x, &y, &b);
	gotoxy(1,1);
	printf("X:%5i, Y:%5i, B:%i",x,y,b);
    }

    return 0;

}