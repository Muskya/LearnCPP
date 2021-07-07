/* Exercice 3 (Tableaux Char Developpez)
Écrire une fonction qui a en paramètre une chaîne de caractères
(paramètre en entrée et en sortie) et qui transforme toutes les
minuscules de la chaîne en majuscules.*/

#pragma region Includes
/*SL headers*/
	//basics
	#include <iostream> 
	#include <string>
	#include <utility>
	#include <cstdlib> //for rand()
	#include <fstream>
/*STL headers*/
	#include <algorithm>
		//containers
			//sequencials
			#include <vector> 
			#include <deque>
			#include <array>
			#include <stack>
			#include <queue> //contains priority-queue as well
			#include <list>
			//associatives
			#include <map> //includes multimap.h
			#include <set> //includes multiset.h
	//pre-defined STL functors
	//https://www.cplusplus.com/reference/functional/
	#include <functional>
#pragma endregion

using namespace std;

int main() {
	/*---FILESTREAM PRACTICE---*/
	//output file stream (ofstream)
	std::string of_file("C:/temp/filetest_of.txt");				//file URL
	std::ofstream of_stream(of_file.c_str(), std::ios::app);	//output stream
	if (of_stream) {											//check for action success
		//could open the file
		of_stream << "Writing at the first line of the file." << endl;
		of_stream << "Additionning 2 + 18 = " << 2 + 18 << endl; 
	} else {
		cout << "Couldn't open file at :" << endl;
		cout << of_file << endl;
	}

	//input file stream (ifstream)
	std::string const if_file("C:/temp/filetest_if.txt");		//doesn't create the file automatically unlike ofstreams
	std::ifstream if_stream(if_file.c_str());					
	std::string l1, l2, l3;										//lines from the text file
	char c1, c2, c3;											//chars from the text file
	int i1, i2;													//integers from the text file
	float f1, f2;												//floats from the text file

	if (if_stream) {
		if_stream.ignore();
		std::getline(if_stream, l1);
		cout << l1;
	} else {
		cout << "Couldn't open file at :" << endl;
		cout << if_file << endl;
	}
}







