#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "display.h"
#include "globals.h"


// This is to test the implementation
int main(void) 
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