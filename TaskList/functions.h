#pragma once
#include "globals.h"


typedef struct taskitem{
    int id;
    char description[DESC_SIZE];
    int completed; // 0 = not completed, 1 = completed
} TASK;

void updateTask(TASK tasks[], int taskCount, int taskId, const char* newDescription, int newStatus);
void displaySingleTask(TASK tasks[], int taskCount, int taskId);
void displayTaskRange(TASK tasks[], int taskCount, int startId, int endId);
void displayAllTasks(TASK tasks[], int taskCount);