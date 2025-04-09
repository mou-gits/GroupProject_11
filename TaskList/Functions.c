#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Functions.h"

void DisplayMainMenu(void)
{
    printf("\n---------------     Main Menu        ---------------");
    printf("\n 1. Add task");
    printf("\n 2. Delete task");
    printf("\n 3. Update existing task");
    printf("\n 4. List task by id");
    printf("\n 5. List task by id range");
    printf("\n 6. List all unfinished task");
    printf("\n 7. List all finished task");
    printf("\n 8. Save task list");
    printf("\n 9. Load task list");
    printf("\n10. Exit");
    printf("\n-----------------------------------------------------");
}

void updateTask(TASK tasks[], int taskCount, int taskId, const char* newDescription, int newStatus) {
    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].id == taskId) {
            if (newDescription != NULL) {
                strncpy(tasks[i].description, newDescription, DESC_SIZE - 1);
                tasks[i].description[DESC_SIZE - 1] = '\0';
            }
            tasks[i].completed = newStatus;
            printf("Task %d updated.\n", taskId);
            return;
        }
    }
    printf("Task %d not found.\n", taskId);
}

void displaySingleTask(TASK tasks[], int taskCount, int taskId) {
    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].id == taskId) {
            printf("Task ID: %d\nDescription: %s\nCompleted: %s\n",
                tasks[i].id, tasks[i].description,
                tasks[i].completed ? "Yes" : "No");
            return;
        }
    }
    printf("Task ID %d not found.\n", taskId);
}

void displayTaskRange(TASK tasks[], int taskCount, int startId, int endId) {
    int found = 0;
    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].id >= startId && tasks[i].id <= endId) {
            printf("Task ID: %d\nDescription: %s\nCompleted: %s\n\n",
                tasks[i].id, tasks[i].description,
                tasks[i].completed ? "Yes" : "No");
            found = 1;
        }
    }
    if (!found) {
        printf("No tasks found in range %d - %d.\n", startId, endId);
    }
}

void displayAllTasks(TASK tasks[], int taskCount) {
    if (taskCount == 0) {
        printf("No tasks to display.\n");
        return;
    }
    for (int i = 0; i < taskCount; i++) {
        printf("Task ID: %d\nDescription: %s\nCompleted: %s\n\n",
            tasks[i].id, tasks[i].description,
            tasks[i].completed ? "Yes" : "No");
    }
}