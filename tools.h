/********************************************
* includes helpful general purpose functions
*********************************************/

#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED

/****************************************
* void clearBuffer()
* clears inputs in the keyboard buffer
* till '\n' (removes '\n' from buffer)
****************************************/
void clearBuffer();

/****************************************
* void waitForEnter()
* waits for user to press enter
* clears Buffer
****************************************/
void waitForEnter();

/****************************************
* void clearScreen()
* clears the console screen
* with windows command
****************************************/
void clearScreen();

/****************************************
* int askYesOrNo(char *)
* Prints what is provided as argument
* Returns 0 when n,N is input
* Returns 1 when j,J is input
****************************************/
int askYesOrNo(char *);

/****************************************
* void printLine(char, int)
* Prints the character (char) the amount of int
****************************************/
void printLine(char, int);

/****************************************
* int getText(char *, int, int, char **)
* gets Text from a user and safes it in a right size of memory
* Parameters: 1. Prompt for the user what he has to input that gets printed on screen
              2. Max length that the input can have
              3. Value if an empty input is ok (1 == its ok)
              4. Pointer of pointer of the location where the input is stored
* Result: was call of the function and the storage of the input successful
****************************************/
int getText(char *, int, int, char **);

/****************************************
* int getNumber(char *, int *, int , int)
* gets a Number from a user
* Parameters: 1. Prompt for the user what he has to input that gets printed on screen
              2. Location were the Number is stored
              3. Smallest possible Number input form the user
              4. Biggest possible Number input form the user
* Result: was the call of the function successful
****************************************/
int getNumber(char *Prompt, int *Number, int Smallest_num, int Biggest_num);
#endif // TOOLS_H_INCLUDED
