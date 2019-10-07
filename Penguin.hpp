/********************************************************
 * Name: Charles Kusk
 * Date: April 18, 2019
 * Description: Defines interface of Penguin class
********************************************************/

#ifndef PENGUIN_HPP
#define PENGUIN_HPP

#include "Animal.hpp"

class Penguin : public Animal
{
	private:
		bool isAlive;		
	public:
		Penguin();		
		void setIsAlive(bool);
		bool getIsAlive();
};

#endif
