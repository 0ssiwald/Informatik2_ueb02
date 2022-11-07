#include <stdio.h>
#include "tools.h"
#include "menu.h"


int getMenu(char *Menu_title, char *Menu_points[], int Count)
{
   int Menu_point_input = 0;

   do{
      clearScreen();
      printf("%s \n", Menu_title);
      printLine('=',30);
      printf("\n");
      int i;
      for(i = 0; i < Count; i++)
         printf("%i. %s \n",i + 1 ,Menu_points[i]);
      printf("Ihre Wahl: ");
      scanf("%i", &Menu_point_input);
      clearBuffer();
   } while(Menu_point_input < 1 || Menu_point_input > Count);

   return Menu_point_input;
}
