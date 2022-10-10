#include <stdio.h>
#include <stdlib.h>  //for casting(atoi)
#include "datastructure.h"
#include "datetime.h"


int getDateFromString(char *Input, sDate *Date){
   char *pDay = Input;
   char *pMonth = NULL;
   char *pYear = NULL;

   while(*Input != '.'){
      if(*Input == '\0')
         return 0;
      Input++;
   }
   pMonth = ++Input;
   while(*Input != '.'){
      if(*Input == '\0')
         return 0;
      Input++;
   }
   pYear = ++Input;

   int Day = atoi(pDay);
   int Month = atoi(pMonth);
   int Year = atoi(pYear);

   Date->Day = Day;
   Date->Month = Month;
   Date->Year = Year;

   if(isDateValid(Date))
      return 1;
   else
      return 0;
}

int isDateValid(sDate *Date){
   int Year_Valid = 0;
   int Month_Valid = 0;
   int Day_Valid = 0;
   if(Date->Year >= 1750 && Date->Year < 3000)
      Year_Valid = 1;
   if(Date->Month >= 0 && Date->Month <= 12)
      Month_Valid = 1;
   switch(Date->Month){
   case 1:
   case 3:
   case 5:
   case 7:
   case 8:
   case 10:
   case 12: if(Date->Day >= 1 && Date->Day <= 31)
               Day_Valid = 1;
            break;
   case 4:
   case 6:
   case 9:
   case 11: if(Date->Day >= 1 && Date->Day <= 30)
               Day_Valid = 1;
            break;
   case 2:  if(isLeapYear(Date) == 0 && Date->Day >= 1 && Date->Day <= 28)
               Day_Valid = 1;
            if(isLeapYear(Date) == 1 && Date->Day >= 1 && Date->Day <= 29)
               Day_Valid = 1;
            break;
   default: Day_Valid = 0;
   }

   if(Year_Valid && Month_Valid && Day_Valid)
      return 1;
   else
      return 0;
}

int isLeapYear(sDate *Date){
   if(Date->Year % 4 == 0 && Date->Year % 100 == 1)
      return 1;
   else if(Date->Year % 400 == 0)
      return 1;
   else
      return 0;
}
