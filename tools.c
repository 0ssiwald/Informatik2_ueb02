#include <stdio.h>
#include <stdlib.h>
#include <string.h> //for strncpy and strlen
#include "tools.h"

void clearBuffer(){
   char Dummy;
   do{
      scanf("%c", &Dummy);
   } while( Dummy != '\n');
}

void waitForEnter(){
   printf("\nBitte druecken Sie die Eingabetaste...");
   clearBuffer();
}


int askYesOrNo(char *Question){
   char YorN;
   int Result;
   do{
      printf("%s", Question);
      scanf("%c", &YorN);
      clearBuffer();
      switch(YorN){
         case 'J':
         case 'j': return 1;
         break;
         case 'N':
         case 'n': return 0;
         break;
         default : Result = 0;
      }
   } while(Result == 0);
   return 1;   // to get rid of the compiler warning ^^
}

void clearScreen(){
   system("CLS");
}

void printLine(char Character, int Number)
{
   int i;
   for(i = 0; i <= Number; i++)
      printf("%c", Character);
   printf("\n");
}

int getText(char *Prompt, int MaxLen, int EmptyOk, char **ppInput)
{
   char *TempInput = NULL; // saves the Input temporally and then puts it into the final input
   char Format[15];        // saves the format for scanf including the MaxLen
   int Ok;                 // to test if the usr makes a input
   int Length = 0;             // saves the length from the TempInput
   if(MaxLen == 0)         // if the function gets called with no MaxLen
      return 0;
   if(ppInput == NULL)
      return 0;
   *ppInput = NULL;
   TempInput = calloc(MaxLen + 1,sizeof(char));
   if(TempInput)                             // if the reservation of storage was sucsessful
   {
      sprintf(Format, "%%%i[^\n]", MaxLen); //prints %MaxLen[^\n] in the String Format
      do
      {
         printf(Prompt);
         Ok = scanf(Format, TempInput);
         clearBuffer();
         Length = strlen(TempInput);
         if(Length > 0)
         {
            *ppInput = calloc(Length + 1, sizeof(char));
            if(*ppInput == 0)
            {
               free(TempInput);
               return 0;
            }
            strcpy(*ppInput, TempInput);
         }
         else if(EmptyOk)
         {
            free(TempInput);
            return 1;
         }
         else
         {
            Ok = 0;                       // to repeat the input of the usr gave no input
         }
      } while(!Ok);
      free(TempInput);
      return 1;
   }
   return 0;
}

int getNumber(char *Prompt, int *Number, int Smallest_num, int Biggest_num)
{
   int Ok;
   if(Number == 0)
      return 0;
   if(Smallest_num > Biggest_num)
      return 0;
   do
   {
      printf(Prompt);
      Ok = scanf("%i[^\n]", Number);
      clearBuffer();
   } while(!Ok || *Number < Smallest_num || *Number > Biggest_num);
   return 1;
}
