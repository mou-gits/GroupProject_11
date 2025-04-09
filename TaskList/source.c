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
    int UserInputStatus;

    do {
        DisplayMainMenu();
        printf("\nEnter Menu Option: ");
        UserInputStatus = scanf("%d", &UserInput);

        if (UserInputStatus != 1 || getchar() != '\n') { //This means either scanf failed or there are extra input
            printf("\nInvalid input!! Try again.\n");
            while (getchar() != '\n') {}; // Blank loop eating up any extra characters in the input buffer
            continue; //Display menu again
        }
        LaunchProperAction(UserInput);       
    } while (UserInput != 10);

    CheckJasonCode(tasks,taskCount);
}

