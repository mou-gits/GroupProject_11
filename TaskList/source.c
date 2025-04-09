#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include "Functions.h"

void main(void)
{
    TASK tasks[MAX_TASKS] = 
    {
        {1, "Complete assignment", 0},
        {2, "Buy groceries", 0},
        {3, "Prepare recipe", 1},
        {4, "Take the bus",0 },
        {5, "Email Tricia",1},
        {6, "Finish C Project",0},
        {7, "Eat Joydeep's Head", 1}
    };
    int taskCount = 7;
    int MainMenuUserInput = 0;

    do {
        //Display the Main Menu
        DisplayMainMenu();

        //Obtain user input for main menu options
        ObtainUserInput(&MainMenuUserInput);

        //UserInput = 0 -> invalid entry
        if (MainMenuUserInput == 0)
        {
            continue;
        }

        //UserInput = 10 -> Exit Menu
        if (MainMenuUserInput == 10)
        {
            break;
        }
        
        //If proper entry
        LaunchProperAction(MainMenuUserInput, tasks, &taskCount);

    } while (true); //Keep looping until Exit is chosen

    CheckJasonCode(tasks,taskCount);
}