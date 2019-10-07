/***********************************************************
 * Name: Charles Kusk
 * Date: April 18, 2019
 * Description: Defines member functions of Animal class
***********************************************************/

#include <iostream>
#include "Animal.hpp"

/**********************************************************
 * Description: Construction (may not be necessary not sure)
**********************************************************/
Animal::Animal()
{

}

void Animal::setAge(int ageIn)
{
	age = ageIn;
}

int Animal::getAge()
{
	return age;
}

void Animal::setCost(int costIn)
{
	cost = costIn;
}

int Animal::getCost()
{
	return cost;
}

void Animal::setNumberOfBabies(int numIn)
{
	numberOfBabies = numIn;
}

int Animal::getNumberOfBabies()
{
	return numberOfBabies;
}

void Animal::setBaseFoodCost(int costIn)
{
	baseFoodCost = costIn;
}

int Animal::getBaseFoodCost()
{
	return baseFoodCost;
}

void Animal::setPayoff(int payoffIn)
{
	payoff = payoffIn;
}

int Animal::getPayoff()
{
	return payoff;
}

void Animal::setIsAdult(bool isIn)
{
	isAdult = isIn;
}

bool Animal::getIsAdult()
{
	return isAdult;
}
