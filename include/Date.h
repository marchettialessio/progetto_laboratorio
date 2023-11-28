#include <iostream>
#include <stdexcept>

class Date
{
	private:
	int d, m, y;  //char o short per d/m?
	
	public:
		//constructor
		Date();
		Date (int y, int m, int d);
		static string getDateFromString(std::string s);
		
		//getter
		int month(void) {return m;}
		int day(void) {return d;}
		int year(void) {return y;} 
		
		//setter
		void set_day(int d);
		void set_month(int m);
		void set_year(int y);
		
		//string
		std::string toString() const;
		
		
};
