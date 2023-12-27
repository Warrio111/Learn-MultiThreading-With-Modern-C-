#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <thread>
using namespace std;
/*
Write a task function that increments a global int variable 100,000 times in a for loop.

Write a program that runs this function in concurrent threads. When all the threads have completed execution, print out the final value of the
counter.

Increase the number of threads until you see anomalous results.

Questions for this assignment
Implement the program as described. Check that your program compiles and runs.

Why does the program appear to give an incorrect result?

*/

int counter = 0;

int main()
{
		thread t1([]() {
		for (int i = 0; i < 100000; i++)
		{
			counter++;
		}
	});

	thread t2([]() {
		for (int i = 0; i < 100000; i++)
		{
			counter++;
		}
	});

	thread t3([]() {
		for (int i = 0; i < 100000; i++)
		{
			counter++;
		}
	});

	thread t4([]() {
		for (int i = 0; i < 100000; i++)
		{
			counter++;
		}
	});

	thread t5([]() {
		for (int i = 0; i < 100000; i++)
		{
			counter++;
		}
	});

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();

	cout << "Counter: " << counter << endl;
	
	return 0;
}