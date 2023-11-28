#include "Book.h"

Book::Book() : isbn_{"None"}, title_{"None"}, nAuth_{"None"}, snAuth_{"None"}, available_{false}
{
}

Book::Book(const string& isbn, const string& title, const string& nAuth, const string& snAuth, const Date& copyright) : available_{true}
{
	set_isbn(isbn);
	this->title_ = title;
	this->nAuth_ = nAuth;
	this->snAuth_ = snAuth;
	set_copyright(copyright);
}

Book::Book(const string& isbn, const string& title, const string& nAuth, const string& snAuth, const string& copyright) : available_{true}
{
	set_isbn(isbn);
	this->title_ = title;
	this->nAuth_ = nAuth;
	this->snAuth_ = snAuth;
	set_copyright(Date(copyright));
}

Book::Book(const Book& arg)
{
	this->isbn_ = arg.isbn_;
	this->title_ = arg.title_;
	this->nAuth_ = arg.nAuth_;
	this->snAuth_ = arg.snAuth_;
	this->copyright_ = arg.copyright_; 
	this->available_ = arg.available_;
}

Book& Book::operator=(const Book& arg)
{
	this->isbn_ = arg.isbn_;
	this->title_ = arg.title_;
	this->nAuth_ = arg.nAuth_;
	this->snAuth_ = arg.snAuth_;
	this->copyright_ = arg.copyright_; 
	this->available_ = arg.available_;
	return *this;
}

/*--- setting and input validation ---*/
void Book::set_isbn(const string& isbn)
{
	if(isbn.length() != 13)
		throw std::invalid_argument("Invalid ISBN. Length should be 13");
	
	if(regex_match(isbn, regex("978[0-9]+")))
		this->isbn_=isbn;
	else
		throw std::invalid_argument("Invalid ISBN format");
}

void Book::set_title(const string& title)
{
	this->title_ = title;
}

void Book::set_nAuth(const string& nAuth)
{
	this->nAuth_ = nAuth;
}

void Book::set_snAuth(const string& snAuth)
{
	this->snAuth_ = snAuth;
}

void Book::set_copyright(const Date& copyright)
{
	if(copyright.Date::invalidDate(copyright))
		throw std::invalid_argument("Invalid copyright date");	//check date isLower or equal then "today"

	this->copyright_ = Date(copyright);
}

/*--- loan functions setting "available_" member ---*/
void Book::loan()
{
	available_ = false;
}

void Book::give_back()
{
	available_ = true;
}

bool operator==(const Book &a, const Book &b)
{
	if(a.get_isbn().compare(b.get_isbn())==0)
		return true;
	else
		return false;
}

bool operator!=(const Book &a, const Book &b)
{
	if(a.get_isbn().compare(b.get_isbn())!=0)
		return true;
	else
		return false;
		
}

std::ostream& operator<<(std::ostream& out, const Book &arg)
{
	return out << "\nISBN: " << arg.get_isbn() << "\nTitle: " << arg.get_title() << "\nAutore: " 
		<< arg.get_nAuth() << " " << arg.get_snAuth() << "\nCopyright: " << arg.get_copyright() << "\n";
}