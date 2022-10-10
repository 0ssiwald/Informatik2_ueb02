#include <stdio.h>
#include "datastructure.h"
#include "datetime.h"
#include "menu.h"
#include "teams.h"
#include "tools.h"

int main()
{
   int Menu_point;
   char Menu_title[] = {"Mannschaften-Verwaltung v0.2"};
   char *Menu_points[] = {"Neue Mannschaft anlegen", "Spieler hinzufügen", "Spieler loeschen", "Mannschaft loeschen", "Suchen", "Sortieren", "Auflisten", "Programm beenden"};
   do{
      Menu_point = getMenu(Menu_title, Menu_points[], 8);              // 8 muss noch ausgetauscht werden
      switch(Menu_point)
      {
         case 1: createTeam();
               break;
         case 2: createPlayer();
               break;
         case 3: deletePlayer();
               break;
         case 4: deleteTeam();
               break;
         case 5: searchPlayer();
               break;
         case 6: sortTeams();
               break;
         case 7: listTeams();
               break;
         case 8: printf("Programm wird beendet...");
               break;
      }
   } while(Menu_point != 8);
    return 0;
}
