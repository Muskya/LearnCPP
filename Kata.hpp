#include <iostream>
#include <vector>
#include <algorithm>

// https://www.codewars.com/kata/57eae20f5500ad98e50002c5/train/cpp 10 Dec 2021
/* C'est un erase-remove idiom. Si on utilise que std::remove, on ne va supprimer les
espaces que LOGIQUEMENT. Cette fonction va shuffer les �l�ments � la suite �
un endroit dans le container (au d�but je crois) et renvoyer un iterator pointant l'�l�ment juste apr�s
le dernier caract�re sp�cifi� qui a �t� "enlev�". C'est ensuite avec std::erase que l'on supprime
ces caract�res pour de bon du container, en partant de l'iterator renvoy� juste avant et en
arrivant � la fin de ce container avec end() */
std::string no_space(std::string x) {
	x.erase(std::remove(x.begin(), x.end(), ' '), x.end());
	return x;
}

// https://www.codewars.com/kata/577a98a6ae28071780000989/train/cpp 10 Dec 2021
int vectorMin(std::vector<int> list) {
    return *std::min_element(list.begin(), list.end());
}
int vectorMax(std::vector<int> list) {
    return *std::max_element(list.begin(), list.end());
}

// https://www.codewars.com/kata/5556282156230d0e5e000089/train/cpp 10 Dec 2021
std::string dnaToRna(std::string dna) {
	for (size_t i = 0; i < dna.length(); ++i) {
		if (dna[i] == 'T') dna[i] = 'U';
	}
	return dna;
}