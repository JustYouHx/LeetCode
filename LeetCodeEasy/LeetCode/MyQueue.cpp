#include "StdAfx.h"
#include "MyQueue.h"


MyQueue::MyQueue(void)
{
}


MyQueue::~MyQueue(void)
{
}

void MyQueue::push(int x)
{
	tmpStack.push(x);
}

int MyQueue::pop()
{
	stack<int> tmp;
	while (tmpStack.size() > 1)
	{
		tmp.push(tmpStack.top());
		tmpStack.pop();
	}
	int i = tmpStack.top();
	tmpStack.pop();
	while (tmp.size() > 0)
	{
		tmpStack.push(tmp.top());
		tmp.pop();
	}
	return i;
}

int MyQueue::peek()
{
	stack<int> tmp;
	while (tmpStack.size() > 0)
	{
		tmp.push(tmpStack.top());
		tmpStack.pop();
	}
	int i = tmp.top();
	while (tmp.size() > 0)
	{
		tmpStack.push(tmp.top());
		tmp.pop();
	}
	return i;
}

bool MyQueue::empty()
{
	return tmpStack.empty();
}