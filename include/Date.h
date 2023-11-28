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
		Date (int y, int m, int d);
		Date(std::string s); //constructor by input string
		
		//getter
		int month(void) {return m;}
		int day(void) {return d;}
		int year(void) {return y;} 
		
		//setter
		void set_day(int d);
		void set_month(int m);
		void set_year(int y);
		
		//helper
		bool invalidDate(Date date);
		Date DateCopy(Date date); // deep copy

		//string
		std::string toString();
		
};

//operator
friend bool operator>( Date date,  Date today);

#endif
