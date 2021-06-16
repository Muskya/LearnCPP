/* 
 .---. .-. .-..----..----.    .----. .----..----. .----.  .----. .-. .-..-. .-.
{_   _}| {_} || {_ /  {}  \   | {}  }| {_  | {}  }| {}  }/  {}  \| { } || {_} |
  | |  | { } || {__\      /   | .-. \| {__ | {}  }| {}  }\      /| {_} || { } |
  `-'  `-' `-'`----'`----'    `-' `-'`----'`----' `----'  `----' `-----'`-' `-'
 */


#include "Timespan.h"
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

Timespan::~Timespan() {}
Timespan::Timespan(int sec, int min, int hrs) : m_seconds(sec), m_minutes(min), 
	m_hours(hrs)
{
	//Conversion
	if (sec > 60) { 
		min += sec / 60;
		m_seconds = sec % 60;	
	} 
	if (min > 60) {
		m_hours += min / 60;
		m_minutes = min % 60;
	}
}

void Timespan::showRev() const {
	cout << "Seconds: " << m_seconds << ", Minutes: " << m_minutes <<
		", Hours: " << m_hours << endl;
}
void Timespan::showStdr() const {
	cout << "Hours: " << m_hours << ", Minutes: " << m_minutes <<
		", Seconds: " << m_seconds << endl;
}
void Timespan::showCout(ostream& stream) const { //for cout << timespan obj use
	stream << "Sec: " << this->m_seconds << ", Min: " << this->m_minutes <<
		", Hrs: " << this->m_hours;
}

//only made for use in operator==() function. //could use getters in operator==()
//to avoid making this function.
bool Timespan::isEqual(Timespan const& ts) const {
	return (this->m_seconds == ts.m_seconds && this->m_minutes == ts.m_minutes
		&& this->m_hours == ts.m_hours);
}
bool Timespan::isLowerThan(Timespan const& ts) const {
	if (m_hours < ts.m_hours) 
		return true;
	else if (m_hours == ts.m_hours && m_minutes < ts.m_minutes) 
		return true;
	else if (m_hours == ts.m_hours && m_minutes == ts.m_minutes
		&& m_seconds < ts.m_seconds)
		return true;
	else              
		return false;
}
Timespan& Timespan::operator+=(Timespan const& ts) {
	this->m_seconds += ts.m_seconds;
	this->m_minutes += ts.m_minutes;
	this->m_hours += ts.m_hours;
	
	//conversion for >60 values on secs and mins
	if (this->m_seconds > 60) {
		this->m_minutes += this->m_seconds / 60;
		this->m_seconds = this->m_seconds % 60;
	} 
	if (this->m_minutes > 60) {
		this->m_hours += this->m_minutes / 60;
		this->m_minutes = this->m_minutes % 60;
	}

	return *this;
}
Timespan& Timespan::operator-=(Timespan const& ts) {
	this->m_seconds -= ts.m_seconds;
	this->m_minutes -= ts.m_minutes;
	this->m_hours -= ts.m_hours;

	if (m_seconds < 0) m_seconds = 0;
	if (m_minutes < 0) m_minutes = 0;
	if (m_hours < 0) m_hours = 0;

	return *this;
}
Timespan& Timespan::operator*=(Timespan const& ts) {
	this->m_seconds *= ts.m_seconds;
	this->m_minutes *= ts.m_minutes;
	this->m_hours *= ts.m_hours;

	//conversion for >60 values on secs and mins
	if (this->m_seconds > 60) {
		this->m_minutes += this->m_seconds / 60;
		this->m_seconds = this->m_seconds % 60;
	}
	if (this->m_minutes > 60) {
		this->m_hours += this->m_minutes / 60;
		this->m_minutes = this->m_minutes % 60;
	}

	return *this;
}

/// / / / IMPLEMENTATION OF COMPARISON METHODS // / / / / / / / /

//no "Timespan::" because this function is out of class in .h
bool operator==(Timespan const& ts1, Timespan const& ts2) {
	//could use getters for comparison here, so we dont need isEqual() method
	//but its more generic
	return ts1.isEqual(ts2);
	/*return (ts1.getSeconds() == ts2.getSeconds() && ts1.getMinutes() ==
		ts2.getMinutes() && ts1.getHours() == ts2.getHours()); works too */
}
bool operator!=(Timespan const& ts1, Timespan const& ts2) {
	return !(ts1.isEqual(ts2));
	//return !(ts1==ts2); works too
}
bool operator<(Timespan const& ts1, Timespan const& ts2) {
	//could use getters for comparison here too
	return ts1.isLowerThan(ts2);
}
bool operator>(Timespan const& ts1, Timespan const& ts2) {
	return (!ts1.isLowerThan(ts2) && !ts1.isEqual(ts2));
	//if ts1 is NOT lower than ts2 (>=) AND is NOT equal to ts2 (>)
}
bool operator<=(Timespan const& ts1, Timespan const& ts2) {
	return (ts1.isLowerThan(ts2) || ts1.isEqual(ts2));
	//if ts1 IS lower than ts2 (<) OR ts1 is EQUAL to ts2 (<=) 
}
bool operator>=(Timespan const& ts1, Timespan const& ts2) {
	return (!ts1.isLowerThan(ts2));
	//if ts1 is NOT lower than ts2 (>=) 
}

//we need operator+ and operator+= functions cuz they both work differently
//we cannot store the result of a "+" operation in a variable if we only
//implemented a operator+=() function, cuz a += b affects a, and because of
//encapsulation concepts we most of the time dont want to modify an object.
Timespan operator+(Timespan const& ts1, Timespan const& ts2) {
	//copy of ts1
	Timespan cpyTS1(ts1);
	cpyTS1 += ts2; //we need the operator+=, operator-= etc first to do this.
	return cpyTS1;
	//could use getters / setters method so we dont need to implement a
	//operator+=() function above, but this method is less generic, and
	//makes impossible the usage of "const&" in parameters, which is TERRIBLE
	//for encapsulation.
}
Timespan operator+(Timespan const& ts1, int sec) {
	Timespan cpyTS1(ts1);
	cpyTS1.setSeconds(cpyTS1.getSeconds() + sec);
	return cpyTS1;
}
Timespan operator-(Timespan const& ts1, Timespan const& ts2) {
	Timespan cpyTS1(ts1);
	cpyTS1 -= ts2;
	return cpyTS1;
	//could use getters / setters method so we dont need to implement a
	//operator+=() function above, but this method is less generic
}
Timespan operator*(Timespan const& ts1, Timespan const& ts2) {
	Timespan cpyTS1(ts1);
	cpyTS1 *= ts2;
	return cpyTS1;
	//could use getters / setters method so we dont need to implement a
	//operator+=() function above, but this method is less generic
}

ostream& operator<<(ostream& stream, Timespan const& ts) {
	ts.showCout(stream);
	return stream;
}

//getters setters
int Timespan::getSeconds() const { return this->m_seconds; }
int Timespan::getMinutes() const { return this->m_minutes; }
int Timespan::getHours() const { return this->m_hours; }
void Timespan::setSeconds(int sec) { this->m_seconds = sec; }
void Timespan::setMinutes(int min) { this->m_minutes = min; }
void Timespan::setHours(int hrs) { this->m_hours = hrs; }
