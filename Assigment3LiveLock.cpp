#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

int x{ 0 };
std::mutex mtx;

void func() {
    
    while (x == 0) {
        std::lock_guard<std::mutex> lock(mtx);
        x = 1 - x;
    }
}

int main()
{
    std::thread thr1{ func };
    std::thread thr2{ func };

    thr1.join();
    thr2.join();
}

