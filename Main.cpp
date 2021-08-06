#include <iostream>
#include <thread>

// Some threading-test functions
void to20() {
	for (int i = 0; i < 20; i++) {
		std::cout << "Boucle une: " << i << std::endl;
	}
}
void to10() {
	for (int i = 0; i < 10; i++) {
		std::cout << "Boucle deux: " << i << std::endl;
	}
}
void saySmth(std::string str) {
	std::cout << str << std::endl;
}

int main() {
	/* C++ THREADS PRACTICE */

	// Create some thread objects
	std::thread t1(to20);
	std::thread t2(to10);

	/* You can specify the attached function's arguments 
    in the constructor of the thread. */
	std::thread t3(saySmth, "Bonjour tout le monde !");

	// Make sure threads have ended before ending the program
	t1.join(); t2.join(); t3.join();
}






