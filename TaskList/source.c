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

        switch (UserInput)
        {
        case 1:
            printf("\nAdding Tasks");
            break;
        case 2:
            printf("\nDeleting Tasks");
            break;
        case 3:
            printf("\nUpdating Tasks");
            break;
        case 4:
            printf("\nList Task by Id");
            break;
        case 5:
            printf("\nList Task by Id range");
            break;
        case 6:
            printf("\nList all unfinished task");
            break;
        case 7:
            printf("\nList all finished task");
            break;
        case 8:
            printf("\nSave tasklist");
            break;
        case 9:
            printf("\nLoad tasklist");
            break;
        }

    } while (UserInput != 10);

    printf("\nChecking Jason's functions");
    // Test update
    printf("\n=== Updating Task ===\n");
    updateTask(tasks, taskCount, 1, "Complete C project", 1);

    // Test display single
    printf("\n=== Display Single Task ===\n");
    displaySingleTask(tasks, taskCount, 1);

    // Test display range
    printf("\n=== Display Task Range (IDs 1-2) ===\n");
    displayTaskRange(tasks, taskCount, 1, 2);

    // Test display all
    printf("\n=== Display All Tasks ===\n");
    displayAllTasks(tasks, taskCount);
}
