#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

class Book
{
	private:
		string ISBN_, title_, nAuth_, snAuth_;
		Date::Date copyright_;
		bool available_;
		
	
	public:
		//constructor
		Book();
		Book (string& ISBN_, string& title_, string& nAuth_, string& snAuth_, Date::date& copyright_);
		
		//copy
		Book(const Book & arg);						
		Book& operator=(const Book& arg);	
		
		//move
		Book(Book && arg); 						
		Book operator=(Book&& arg);			
		
		//destructor
		~Book(); 				
		
		
		//getter methods
		const string& get_ISBN() const {return ISBN_;}
		const string& get_title() const {return title_;}
		const string& get_nAuth() const {return nAuth_;}
		const string& get_snAuth() const {return snAuth_;}
		void get_copyright() const {copyright_.toString();} //oppure const riferimento?
		bool get_available() const {return available_}
	
		//loan function
		void loan();
		void give_back();
		
		
};

bool operator==(const Book &a, const Book &b);
bool operator!=(const Book &a, const Book &b);
std::ostream& operator<<(std::ostream& out, const Book &other);

#endif
