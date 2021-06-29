#include <iostream>

#include "boost/random.hpp"


int main()
{
	boost::random::mt19937 gen;
	boost::random::uniform_int_distribution<> dist(1, 10);
	std::cout << "Project 4 : ";
	for (int i = 0; i < dist(gen); i++)
	{
		std::cout << i << " ";
	};
}