/*********************************************************
 * Name: Charles Kusk
 * Date: April 18, 2019
 * Description: Defines interface of Animal class
 ********************************************************/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal
{
	private:
	protected:
		int age;
		bool isAdult;
		int cost;
		int numberOfBabies;
		int baseFoodCost;
		int payoff;
	public:
		Animal();
		void setAge(int);
		int getAge();
		void setIsAdult(bool);
		bool getIsAdult();
		void setCost(int);
		int getCost();
		void setNumberOfBabies(int);
		int getNumberOfBabies();
		void setBaseFoodCost(int);
		int getBaseFoodCost();
		void setPayoff(int);
		int getPayoff();
};

#endif
