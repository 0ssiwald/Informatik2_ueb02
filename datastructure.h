/*******************************************
* datastructure.h contains all new data types
********************************************/

#ifndef DATASTRUCTURE_H_INCLUDED
#define DATASTRUCTURE_H_INCLUDED

#define MAXPLAYER 23
#define MAXTEAMS 10

/************************************
* sDate data type for creating Dates
***********************************/
typedef struct
{
   int Day;
   int Month;
   int Year;
} sDate;

/************************************
* sPlayer contains infos about the player
***********************************/
typedef struct
{
   char *Name;
   sDate *Birthday;
   int ShirtNumber;
   int GoalNumber;
} sPlayer;

/************************************
* sTeam contains infos about the team
***********************************/
typedef struct
{
   char *Name;
   char *Trainer;
   int NumberOfPlayers;
   sPlayer Players[MAXPLAYER];
} sTeam;

//Initialized in teams.c                   //gehört das in den include wächter????
extern int TeamCounter;
extern sTeam Teams[];


#endif // DATASTRUCTURE_H_INCLUDED

