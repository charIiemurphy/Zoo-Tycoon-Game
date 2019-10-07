/********************************************************
 * Name: Charles Kusk
 * Date: April 20, 2019
 * Description: Defines interface for zoo class
********************************************************/

#ifndef ZOO_HPP
#define ZOO_HPP

#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"

class Zoo
{
	private:
		Tiger   *tigerArray;
		Penguin *penguinArray;
		Turtle  *turtleArray;
		int      userCash;
		int      day;
		int      numTigers;
		int      numPenguins;
		int      numTurtles;
		int	 maxTigers;
		int	 maxPenguins;
		int	 maxTurtles;
		int      bonus;
	public:
		Zoo();
		void startGame();
		void initialPurchase();
		void ageAnimals();
		void randomEvent();
		void purchaseAnimal(int);
		void checkArraySize();
		void tigerHaveBaby();
		void penguinHaveBaby();
		void turtleHaveBaby();
		void setuserCash(int);
		int  getuserCash();
		void setDay(int);
		int  getDay();
		void setBonus(int);
		int  getBonus();
};

#endif
