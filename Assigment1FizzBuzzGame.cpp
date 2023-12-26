#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <thread>
using namespace std;
/*
A group of children sit in a circle, counting numbers out loud.

The first child says "one", the next child says "two", the next child says "three", and so on.

However, if the number is divisible by 3, they say "fizz" instead of the number. If the number is divisible by 5, they say "buzz", and if the number is divisible by 3 and by 5, they say "fizzbuzz".

Write a function which produces the output from a game of Fizzbuzz:

Abdul says 1

Bart says 2

Claudia says fizz!

Divya says 4

Abdul says buzz!

Bart says fizz!

Claudia says 7

Divya says 8

and so on...

Write a program which calls this function. Check that your program compiles and runs correctly.

Now modify your program so that it plays the game in a separate thread.
*/
void fizzbuzz(int n)
{
	for (int i = 1; i <= n; i++)
	{
		if (i % 3 == 0 && i % 5 != 0)
		{
			cout << "fizz" << endl;
		}
		else if (i % 5 == 0 && i % 3 != 0)
		{
			cout << "buzz" << endl;
		}
		else if (i % 3 == 0 && i % 5 == 0)
		{
			cout << "fizzbuzz" << endl;
		}
		else
		{
			cout << i << endl;
		}
	}
}
int main()
{
	// create a loop for entering numbers
	int n;
	bool flag = true;
	while (flag)
	{
		cout << "Enter a number: ";
		cin >> n;
		// if the number is 0, the loop ends
		if (0 == n)
		{
			flag = false;
		}
		else
		{
			//create a thread with a lambda function fizzbuzz
			thread t1([](int n) 
				{
					fizzbuzz(n);
				}, n);
			t1.join();
		}

	}
	
	return 0;
}