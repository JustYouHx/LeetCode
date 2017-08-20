#pragma once

#include <queue>

using namespace std;

class MyStack
{
public:
	MyStack(void);
	~MyStack(void);

	void push(int x);

	int pop();

	int top();

	bool empty();

private:
	queue<int> tmpQue;
};

