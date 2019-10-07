/**********************************************************
 * Name: Charles Kusk
 * Date: April 18, 2019
 * Description: Defines member functions of Penguin class
**********************************************************/

#include <iostream>
#include "Animal.hpp"
#include "Penguin.hpp"

Penguin::Penguin()
{
	cost           = 1000;
	numberOfBabies = 5;
	baseFoodCost   = 20;
	payoff         = 0.1 * cost;
	age            = 1;
	isAdult        = false;
	isAlive        = false;
}

void Penguin::setIsAlive(bool statusIn)
{
	isAlive = statusIn;
}

bool Penguin::getIsAlive()
{
	return isAlive;
}
