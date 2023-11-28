#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <stdexcept>
#include <time.h>
#include <string>

class Date
{
	private:
	int d, m, y;
	
	public:
		//constructor
		Date();
		Date(const Date& date);
		Date(int y, int m, int d);
		Date(std::string s); 		//constructor by input string
		
		//getter
		int month(void) const {return m;}
		int day(void) const {return d;}
		int year(void) const {return y;} 
		
		//setter
		void set_day(int d);
		void set_month(int m);
		void set_year(int y);
		
		//helper
		bool invalidDate(const Date& date) const;
		Date today() const;

		//string
		std::string toString() const;
		
};

//operator
bool operator>(const Date date, const Date today);
std::ostream& operator<<(std::ostream& os, const Date& date);

#endif
