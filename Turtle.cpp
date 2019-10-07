/**********************************************************
 * Name: Charles Kusk
 * Date: April 18, 2019
 * Description: Defines member functions of Turtle class
**********************************************************/

#include <iostream>
#include "Animal.hpp"
#include "Turtle.hpp"

Turtle::Turtle()
{
	cost           = 100;
	numberOfBabies = 10;
	baseFoodCost   = 10;
	payoff         = 0.05 * cost;
	age            = 1;
	isAdult	       = false;
	isAlive	       = false;
}

void Turtle::setIsAlive(bool statusIn)
{
	isAlive = statusIn;
}

bool Turtle::getIsAlive()
{
	return isAlive;
}
