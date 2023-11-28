#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <regex>
#include "Date.h"
using namespace std;

class Book
{
	private:
		string isbn_, title_, nAuth_, snAuth_;
		Date copyright_;
		bool available_;
		
	
	public:
		//constructor
		Book();
		Book (const string& isbn_, const string& title_, const string& nAuth_, const string& snAuth_, const Date& copyright_);
		Book(const string& isbn, const string& title, const string& nAuth, const string& snAuth, const string& copyright);
		
		//copy (no move needed)
		Book(const Book & arg);						
		Book& operator=(const Book& arg);			
		
		//destructor
		~Book() = default; 				

		//setting methods
		void set_isbn(const string& isbn);
		void set_title(const string& title);
		void set_nAuth(const string& nAuth);
		void set_snAuth(const string& snAuth);
		void set_copyright(const Date& copyright);	
		
		//getter methods
		const string& get_isbn() const {return isbn_;}
		const string& get_title() const {return title_;}
		const string& get_nAuth() const {return nAuth_;}
		const string& get_snAuth() const {return snAuth_;}
		string get_copyright() const {return copyright_.toString();}
		bool get_available() const {return available_;}
	
		//loan functions
		void loan();
		void give_back();
		
		
};

bool operator==(const Book &a, const Book &b);
bool operator!=(const Book &a, const Book &b);
std::ostream& operator<<(std::ostream& out, const Book &other);

#endif
