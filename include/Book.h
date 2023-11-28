#include <iostream>
#include <stdexcept>

class Date
{
	private:
	;
	
	public:
		//constructor
		Date();
		Date (int y, int m, int d);
		static string getDateFromString(string a);
		
		//getter methods
		int month(void);
		int day(void);
		int year(void);
		
		//setter methods
		void set_day(int d);
		void set_month(int m);
		void set_year(int y);
		
		//string
		string toString() const;
		
		
};
