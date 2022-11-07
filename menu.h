/****************************************
* is responsible for menu navigation
****************************************/

#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

/****************************************
* int getMenu(char*, char* , int)
* displays the menu and ask to input a int as menu point
* Parameters: 1. Pointer to menu tile
              2. Pointer to array of menu points
              3. Number of menu points
* Result: The inputed menu point
****************************************/
int getMenu(char*, char**, int);               // ist das so richtig mit dem array einfach als char* ???

#endif // MENU_H_INCLUDED
