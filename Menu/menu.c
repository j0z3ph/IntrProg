/**
 * @file menu.c
 * @author Jose Luis Cruz (j0z3ph@gmail.com)
 * @brief Test
 * @version 0.1
 * @date 2022-12-01
 * 
 */

#include<stdio.h>
#include<stdlib.h>
#include"tools.h"

int main(int argc, char const *argv[])
{
    int opt;
    const int numItems = 3;
    char* items[numItems];
    items[0] = "Opt1";
    items[1] = "Opt2";
    items[2] = "Opt3";
    
    opt = showMenu(numItems, items, "Prueba");
    
    printf("Opcion seleccionada: %s", items[opt]);
    
    return 0;
}
