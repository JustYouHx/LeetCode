#include "StdAfx.h"
#include "MinStack.h"

MinStack::MinStack(void)
{
}

MinStack::~MinStack(void)
{
}

void MinStack::push(int x)
{
	m_stack.push(x);
	if (m_minStack.empty() || x <= m_minStack.top())		// 注意这里是小于等于
	{
		m_minStack.push(x);
	}
}

void MinStack::pop()
{
	if (!m_minStack.empty() && m_stack.top() == m_minStack.top())	//注意要先pop最小值的stack
	{
		m_minStack.pop();
	}
	if (!m_stack.empty())
	{
		m_stack.pop();
	}
}

int MinStack::top()
{
	if (m_stack.empty())
	{
		return NULL;
	}
	return m_stack.top();
}

int MinStack::getMin()
{
	if (m_minStack.empty())
	{
		return NULL;
	}
	return m_minStack.top();
}