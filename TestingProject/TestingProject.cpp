#include "pch.h"
#include "CppUnitTest.h"

extern "C" 
{
#include "../TaskList/Functions.h"
}

	using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestingProject
{
	TEST_CLASS(TestingProject)
	{
	public:
		TEST_METHOD(Testing_isIDAbsent_Exception1)
		{
			TASK tasklist[4] = { {2, "Try this", 0},
								{3, "Do that",0},
								{4, "Beat up Joydeep", 0},
								{5, "Finish Project", 0} };
			int taskCount = 4;
			bool result = isIDAbsent(tasklist, taskCount, -1, false);
			Assert::AreEqual(result, false);
		}
		TEST_METHOD(Testing_isIDAbsent_Exception2)
		{
			TASK tasklist[4] = { {2, "Try this", 0},
								{3, "Do that",0},
								{4, "Eat Breakfast", 0},
								{5, "Finish Project", 0} };
			int taskCount = 4;
			bool result = isIDAbsent(tasklist, taskCount, 7, false);
			Assert::AreEqual(result, true);
		}
		TEST_METHOD(Testing_isIDAbsent_EdgeCase1)
		{
			TASK tasklist[4] = { {2, "Try this", 0},
								{3, "Do that",0},
								{4, "Eat Breakfast", 0},
								{5, "Finish Project", 0} };
			int taskCount = 4;
			bool result = isIDAbsent(tasklist, taskCount, 2, false);
			Assert::AreEqual(result, false);
		}
		TEST_METHOD(Testing_isIDAbsent_EdgeCase2)
		{
			TASK tasklist[4] = { {2, "Try this", 0},
								{3, "Do that",0},
								{4, "Eat Breakfast", 0},
								{5, "Finish Project", 0} };
			int taskCount = 4;
			bool result = isIDAbsent(tasklist, taskCount, 5, false);
			Assert::AreEqual(result, false);
		}
		TEST_METHOD(Testing_isIDPresent_EdgeCase1)
		{
			TASK tasklist[4] = { {2, "Try this", 0},
								{3, "Do that",0},
								{4, "Eat Breakfast", 0},
								{5, "Finish Project", 0} };
			int taskCount = 4;
			bool result = isIDPresent(tasklist, taskCount, 2, true);
			Assert::AreEqual(result, true);
		}
		TEST_METHOD(Testing_isIDPresent_EdgeCase2)
		{
			TASK tasklist[4] = { {2, "Try this", 0},
								{3, "Do that",0},
								{4, "Eat Breakfast", 0},
								{5, "Finish Project", 0} };
			int taskCount = 4;
			bool result = isIDPresent(tasklist, taskCount, 5, true);
			Assert::AreEqual(result, true);
		}
		TEST_METHOD(Testing_isIDPresent_Exception1)
		{
			TASK tasklist[4] = { {2, "Try this", 0},
								{3, "Do that",0},
								{4, "Eat Breakfast", 0},
								{5, "Finish Project", 0} };
			int taskCount = 4;
			bool result = isIDPresent(tasklist, taskCount, -5, true);
			Assert::AreEqual(result, false);
		}
		TEST_METHOD(Testing_isIDPresent_Exception2)
		{
			TASK tasklist[4] = { {2, "Try this", 0},
								{3, "Do that",0},
								{4, "Eat Breakfast", 0},
								{5, "Finish Project", 0} };
			int taskCount = 4;
			bool result = isIDPresent(tasklist, taskCount, 1500, true);
			Assert::AreEqual(result, false);
		}
		TEST_METHOD(Testing_updateTask_UsualCase1)
		{
			TASK tasklist[4] = { {2, "Try this", 0},
								{3, "Do that",0},
								{4, "Eat Breakfast", 0},
								{5, "Finish Project", 0} };
			int taskCount = 4;
			updateTask(tasklist, taskCount, 4, "Send a letter to him", 1);
			Assert::AreEqual(tasklist[2].description, "Send a letter to him");
		}
		TEST_METHOD(Testing_updateTask_UsualCase2)
		{
			TASK tasklist[4] = { {2, "Try this", 0},
								{3, "Do that",0},
								{4, "Eat Breakfast", 0},
								{5, "Finish Project", 0} };
			int taskCount = 4;
			updateTask(tasklist, taskCount, 5, NULL, 1);
			Assert::AreEqual(tasklist[3].completed, 1);
		}
		TEST_METHOD(Testing_AddTask_UsualCase1)
		{
			TASK tasklist[4];
			int taskCount = 0;

			AddTask(tasklist, &taskCount, 1, "Write unit test for addition", 0);
			Assert::AreEqual(taskCount, 1);
			Assert::AreEqual(tasklist[0].description, "Write unit test for addition");
		}
		TEST_METHOD(Testing_AddTask_UsualCase2)
		{
			TASK tasklist[10] = { {2, "Try this", 0},
								{3, "Do that",0},
								{4, "Eat Breakfast", 0},
								{5, "Finish Project", 0} };

			int taskCount = 4;

			AddTask(tasklist, &taskCount, 1, "Write unit test for addition", 0);
			Assert::AreEqual(5, taskCount);
			Assert::AreEqual(tasklist[0].description, "Try this");
			Assert::AreEqual(tasklist[1].description, "Do that");
			Assert::AreEqual(tasklist[4].description, "Write unit test for addition");
		}
		TEST_METHOD(Testing_DeleteTask_UsualCase1)
		{
			TASK tasklist[10] = { {2, "Try this", 0},
								{3, "Do that",0},
								{4, "Eat Breakfast", 0},
								{5, "Finish Project", 0} };

			int taskCount = 4;
			DeleteTask(tasklist, &taskCount, 2);
			Assert::AreEqual(taskCount, 3);
			Assert::AreEqual(tasklist[2].description, "Finish Project");
			DeleteTask(tasklist, &taskCount, 1);
			Assert::AreEqual(taskCount, 2);
			DeleteTask(tasklist, &taskCount, 0);
			Assert::AreEqual(taskCount, 1);
		}
	};
}
