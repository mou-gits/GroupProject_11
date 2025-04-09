#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_TASKS 50
#define DESC_SIZE 256

typedef struct taskitem {
    int id;
    char description[DESC_SIZE];
    int completed; // 0 = not completed, 1 = completed
} TASK;

void updateTask(TASK tasks[], int taskCount, int taskId, const char* newDescription, int newStatus);
void displaySingleTask(TASK tasks[], int taskCount, int taskId);
void displayTaskRange(TASK tasks[], int taskCount, int startId, int endId);
void displayAllTasks(TASK tasks[], int taskCount);

void main(void)
{
    TASK tasks[MAX_TASKS] = {
        {1, "Complete assignment", 0},
        {2, "Buy groceries", 0},
        {3, "Prepare recipe", 1}
    };
    int taskCount = 3;

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

    return 0;
}