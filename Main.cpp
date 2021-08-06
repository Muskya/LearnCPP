#include <iostream>
#include <thread>
#include <mutex>

int coin = 0;
std::mutex lock; // Mutex to synchronize threads on specific ressources

// Some threading-test functions
void ASCoin() {
	lock.lock(); // Exclusive access (one thread at a time)
	std::cout << "Coins before adding one: " << coin << std::endl;
	coin++; std::cout << "1 Coin Added" << std::endl;
	std::cout << "Coins after adding one: " << coin << std::endl;
	lock.unlock();
}

int main() {
	/* C++ THREADS PRACTICE */
	std::thread t1(ASCoin);
	std::thread t2(ASCoin);
	std::thread t3(ASCoin);

	t1.join(); t2.join(); t3.join();
}






