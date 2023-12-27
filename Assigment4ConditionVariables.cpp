#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <string>

using namespace std;
using namespace std::chrono;

// Global variables
mutex mut;
condition_variable cv;
string sdata{ "Empty" };
bool data_ready{ false };

// Waiting thread
void reader() {
	while(true)
        {
            unique_lock<std::mutex> lg(mut); // Acquire lock
            while(!data_ready) 
            {
                lg.unlock();
                std::this_thread::sleep_for(10ms);
                lg.lock();
            }
            if (data_ready) break;
        }                              
	cout << "Data is " << sdata << endl;           
}

// Modyifing thread
void writer() {
	cout << "Writing data..." << endl;
        lock_guard<std::mutex> lg(mut);            // Acquire lock
		std::this_thread::sleep_for(2s);           // Pretend to be busy...
		sdata = "Populated";                       // Modify the data
	    data_ready = true;                          // Notify the flag
}

int main() {
	cout << "Data is " << sdata << endl;
	thread read{ reader };
	thread write{ writer };
	/*
	// If the writer thread finishes before the reader thread starts, the notification is lost
	thread write{writer};
	std::this_thread::sleep_for(500ms);
	thread read{reader};
	*/
	write.join();
	read.join();
}