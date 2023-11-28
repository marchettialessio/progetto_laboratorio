#include "BookShelf.h"

BookShelf::BookShelf() : buffer_size_{0}, current_size_{0}, elem_{nullptr}
{
}

BookShelf::BookShelf(size_t s) : buffer_size_{s}, current_size_{0}, elem_{new Book[s]}
{
	if(s == 0){ elem_ = nullptr;}
}

BookShelf::BookShelf(std::initializer_list<double> lst) : buffer_size_{lst.size()}, current_size_{lst.size()}, elem_ {new Book[lst.size()]}
{
	std::copy(lst.begin(), lst.end(), elem_);

}

BookShelf::BookShelf(const BookShelf& a) : buffer_size_{a.buffer_size_}, current_size_{a.current_size_}, elem_{new Book[a.buffer_size_]}
{
	std::copy(a.elem_, a.elem_ + current_size_, elem_);	
}

BookShelf::BookShelf(BookShelf&& a) : buffer_size_{a.buffer_size_}, current_size_{a.current_size_}, elem_{a.elem_}
{
	a.buffer_size_ = 0;
	a.elem_ = nullptr;	
}

BookShelf& BookShelf::operator=(const BookShelf& a)
{
	Book* p = new Book[a.buffer_size_];
	std::copy(a.elem_, a.elem_ + a.current_size_, p);
	delete[] elem_;
	elem_ = p;
	current_size_ = a.current_size_;
	buffer_size_ = a.buffer_size_;
	return *this;
}

BookShelf BookShelf::operator=(BookShelf&& a)
{
	delete[] elem_;
	elem_ = a.elem_;
	current_size_ = a.current_size_;
	buffer_size_ = a.buffer_size_;
	a.elem_ = nullptr;
	a.buffer_size_ = 0;
	return *this;
}

const Book& BookShelf::at(const size_t pos) const
{
	if(pos >= current_size_ || pos < 0)
		throw std::out_of_range("Position out of size");
	
	return elem_[pos];
}

Book& BookShelf::at(const size_t pos)
{
	if(pos >= current_size_ || pos < 0)
		throw std::out_of_range("Position out of size");
	
	return elem_[pos];
}

void BookShelf::push_back(const Book& value)
{
	if(current_size_ >= buffer_size_)
	{
		try
		{
			if(buffer_size_ == 0)
				this->BookShelf::reserve(10);
			else
				this->BookShelf::reserve(buffer_size_*2);
		}
		catch(const std::bad_alloc ex)
		{
			std::cout << "Memory fault. Push not allowed";
		}
	}

	elem_[current_size_++] = value;
}

void BookShelf::pop_back()
{
	if(current_size_ > 0)
	{
		elem_[current_size_--] = 0;
	}
}

void BookShelf::reserve(const size_t dim)
{
	if(dim <= buffer_size_)
		return;
	
	Book *newAlloc = new Book[dim];
	std::copy(newAlloc, newAlloc + this->current_size_, this->elem_);
	
	this->buffer_size_ = dim;
	
	delete[] elem_;
	this->elem_ = newAlloc;
	newAlloc = nullptr;
}


