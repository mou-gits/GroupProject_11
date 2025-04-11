#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include "Functions.h"

#define EXIT_NUM 12

void main(void)
{
    TASK listofTasks[MAX_TASKS];
    int taskCount = 0;
    int MainMenuUserInput = 0;

    bool running = true;

    while (running) {

        // Main menu display moved here
        printf("\n---------------     Main Menu        ---------------");
        printf("\n 1. Display the task list");
        printf("\n 2. Add task");
        printf("\n 3. Delete task");
        printf("\n 4. Update existing task");
        printf("\n 5. List task by id");
        printf("\n 6. List task by id range");
        printf("\n 7. List all unfinished task");
        printf("\n 8. List all finished task");
        printf("\n 9. Save task list");
        printf("\n10. Load task list");
        printf("\n11. Search task");
        printf("\n12. Exit");
        printf("\n-----------------------------------------------------");
        printf("\nEnter Menu Option: ");

        // Getting input
        ObtainUserInput(&MainMenuUserInput);

        // Menu action logic also moved here
        switch (MainMenuUserInput) {
        case 1:
            displayAllTasks(listofTasks, taskCount);
            printf("\n\nPress Enter(<-') to go back to main menu.");
            char c = getchar(); // Wait for Enter
            break;
        case 2:
            MenuCall_AddTask(listofTasks, &taskCount);
            break;
        case 3:
            MenuCall_DeleteTask(listofTasks, &taskCount);
            break;
        case 4:
            MenuCall_UpdateTask(listofTasks, taskCount);
            break;
        case 5:
            printf("\nList Task by Id");
            MenuCall_ListSingleTask(listofTasks, taskCount);
            break;
        case 6:
            printf("\nList Task by Id range");
            MenuCall_ListRangeTask(listofTasks, taskCount);
            break;
        case 7:
            printf("\nList all unfinished task");
            MenuCall_ListAllPendingTasks(listofTasks, taskCount);
            break;
        case 8:
            printf("\nList all finished task");
            MenuCall_ListAllFinishedTasks(listofTasks, taskCount);
            break;
        case 9:
            SaveDataToDrive(listofTasks, taskCount, FILENAME);
            break;
        case 10:
            ReadTasksFromFile(listofTasks, &taskCount, FILENAME);
            break;
        case 11:
            printf("Enter Task ID to search: ");
            int input;
            ObtainUserInput(&input);
            SearchTask(listofTasks, taskCount, input);
            break;
        case 12:
            printf("Exiting....\n");
            running = false;
            break;
        default:
            printf("Invalid choice. Please enter a number between 1 and 12.\n");
            break;
        }
    }
   
}


