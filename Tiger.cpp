/**********************************************************
 * Name: Charles Kusk
 * Date: April 18, 2019
 * Description: Defines member functions of Tiger class
**********************************************************/

#include <iostream>
#include "Animal.hpp"
#include "Tiger.hpp"

Tiger::Tiger()
{
	cost           = 10000;
	numberOfBabies = 1;
	baseFoodCost   = 100;
	payoff         = 0.2 * cost;
	age            = 1;
	isAdult        = false;
	isAlive        = false;
}

void Tiger::setIsAlive(bool statusIn)
{
	isAlive = statusIn;
}

bool Tiger::getIsAlive()
{
	return isAlive;
}
