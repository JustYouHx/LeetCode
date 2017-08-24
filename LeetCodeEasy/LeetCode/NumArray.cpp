#include "StdAfx.h"
#include "NumArray.h"


NumArray::NumArray(vector<int> nums)
{
	int tmp = 0;
	sums.push_back(0);
	for (int i = 0; i < nums.size(); i++)
	{
		tmp += nums[i];
		sums.push_back(tmp);
	}
}


NumArray::~NumArray(void)
{
}

int NumArray::sumRange(int i, int j)
{
	if (i < sums.size() && j < sums.size() - 1 && i <= j)
	{
		return sums[j+1] - sums[i];
	}
	return 0;
}