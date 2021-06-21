//Exercice 15
/*  */

#include <iostream> 
#include <string>

#include "GlobalFunctions.h"
#include "Character.h"
#include "Timespan.h"

using namespace std;

int main() {
	Character oui("Bjr", "Thunder", 20);
	oui.showThisPtr();
	Character* un = new Character(oui);
	un->showThisPtr();
}
