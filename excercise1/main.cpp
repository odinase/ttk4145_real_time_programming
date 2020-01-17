#include <thread>
#include <iostream>

int f() {
    std::cout << "Thread 1!\n";
}

int main() {
    std::thread t1(f);
    t1.join();
}