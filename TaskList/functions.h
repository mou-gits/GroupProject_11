#pragma once
#include <string.h>
#define MAX_TASKS 50
#define DESC_SIZE 256
#define FILENAME "Tasklist.txt"

typedef struct task {
    int id;
    char description[DESC_SIZE];
    int completed; // 0 = not completed, 1 = completed
} TASK;

void updateTask(TASK tasks[], int taskCount, int taskId, const char* newDescription, int newStatus);

void displaySingleTask(TASK tasks[], int taskCount, int taskId);

void displayTaskRange(TASK tasks[], int taskCount, int startId, int endId);

void displayAllTasks(TASK tasks[], int taskCount);


void ObtainUserInput(int* ptUserInput);

void MenuCall_ListSingleTask(TASK tasks[], int taskCount);

void MenuCall_ListRangeTask(TASK tasks[], int taskCount);

void MenuCall_ListAllFinishedTasks(TASK tasks[], int taskCount);

void MenuCall_ListAllPendingTasks(TASK tasks[], int taskCount);

void MenuCall_UpdateTask(TASK tasks[], int taskCount);

void MenuCall_AddTask(TASK tasks[], int* ptTaskCount);

bool isIDAbsent(TASK tasks[], int taskCount, int newtaskId);

bool isIDPresent(TASK tasks[], int taskCount, int newtaskId);

void  MenuCall_DeleteTask(tasks, ptTaskCount);

void SaveDataToDrive(TASK tasks[], int taskCount, const char* filename);

void ReadTasksFromFile(TASK listofTasks[], int* TaskCount, const char* filename);