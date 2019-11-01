#pragma once
#include "State.h"
#include <iostream>
//class AbstractState;
class Machine
{
	friend class AbstractState;
public:
	Machine(int stock);
	void Sell(int number);
	void Refill(int number);
	int GetStock() const
	{
		return m_inStock;
	}
	void AddStock(int number)
	{
		m_inStock += number;
	}
	void TakeStock(int number)
	{
		m_inStock -= number;
	}

	~Machine();

private:
	int m_inStock;
	AbstractState* m_state;
};

