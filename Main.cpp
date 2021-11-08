// C/C++ Standard Library Headers
#include <iostream>
#include <string>
#include <time.h>
#include <typeinfo>
// STL Headers
#include <array>
#include <vector>
#include <list>
#include <algorithm>
#include <memory>
#include <utility>

void copyVector(unsigned long n)
{
	std::vector<int> myVector;
	for (int i = 0; i < n; ++i) {
		myVector.push_back(n / 10 + i);
	}
	std::vector<int> vec2;
	for (int i = myVector.size()-1; i >= 0; --i) {
		vec2.push_back(myVector[i]);
	}
}

enum class Action { Sleeping, Working, Playing, Eating };
std::ostream& operator<<(std::ostream& out, Action act) {
	switch (act) {
	case Action::Sleeping:
		out << "Sleeping";
		break;
	case Action::Working:
		out << "Working";
		break;
	case Action::Playing:
		out << "Playing";
		break;
	case Action::Eating:
		out << "Eating";
		break;
	default:
		break;
	}
	return out;
}

int main()
{
	Action act = Action::Working;
	std::cout << act << std::endl;
}