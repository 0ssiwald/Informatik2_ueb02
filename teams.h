/*******************************************
* includes functions that can be called by the
* menu regarding Teams and Players
********************************************/

//#ifndef TEAMS_H_INCLUDED
//#define TEAMS_H_INCLUDED
/****************************************
* void createTeam()
* Asks the User to input Data like Name of Team
* Calls createPlayer()
****************************************/
void createTeam();

/****************************************
* void createPlayer()
* Gets called by createTeam()
* Asks the User to input Data for One Player like Name
****************************************/
void createPlayer();

/*******************************************
* not finished yet
********************************************/
void deleteTeam();

/*******************************************
* not finished yet
********************************************/
void deletePlayer();

/*******************************************
* not finished yet
********************************************/
void searchPlayer();

/*******************************************
* not finished yet
********************************************/
void sortTeams();

/****************************************
* void listTeams()
* Dispalys all Teams with the Players in the Console
* Calls listOneTeam()
****************************************/
void listTeams();

/****************************************
* void listOneTeams(int )
* Dispalys one Team with the Players in the Console
* Gets called by listTeam()
* Parameter: Position in Teams Array
****************************************/
void listOneTeam(int );
//#endif // TEAMS_H_INCLUDED
