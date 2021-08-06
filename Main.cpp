#include <iostream>
#include <thread>
#include <mutex>

// Some threading-test functions
void testOne(int a, int b) {
	bool higherThan = false;
	a > b ? higherThan = true : higherThan = false;
	if (higherThan)
		std::cout << a << " is superior to " << b << std::endl;
	else
		std::cout << a << " is not superior to " << b << std::endl;
}
void saySmth(std::string str) {
	std::cout << str << std::endl;
}

void to10A() {
	for (int i = 0; i < 10; i++) {
		std::cout << "A: " << i << std::endl;
	}
}
void to10B() {
	for (int i = 0; i < 10; i++) {
		std::cout << "B: " << i << std::endl;
	}
}

int main() {

	/* C++ THREADS PRACTICE */

	int a, b;
	std::cout << "Input value a then value b: " << std::endl;
	std::cin >> a; std::cin >> b; std::cout << "\n";

	//	Fetches current thread's ID (it will be Main thread here)
	std::thread::id main_thread_id = std::this_thread::get_id();
	std::cout << "Main thread ID: " << main_thread_id << std::endl;

	//	Create some thread objects
	std::thread t1(testOne, a, b);

	/*	You can specify the attached function's arguments 
		in the constructor of the thread. */
	std::thread t2(saySmth, "Bonjour tout le monde !");

	//	Fetches ongoing threads' IDs
	std::cout << "t1 ID: " << t1.get_id() << std::endl;
	std::cout << "t2 ID: " << t2.get_id() << std::endl;

	//	Make sure threads have ended before ending the program
	t1.join(); t2.join();
	std::cout << "\n\n" << std::endl;

}






