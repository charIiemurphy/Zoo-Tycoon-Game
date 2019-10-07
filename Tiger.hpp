/********************************************************
 * Name: Charles Kusk
 * Date: April 18, 2019
 * Description: Defines interface of Tiger class
********************************************************/

#ifndef TIGER_HPP
#define TIGER_HPP

#include "Animal.hpp"

class Tiger : public Animal
{
	private:
		bool isAlive;		
	public:
		Tiger();
		void setIsAlive(bool);
		bool getIsAlive();
};


#endif
