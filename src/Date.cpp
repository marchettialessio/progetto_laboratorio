#include <Date.h>

Date::Date():d{0},m{0},y{0} {}

Date:: Date(int day, int month, int year): set_day(day), set_month(month), set_year(year){}

void Date::set_day(int day)
{
	switch(month())
	{
		case 2 :
			if(y % 4 == 0 || y % 400 == 0)
			{
				if(day >= 1 && day <=29)
					d = day;
				else throw std::invalid_argument("invalid day");
			}
			else 
			{
				if(day >= 1 && day <=28)
						d = day;
				else throw std::invalid_argument("invalid day");
			}
			
		case 4 || 6 || 9 || 11 :
			if(day >= 1 && day <=30)
				d = day;
			else throw std::invalid_argument("invalid day");
		
		default: 
			if(day >= 1 && day <=31)
				d = day;
			else throw std::invalid_argument("invalid day");
	}
}

void Date::set_month(int month)
{
	if(month >= 1 && month <=12)
		m = month;
	else throw std::invalid_argument("invalid month")
	
}

void Date::set_year(int year)
{
	y = year;
}

std::string Date::toString() const 
{
    stringstream ss;
    ss << "day: " << day() << " month: " << month() << " year: " << year();
	
    return ss.str();
}
