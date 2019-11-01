#include "Machine.h"

Machine::Machine(int stock)
	:
	m_inStock(stock)
{	
	if (stock > 0)
	{
		m_state = new Normal();
	}
	else
	{
		m_state = new Empty();
	}
}

Machine::~Machine()
{
	delete m_state;
	m_state = nullptr;
}

void Machine::Sell(int number)
{
	m_state->Sell(*this, number);
}

void Machine::Refill(int number)
{
	m_state->Refill(*this, number);
}

