#include <mutex>
#include <thread>
#include <vector>
#include <atomic>
#include <future>
#include <iostream>

using namespace std;
/*You will write a program which is similar to the second example in the lecture, but without using a packaged task. (For reference, the code used in the lecture is attached as a downloadable resource)

Your program will create two threads. The task function for the first thread will add together its arguments and store the result in a promise object.

The second thread will display the result of the addition performed by the first thread.

Questions for this assignment
Check that your program compiles and runs correctly.*/
void task(int x, int y, promise<int>& p) {
	p.set_value(x + y);
}
int display(promise<int>& p) {
	cout << p.get_future().get() << endl;
	return 0;
}

int main() {
	// Create an std::promise object
	// This creates an associated std::future object
	// and sets up a shared state between them
	promise<int> p;

	thread t1(task, 2, 9, ref(p));
	thread t2(display, ref(p));
	t1.join();
	t2.join();


}