#pragma once
#include <stack>

using namespace std;

class MyQueue
{
public:
	MyQueue(void);
	~MyQueue(void);

	void push(int x);

	int pop();
	// »ñÈ¡frontÔªËØ
	int peek();

	bool empty();

private:
	stack<int> tmpStack;
};

