#include "tools.h"

void clearBuffer()
{
   char Dummy;
   do{
      scanf("%c", &Dummy);
   } while( Dummy != '\n');
}

void waitForEnter()
{
   printf("\nBitte druecken Sie die Eingabetaste...");
   clearBuffer();
}


int askYesOrNo(char *Question)
{
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
}

void clearScreen()
{
   system("CLS");
}

void printLine(char Character, int Number)
{
   int i;
   for(i = 0; i <= Number; i++)
      printf("%c", Character);
   printf("\n");
}
