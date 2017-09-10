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

	// <225> �½���MyStack������push pop�Ȳ�����Ҫ��ʹ��queue��������

	static TreeNode* invertTree(TreeNode* root);	// <226> ��һ�����������ҷ�ת��ʹ�õݹ齻��ÿ���ڵ�����ҽڵ㼴��

	static bool isPowerOfTwo(int n);	// <231> �ж�һ�����Ƿ���2��n���ݣ�ֻ��ݹ����2����

	// <232> �½���MyQueue������push pop�Ȳ�����Ҫ��ʹ��stack��������

	static bool isPalindromeList(ListNode* head);	// <234> �ж�һ�����������Ƿ��ǻ��������轫���η�ת

	static TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);	// <235> Ѱ�Ҷ���ƽ�����У������ڵ����͹�ͬ����

	static void deleteNode(ListNode* node);	// <237> ɾ�������еĽڵ㣬����ýڵ㲻��β�ڵ�

	static bool isAnagram(string s, string t);	// <242> �ж�t�Ƿ���s�ߵ���ĸ˳�򹹳ɵģ������ȸ�string����sort������Ȼ��Ƚ������ַ����Ƿ�һ��

	static vector<string> binaryTreePaths(TreeNode* root);	// <257> ��ȡ������������·��
	static void addTreePaths(TreeNode* node, string tmpS, vector<string> *vec);

	static int addDigits(int num);	// <258> ��һ���Ǹ�������ÿһλ��ӣ�ֱ����Ϊһλ��Ϊֹ������38,3+8=11,1+1=2�����Ϊ2

	static bool isUgly(int num);	// <263> �ж�һ�������Ƿ��ǳ�ª������ª����ָֻ�ܱ�2��3��5����������1Ҳ�ǳ�ª��

	static int missingNumber(vector<int>& nums);	// <268> ��0��1��...��n�г��n�������ҳ��ĸ�����ʧ�ˣ�ʹ�����

	static int firstBadVersion(int n);	// <278> �ҵ�n���汾�е�һ����bug�İ汾���ṩ�жϵ�ǰ�汾�Ƿ���bug�ĺ�������
	static bool isBadVersion(int version);

	static void moveZeroes(vector<int>& nums);	// <283> ����������Ϊ0��Ԫ�طŵ�����棬Ҫ���ܸ������飬������С�Ĳ���

	static bool wordPattern(string pattern, string str);	// <290> �ж�str�Ƿ���pattern��ʽһ�£�����patternΪ��aab����strΪ��be be key��

	static bool canWinNim(int n);	// <292> ��ʯͷ������ÿ��ֻ����1��2��3��ʯͷ��˭�õ����һ��ʯͷ��Ӯ������˫�����㹻�������Լ����ã���n��ʯͷʱ�Ƿ���Ӯ

	// <303> �½���NumArray����ʼ������һ�����飬Ҫ��ʵ��int sumRange(int i, int j)���������Ҹú�������úö�Σ���Ҫ���Ǹ��Ӷ�

	static bool isPowerOfTree(int n);	// <326> �ж�һ�����Ƿ���3�Ĵη�����ò���ѭ����ݹ�

	static bool isPowerOfFour(int n);	// <342> �ж�һ�����Ƿ���4�Ĵη�����ò���ѭ����ݹ�

	static string reverseString(string s);	// <344> ��תһ���ַ���

	static string reverseVowels(string s);	// <345> ��ת�ַ����е�Ԫ����ĸ
	static bool isVowel(char c);

	static vector<int> intersection(vector<int>& nums1, vector<int>& nums2);	// <349> �ҵ���������Ĺ���Ԫ�أ�Ҫ�����ظ�

	static vector<int> intersect(vector<int>& nums1, vector<int>& nums2);	// <350> �ҵ���������Ĺ���Ԫ�أ�Ҫ���ظ���ҲҪ��¼

	static bool isPerfectSquare(int num);	// <367> �ж�num�Ƿ��ܿ�ƽ��

	static int getSum(int a, int b);	// <371> ���������ĺͣ�Ҫ����ʹ�üӺ�

	static int guessNumber(int n);	// <374> ������Ϸ����һ����1��n��Χ�ڵ���������guess�������£��᷵��-1/0/1����ֵ
	static int guess(int num);

	static bool canConstruct(string ransomNote, string magazine);	// <383> ��magazine�ϵ��ַ���������ţ�Ҫ��ransomNoteÿ���ַ�������С��magazine��ͬ�ַ��ĸ���
	
	static int firstUniqChar(string s);	// <387> ���ص�һ�����ظ���ĸ��index

	static char findTheDifference(string s, string t);	// <389> t����s����˳�������λ�����һ����ĸ��ɵ�

	static int findNthDigit(int n);	// <400> ��1,2,3,4,...9,10,11...99,100,101,...����һ���ַ��������ص�n�����֣�����nΪ11ʱ������0

	static vector<string> readBinaryWatch(int num);	// <401> �������ֱ�ʱ����4λ�����Ʊ�ʾ��������6λ�����Ʊ�ʾ����10��LED������num�������ؿ��ܵ�ʱ�����
	static vector<string> readBinaryNum(int num, int max);

	static int sumOfLeftLeaves(TreeNode* root);	// <404> ���������Ҷ�ӽڵ��ֵ�ĺ�

	static string toHex(int num);	// <405> ����num��ʮ�������ַ���

	static int longestPalindrome(string s);	// <409> �����ַ����п��ܴ��ڵ�������ַ�����������abccccdd������7

	static vector<string> fizzBuzz(int n);	// <412> �����ַ���vector���ܱ�3������ΪFizz���ܱ�5������ΪBuzz���ܱ�����������ΪFizzBuzz

	static int thirdMax(vector<int>& nums);	// <414> �ҳ��ǿ������еĵ������ֵ���������ڵ�����ģ��򷵻����ģ�����2,2,3,1�����ص������Ϊ1

	static string addStrings(string num1, string num2);	// <415> ������������ɵ��ַ�����������Ӻ���ַ�����Ҫ����ת��Ϊ�������

	static int coutSegments(string s);	// <434> ����һ���ַ��е��ֶθ������ÿո�ֿ��ľ����ֶ�

	static int pathSum(TreeNode* root, int sum);	// �ҵ�ֵ�ĺ�Ϊsum��·���ĸ�����·������ϵ��£�����ʼ�ͽ���û��Ҫ��
	static void pathSumCount(TreeNode* node, vector<int> vec_sum, int &count, const int &sum);

	static vector<int> findAnagrams(string s, string p);	// <438> �ҵ�s�а���p��λ�ã�����"cbaebabacd","abc",����[0,6]

	static int arrangeCoins(int n);	// <441> ��n��Ӳ�����һ��¥�ݣ���һ��1�����ڶ���2�����Դ����ƣ���������¥����������nΪ5�����1/2/2����������2��

	static int numberOfBoomerangs(vector<pair<int, int>>& points);	// <447> ����һ����Ԫ��ṹ������Ԫ��(i, j, k)��i��j֮��ľ�����i��k֮��ľ�����ȡ��ҵ������У��м��������ṹ��

	static vector<int> findDisappearedNumbers(vector<int>& nums);	// <448> nums�е�Ԫ�ض����ڵ���1��С�ڵ���n��nums��Ԫ�ظ��������ҵ�nums��û�г��ֵ�����

	static int minMoves(vector<int>& nums);	// <453> ÿ�ο��԰�nums�е�size-1������1����Ҫ���ٲ���������������

	static int findContentChildren(vector<int>& g, vector<int>& s);	// <455> g����С���ѵ�θ��ֵ��s����������ɵĴ�С���ַ�����������ܶ��С����

	static int poorPigs(int buckets, int minutesToDie, int minutesToTest);	// <458> �����Զ�ҩ��bucketsͰ��ֻ��1���ж�ҩ������minutesToDie���ӻ�����minutesToTest���Ӳ����꣬����Ҫ������

	static bool repeatedSubstringPattern(string s);	// <459> �ж��ַ����Ƿ��ɶ���Ӵ��ظ����ɣ�����abcabc��Ϊtrue

	static int hammingDistance(int x, int y);	// <461> �������룬��x��y�Ķ����ƽ��бȽϣ�������ͬλ���ϲ���ȵ�ֵ�ĸ���

	static int islandPerimeter(vector<vector<int>>& grid);	// <463> grid���һ�ŵ�ͼ��1����½�أ�0����ˮ����½�ص��ܳ�

	static int findRadius(vector<int>& houses, vector<int>& heaters);	// <475> ȡů�����⣬housesΪ���ӵ�λ�ã�heatersΪȡů����λ�ã���ȡů����С��Χ���ܸ���ȫ������

	static int findComplement(int num);	// <476> ����num�����ƵĲ����ֵ

	static int largestPalindrome(int n);	// <479> ����n�������nλ���ĳ˻������ػ���������1337��ģ
	static long long largestPalindromeGet(int num);

	static int findMaxConsecutiveOnes(vector<int>& nums);	// <485> numsΪ0��1��ɵ����飬������1�ĸ���������1,1,0,0,1,1,1������3

	static vector<int> constructRectangle(int area);	// <492> ���������Ϊarea���󳤿�Ҫ�󳤿�֮����С

	static vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums);	// <496> findNums��nums���Ӽ�����findNums��ÿһ��Ԫ����nums����һ�����������λ��

	static vector<string> findWords(vector<string>& words);	// <500> �ҳ�words��ÿ����ĸ���ڼ�����ͬһ�еĵ���
	static bool wordOnOneRow(string word);


};
