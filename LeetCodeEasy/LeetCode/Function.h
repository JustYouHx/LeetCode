#pragma once

#include <string>
#include <vector>
#include <queue>

using namespace std;

struct ListNode1 
{
	int val;
	ListNode1 *next;
	ListNode1(int x) : val(x), next(NULL) {}
};

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Function
{
public:
	Function(void);
	~Function(void);

	//-------------------- LeetCode Easy Progress -------------------//

	static int myReverse(int x);	// <7>
	
	static bool isPalindrome(int x);	// <9>
	
	static int romanToInt(string s);	// <13> ��������תint��IX = 9�� XCIX = 99
	static int toNumber(char c);		// �����ַ�תint�ͣ�I��V��X��L��C��D��M�ֱ��ʾ1��5��10��50��100��500��1000

	static string longestCommonPrefix(vector<string>& strs);	// <14> �ҳ������ַ�����ͬǰ׺
	static string findCommonPrefix(string s1, string s2);	// �ҳ������ַ�������ͬ��ǰ׺

	static bool isValid(string s);	// <20> �ж��ַ����Ƿ����()��{}��[]�Ĺ���

	ListNode1* mergeTwoLists(ListNode1* l1, ListNode1* l2);	// <21> ���մ�С˳���ں���������

	static int removeDuplicates(vector<int>& nums);	// <26> ɾ���������ظ���Ԫ�أ������س���		***�������������������ģ����Խ���в���Ҫ�õ�˫ѭ������˫ѭ���ᳬʱ

	static int removeElement(vector<int>& nums, int val);	// <27> ɾ����������val��ͬ��Ԫ�أ������س���

	static int strStr(string hay, string nee);	// <28> �ҵ�nee��hay��һ�γ��ֵ�λ��

	static int searchInsert(vector<int>& nums, int target);	// <35> �ҵ�target�����������е�λ�ã����������򷵻�Ҫ�����λ��

/** 
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 * 
 * 1 is read off as "one 1" or 11. 11 is read off as "two 1s" or 21. 21 is read
 * off as "one 2, then one 1" or 1211.
 * 
 * Given an integer n, generate the nth sequence.
 * 
 * Note: The sequence of integers will be represented as a string.
 */
	static string countAndSay(int n);	// <38> ��ʼΪ1����1��������1��1����11����2��������2��1����21����3������1��2,1��1����1211
	static string sayIt(string s);	// 

	static int maxSubArray(vector<int>& nums);	// <53> Ѱ������������Ԫ��֮�͵����ֵ�� ʹ��˫ѭ���ᳬʱ

	static int lengthOfLastWord(string s);	// <58> �ҵ����һ�����ʣ���������

	static vector<int> plusOne(vector<int>& digits);	// <66> һ���������ֵĸ���λ����ɵ����飬Ȼ���һ�����ؼ�һ�������

	static string addBinary(string a, string b);	// <67> ���ַ���a��b��ʾ�Ķ���������ӣ��õ��µ��ַ���
	static string addOneBit(char a1, char b1, char& c);

	static int mySqrt(int x);	// <69> �󿪷�, ע��ʹ��double����

	static int climbStairs(int n);	// <70> �����ӣ�ʹ��쳲��������У�stair(n) = stair(n-1) + stair(n-2)
	
	static ListNode1* deleteDuplicates(ListNode1* head);	// <83> ɾ���������ظ��Ľڵ�

	static void merge(vector<int>&nums1, int m, vector<int>&nums2, int n);	// <88> �ϲ����������������飬�ϲ���num1�У��ռ��㹻��

	static bool isSameTree(TreeNode* p, TreeNode* q);	// <100> �ж϶������Ƿ���ͬ

	static bool isSymmetric(TreeNode* root);	// <101> �ж϶������Ƿ��Ǿ����
	static bool isSymmetric(TreeNode* node1, TreeNode* node2);	// ���غ���

	static int maxDepth(TreeNode* root);	// <104> ������������

	static vector<vector<int>> levelOrderBottom(TreeNode* root);	// <107> ��ȡ�������ӵ׵����ڵ������, ʹ�ö���queue��������

/**
*������ڵ�����������գ��������������н���ֵ��С�����ĸ�����ֵ
*������ڵ�����������գ��������������н���ֵ���������ĸ�����ֵ
*����һ�ÿ����������������������ĸ߶Ȳ�ľ���ֵ������1����������������������һ��ƽ�������
*/
	static TreeNode* sortedArrayToBST(vector<int>& nums);	// <108> ��һ����������ת��Ϊһ��ƽ�������, ʹ�õݹ�
	static TreeNode* createTreeNode(vector<int>& nums, int left, int right);
};
