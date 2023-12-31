#ifndef BookShelf_H
#define BookShelf_H

#include <algorithm>
#include "Book.h"

class BookShelf
{
	public:
		BookShelf();
		BookShelf(size_t s = kDefaultSize);		
		BookShelf(const BookShelf& arg);	
		BookShelf(BookShelf&& arg);
		~BookShelf() {delete[] elem_; }
		
		BookShelf& operator=(const BookShelf& a);
		BookShelf operator=(BookShelf&& a);
		
		Book& operator[] (int n) {return elem_[n]; }
		Book operator[] (int n) const {return elem_[n]; }

		void push_back(const Book& value);
		void pop_back();
		int size(){ return current_size_; }
		void reserve(const size_t dim);
		
		const Book& at(const size_t pos) const;
		Book& at(const size_t pos);
		
		size_t get_buffer_size() const {return buffer_size_;}
		size_t get_current_size() const {return current_size_;}
		
	private:

		size_t buffer_size_;
		size_t current_size_;
		Book *elem_;
		
		static const int kDefaultSize = 0;
};

#endif 
