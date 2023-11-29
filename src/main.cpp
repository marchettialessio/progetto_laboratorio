#include "BookShelf.h"

int main(void)
{

	BookShelf shelf(10);
    
	try
	{
	        Book b1("9781234567891","Il buio oltre la siepe","Morgana","Fielman",Date(12,6,2012));
	        Book b2("9781234567892","Moby Dick","Fred","Alfred",Date(22,5,2002));
	        Book b3("9781234567893","Aria di guerra","Laura","May",Date(3,11,1987));
	        Book b4(b3);
	        Book mybook("9781234567894","Teo e Ale","Fil","Foster",Date(28,12,2022));
	
	        shelf.push_back(b1);
	        shelf.push_back(b2);
	        shelf.push_back(mybook);
	        shelf.push_back(b3);
	    
	    
	        //Other test
	        
	    	std::cout << "Book in position = 2" << shelf[2] << "\n\n";
	    
	    
	    	try
	    	{
	    		std::cout << "> Test at function\n\n";
	    		std::cout << "Book in position = 1 before" << shelf[1] << "\n";
	    		shelf.at(1)=b4;
	    		std::cout << "> Book in position = 1 after" << shelf.at(1) << "\n\n";
	    
	    		std::cout << "Test range contol --> ";
	    		shelf.at(12);
	    	}
	    	catch(const std::out_of_range ex)
	    	{
	    		std::cout << "Position in tested functions out of size!\n\n";	
	    	}
	    
	    	std::cout << "Size before push: " << shelf.get_current_size() << "\n";
	    	shelf.push_back(b2);
	    	std::cout << "Size after push: " << shelf.get_current_size() << "\n\n";
		
	}
	catch(std::invalid_argument ex)
	{
	    std::cout << "Initialization error: " << ex.what() << "\n";
	}


	return 0;
}
