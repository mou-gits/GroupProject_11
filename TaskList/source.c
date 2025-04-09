#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "Functions.h"

void main(void)
{
    TASK tasks[MAX_TASKS] = {
        {1, "Complete assignment", 0},
        {2, "Buy groceries", 0},
        {3, "Prepare recipe", 1}
    };
    int taskCount = 3;
    int UserInput = 0;

    do {
        //Display the Main Menu
        DisplayMainMenu();

        //Obtain user input for main menu options
        ObtainUserInput(&UserInput);

        //UserInput = 0 -> invalid entry
        if (UserInput == 0) 
        {
            continue;
        }
        
        //If proper entry
        LaunchProperAction(UserInput);
    } while (UserInput != 10);

    CheckJasonCode(tasks,taskCount);
}

