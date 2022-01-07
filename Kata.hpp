#include <iostream>
#include <vector>
#include <algorithm>

// https://www.codewars.com/kata/5541f58a944b85ce6d00006a/train/cpp 07 January 2022
typedef unsigned long long ull; 
class ProdFib {
public:
	static std::vector<ull> productFib(ull prod) {
		std::vector<ull> res;
		ull f0 = 0, f1 = 1, fn, tmp;
		bool done = false;

		do {
			res.clear();
			fn = f0 + f1;

			res.push_back(f1);
			res.push_back(fn);

			if (prod == (fn * f1)) {
				res.push_back(1);
				done = true;
			}
			else if ((fn * f1) > prod) {
				res.push_back(0);
				done = true;
			}

			tmp = f1;
			f1 = fn;
			f0 = tmp;
		} while (!done);
		return res;
	}

	// here is the best practice solution (mine was so bad omg)
	static std::vector<ull> productFibGood(ull prod) {
		ull a = 0, b = 1;
		while (a * b < prod) {
			std::swap(a, b);
			b += a;
		}
		return {a, b, ((a * b == prod) ? true : false)};
	}
};

// https://www.codewars.com/kata/5663f5305102699bad000056/train/cpp 31 Dec 2021
struct length {
	bool operator() (const std::string& a, const std::string& b) {
		return a.size() < b.size();
	}
};

class MaxDiffLength {
public:
	static int mxdiflg(std::vector<std::string>& a1, std::vector<std::string>& a2);
};

int MaxDiffLength::mxdiflg(std::vector<std::string>& a1, std::vector<std::string>& a2) {
	if ((a1.empty() || a2.empty()) || (a1.empty() && a2.empty())) return -1;
	auto max = 0;
	for (auto it = a1.begin(); it != a1.end(); ++it) {
		for (auto it2 = a2.begin(); it2 != a2.end(); ++it2) {
			auto diff = std::abs((int)(((*it).size()) - ((*it2).size())));
			if (diff > max) max = diff;
		}
	}
	return max;
}

// https://www.codewars.com/kata/57eae20f5500ad98e50002c5/train/cpp 10 Dec 2021
/* C'est un erase-remove idiom. Si on utilise que std::remove, on ne va supprimer les
espaces que LOGIQUEMENT. Cette fonction va shuffer les éléments à la suite à
un endroit dans le container (au début je crois) et renvoyer un iterator pointant l'élément juste après
le dernier caractère spécifié qui a été "enlevé". C'est ensuite avec std::erase que l'on supprime
ces caractères pour de bon du container, en partant de l'iterator renvoyé juste avant et en
arrivant à la fin de ce container avec end() */
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