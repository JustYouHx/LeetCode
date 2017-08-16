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
	
	static int romanToInt(string s);	// <13> ��������תint��IX = 9�� XCIX = 99
	static int toNumber(char c);		// �����ַ�תint�ͣ�I��V��X��L��C��D��M�ֱ��ʾ1��5��10��50��100��500��1000

	static string longestCommonPrefix(vector<string>& strs);	// <14> �ҳ������ַ�����ͬǰ׺
	static string findCommonPrefix(string s1, string s2);	// �ҳ������ַ�������ͬ��ǰ׺

	static bool isValid(string s);	// <20> �ж��ַ����Ƿ����()��{}��[]�Ĺ���

	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);	// <21> ���մ�С˳���ں���������

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
	
	static ListNode* deleteDuplicates(ListNode* head);	// <83> ɾ���������ظ��Ľڵ�

	static void merge(vector<int>&nums1, int m, vector<int>&nums2, int n);	// <88> �ϲ����������������飬�ϲ���num1�У��ռ��㹻��

	static bool isSameTree(TreeNode* p, TreeNode* q);	// <100> �ж϶������Ƿ���ͬ

	static bool isSymmetric(TreeNode* root);	// <101> �ж϶������Ƿ��Ǿ����
	static bool isSymmetric(TreeNode* node1, TreeNode* node2);	// ���غ���

	static int maxDepth(TreeNode* root);	// <104> ������������

	static vector<vector<int>> levelOrderBottom(TreeNode* root);	// <107> ��ȡ�������ӵ׵����ڵ������, ʹ�ö���queue��������

/**
* ������ڵ�����������գ��������������н���ֵ��С�����ĸ�����ֵ
* ������ڵ�����������գ��������������н���ֵ���������ĸ�����ֵ
* ����һ�ÿ����������������������ĸ߶Ȳ�ľ���ֵ������1����������������������һ��ƽ�������
*/
	static TreeNode* sortedArrayToBST(vector<int>& nums);	// <108> ��һ����������ת��Ϊһ��ƽ�������, ʹ�õݹ�
	static TreeNode* createTreeNode(vector<int>& nums, int left, int right);

	static bool isBalanced(TreeNode* root);	// <110> �ж�һ���������Ƿ���ƽ�������
	static bool isBalancedTree(TreeNode* root, int minValue, int maxValue, int& depth);

	static int minDepth(TreeNode* root);	// <111> �����������С��ȣ�Ҫע������ڵ�Ϊ��ʱ�����ҽڵ�Ϊ׼���ҽڵ�Ϊ��ʱ������ڵ�Ϊ׼

	static bool hasPathSum(TreeNode* root, int sum);	// <112> �ж϶������Ƿ���ڴ�ͷ��β��һ��·����ʹ������ֵ�ú�Ϊsum

	static vector<vector<int>> generatePascalTriangle(int numRows);	// <118> ���������ǵ����飬numRowsΪ����

	static vector<int> getRwoPascalTriangle(int rowIndex);	// <119> ����������ǵ�ĳһ������

	static int getMaxProfix(vector<int>& prices);	// <121> �����Ʊÿ��ļ۸����飬�������һ�Σ������������

	static int getMaxProfix2(vector<int>& prices);	// <122> �����Ʊÿ��ļ۸����飬�����������ޣ������������

	static bool isPalindrome(string s);	// <125> �ж�һ���ַ����Ƿ��ǻ��ģ������������ֻ��ַ�����������A man,a plan,a canal:Panama��Ϊtrue

	static int singleNumber(vector<int>& nums);	// <136> ����һ�����飬ÿ��Ԫ�ض��������Σ�����һ�����ҳ��Ǹ�Ԫ�أ�Ҫ��ʹ�ö���Ŀռ�(����ʹ�����)

	static bool listHasCycle(ListNode* head);	// <141> �ж�һ�������Ƿ���ڻ�·��Ҫ��ʹ�ö���Ŀռ䣨�����ڻ�·�����ָ��һ����׷����ָ�룩

	// <155> �½���MinStack������push pop�Ȳ���

	static ListNode* getInterSectionNode(ListNode* headA, ListNode* headB);	// <160> ���������ཻ��ĳ�ڵ㣬����ڵ�֮������нڵ㶼�ǹ��е�

	static vector<int> twoSum(vector<int>& numbers, int target);	// <167> ��ȡ�����к�Ϊtarget������Ԫ�ص�index������[2,3,4]��targetΪ6������[1,3]

	static string convertToTitle(int n);	// <168> ��ȡexcel�����б��⣬1��ӦA��26��ӦZ��27��ӦAA��28��ӦAB...
	
	static int majorityElement(vector<int>& nums);	// <169> ��ȡ�����г��ִ�������n/2���������������һ������

	static int titleToNumber(string s);	// <171> excel����б����ʾ��������A��Ӧ1��AA��Ӧ27�ȵ�

	static int trailingZeroes(int n);	// <172> ��n!�׳ˣ���β��0�ĸ�����Ҫ��ʱ�临�Ӷ�С��logn...�׳����ж���5��β���ж���0��nums = n/5 + n/25 + n/125 + ...

	static void rotateArray(vector<int>& nums, int k);	// <189> ����������Ԫ�������ƶ�k����ѭ���ƶ�

	static uint32_t reverseBits(uint32_t n);	// <190> ���޷�������ת���ɶ�����Ȼ��reverse�������޷������ͣ�ʹ����λ

	static int hammingWeight(uint32_t n);	// <191> �����޷������͵Ķ��������С�1���ĸ���

	static int robMax(vector<int>& nums);	// <198> ���������в�����Ԫ�غ͵����ֵ����̬�滮��k[i]=max(k[i-2]+nums[i],k[i-1])

/** 19 is a happy number
* 1ƽ�� + 9ƽ�� = 82
* 8ƽ�� + 2ƽ�� = 68
* 6ƽ�� + 8ƽ�� = 100
* 1ƽ�� + 0ƽ�� + 0ƽ�� = 1
*/
	static bool isHappyNum(int n);	// <202> �ж�һ�����Ƿ���happy�����õ�set����

	static ListNode* removeListElement(ListNode* head, int val);	// <203> ɾ����������val��ͬ��Ԫ�أ�Ҫע��head��ͷ����Ԫ�ز�Ҫ����val

	static int countPrimes(int n);	// <204> ����С��n�������ĸ������ж�x�Ƿ���������ֻ���ж��ܷ�С��sqrt(x)��������������

	static bool isIsomorphic(string s, string t);	// <205> �ж������ַ����Ƿ���ͬ���ģ�����s��t��ͬ���ȣ�����abb��trr��ͬ��

	static ListNode* reverseList(ListNode* head);	// <206> ��תһ��û�лػ�������

	static bool containsDuplicate(vector<int>& nums);	// <217> �ж�һ�������Ƿ����ظ���Ԫ�أ����򷵻�true

	static bool containsNearbyDuplicate(vector<int>& nums, int k);	// <219> �ж���k�ļ�����Ƿ�����ظ�Ԫ��

	// <225> �½���MyStack������push pop�Ȳ�����Ҫ��ʹ��queue����

	static TreeNode* invertTree(TreeNode* root);	// <226> ��һ�����������ҷ�ת��ʹ�õݹ齻��ÿ���ڵ�����ҽڵ㼴��

	static bool isPowerOfTwo(int n);	// <231> �ж�һ�����Ƿ���2��n���ݣ�ֻ��ݹ����2����
};
