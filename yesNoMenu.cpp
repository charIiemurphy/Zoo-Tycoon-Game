/*****************************************************************
 * Name: Charles Kusk
 * Date: April 20, 2019
 * Description: Simple 2 option menu that takes in a prompt
*****************************************************************/

#include <iostream>
#include <string>
#include "yesNoMenu.hpp"

char yesNoMenu(std::string prompt)
{		
	std::string input;
		
	// Repeats loop until a valid integer is entered
	while(1)
	{
		
		std::cout << prompt;
		std::cin >> input;
		
		if(input.length() > 1)
		{
			std::cout << "\nPlease enter only a single character!\n\n";
		}
		else
		{
			if(input == "y" || input == "Y")
			{
				return 'y';
			}
			else if(input == "n" || input == "N")
			{
				return 'n';
			}
			else
			{
				std::cout << "\nPlease enter either 'y' for yes or 'n' for no\n\n";
			}
		}		   		
		std::cin.clear();	//clears error flag
	}
}
