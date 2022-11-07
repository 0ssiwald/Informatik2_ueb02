#include <stdio.h>
#include "teams.h"
#include "datastructure.h"
#include "tools.h"
#include "datastructure.h"
#include "datetime.h"


//MAXTEAMS defined in datastructure.h
   int TeamCounter = 0;
   sTeam Teams[MAXTEAMS];

void createTeam()
{
  // muss geprüft werden ob get Text sucessfull ist?
   if(TeamCounter < MAXTEAMS) // to ensure that there is still space in the array
   {
      (Teams + TeamCounter)->NumberOfPlayers = 0;
      getText("Geben Sie bitte den Namen der Mannschaft ein \n -> ", 100, 0, &((Teams + TeamCounter)->Name)); //Teams + TeamCounter Zeigerschreibweise für Teams[TeamCounter]
      getText("Geben Sie bitte den Namen des Trainers ein \n -> ", 100, 1, &((Teams + TeamCounter)->Trainer));
      do{
         if((Teams + TeamCounter)->NumberOfPlayers < MAXPLAYER) // to ensure that there is still space in the array
         {
            createPlayer();
         }
      } while(askYesOrNo("Moechten Sie einen weiteren Spieler eingeben (j/n) ? \n"));
      clearScreen();
      TeamCounter++;
   }
}

void createPlayer()
{
   char *Date_as_text = NULL;
   int Valid_Date;
   getText("Bitte geben Sie den Namen eines Spielers ein: \n -> ", 50, 0, &((Teams + TeamCounter)->Players[(Teams + TeamCounter)->NumberOfPlayers].Name)); // wie mit zeigern?????????????????
   do{
      getText("Geben Sie bitte das Geburtsdatum des Spielers ein: \n -> ", 50, 1, &Date_as_text);
      if(Date_as_text) // if Date_as_text is still NULL pointer dont get Date from String
         Valid_Date = getDateFromString(Date_as_text, &((Teams + TeamCounter)->Players[(Teams + TeamCounter)->NumberOfPlayers].Birthday));
      else
         Valid_Date = 1;
   } while(!Valid_Date); // to allow empty Date input
   getNumber("Geben Sie bitte die Trikotnr. des Spilers ein: \n -> ", &((Teams + TeamCounter)->Players[(Teams + TeamCounter)->NumberOfPlayers].ShirtNumber), 0, 99);
   ((Teams + TeamCounter)->Players[(Teams + TeamCounter)->NumberOfPlayers].GoalNumber) = 0;
   (Teams->NumberOfPlayers)++;
}

void deleteTeam()
{
   printf("deleteTeam");
   waitForEnter();
}
void deletePlayer()
{
   printf("deletePlayer");
   waitForEnter();
}
void searchPlayer()
{
   printf("searchPlayer");
   waitForEnter();
}
void sortTeams()
{
   printf("sortTeams");
   waitForEnter();
}
void listTeams()
{
   printf("Liste der Mannschaften\n");
   printf("======================\n \n");
   int i;
   for(i = 0; i < TeamCounter; i++)
   {
      listOneTeam(i);
   }
   waitForEnter();

}

void listOneTeam(int Team_Number)
{
   printf("Name               : %s \n", (Teams + Team_Number)->Name);
   if((Teams + Team_Number)->Trainer) //if not NULL
      printf("Trainer            : %s \n", (Teams + Team_Number)->Trainer);
   else
      printf("Trainer            : <dieser Posten ist verkant> \n");
   printf("Anzahl der Spieler : %d \n", (Teams + Team_Number)->NumberOfPlayers);
   printf("Spieler: \n");
   int i;
   for(i = 0; i < (Teams + Team_Number)->NumberOfPlayers; i++)
   {
      printf("%02d. %s (%d", (i + 1), (Teams + Team_Number)->Players[i].Name, (Teams + Team_Number)->Players[i].ShirtNumber);
      if((Teams + Team_Number)->Players[i].Birthday) //if not NULL
      {
         printf("; * ");
         printDate((Teams + Team_Number)->Players[i].Birthday);
      }
      printf(") \n");
   }
}
