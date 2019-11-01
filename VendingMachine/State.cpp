#pragma once
#include "State.h"
#include "Machine.h"

void AbstractState::SetState(Machine& m, AbstractState* p_newState)
{
	delete m.m_state;
	m.m_state = p_newState;
}

void Normal::Sell(Machine& m, int number) 
{
	if (m.GetStock() > number)
	{
		std::cout << "Trying to sell " << number << " items.\n";
		std::cout << number << " items sold. Inventory left: ";
		m.TakeStock(number);
		std::cout << m.GetStock() << std::endl;
	}
	else
	{
		std::cout << "Trying to sell " << number << " items.\n";
		std::cout << m.GetStock() << " items sold. Inventory left: ";
		m.TakeStock(m.GetStock());
		std::cout << m.GetStock() << std::endl;
		//AbstractState* p = new Empty(m);
		AbstractState::SetState(m, new Empty);
	}
}

void Normal::Refill(Machine& m, int number)
{
	m.AddStock(number);
	std::cout << number << " added to stock. Stock is now " << m.GetStock() << ".\n";
}

void Empty::Sell(Machine& m, int number) 
{
	std::cout << "Trying to sell " << number << " items.\n"; 
	std::cout << "You can't sell, machine is empty.\n";
}
void Empty::Refill(Machine& m, int number) 
{
	m.AddStock(number);
	std::cout << number << " added to stock. Stock is now " << m.GetStock() << ".\n";
	AbstractState::SetState(m, new Normal());
}
