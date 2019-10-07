/******************************************************************
 * Name: Charles Kusk
 * Date: April 18, 2019
 * Description: Create a zoo tycoon game.  Allows player to run a zoo business
 * 		with different types of animals that have different maintenance
 * 		costs and profits.  
******************************************************************/

#include <iostream>
#include <string>
#include <stdlib.h>		// srand(), rand();
#include <time.h>		// time()

#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include "Zoo.hpp"
#include "yesNoMenu.hpp"

int main()
{	
	srand(time(0));		// Seed random function
	Zoo myZoo;		// Initialize zoo object

	std::string introPrompt = "\n\n\n\nWelcome to Zoo Tycoon!!!\nWould you like to start a game?\n'y' = yes, and 'n' = no : ";
	char userDecision;
	userDecision = yesNoMenu(introPrompt);
	
	// User chooses to play game
	if(userDecision == 'y')
	{
		myZoo.startGame();
	}
	// User chooses to not play game
	else
	{
		std::cout << "Thank you for using my program, goodbye\n\n";
	}	

	return 0;
}
