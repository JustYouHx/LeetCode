#include "StdAfx.h"
#include "Function.h"

Function::Function(void)
{
}


Function::~Function(void)
{
}

int Function::myReverse(int x) 
{
	bool na = true;
	if (x == 0 || x == -2147483648)
		return 0;
	else if (x < 0)
		x = -x;
	else
		na = false;

	vector<int> nums;
	long l = 0;
	long n = 1;
	int temp;

	while(1)
	{
		if (x < 10)
		{
			nums.push_back(x);
			break; 
		}
		else
		{
			nums.push_back(x % 10);
			x /= 10;
		}
	}

	for (int i = nums.size()-1; i >= 0; i--)
	{
		l += nums.at(i) * n;
		n *= 10;
	}

	temp = (int)l;
	if (temp == l)
	{
		if (na)
			return -temp;
		else
			return temp;
	}
	else
	{
		return 0;
	}
}

bool Function::isPalindrome(int x)
{
	if (x < 0)
		return false;
	int nums[10];
	int n = 0;
	while (1)
	{
		if (x < 10)
		{
			nums[n] = x;
			break;
		}
		else
		{
			nums[n] = x % 10;
			x /= 10;
			n++;
		}
	}
	for (int j = 0; j <= n/2; j++)
	{
		if (nums[j] != nums[n-j])
		{
			return false;
		}
	}
	return true;
}

int Function::romanToInt(string s) 
{
	int n = toNumber(s[0]);
	for (int i = 1; i < s.length(); i++)
	{
		if (toNumber(s[i-1]) < toNumber(s[i]))
		{
			n += toNumber(s[i]) - 2 * toNumber(s[i-1]);
		}
		else
		{
			n += toNumber(s[i]);
		}
	}
	return n;
}

int Function::toNumber(char c)
{
	switch(c)
	{
	case 'I': return 1;
	case 'V': return 5;
	case 'X': return 10;
	case 'L': return 50;
	case 'C': return 100;
	case 'D': return 500;
	case 'M': return 1000;
	}
	return 0;
}

string Function::longestCommonPrefix(vector<string>& strs)
{
	int n = strs.size();
	if (n == 0)
	{
		return "";
	}
	else if (n == 1)
	{
		return strs.at(0);
	}
	else
	{
		string s = findCommonPrefix(strs.at(0), strs.at(1));
		for (int i = 2; i < strs.size(); i++)
		{
			s = findCommonPrefix(s, strs.at(i));
		}
		return s;
	}
}

string Function::findCommonPrefix(string s1, string s2)
{
	string s = "";
	for (int i = 0; i < s1.length() && i < s2.length(); i++)
	{
		if (s1[i] != s2[i])
		{
			return s;
		}
		else
		{
			s += s1[i];
		}
	}
	return s;
}

bool Function::isValid(string s)
{
	string tmp = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
		{
			tmp.append(1, s[i]);
		}
		else if (s[i] == ')')
		{
			if (tmp.empty() || tmp.at(tmp.length() - 1) != '(')
				return false;
			else
				tmp.erase(tmp.begin() + tmp.length() - 1);
		}
		else if (s[i] == ']')
		{
			if (tmp.empty() || tmp.at(tmp.length() - 1) != '[')
				return false;
			else
				tmp.erase(tmp.begin() + tmp.length() - 1);
		}
		else if (s[i] == '}')
		{
			if (tmp.empty() || tmp.at(tmp.length() - 1) != '{')
				return false;
			else
				tmp.erase(tmp.begin() + tmp.length() - 1);
		}
	}
	if (tmp.empty())
		return true;
	else
		return false;
}

ListNode1* Function::mergeTwoLists(ListNode1* l1, ListNode1* l2)
{
	ListNode1* head;
	ListNode1* p;
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;
	if (l1->val <= l2->val)
	{
		head = l1;
		p = l1;
		l1 = l1->next;
	}
	else
	{
		head = l2;
		p = l2;
		l2 = l2->next;
	}
	while (1)
	{
		if (l1 == NULL)
		{
			p->next = l2;
			break;
		}
		if (l2 == NULL)
		{
			p->next = l1;
			break;
		}
		if (l1->val <= l2->val)
		{
			p->next = l1;
			p = l1;
			l1 = l1->next;
		}
		else
		{
			p->next = l2;
			p = l2;
			l2 = l2->next;
		}
	}
	return head;
}

int Function::removeDuplicates(vector<int>& nums)
{
	int n = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		int j;
		for (j = 0; j < i; j++)
		{
			if (nums[i] == nums[j])
			{
				break;
			}
		}
		if (j == i)
		{
			n++;
			nums[n-1] = nums[i];
		}
	}
	return n;
}

int Function::removeElement(vector<int>& nums, int val)
{
	int n = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] != val)
		{
			nums[n] = nums[i];
			n++;
		}
	}
	return n;
}

int Function::strStr(string hay, string nee)
{
	int n1 = hay.length();
	int n2 = nee.length();
	if (n1 < n2)
		return -1;
	for (int i = 0; i <= n1-n2; i++)
	{
		int j;
		for (j = 0; j < n2; j++)
		{
			if (hay.at(i+j) != nee.at(j))
				break;
		}
		if (j == n2)
			return i;
	}
	return -1;
}

int Function::searchInsert(vector<int>& nums, int target)
{
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] >= target)
		{
			return i;
		}
	}
	return nums.size();
}

string Function::countAndSay(int n)
{
	if (n == 1)
	{
		return "1";
	}
	string s = "1";
	for (int i = 1; i < n; i++)
	{
		s = sayIt(s);
	}
	return s;
}

string Function::sayIt(string s)
{
	string ret = "";
	int count = 1;
	int i = 1;
	char buff[10];
	for (i = 1; i < s.length(); i++)
	{
		if (s.at(i) == s.at(i-1))
		{
			count++;
		}
		else
		{
			//itoa(count, buff, 10);
			sprintf(buff, "%d", count);			// 把数字int转为char数组
			ret = ret + buff + s.at(i-1);
			count = 1;
		}
	}
	//itoa(count, buff, 10);
	sprintf(buff, "%d", count);
	ret = ret + buff + s.at(i-1);
	return ret;
}

int Function::maxSubArray(vector<int>& nums)
{
	int res = INT_MIN, curSum = 0;
	for (int i = 0; i < nums.size(); i++) 
	{
		curSum = max(curSum + nums[i], nums[i]);
		res = max(res, curSum);
	}
	return res;
}

int Function::lengthOfLastWord(string s)
{
	int n = s.length()-1, m = 0;
	while (n >= 0)
	{
		if (s[n] == ' ')
		{
			n--;
		}
		else
		{
			break;
		}
	}
	while(n >= 0)
	{
		if (s[n] == ' ')
		{
			break;
		}
		else
		{
			m++;
			n--;
		}
	}
	return m;
}

vector<int> Function::plusOne(vector<int>& digits)
{
	int c = 1, n = digits.size()-1;
	
	for (int i = n; i >= 0; i--)
	{
		if (digits[i]+c > 9)
		{
			c = 1;
			digits[i] = 0;
		}
		else
		{
			digits[i] += c;
			c = 0;
		}
	}
	if (c == 1)
	{
		digits.insert(digits.begin(), 1);
	}
	return digits;
}

string Function::addBinary(string a, string b)
{
	int m = a.length() - 1;
	int n = b.length() - 1;
	string rst = "";
	char a1, b1, c = '0';
	while (m >= 0 || n >= 0)
	{
		a1 = (m>=0)?a[m]:'0';
		b1 = (n>=0)?b[n]:'0';
		rst = addOneBit(a1, b1, c) + rst;
		m--;
		n--;
	}
	if (c == '1')
	{
		rst = "1" + rst;
	}
	return rst;
}

string Function::addOneBit(char a1, char b1, char& c)
{
	if (c == '0')
	{
		if (a1 == b1)
		{
			c = a1;
			return "0";
		}
		else
		{
			return "1";
		}
	}
	else if (c == '1')
	{
		if (a1 == b1)
		{
			c = a1;
			return "1";
		}
		else
		{
			return "0";
		}
	}
}

int Function::mySqrt(int x)
{
	if (x == 0 || x == 1)
	{
		return x;
	}
	double start = 0, stop = x, result = 1, mid = 1;
	while (abs(result-x) > 0.001)
	{
		mid = (start + stop) / 2;
		result = mid * mid;
		if (result > x)
		{
			stop = mid;
		}
		else
		{
			start = mid;
		}
	}
	return (int)mid;
}

int Function::climbStairs(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else if (n == 2)
	{
		return 2;
	}
	int n1 = 1, n2 = 2, tmp = 0;
	for (int i = 3; i <= n; i++)
	{
		tmp = n1;
		n1 = n2;
		n2 += tmp;
	}
	return n2;
}

ListNode1* Function::deleteDuplicates(ListNode1* head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	ListNode1* p1 = head;
	ListNode1* p2 = head->next;
	while (p2 != NULL)
	{
		if (p1->val == p2->val)
		{
			p1->next = p2->next;
			delete p2;
			p2 = p1->next;
		}
		else
		{
			p1 = p2;
			p2 = p2->next;
		}
	}
	return head;
}

void Function::merge(vector<int>&nums1, int m, vector<int>&nums2, int n)
{
	while (m > 0 || n > 0)
	{
		if (m == 0)
		{
			nums1[m+n-1] = nums2[n-1];
			n--;
		}
		else if (n == 0)
		{
			nums1[m+n-1] = nums1[m-1];
			m--;
		}
		else if (nums1[m-1] >= nums2[n-1])
		{
			nums1[m+n-1] = nums1[m-1];
			m--;
		}
		else
		{
			nums1[m+n-1] = nums2[n-1];
			n--;
		}
	}
}

bool Function::isSameTree(TreeNode* p, TreeNode* q)
{
	if (p != NULL && q != NULL)
	{
		if (p->val != q->val || !isSameTree(p->left, q->left) || !isSameTree(p->right, q->right))
			return false;
		else
			return true;
	}
	else if (p != q)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Function::isSymmetric(TreeNode* root)
{
	if (root == NULL)
	{
		return true;
	}
	else
	{
		return isSymmetric(root->left, root->right);
	}
}

bool Function::isSymmetric(TreeNode* node1, TreeNode* node2)
{
	if (node1 != NULL && node2 != NULL)
	{
		if (node1->val != node2->val || !isSymmetric(node1->left, node2->right) || !isSymmetric(node1->right, node2->left))
		{
			return false;
		}
	}
	else if (node1 != node2)
	{
		return false;
	}
	return true;
}

int Function::maxDepth(TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int d = max(maxDepth(root->left), maxDepth(root->right));
	return d+1;
}

vector<vector<int>> Function::levelOrderBottom(TreeNode* root)
{
	vector<vector<int>> vecc;
	queue<TreeNode*> que;
	if (root == NULL)
	{
		return vecc;
	}
	que.push(root);
	while (que.size() > 0)
	{
		queue<TreeNode*> tmpQue;
		vector<int> vec;
		while (que.size() > 0)
		{
			TreeNode* n = que.front();
			que.pop();
			if (n->left != NULL)
			{
				tmpQue.push(n->left);
			}
			if (n->right != NULL)
			{
				tmpQue.push(n->right);
			}
			vec.push_back(n->val);
		}
		que = tmpQue;
		vecc.push_back(vec);
	}
	reverse(vecc.begin(), vecc.end());
	return vecc;
}

TreeNode* Function::sortedArrayToBST(vector<int>& nums)
{
	return createTreeNode(nums, 0, nums.size()-1);
}

TreeNode* Function::createTreeNode(vector<int>& nums, int left, int right)
{
	TreeNode* node = NULL;
	if (left > right)
	{
		return node;
	}
	int mid = (left + right) / 2;
	node = new TreeNode(nums[mid]);
	node->left = createTreeNode(nums, left, mid-1);
	node->right = createTreeNode(nums, mid + 1, right);
	return node;
}