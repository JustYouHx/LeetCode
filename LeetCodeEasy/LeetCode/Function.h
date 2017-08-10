#pragma once

#include <string>
#include <vector>
#include <queue>

using namespace std;

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
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
	
	static int romanToInt(string s);	// <13> 罗马数字转int，IX = 9， XCIX = 99
	static int toNumber(char c);		// 罗马字符转int型，I、V、X、L、C、D、M分别表示1、5、10、50、100、500、1000

	static string longestCommonPrefix(vector<string>& strs);	// <14> 找出几个字符串相同前缀
	static string findCommonPrefix(string s1, string s2);	// 找出两个字符串中相同的前缀

	static bool isValid(string s);	// <20> 判断字符串是否符合()、{}、[]的规则

	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);	// <21> 按照大小顺序融合两个链表

	static int removeDuplicates(vector<int>& nums);	// <26> 删除数组中重复的元素，并返回长度		***这题输入的数组是有序的，所以解答中不需要用到双循环，用双循环会超时

	static int removeElement(vector<int>& nums, int val);	// <27> 删除数组中与val相同的元素，并返回长度

	static int strStr(string hay, string nee);	// <28> 找到nee在hay第一次出现的位置

	static int searchInsert(vector<int>& nums, int target);	// <35> 找到target在有序数组中的位置，若不存在则返回要插入的位置

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
	static string countAndSay(int n);	// <38> 开始为1，第1个数就是1个1，即11，第2个数就是2个1，即21，第3个数是1个2,1个1，即1211
	static string sayIt(string s);	// 

	static int maxSubArray(vector<int>& nums);	// <53> 寻找数组中连续元素之和的最大值， 使用双循环会超时

	static int lengthOfLastWord(string s);	// <58> 找到最后一个单词，反馈长度

	static vector<int> plusOne(vector<int>& digits);	// <66> 一个整型数字的各个位数组成的数组，然后加一，返回加一后的数组

	static string addBinary(string a, string b);	// <67> 把字符串a和b表示的二进制数相加，得到新的字符串
	static string addOneBit(char a1, char b1, char& c);

	static int mySqrt(int x);	// <69> 求开方, 注意使用double类型

	static int climbStairs(int n);	// <70> 爬梯子，使用斐波那契数列，stair(n) = stair(n-1) + stair(n-2)
	
	static ListNode* deleteDuplicates(ListNode* head);	// <83> 删除链表中重复的节点

	static void merge(vector<int>&nums1, int m, vector<int>&nums2, int n);	// <88> 合并两个有序整型数组，合并到num1中，空间足够大

	static bool isSameTree(TreeNode* p, TreeNode* q);	// <100> 判断二叉树是否相同

	static bool isSymmetric(TreeNode* root);	// <101> 判断二叉树是否是镜像的
	static bool isSymmetric(TreeNode* node1, TreeNode* node2);	// 重载函数

	static int maxDepth(TreeNode* root);	// <104> 求二叉树的深度

	static vector<vector<int>> levelOrderBottom(TreeNode* root);	// <107> 获取二叉树从底到根节点的数组, 使用队列queue，逐层遍历

/**
*若任意节点的左子树不空，则左子树上所有结点的值均小于它的根结点的值
*若任意节点的右子树不空，则右子树上所有结点的值均大于它的根结点的值
*它是一棵空树或它的左右两个子树的高度差的绝对值不超过1，并且左右两个子树都是一棵平衡二叉树
*/
	static TreeNode* sortedArrayToBST(vector<int>& nums);	// <108> 把一个有序数组转换为一个平衡二叉树, 使用递归
	static TreeNode* createTreeNode(vector<int>& nums, int left, int right);

	static bool isBalanced(TreeNode* root);	// <110> 判断一个二叉树是否是平衡二叉树
	static bool isBalancedTree(TreeNode* root, int minValue, int maxValue, int& depth);

	static int minDepth(TreeNode* root);	// <111> 求二叉树的最小深度，要注意在左节点为空时，以右节点为准，右节点为空时，以左节点为准

	static bool hasPathSum(TreeNode* root, int sum);	// <112> 判断二叉树是否存在从头到尾的一条路径，使得所有值得和为sum

	static vector<vector<int>> generatePascalTriangle(int numRows);	// <118> 输出杨辉三角的数组，numRows为行数

	static vector<int> getRwoPascalTriangle(int rowIndex);	// <119> 返回杨辉三角的某一行数组

	static int getMaxProfix(vector<int>& prices);	// <121> 输入股票每天的价格数组，最多买卖一次，返回最大收入

	static int getMaxProfix2(vector<int>& prices);	// <122> 输入股票每天的价格数组，买卖次数不限，返回最大收入

	static bool isPalindrome(string s);	// <125> 判断一个字符串是否是回文，若遇到非数字或字符则跳过，“A man,a plan,a canal:Panama”为true

	static int singleNumber(vector<int>& nums);	// <136> 输入一个数组，每个元素都出现两次，除了一个，找出那个元素，要求不使用多余的空间(考虑使用异或)

	static bool listHasCycle(ListNode* head);	// <141> 判断一个链表是否存在回路，要求不使用多余的空间（若存在回路，则快指针一定能追上慢指针）

	// <155> 新建类MinStack，进行push pop等操作



};

