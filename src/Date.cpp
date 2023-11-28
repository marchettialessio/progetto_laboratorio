#include "Date.h"

Date::Date():d{0},m{0},y{0} {}

Date:: Date(int day, int month, int year){
	set_day(day);
	set_month(month);
	set_year(year);
}

/*Date::Date(const Date& date):d{date.d}, m{date.m}, y{date.y}{
	std::copy(date.d, date.y, d);
}*/

Date::Date(std::string s){
	if(!s.empty()) Date(std::stoi(s.substr(0,1)),std::stoi(s.substr(3,4)),std::stoi(s.substr(6,10)));
	else Date();
}


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
	else throw std::invalid_argument("invalid month");

}

void Date::set_year(int year)
{
	y = year;
}


/*----------------overloading operatore > tra due date-------------------------*/
bool operator>( Date date, Date today){
	if(date.year() > today.year()) return true;
	else if(date.year() == today.year() && date.month() > today.month()) return true;
	else if(date.year() == today.year() && date.month() == today.month() && date.day() > today.day()) return true;

	return false;
}


/*----------------controllo che la data sia valida e non sia successiva ad oggi-------------------------*/
bool Date::invalidDate(Date date){
	//da true se non valida
	if(date > today())return true;
	return false;
}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
    os << "date[ " << date.d << "/" << date.m << "/" << date.y  << "]";
    return os;
}

Date Date::today(){
	time_t data;
	tm *dataInfo;
	data=time(NULL); // ottiene l' ora odierna
	dataInfo=localtime(&data);
	Date today{dataInfo->tm_mday, dataInfo->tm_mon, dataInfo->tm_year+1900};
	return today;
}
