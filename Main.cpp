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

	//OUTPUT FILE STREAM (ofstream)
	std::string of_file("C:/temp/filetest_of.txt");				//file URL
	std::ofstream of_stream(of_file.c_str(), std::ios::app);	//output stream. ios::app is for append mode
	if (of_stream) {											//check for action success
		//could open the file
		of_stream << "Appending one more line to the file." << endl;
	}
	else {
		cout << "Couldn't open file at :" << endl;
		cout << of_file << endl;
	} cout << "\n";

	//INPUT FILE STREAM (ifstream)
	std::string const if_file("C:/temp/filetest_if.txt");		//doesn't create the file automatically unlike ofstreams
	std::ifstream if_stream(if_file.c_str());
	std::string l1, l2, l3;										//lines from the text file
	char c1, c2, c3;											//chars from the text file
	int i1, i2;													//integers from the text file
	float f1, f2;												//floats from the text file

	cout << "----------Displaying the whole filetest_if.txt file------------" << endl;
	if (if_stream) {
		while (getline(if_stream, l1)) {						//till we get to the last line
			cout << l1 << endl;
		}
		cout << "---------------------------------------------------------------" << endl; 

		//number of characters in the file
		int chars_number = 0;
		while (if_stream.get(c1)) {
			chars_number++;
		}
		cout << "\nThere are " << chars_number << " characters in the file \"filetest_if.txt\"." << endl;
	}
	else {
		cout << "Couldn't open file at :" << endl;
		cout << if_file << endl;
	} cout << "\n";

	/* when declaring streams, the associated files are opened automatically. when going out of the scope where
	* they were declared from, they also close automatically. we can also explicitly call for the opening/closing of
	* these streams but its mostly a question of taste to pinpoint where and when they are opened. the functions are
	* open() and close(), easy as 123. */

	//WORK WITH THE CURSOR (of/ifstream)
	int if_pos = if_stream.tellg();								//tellg = tell the get pointer position. (ifstreams)
	int of_pos = of_stream.tellp();								//tellp = tell the put pointer position. (ofstreams)
	cout << "ifstream cursor position: " << if_pos << endl;
	cout << "ofstream cursor position: " << of_pos << endl;
	cout << "\n";
	
	if_stream.seekg(10, std::ios::beg);							//seekg = moves get cursor 10 chars from beginning of file.
	of_stream.seekp(24, std::ios::beg);							//seekp = moves put cursor 24 chars from beginning of file.
																//2nd argument can be "std::ios::beg", "std::ios::end", "std::ios:::cur"

	of_stream << "At the middle of the first sentence.";		//writes the passed string into the file after the 24th cursor position.
	getline(if_stream, l2);										//puts into l2 the remaining of the line after the 10th cursor position.
	cout << l2 << "\n";

	//FILE SIZE
	if_stream.seekg(0, std::ios::end);
	int ifstream_size = if_stream.tellg();						//file size is basically the cursor current position. (in bytes)
	cout << "filetest_if.txt's size is about: " << ifstream_size << " bytes / octets." << endl;
}







