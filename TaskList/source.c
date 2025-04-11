#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include "Functions.h"

void main(void)
{
    TASK listofTasks[MAX_TASKS];
    int taskCount = 0;
    int MainMenuUserInput = 0;

    do {
        //Display the Main Menu
        DisplayMainMenu();

        //Obtain user input for main menu options
        ObtainUserInput(&MainMenuUserInput);

        //exit menu
        if (MainMenuUserInput == 12)
        {
            break;
        }

        //If proper entry
        LaunchProperAction(MainMenuUserInput, listofTasks, &taskCount);
    } while (true); //Keep looping until Exit is chosen
}


