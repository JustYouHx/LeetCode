// LeetCode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Function.h"
#include "MinStack.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string x;
	cout << "请输入：";
	cin >> x;
	vector<int> strs;
	vector<int> strs2;
	strs.push_back(2);
	strs.push_back(4);
	strs.push_back(5);
	strs.push_back(8);
	strs.push_back(0);
	strs.push_back(0);
	strs.push_back(0);
	strs2.push_back(1);
	strs2.push_back(8);
	strs2.push_back(1);
	strs2.push_back(1);

	int i = 14;

	string s1 = "nadd";
	string s2 = "andd";

//	int r = Function::myReverse(x);
//	bool r = Function::isPalindrome(x);
//	int r = Function::romanToInt(x);
//	string r = Function::longestCommonPrefix(strs);
//	bool r = Function::isValid(x);
//	int r = Function::removeDuplicates(strs);
//	int r = Function::strStr(s1, s2);
//	int r = Function::searchInsert(strs, i);
//	string r = Function::countAndSay(6);
//	int r = Function::maxSubArray(strs);
//	string r = Function::addBinary(s1, s2);
//	int r = Function::mySqrt(i);
//	int r = Function::climbStairs(i);
//	Function::merge(strs, 4, strs2, 3);
//	string r = Function::convertToTitle(i);
//	int r = Function::titleToNumber(x);
//	int r = Function::trailingZeroes(i);
//	Function::rotateArray(strs2, i);
//	int r = Function::robMax(strs2);
//	bool r = Function::isHappyNum(i);
//	int r = Function::countPrimes(i);
//	bool r = Function::isIsomorphic(s1, s2);
//	bool r = Function::containsDuplicate(strs2);
//	bool r = Function::containsNearbyDuplicate(strs2, 1);
//	bool r = Function::isAnagram(s1, s2);
//	int r = Function::addDigits(i);
//	bool r = Function::isUgly(i);
	int r = Function::firstBadVersion(i);

	cout << "\n结果：" << r << endl;
//	cout << strs2[0] << endl;
//	cout << strs2[1] << endl;
//	cout << strs2[2] << endl;
//	cout << strs[3] << endl;
//	cout << strs[4] << endl;
//	cout << strs[5] << endl;
//	cout << strs[6] << endl;

	system("pause");
	return 0;
}

