#ifndef __TOOLS_H__
#define __TOOLS_H__

/**
 * @brief Moves cursor to desired coordinates.
 * 
 * @param x X coordinate (column).
 * @param y Y coordinate (row).
 */
void gotoXY(int x, int y);

/**
 * @brief Clears command window.
 * 
 */
void clear();

/**
 * @brief Prints the given menu. 
 * User can interact with menu using Up/Down arrows
 * and can select an option pressing the ENTER key.
 * 
 * @param numItems Number of items in the string array.
 * @param items String array. Each item is a menu option.
 * @param title Menu title.
 * @return int 0-base index of the selected item.
 */
int showMenu(int numItems, char* items[], char const *title);

#endif