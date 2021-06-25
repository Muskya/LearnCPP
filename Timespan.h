#pragma once

/*

 .---. .-. .-..----..----.    .----. .----..----. .----.  .----. .-. .-..-. .-.
{_   _}| {_} || {_ /  {}  \   | {}  }| {_  | {}  }| {}  }/  {}  \| { } || {_} |
  | |  | { } || {__\      /   | .-. \| {__ | {}  }| {}  }\      /| {_} || { } |
  `-'  `-' `-'`----'`----'    `-' `-'`----'`----' `----'  `----' `-----'`-' `-'

*/

#include <iostream>
#include <string>
#include <ostream>

class Timespan
{
private:
	int m_seconds, m_minutes, m_hours;
	void showCout(std::ostream& stream) const;

public:
	~Timespan();
	Timespan(int sec = 0, int min = 0, int hours = 0);

	void showRev() const;
	void showStdr() const;

	//methods used for operator functions
	bool isEqual(Timespan const& ts) const;
	bool isLowerThan(Timespan const& ts) const;

	//more comparison functions (shortcut operators)
	//so they stay in the class (+=, -=, *=, /= ...)
	Timespan& operator+=(Timespan const& ts);
	Timespan& operator-=(Timespan const& ts);
	Timespan& operator*=(Timespan const& ts);
	//Timespan& operator/=(Timespan const& ts);
	
	//getters setters
	int getSeconds() const;
	int getMinutes() const;
	int getHours() const;
	void setSeconds(int sec); 
	void setMinutes(int min);
	void setHours(int hrs);

	//stream comparison operators functions <<, >> ...
	friend std::ostream& operator<<(std::ostream& stream, Timespan const& ts);
	//std::ostream &operator>>(std::ostream& stream(?), Timespan const& ts);
	//would be used so the user can input values directly into a Timespan
	//members but I guess it makes no sense ?
};

//Allows comparison operators between two Timespan objects

bool operator!=(Timespan const& ts1, Timespan const& ts2);
bool operator<(Timespan const& ts1, Timespan const& ts2); 
bool operator>(Timespan const& ts1, Timespan const& ts2);
bool operator<=(Timespan const& ts1, Timespan const& ts2);
bool operator>=(Timespan const& ts1, Timespan const& ts2);
//arithmetic ones would be
Timespan operator+(Timespan const& ts1, Timespan const& ts2);
Timespan operator+(Timespan const& ts1, int sec);
Timespan operator-(Timespan const& ts1, Timespan const& ts2);
Timespan operator*(Timespan const& ts1, Timespan const& ts2);
//we need the shortcut operators functions nested in the class
//(just like we used isEqual() and isLowerThan() functions to
//implement ==, !=, <, >, <=, >= operator functions.

