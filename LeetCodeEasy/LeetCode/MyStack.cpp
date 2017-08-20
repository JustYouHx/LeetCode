#include "StdAfx.h"
#include "MyStack.h"


MyStack::MyStack(void)
{
}


MyStack::~MyStack(void)
{
}

void MyStack::push(int x)
{
	tmpQue.push(x);
}

int MyStack::pop()
{
	int tmpValue;
	for (int i = 0; i < tmpQue.size() - 1; i++)
	{
		tmpQue.push(tmpQue.front());
		tmpQue.pop();
	}
	tmpValue = tmpQue.front();
	tmpQue.pop();
	return tmpValue;
}

int MyStack::top()
{
	return tmpQue.back();
}

bool MyStack::empty()
{
	return tmpQue.empty();
}