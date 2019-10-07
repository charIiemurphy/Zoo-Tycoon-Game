
#target: dependencies
#	action

# Based on "Make help" video under resources in canvas

zooTycoon: main.o Animal.o intValidationMax.o Penguin.o Tiger.o Turtle.o yesNoMenu.o Zoo.o
	g++ -std=c++11 main.o Animal.o intValidationMax.o Penguin.o Tiger.o Turtle.o yesNoMenu.o Zoo.o -o zooTycoon

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Animal.o: Animal.cpp Animal.hpp
	g++ -std=c++11 -c Animal.cpp

intValidationMax.o: intValidationMax.cpp intValidationMax.hpp
	g++ -std=c++11 -c intValidationMax.cpp

Penguin.o: Penguin.cpp Penguin.hpp
	g++ -std=c++11 -c Penguin.cpp

Tiger.o: Tiger.cpp Tiger.hpp
	g++ -std=c++11 -c Tiger.cpp

Turtle.o: Turtle.cpp Turtle.hpp
	g++ -std=c++11 -c Turtle.cpp

yesNoMenu.o: yesNoMenu.cpp yesNoMenu.hpp
	g++ -std=c++11 -c yesNoMenu.cpp

Zoo.o: Zoo.cpp Zoo.hpp
	g++ -std=c++11 -c Zoo.cpp

clean:
	rm *.o zooTycoon
