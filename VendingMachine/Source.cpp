#include "Machine.h"


int main()
{
	
	Machine m(10);
	m.Sell(6);
	m.Sell(5);
	m.Sell(1);
	m.Refill(4);
	m.Sell(1);
	
	std::cin.get();
	return 0;

}