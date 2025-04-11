#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Functions.h"


void updateTask(TASK tasks[], int taskCount, int taskId, const char* newDescription, int newStatus) {
    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].id == taskId) {
            if (newDescription != NULL) {
                strncpy(tasks[i].description, newDescription, DESC_SIZE - 1);
                tasks[i].description[DESC_SIZE - 1] = '\0';
            }
            tasks[i].completed = newStatus;
            printf("\nTask %d updated.", taskId);
            return;
        }
    }
    printf("Task %d not found.\n", taskId);
}

void AddTask(TASK tasks[], int taskCount, int newtaskId, const char* newDescription, int newStatus)
{
    tasks[taskCount].id = newtaskId;

    strncpy(tasks[taskCount].description, newDescription, DESC_SIZE - 1);
    tasks[taskCount].description[DESC_SIZE - 1] = '\0';
    tasks[taskCount].completed = newStatus;
    printf("\nTask %d added.", newtaskId);

}

void DeleteTask(TASK tasks[], int* ptTaskCount, int IndextoDelete)
{
    if (IndextoDelete >= *ptTaskCount && IndextoDelete < 0)
    {
        printf("\nInvalid index to delete!!");
    }
    else
    {
        for (int i = IndextoDelete; i < *ptTaskCount; i++)
        {
            tasks[i] = tasks[i + 1];
        }
        *ptTaskCount = *ptTaskCount - 1;
        printf("\nDeleted successfully!! \n");
    }
}

void displaySingleTask(TASK tasks[], int taskCount, int taskId) {
    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].id == taskId) {
            printf("\n%d. %s.(%s)",
                tasks[i].id, tasks[i].description,
                tasks[i].completed ? "Done" : "Pendings");
            return;
        }
    }
    printf("Task ID %d not found.\n", taskId);
}

void displayTaskRange(TASK tasks[], int taskCount, int startId, int endId) {
    int found = 0;
    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].id >= startId && tasks[i].id <= endId) {
            printf("\n%d. %s.(%s)",
                tasks[i].id, tasks[i].description,
                tasks[i].completed ? "Done" : "Pendings");
            found = 1;
        }
    }
    if (!found) {
        printf("No tasks found in range %d - %d.\n", startId, endId);
    }
}

void displayAllTasks(TASK tasks[], int taskCount) {
    if (taskCount == 0) 
    {
        printf("No tasks to display.\n");
    }
    else 
    {
        printf("\nHere is the whole task list:\n");
        for (int i = 0; i < taskCount; i++) 
        {
            printf("\n%d. %s.(%s)"  , tasks[i].id
                                    , tasks[i].description
                                    , tasks[i].completed ? "Done" : "Pendings");
        }
    }   
}



void ObtainUserInput(int* ptUserInput)
{
    int UserInputStatus = scanf("%d", ptUserInput);
    if (UserInputStatus != 1 || getchar() != '\n') //Either scanf failed or there are extra input
    { 
        printf("\nInvalid input!! Try again.\n");
        while (getchar() != '\n'); // Blank loop eating up any extra characters in the input buffer
        *ptUserInput = 0; //Set Invalid code 
    }
}

void MenuCall_ListSingleTask(TASK tasks[], int taskCount)
{
    int taskId;
    //Obtain task id to seek
    printf("\nEnter Task Id: ");
    ObtainUserInput(&taskId);
 
    displaySingleTask(tasks, taskCount, taskId);

    //Wait for enter to return to Main Menu
    printf("\n\nPress Enter to continue...");
    char c = getchar();
}

void MenuCall_ListRangeTask(TASK tasks[], int taskCount)
{
    int taskId_start;
    int taskId_end;

    //Obtain starting task Id
    printf("\nEnter Starting Task Id: ");
    ObtainUserInput(&taskId_start);

    //Obtain ending task id
    printf("\nEnter Ending Task Id: ");
    ObtainUserInput(&taskId_end);

    //call display function
    displayTaskRange(tasks, taskCount, taskId_start, taskId_end);
    
    //Wait for enter to return to Main Menu
    printf("\n\nPress Enter to continue...");
    char c = getchar();
}

void MenuCall_ListAllFinishedTasks(TASK tasks[], int taskCount)
{
    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].completed == 1) 
        {
            printf("\n%d. %s.(%s)",
                tasks[i].id, tasks[i].description,
                tasks[i].completed ? "Done" : "Pendings");
        }
    }

    //Wait for enter to return to Main Menu
    printf("\n\nPress Enter to continue...");
    char c = getchar();
}

void MenuCall_ListAllPendingTasks(TASK tasks[], int taskCount)
{
    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].completed == 0)
        {
            printf("\n%d. %s.(%s)",
                tasks[i].id, tasks[i].description,
                tasks[i].completed ? "Done" : "Pendings");
        }
    }

    //Wait for enter to return to Main Menu
    printf("\n\nPress Enter to continue...");
    char c = getchar();
}

void MenuCall_UpdateTask(TASK tasks[], int taskCount)
{
    //Declaring local variables
    int taskId, newStatus;
    char newDescription[DESC_SIZE], choice;

    //Displaying all available tasks
    printf("\nList of avaliable tasks: ");
    displayAllTasks(tasks, taskCount);

    //Obtaining which task to edit
    do
    {
        printf("\nPlease enter the Id to update: ");
        ObtainUserInput(&taskId);
    } while (isOKtoDelete(tasks, taskCount, taskId) == false);
    
        printf("\nDo you want to change the description? (Y/N) ");
        int val = scanf("%c", &choice);
        while (getchar() != '\n');

        if (choice == 'Y' || choice == 'y')
        {
            printf("\nPlease enter the description: ");
            fgets(newDescription, DESC_SIZE, stdin);
            newDescription[strcspn(newDescription, "\n")] = '\0';
        }

        printf("\nPlease define the status (1/0): ");
        ObtainUserInput(&newStatus);

        if (choice == 'Y' || choice == 'y')
        {
            updateTask(tasks, taskCount, taskId, newDescription, newStatus);
        }
        else {
            updateTask(tasks, taskCount, taskId, NULL, newStatus);
        }
    
     //Wait for enter to return to Main Menu
    printf("\nPress Enter to go back to main menu...");
    char c = getchar();
}

void MenuCall_AddTask(TASK tasks[], int* ptTaskCount)
{
    //Obtain task details from user
        //define variables
    int newtaskId, newStatus;
    char newDescription[DESC_SIZE];

    do {
        printf("\nPlease provide the task ID to add: ");
        ObtainUserInput(&newtaskId);
    } while (!isProperId(tasks, *ptTaskCount, newtaskId));

        //put a printf to take the details to add to the task list
    printf("\nPlease provide the description: ");
    fgets(newDescription, DESC_SIZE, stdin);
    newDescription[strcspn(newDescription, "\n")] = '\0';
    
    do {
        printf("\nPlease define the status (1/0): ");
        ObtainUserInput(&newStatus);
        
    }while(newStatus!=0 && newStatus!=1);
    
    //Add task information for New member in the tasks array 
    AddTask(tasks, *ptTaskCount, newtaskId, newDescription, newStatus);
    *ptTaskCount = *ptTaskCount + 1;

}

void MenuCall_DeleteTask(TASK tasks[], int* ptTaskCount)
{
    //Declaring local variables
    int taskId, newStatus;
    int IndextoDelete;
    char newDescription[DESC_SIZE], choice;

    //Displaying all available tasks
    printf("\nList of avaliable tasks: ");
    displayAllTasks(tasks, *ptTaskCount);

    do {
        printf("\nPlease provide the task ID to delete: ");
        ObtainUserInput(&taskId);
    } while (!isOKtoDelete(tasks, *ptTaskCount, taskId));
    
    //find the location of that taskid
    for (IndextoDelete = 0; IndextoDelete < *ptTaskCount; IndextoDelete++)
    {
        if (taskId==tasks[IndextoDelete].id)
        {
            break;
        }
    }
    //call the del func
    DeleteTask(tasks, ptTaskCount, IndextoDelete);

    printf("\nPress Enter to go back to main menu...");
    char c = getchar();

}

bool isProperId(TASK tasks[], int taskCount, int newtaskId)
{
    if (newtaskId <= 0)
    {
        printf("\nNeed a positive integer. Please try again!");
        return false;
    }
    else
    {
        for (int i = 0; i < taskCount; i++)
        {
            if (tasks[i].id == newtaskId)
            {
                printf("\nTask Id is already exists! Please try again!");
                return false;
            }
        }
        return true;
    }
}

bool isOKtoDelete(TASK tasks[], int taskCount, int newtaskId)
{
    if (newtaskId <= 0)
    {
        printf("\nNeed a positive integer. Please try again!");
        return false;
    }
    else
    {
        for (int i = 0; i < taskCount; i++)
        {
            if (tasks[i].id == newtaskId)
            {
                return true;
            }
        }
        printf("\nTask Id does not exist! Please try again!");
        return false;
    }
}

void SaveDataToDrive(TASK tasks[], int taskCount, const char* filename)
{   
    //opening file to write    
    FILE* file = fopen(filename, "w");

    //checking the if the file opening correctly
    if (file == NULL) {
        perror("\nError opening file");
        return;
    }

    //printing on the file which is opened and showing how many task we have written
    fprintf(file, "%d\n", taskCount);

    //using a for loop to write the task id, task description and task status
    for (int i = 0; i < taskCount; i++) {
        fprintf(file, "<%d><%s><%d>\n", tasks[i].id, tasks[i].description, tasks[i].completed);
    }
    fclose(file);       //closing the file
    printf("\nData successfully saved to %s.", filename);
}

void ReadTasksFromFile(TASK listofTasks[], int* TaskCount, const char* filename)
{
    //opening the file to read
    FILE* file = fopen(filename, "r");

    //checking if the file is opening correctly
    if (file == NULL) {
        perror("Error opening file");
    }
    else {
        int taskId;
        int taskStatus;
        char strDescription[DESC_SIZE];
        char buffer[DESC_SIZE * 2]; // Buffer to hold each line

        //showing the total number of tasks
        int val = fscanf(file, "%d\n", TaskCount);

        //using a for loop to read tasks from the file
        for (int i = 0; i < *TaskCount; i++)
        {
            //Read a line until you reach \n
            fgets(buffer, sizeof(buffer), file);

            //Replace the \n with the endline character
            buffer[strcspn(buffer, "\n")] = '\0';

            //parse the string obtained by reading each line
            val = sscanf(buffer, "<%d><%256[^><]><%d>", &taskId, strDescription, &taskStatus);

            // If the last position is not '\0', explicitly null-terminate
            if (strDescription[sizeof(strDescription) - 1] != '\0') 
            {
                strDescription[sizeof(strDescription) - 1] = '\0';
            }

            //Set the values read from file into the array structure
            listofTasks[i].id = taskId;
            listofTasks[i].completed = taskStatus;
            strcpy(listofTasks[i].description, strDescription);
        }

        //close the file when done
        fclose(file);
        printf("Data successfully loaded from %s.\n", filename);
    }
}

void SearchTask(TASK task[], int taskCount, int taskId) {

    // Use a for loop to interrate the task
    for (int i = 0; i < taskCount; i++) {

        // This will look for the task Id that the user inputted. 
        // If found it will print the task and if it is completed or not.
        if (task[i].id == taskId) {
            printf("\nTask Found:\n");
            printf("Task: TASK ID:%d %s %d\n", task[i].id, task[i].description, task[i].completed);
            return EXIT_SUCCESS;
        }
    }

    // Will tell the user that their is no task with the task id they 
    // Inputted
    printf("No task found with ID %d.\n", taskId);

}