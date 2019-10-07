/********************************************************
 * Name: Charles Kusk
 * Date: April 18, 2019
 * Description: Defines interface of Turtle class
********************************************************/

#ifndef TURTLE_HPP
#define TURTLE_HPP

#include "Turtle.hpp"

class Turtle : public Animal
{
	private:
		bool isAlive;		
	public:
		Turtle();		
		void setIsAlive(bool);
		bool getIsAlive();

};


#endif
