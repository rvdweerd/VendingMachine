#pragma once
#include "Machine.h"
#include <iostream>
class Machine;

class AbstractState
{
public:
	virtual void Sell(Machine& m, int number) = 0;
	virtual void Refill(Machine& m, int number) = 0;
	virtual ~AbstractState() = default;
protected:
	void SetState(Machine& m, AbstractState* p_newState);
};


class Normal : public AbstractState
{
public:
	Normal()
	{
		std::cout << "Machine in normal mode. " << "\n";
	}
	void Sell(Machine& m, int number) override;
	void Refill(Machine& m, int number) override;

	virtual ~Normal()
	{
		std::cout << "Normal dtor called\n";
	}
};



class Empty : public AbstractState
{
public:
	Empty()
	{
		std::cout << "Machine is now empty. \n";
	}
	void Sell(Machine& m, int number) override;
	void Refill(Machine& m, int number) override;
	virtual ~Empty()
	{
		std::cout <<"Empty dtor called\n";
	}
};