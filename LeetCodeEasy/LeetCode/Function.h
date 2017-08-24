#pragma once

#include <stdint.h>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>

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
* 若任意节点的左子树不空，则左子树上所有结点的值均小于它的根结点的值
* 若任意节点的右子树不空，则右子树上所有结点的值均大于它的根结点的值
* 它是一棵空树或它的左右两个子树的高度差的绝对值不超过1，并且左右两个子树都是一棵平衡二叉树
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

	static ListNode* getInterSectionNode(ListNode* headA, ListNode* headB);	// <160> 两个链表相交于某节点，这个节点之后的所有节点都是共有的

	static vector<int> twoSum(vector<int>& numbers, int target);	// <167> 获取数组中和为target的两个元素的index，比如[2,3,4]，target为6，输入[1,3]

	static string convertToTitle(int n);	// <168> 获取excel表格的行标题，1对应A、26对应Z、27对应AA、28对应AB...
	
	static int majorityElement(vector<int>& nums);	// <169> 获取数组中出现次数超过n/2的数，假设这个数一定存在

	static int titleToNumber(string s);	// <171> excel表格行标题表示的列数，A对应1、AA对应27等等

	static int trailingZeroes(int n);	// <172> 求n!阶乘，结尾的0的个数，要求时间复杂度小于logn...阶乘里有多少5结尾就有多少0，nums = n/5 + n/25 + n/125 + ...

	static void rotateArray(vector<int>& nums, int k);	// <189> 把数组所有元素向右移动k步，循环移动

	static uint32_t reverseBits(uint32_t n);	// <190> 把无符号整型转换成二进制然后reverse，返回无符号整型，使用移位

	static int hammingWeight(uint32_t n);	// <191> 返回无符号整型的二进制数中‘1’的个数

	static int robMax(vector<int>& nums);	// <198> 返回数组中不相邻元素和的最大值，动态规划，k[i]=max(k[i-2]+nums[i],k[i-1])

/** 19 is a happy number
* 1平方 + 9平方 = 82
* 8平方 + 2平方 = 68
* 6平方 + 8平方 = 100
* 1平方 + 0平方 + 0平方 = 1
*/
	static bool isHappyNum(int n);	// <202> 判断一个数是否是happy数，用到set集合

	static ListNode* removeListElement(ListNode* head, int val);	// <203> 删除链表中与val相同的元素，要注意head开头几个元素不要等于val

	static int countPrimes(int n);	// <204> 计算小于n的素数的个数，判断x是否是素数，只需判断能否被小于sqrt(x)的所有素数整除

	static bool isIsomorphic(string s, string t);	// <205> 判断两个字符串是否是同构的，假设s和t相同长度，比如abb和trr是同构

	static ListNode* reverseList(ListNode* head);	// <206> 翻转一个没有回环的链表

	static bool containsDuplicate(vector<int>& nums);	// <217> 判断一个数组是否有重复的元素，有则返回true

	static bool containsNearbyDuplicate(vector<int>& nums, int k);	// <219> 判断在k的间隔中是否存在重复元素

	// <225> 新建类MyStack，进行push pop等操作，要求使用queue操作数据

	static TreeNode* invertTree(TreeNode* root);	// <226> 把一个二叉树左右翻转，使用递归交换每个节点的左右节点即可

	static bool isPowerOfTwo(int n);	// <231> 判断一个数是否是2的n次幂，只需递归除以2即可

	// <232> 新建类MyQueue，进行push pop等操作，要求使用stack操作数据

	static bool isPalindromeList(ListNode* head);	// <234> 判断一个单向链表是否是回文链表，需将后半段翻转

	static TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);	// <235> 寻找二叉平衡树中，两个节点的最低共同祖先

	static void deleteNode(ListNode* node);	// <237> 删除链表中的节点，假设该节点不是尾节点

	static bool isAnagram(string s, string t);	// <242> 判断t是否是s颠倒字母顺序构成的，可以先给string排序sort函数，然后比较两个字符串是否一样

	static vector<string> binaryTreePaths(TreeNode* root);	// <257> 获取二叉树的所有路径
	static void addTreePaths(TreeNode* node, string tmpS, vector<string> *vec);

	static int addDigits(int num);	// <258> 把一个非负整数的每一位相加，直到和为一位数为止，比如38,3+8=11,1+1=2，结果为2

	static bool isUgly(int num);	// <263> 判断一个正数是否是丑陋数，丑陋数是指只能被2、3、5整除的数，1也是丑陋数

	static int missingNumber(vector<int>& nums);	// <268> 从0、1、...、n中抽出n个数，找出哪个数丢失了（使用异或）

	static int firstBadVersion(int n);	// <278> 找到n个版本中第一个有bug的版本，提供判断当前版本是否有bug的函数如下
	static bool isBadVersion(int version);

	static void moveZeroes(vector<int>& nums);	// <283> 把数组所有为0的元素放到最后面，要求不能复制数组，并且最小的操作

	static bool wordPattern(string pattern, string str);	// <290> 判断str是否与pattern格式一致，比如pattern为“aab”，str为“be be key”

	static bool canWinNim(int n);	// <292> 拿石头比赛，每次只能拿1、2、3块石头，谁拿到最后一块石头算赢，假设双方都足够聪明，自己先拿，共n块石头时是否能赢

	// <303> 新建类NumArray，初始化输入一个数组，要求实现int sumRange(int i, int j)函数，并且该函数会调用好多次，需要考虑复杂度

	static bool isPowerOfTree(int n);	// <326> 判断一个数是否是3的次方，最好不用循环或递归

	static bool isPowerOfFour(int n);	// <342> 判断一个数是否是4的次方，最好不用循环或递归

	static string reverseString(string s);	// <344> 翻转一个字符串

	static string reverseVowels(string s);	// <345> 翻转字符串中的元音字母
	static bool isVowel(char c);

	static vector<int> intersection(vector<int>& nums1, vector<int>& nums2);	// <349> 找到两个数组的公共元素，要求不能重复

	static vector<int> intersect(vector<int>& nums1, vector<int>& nums2);	// <350> 找到两个数组的公共元素，要求重复的也要记录

	static bool isPerfectSquare(int num);	// <367> 判断num是否能开平方

	static int getSum(int a, int b);	// <371> 求两个数的和，要求不能使用加号

	static int guessNumber(int n);	// <374> 猜数游戏，猜一个在1到n范围内的数，给定guess函数如下，会返回-1/0/1三个值
	static int guess(int num);

	static bool canConstruct(string ransomNote, string magazine);	// <383> 用magazine上的字符组成勒索信，要求ransomNote每个字符个数得小于magazine相同字符的个数

};
