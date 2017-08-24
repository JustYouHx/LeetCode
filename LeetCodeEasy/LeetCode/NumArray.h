#pragma once

#include <vector>

using namespace std;

class NumArray
{
public:
	NumArray(vector<int> nums);
	~NumArray(void);
	
	int sumRange(int i, int j);

private:
	vector<int> sums;
};

