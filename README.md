**Moutushi Sarkar**

Implemented the following features
- Menu driven interface
- Add() task functionality
- Delete() task functionality
- File Save functionality
- File Load functionality
- Frontend of the Update() task functionality


**List of functions**
- bool isIDAbsent(TASK tasks[], int taskCount, int newtaskId, bool verbose);
- bool isIDPresent(TASK tasks[], int taskCount, int newtaskId, bool verbose);
- void ObtainUserInput(int* ptUserInput);
- void MenuCall_ListSingleTask(TASK tasks[], int taskCount);
- void MenuCall_ListRangeTask(TASK tasks[], int taskCount);
- void MenuCall_ListAllFinishedTasks(TASK tasks[], int taskCount);
- void MenuCall_ListAllPendingTasks(TASK tasks[], int taskCount);
- void MenuCall_UpdateTask(TASK tasks[], int taskCount);
- void MenuCall_AddTask(TASK tasks[], int* ptTaskCount);
- void SaveDataToDrive(TASK tasks[], int taskCount, const char* filename);
- void ReadTasksFromFile(TASK listofTasks[], int* TaskCount, const char* filename);
- void  MenuCall_DeleteTask(tasks, ptTaskCount);

**Jason S. Little**

**List of functions**
- void updateTask(TASK tasks[], int taskCount, int taskId, const char* newDescription, int newStatus);
- void displaySingleTask(TASK tasks[], int taskCount, int taskId);
- void displayTaskRange(TASK tasks[], int taskCount, int startId, int endId);
- void displayAllTasks(TASK tasks[], int taskCount);
- void SearchTask(TASK task[], int taskCount, int taskId);


**Basil Vavasis**
  
