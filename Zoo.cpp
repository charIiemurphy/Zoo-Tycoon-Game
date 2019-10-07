/******************************************************************
 * Name: Charles Kusk
 * Date: April 20, 2019
 * Description: Defines memeber fuctions of Zoo class
******************************************************************/

#include <iostream>
#include <string>
#include <stdlib.h>		// srand(), rand();

#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include "Zoo.hpp"
#include "yesNoMenu.hpp"
#include "intValidationMax.hpp"

/*****************************************************************
 * Description: Constructor of zoo class
*****************************************************************/
Zoo::Zoo()
{
	userCash = 100000;
	day = 0;
	bonus = 0;
}

/*****************************************************************
 * Description: Starts game and contains most logic
******************************************************************/
void Zoo::startGame()
{
	int dailyCost, dailyProfit, purchaseDecision;
	char repeatDecision;	
	bool continuePlaying = true;
	
	// Initialize animal arrays
	tigerArray   = new Tiger[10];
	penguinArray = new Penguin[10];
	turtleArray  = new Turtle[10];

	// Initial purchase of animals to begin game
	initialPurchase();

	while(continuePlaying)
	{
		bonus = 0;	//  reset bonus

		// Age all animals one day, make adults if 3 or older
		ageAnimals();	

		// Pay feeding cost of each animal
		dailyCost = (numTigers   * tigerArray[0].getBaseFoodCost())	
			  + (numPenguins * penguinArray[0].getBaseFoodCost())
			  + (numTurtles  * turtleArray[0].getBaseFoodCost());

		userCash = userCash - dailyCost;
		
		// Perform randomized event
		randomEvent();
	
		// Calculate profit for the day
		dailyProfit = (numTigers   * tigerArray[0].getPayoff())
			    + (numPenguins * penguinArray[0].getPayoff())
			    + (numTurtles  * turtleArray[0].getPayoff());

		userCash = userCash + dailyProfit;

		// If there is a bonus, add that
		userCash = userCash + (bonus * numTigers);

		// Giver user update of game
		std::cout << "\nYou currently have \n" << numTigers << " Tigers\n" << numPenguins << " Penguins\n" 
			  << numTurtles << " Turtles\n" << "The feeding costs were $" << dailyCost  
			  << "\nThe profits were $" << dailyProfit << "\nAnd you currently have $" << userCash << "\n\n";
	
		// Ask user if they would like to purchase an animal (can only purchase adult, will be 3 days old at purchase)
		std::cout << "Would you like to purchase an animal?\n1. Tiger\n2. Penguin\n3. Turtle\n4. Do not purchase animal\n";
		purchaseDecision = intValidationMax(4);

		// Purchase animal based on passed in decision which is only parameter
		purchaseAnimal(purchaseDecision);
	
		// Ask user if they would like to continue playing (if they have money)	
		if(userCash > 0)
		{
			std::string repeatPrompt = "Would you like to continue another day? yes = 'y', no = 'n'\n";
			repeatDecision = yesNoMenu(repeatPrompt);
				
			// If user does not want to continue playing set continuePlaying to false
			if(repeatDecision == 'n')
			{
				continuePlaying = false;
			}
		}
		// If user does not have any money
		else
		{
			std::cout << "Sorry but you have run out of money! Game over!!!\n\n";
			continuePlaying = false;
		}
	}

	// Deallocate memory
	delete [] tigerArray;
	delete [] penguinArray;
	delete [] turtleArray;
}


/*************************************************************
 * Description: Initial purchase of animals
*************************************************************/
void Zoo::initialPurchase()
{
	maxTigers = maxPenguins = maxTurtles = 10;

	std::cout << "\n\nYou will begin zoo tycoon by purchasing either 1 or 2 tigers, penguins, and turtles.\n"
		  << "You will start with " << userCash << "$\n" << "How many tigers ($10,000) would you like: ";
	numTigers = intValidationMax(2);
	for(int j = 0; j < numTigers; j++)
	{
		tigerArray[j].setAge(1);	// All newly bought animals initialize to 1 day old
	}
	userCash = userCash - (numTigers * tigerArray[0].getCost());
 
	std::cout << "\nHow many Penguins ($1,000) would you like: ";
	numPenguins = intValidationMax(2);
	for(int j = 0; j < numPenguins; j++)
	{
		penguinArray[j].setAge(1);	// All newly bought animals initialize to 1 day old
	}
	userCash = userCash - (numPenguins * penguinArray[0].getCost());

	std::cout << "\nHow many Turtles ($100) would you like: ";
	numTurtles = intValidationMax(2);
	for(int j = 0; j < numTurtles; j++)
	{
		turtleArray[j].setAge(1);	// All newly bought animals initialize to 1 day old
	}
	userCash = userCash - (numTurtles * turtleArray[0].getCost());
}



/*************************************************************
 * Description: Ages all alive animals by one day
*************************************************************/
void Zoo::ageAnimals()
{
	for(int i = 0; i < numTigers; i++)
	{
		tigerArray[i].setAge(tigerArray[i].getAge() + 1);	  // Increment age one day
		if(tigerArray[i].getAge() > 2)			
		{
			tigerArray[i].setIsAdult(true);       	   	  // Make adult if 3 or older
		}
	}
	for(int i = 0; i < numPenguins; i++)
	{
		penguinArray[i].setAge(penguinArray[i].getAge() + 1);	 // Increment age one day 
		if(penguinArray[i].getAge() > 2)
		{
			penguinArray[i].setIsAdult(true);		  // Make adult if 3 or older
		}
	}
	for(int i = 0; i < numTurtles; i++)
	{
		turtleArray[i].setAge(turtleArray[i].getAge() + 1);   // Increment age one day
		if(turtleArray[i].getAge() > 2)
		{
			turtleArray[i].setIsAdult(true);	  // Make adult if 3 or older
		}			
	}
}	

/***************************************************************************
 * Description: Purchases animal for user if they choose
***************************************************************************/
void Zoo::purchaseAnimal(int decisionIn)
{
	switch(decisionIn)
	{
		case 1:
			numTigers++;
			
			// If tiger array fills up
			if(numTigers >= maxTigers)
			{
				// Create new array that will be double the size
				Tiger *newTiger = new Tiger[maxTigers * 2];
				for(int i = 0; i < maxTigers; i++)
				{
					// Copy everything from olda rray into new
					newTiger[i] = tigerArray[i];
				}
				// Delete old array
				delete [] tigerArray;
				tigerArray = newTiger;
				// Double size of array
				maxTigers *= 2;
			} 

			userCash = userCash - tigerArray[0].getCost();
			std::cout << "\nYou have purchased a tiger!\n";
			break;
		case 2:
			numPenguins++;

			// If penguin array fills up
			if(numPenguins >= maxPenguins)
			{
				// Create new array that will be double the size
				Penguin *newPenguin = new Penguin[maxPenguins * 2];
				for(int i = 0; i < maxPenguins; i++)
				{
					// Copy everything from old array into new
					newPenguin[i] = penguinArray[i];
				}
				// Delete old array
				delete [] penguinArray;
				penguinArray = newPenguin;
				// Double size of array
				maxPenguins *= 2;
			} 

			userCash = userCash - penguinArray[0].getCost();
			std::cout << "\nYou have purchased a penguin!\n";
			break;
		case 3:
			numTurtles++;

			// If turtle array fills up
			if(numTurtles >= maxTurtles)
			{
				// Create new array that will be double the size
				Turtle *newTurtle = new Turtle[maxTurtles * 2];
				for(int i = 0; i < maxTurtles; i++)
				{
					// Copy everything from olda rray into new
					newTurtle[i] = turtleArray[i];
				}
				// Delete old array
				delete [] turtleArray;
				turtleArray = newTurtle;
				// Double size of array
				maxTurtles *= 2;
			} 


			userCash = userCash - turtleArray[0].getCost();
			std::cout << "\nYou have purchased a turtle!\n";
			break;
		case 4:
			break;
	}		
}

/***************************************************************************
 * Description: Decide random event to happen
***************************************************************************/
void Zoo::randomEvent()
{	
	int randomEvent = (rand() % 4) + 1;

	switch(randomEvent)
	{
		// A sickness occurs (one animal dies)
		case 1:
			{
				int animalDeath = (rand() % 3) + 1; // Chooses a number 1 to 3
				// Tiger
				if(animalDeath == 1)
				{
					if(numTigers > 0)
					{			
						// Decrement tigers
						numTigers--;	
						// Set tiger to not alive at array location			
						tigerArray[numTigers].setIsAlive(false);
						std::cout << "\n\nOne of your tigers has died!\n\n";
					}
					else if(numPenguins > 0)
					{
						numPenguins--;
						penguinArray[numPenguins].setIsAlive(false);

						std::cout << "\n\nOne of your penguins has died!\n\n";
					}
					else if(numTurtles > 0)
					{
						numTurtles--;
						turtleArray[numTurtles].setIsAlive(false);
						std::cout << "\n\nOne of your turtles has died!\n\n";
					}
					else
					{
						std::cout << "\n\nAll your animals are dead\n\n";
					}
				}
				// Penguin
				else if(animalDeath == 2)
				{
					if(numPenguins > 0)
					{			
						// Decrement Penguins
						numPenguins--;	
						// Set Penguin to not alive at array location			
						penguinArray[numPenguins].setIsAlive(false);
						std::cout << "\n\nOne of your penguins has died!\n\n";
					}
					else if(numTurtles > 0)
					{
						numTurtles--;
						turtleArray[numTurtles].setIsAlive(false);
						std::cout << "\n\nOne of your turtles has died!\n\n";
					}
					else if(numTigers > 0)
					{
						numTigers--;
						tigerArray[numTigers].setIsAlive(false);
						std::cout << "\n\nOne of your tigers has died!\n\n";
					}
					else
					{
						std::cout << "\n\nAll your animals are dead\n\n";
					}
				}
				// Turtle
				else
				{
					if(numTurtles > 0)
					{			
						// Decrement turtles
						numTurtles--;	
						// Set turtle to not alive at array location			
						turtleArray[numTurtles].setIsAlive(false);
						std::cout << "\n\nOne of your turtles has died!\n\n";
					}
					else if(numTigers > 0)
					{
						numTigers--;
						tigerArray[numTigers].setIsAlive(false);
						std::cout << "\n\nOne of your tigers has died!\n\n";
					}
					else if(numPenguins > 0)
					{
						numPenguins--;
						penguinArray[numPenguins].setIsAlive(false);
						std::cout << "\n\nOne of your penguins has died!\n\n";
					}
					else
					{
						std::cout << "\n\nAll your animals are dead\n\n";
					}
				}						
			}
			break;
		// Bonus between 250-500 per tiger in zoo
		case 2:
			{
				if(numTigers > 0)
				{
					int tigerBonus = (rand() % 251) + 250;
					bonus = tigerBonus;
					std::cout << "\n\nToday is National Tiger Day! Tigers generate extra money today! YOu made: "
						  << bonus << " extra dollars for each tiger you own!\n\n";
				}
				else
				{
					std::cout << "\n\nYou do not have any tigers for a bonus :( \n\n";
				}
			}
			break;
		// An adult animal (age > 2) has a baby
		case 3:
			{
				// Picks a random animal to have a baby
				int babyAnimal = (rand() % 3) + 1;
				// Starts false then should only become true once
				bool canHaveBaby = false;
				// Tiger
				if(babyAnimal == 1)
				{
					if(numTigers > 0)
					{		
						// If any of the owned tigers are 3 or older they can have a baby
						for(int x = 0; x < numTigers; x++)
						{
							if(tigerArray[x].getAge() >= 3)
							{
								canHaveBaby = true;
							}
						}
						// There will be one more tiger if one can have a baby
						if(canHaveBaby)
						{
							tigerHaveBaby();
						}
						// If no tigers can have babies we will check penguins
						else
						{
							for(int x = 0; x < numPenguins; x++)
							{
								if(penguinArray[x].getAge() >= 3)
								{
									canHaveBaby = true;
								}
							}
							if(canHaveBaby)
							{
								penguinHaveBaby();
							}
							// If no penguins can have babies we will check turtles
							else	
							{
								for(int x = 0; x < numTurtles; x++)
								{
									if(turtleArray[x].getAge() >= 3)
									{
										canHaveBaby == true;
									}
								}
								if(canHaveBaby)
								{
									turtleHaveBaby();
								}
								// No animals could have a baby
								else
								{
									std::cout << "\n\nSorry none of your animals are adults, and therefore none can have a baby\n\n";								}
							}
						}
					}
				}
				// Penguin
				else if(babyAnimal == 2)
				{
					if(numPenguins > 0)
					{		
						// If any of the owned Penguins are 3 or older they can have a baby
						for(int x = 0; x < numPenguins; x++)
						{
							if(penguinArray[x].getAge() >= 3)
							{
								canHaveBaby = true;
							}
						}
						// There will be one more tiger if one can have a baby
						if(canHaveBaby)
						{
							penguinHaveBaby();
						}
						// If no penguins can have babies we will check turtles
						else
						{
							for(int x = 0; x < numTurtles; x++)
							{
								if(turtleArray[x].getAge() >= 3)
								{
									canHaveBaby = true;
								}
							}
							if(canHaveBaby)
							{
								turtleHaveBaby();
							}
							// If no turtles can have babies we will check tigers
							else	
							{
								for(int x = 0; x < numTigers; x++)
								{
									if(tigerArray[x].getAge() >= 3)
									{
										canHaveBaby == true;
									}
								}
								if(canHaveBaby)
								{
									tigerHaveBaby();
								}
								// No animals could have a baby
								else
								{
									std::cout << "\n\nSorry none of your animals are adults, and therefore none can have a baby\n\n";								}
							}
						}
					}
				}
				// Turtle
				else
				{
					if(numTurtles > 0)
					{		
						// If any of the owned tigers are 3 or older they can have a baby
						for(int x = 0; x < numTurtles; x++)
						{
							if(turtleArray[x].getAge() >= 3)
							{
								canHaveBaby = true;
							}
						}
						// There will be one more tiger if one can have a baby
						if(canHaveBaby)
						{
							turtleHaveBaby();
						}
						// If no turtles can have babies we will check tigers
						else
						{
							for(int x = 0; x < numTigers; x++)
							{
								if(tigerArray[x].getAge() >= 3)
								{
									canHaveBaby = true;
								}
							}
							if(canHaveBaby)
							{
								tigerHaveBaby();
							}
							// If no tigers can have babies we will check pengins
							else	
							{
								for(int x = 0; x < numPenguins; x++)
								{
									if(penguinArray[x].getAge() >= 3)
									{
										canHaveBaby == true;
									}
								}
								if(canHaveBaby)
								{
									penguinHaveBaby();
								}
								// No animals could have a baby
								else
								{
									std::cout << "\n\nSorry none of your animals are adults, and therefore none can have a baby\n\n";								}
							}
						}
					}
				}					
			}
			break;
		// Nothing happens
		case 4:
			std::cout << "\nNo random event occured!\n";
			break;
	}

} 

/*********************************************************
 * Description: Adds another tiger to array 
*********************************************************/
void Zoo::tigerHaveBaby()
{
	// Increase tigers by 1
	numTigers++;
							
	// If tiger array fills up
	if(numTigers >= maxTigers)
	{
		// Create new array that will be double the size
		Tiger *newTiger = new Tiger[maxTigers * 2];
		for(int i = 0; i < maxTigers; i++)
		{
			// Copy everything from olda rray into new
			newTiger[i] = tigerArray[i];
		}
		// Delete old array
		delete [] tigerArray;
		tigerArray = newTiger;
		// Double size of array
		maxTigers *= 2;
	} 
						
	tigerArray[numTigers-1].setIsAlive(true);	// Sets animal to alive at appropriate array spot
	tigerArray[numTigers-1].setAge(0);	// Sets age to 1
							
	std::cout << "\n\nCongratulations!!! One of your tigers had a baby!\n\n";
}


/*********************************************************
 * Description: Adds another penguin to array 
*********************************************************/
void Zoo::penguinHaveBaby()
{
	int tempNum = numPenguins;	

	// Increase penguins by 5
	numPenguins = numPenguins + 5;
							
	// If penguin array fills up
	if(numPenguins >= maxPenguins)
	{
		// Create new array that will be double the size
		Penguin *newPenguin = new Penguin[maxPenguins * 2];
		for(int i = 0; i < maxPenguins; i++)
		{
			// Copy everything from old array into new
			newPenguin[i] = penguinArray[i];
		}
		// Delete old array
		delete [] penguinArray;
		penguinArray = newPenguin;
		// Double size of array
		maxPenguins *= 2;
	}
 
	for(int i = tempNum; i < maxPenguins; i++)
	{ 					
		penguinArray[i].setIsAlive(true);	// Sets animal to alive at appropriate array spot
		penguinArray[i].setAge(0);		// Sets age to 0
	}
						
	std::cout << "\n\nCongratulations!!! One of your penguins had 5 babies!\n\n";
}

/*********************************************************
 * Description: Adds another turtle to array 
*********************************************************/
void Zoo::turtleHaveBaby()
{
	int tempNum = numTurtles;	
	
	// Increase turtles by 1
	numTurtles = numTurtles + 10;
							
	// If turtle array fills up
	if(numTurtles >= maxTurtles)
	{
		// Create new array that will be double the size
		Turtle *newTurtle = new Turtle[maxTurtles * 2];
		for(int i = 0; i < maxTurtles; i++)
		{
			// Copy everything from old array into new
			newTurtle[i] = turtleArray[i];
		}
		// Delete old array
		delete [] turtleArray;
		turtleArray = newTurtle;
		// Double size of array
		maxTurtles *= 2;
	} 
				
	for(int i = tempNum; i < maxTurtles; i++)
	{
		turtleArray[i].setIsAlive(true);	// Sets animal to alive at appropriate array spot
		turtleArray[i].setAge(0);	// Sets age to 1
	}						
	std::cout << "\n\nCongratulations!!! One of your turtles had 10 babies!\n\n";
}

void Zoo::setuserCash(int cashIn)
{
	userCash = cashIn;
}

int Zoo::getuserCash()
{
	return userCash;
}

void Zoo::setDay(int dayIn)
{
	day = dayIn;
}

int Zoo::getDay()
{
	return day;
}

void Zoo::setBonus(int bonusIn)
{
	bonus = bonusIn;
}

int Zoo::getBonus()
{
	return bonus;
}
