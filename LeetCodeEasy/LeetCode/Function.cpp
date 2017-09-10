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

ListNode* Function::mergeTwoLists(ListNode* l1, ListNode* l2)
{
	ListNode* head;
	ListNode* p;
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

ListNode* Function::deleteDuplicates(ListNode* head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	ListNode* p1 = head;
	ListNode* p2 = head->next;
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

bool Function::isBalanced(TreeNode* root)
{
	int depth = 0;
	return isBalancedTree(root, INT_MIN, INT_MAX, depth);
}

bool Function::isBalancedTree(TreeNode* root, int minValue, int maxValue, int& depth)
{
	if (root == NULL)
	{
		return true;
	}
	depth++;
	int dl = 0, dr = 0;
	if (!isBalancedTree(root->left, minValue, root->val, dl))
	{
		return false;
	}
	if (!isBalancedTree(root->right, root->val, maxValue, dr))
	{
		return false;
	}
	if (abs(dl-dr) > 1)
	{
		return false;
	}
	else
	{
		depth += max(dl, dr);;
	}
	return true;
}

int Function::minDepth(TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL)
	{
		return 1 + minDepth(root->right);
	}
	if (root->right == NULL)
	{
		return 1 + minDepth(root->left);
	}
	return 1 + min(minDepth(root->left), minDepth(root->right));
}

bool Function::hasPathSum(TreeNode* root, int sum)
{
	if (root == NULL)
	{
		return false;
	}
	if (root->left == NULL && root->right == NULL && sum == root->val)
	{
		return true;
	}
	if (hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val))
	{
		return true;
	}
	return false;
}

vector<vector<int>> Function::generatePascalTriangle(int numRows)
{
	vector<vector<int>> vecc;
	vector<int> vec;
	if (numRows == 0)
	{
		return vecc;
	}
	vec.push_back(1);
	vecc.push_back(vec);
	if (numRows == 1)
	{
		return vecc;
	}
	for (int i = 1; i < numRows; i++)
	{
		vector<int> tmp;
		tmp.push_back(1);
		for (int j = 1; j < i; j++)
		{
			tmp.push_back(vec[j-1] + vec[j]);
		}
		tmp.push_back(1);
		vecc.push_back(tmp);
		vec = tmp;
	}
	return vecc;
}

vector<int> Function::getRwoPascalTriangle(int rowIndex)
{
	int a = 1, b = 1;
	vector<int> vec;
	vec.push_back(1);
	if (rowIndex == 0)
	{
		return vec;
	}
	vec.push_back(1);
	if (rowIndex == 1)
	{
		return vec;
	}
	for (int i = 2; i <= rowIndex; i++)
	{
		for (int j = 1; j < i; j++)
		{
			a = b;
			b = vec[j];
			vec[j] = a + b;
		}
		vec.push_back(1);
	}
	return vec;
}

int Function::getMaxProfix(vector<int>& prices)
{
	if (prices.size() == 0)
	{
		return 0;
	}
	int min = prices[0], profit = 0;
	for (int i = 0; i < prices.size(); i++)
	{
		if (prices[i] < min)
		{
			min = prices[i];
		}
		if (prices[i] - min > profit)
		{
			profit = prices[i] - min;
		}
	}
	return profit;
}

int Function::getMaxProfix2(vector<int>& prices)
{
	int profit = 0;
	for (int i = 1; i < prices.size(); i++)
	{
		if (prices[i] > prices[i-1])
		{
			profit = profit + prices[i] - prices[i-1];
		}
	}
	return profit;
}

bool Function::isPalindrome(string s)
{
	int start = 0;
	int stop = s.length()-1;
	while (start <= stop)
	{
		if (!isalnum(s.at(start)))
		{
			start++;
			continue;
		}
		if (!isalnum(s.at(stop)))
		{
			stop--;
			continue;
		}
		if (tolower(s.at(start)) == tolower(s.at(stop)))
		{
			start++;
			stop--;
		}
		else
		{
			return false;
		}
	}
	return true;
}

int Function::singleNumber(vector<int>& nums)
{
	int single = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		single = single ^ nums[i];
	}
	return single;
}

bool Function::listHasCycle(ListNode* head)
{
	if (head == NULL)
	{
		return false;
	}
	ListNode* slow = head;
	ListNode* fast = head->next;
	while (fast != NULL && fast->next != NULL)
	{
		if (slow == fast)
		{
			return true;
		}
		fast = fast->next->next;
		slow = slow->next;
	}
	return false;
}

ListNode* Function::getInterSectionNode(ListNode* headA, ListNode* headB)
{
	ListNode* pa = headA;
	ListNode* pb = headB;
	if (pa == NULL || pb == NULL)
	{
		return NULL;
	}
	while (pa != NULL && pb != NULL && pa != pb)
	{
		pa = pa->next;
		pb = pb->next;
		if (pa == pb)
		{
			return pa;
		}
		if (pa == NULL)
		{
			pa = headB;
		}
		if (pb == NULL)
		{
			pb = headA;
		}
	}
	return pa;
}

vector<int> Function::twoSum(vector<int>& numbers, int target)
{
	vector<int> index;
	if (numbers.size() < 2)
	{
		return index;
	}
	int min = 0;
	int max = numbers.size()-1;
	while (min < max)
	{
		if (numbers[min] + numbers[max] == target)
		{
			index.push_back(min+1);
			index.push_back(max+1);
			return index;
		}
		else if (numbers[min] + numbers[max] > target)
		{
			max--;
		}
		else if (numbers[min] + numbers[max] < target)
		{
			min++;
		}
	}
	return index;
}

string Function::convertToTitle(int n)
{
	string s = "";
	while (n > 0)
	{
		s.insert(0, 1, char('A' + (n-1) % 26));
		n = (n-1) / 26;
	}
	return s;
}

int Function::majorityElement(vector<int>& nums)
{
	map<int, int> tmpMap;
	map<int, int>::iterator it;
	for (int i = 0; i < nums.size(); i++)
	{
		it = tmpMap.find(nums[i]);
		if (it == tmpMap.end())
		{
			tmpMap[nums[i]] = 1;
		}
		else
		{
			tmpMap[nums[i]]++;
		}
		if (tmpMap[nums[i]] > nums.size() / 2)
		{
			return nums[i];
		}
	}
	return 0;
}

int Function::titleToNumber(string s)
{
	int n = 0;
	int k = 1;
	for (int i = s.length() - 1; i >= 0; i--)
	{
		n = n + int(s.at(i) - 'A' + 1) * k;
		k *= 26;
	}
	return n;
}

int Function::trailingZeroes(int n)
{
	int nums = 0;
	long long k = 5;
	//int k = 5;
	while ( n / k > 0)
	{
		nums += n/k;
		k *= 5;
	}
	return nums;
}

void Function::rotateArray(vector<int>& nums, int k)
{
	int n = nums.size();
	int tmpK = k % n;
	int tmp1, tmp2;
	while (tmpK > 0)
	{
		tmp1 = nums[0];
		for (int i = 0; i < n; i++)
		{
			if (i == n-1)
			{
				tmp2 = nums[0];
				nums[0] = tmp1;
			}
			else
			{
				tmp2 = nums[i+1];
				nums[i+1] = tmp1;
			}
			tmp1 = tmp2;
		}
		tmpK--;
	}
}

uint32_t Function::reverseBits(uint32_t n)
{
	uint32_t value = 0;
	uint32_t k = 1;
	for (int i = 0; i < 32; i++)
	{
		value = (value << 1) | ((n & k) >> i);
		k = k << 1;
	}
	return value;
}

int Function::hammingWeight(uint32_t n)
{
	int count = 0;
	uint32_t k = 1;
	for (int i = 0; i < 32; i++)
	{
		if ((n & k) >> i == 1)
		{
			count++;
		}
		k = k << 1;
	}
	return count;
}

int Function::robMax(vector<int>& nums)
{
	int value = 0;
	int n = nums.size();
	if (n == 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return nums[0];
	}
	else if (n == 2)
	{
		return max(nums[0], nums[1]);
	}
	vector<int> k;
	k.push_back(nums[0]);
	k.push_back(max(nums[0], nums[1]));
	for (int i = 2; i < n; i++)
	{
		k.push_back(max(k[i-2] + nums[i], k[i-1]));
	}
	return k[k.size()-1];
}

bool Function::isHappyNum(int n)
{
	set<int> tmpSet;
	set<int>::iterator it;
	int tmp;
	tmpSet.insert(n);
	while (1)
	{
		tmp = 0;
		while (n > 0)
		{
			tmp += (n % 10) * (n % 10);
			n /= 10;
		}
		it = tmpSet.find(tmp);
		if (tmp == 1)
		{
			return true;
		}
		else if (it != tmpSet.end())
		{
			return false;
		}
		else 
		{
			tmpSet.insert(tmp);
			n = tmp;
		}
	}
	return n==1;
}

ListNode* Function::removeListElement(ListNode* head, int val)
{
	if (head == NULL)
	{
		return head;
	}
	ListNode* p = head;
	ListNode* q = head;
	while (head != NULL)
	{
		if (head->val == val)
		{
			head = head->next;
		}
		else
		{
			p = head;
			q = head->next;
			break;
		}
	}
	while (q != NULL)
	{
		if (q->val == val)
		{
			p->next = q->next;
			q = q->next;
		}
		else
		{
			p = q;
			q = q->next;
		}
	}
	return head;
}

int Function::countPrimes(int n)
{
	int count = 0;
	vector<int> vec;
	for (int i = 2; i < n; i++)
	{
		bool isPrimes = true;
		for (int j = 0; j < vec.size() && vec[j]*vec[j] <= i; j++)
		{
			if (i % vec[j] == 0)
			{
				isPrimes = false;
				break;
			}
		}
		if (isPrimes)
		{
			vec.push_back(i);
			count++;
		}
	}
	return count;
}

bool Function::isIsomorphic(string s, string t)
{
	map<char, char> ms;
	map<char, char> mt;
	map<char, char>::iterator its;
	map<char, char>::iterator itt;
	for (int i = 0; i < s.length(); i++)
	{
		its = ms.find(s[i]);
		itt = mt.find(t[i]);
		if (its == ms.end() && itt == mt.end())
		{
			ms.insert(map<char, char>::value_type(s[i], t[i]));
			mt.insert(map<char, char>::value_type(t[i], s[i]));
		}
		else if (its != ms.end() && itt != mt.end())
		{
			if (ms[s[i]] != t[i] || mt[t[i]] != s[i])
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	return true;
}

ListNode* Function::reverseList(ListNode* head)
{
	ListNode* p = NULL;
	ListNode* q = NULL;
	while (head != NULL)
	{
		q = head->next;
		head->next = p;
		p = head;
		if (q == NULL)
		{
			break;
		}
		head = q;
	}
	return head;
}

bool Function::containsDuplicate(vector<int>& nums)
{
	set<int> tmpSet;
	set<int>::iterator it;
	for (int i = 0; i < nums.size(); i++)
	{
		it = tmpSet.find(nums[i]);
		if (it == tmpSet.end())
		{
			tmpSet.insert(nums[i]);
		}
		else
		{
			return true;
		}
	}
	return false;
}

bool Function::containsNearbyDuplicate(vector<int>& nums, int k)
{
	map<int, int> tmpMap;
	map<int, int>::iterator it;
	for (int i = 0; i < nums.size(); i++)
	{
		it = tmpMap.find(nums[i]);
		if (it != tmpMap.end())
		{
			if (i - tmpMap[nums[i]] <= k)
			{
				return true;
			}
			else
			{
				tmpMap.erase(it);
				tmpMap.insert(map<int, int>::value_type(nums[i], i));
			}
		}
		else
		{
			tmpMap.insert(map<int, int>::value_type(nums[i], i));
		}
	}
	return false;
}

TreeNode* Function::invertTree(TreeNode* root)
{
	if (root == NULL)
	{
		return NULL;
	}
	invertTree(root->left);
	invertTree(root->right);
	TreeNode* tmp = root->left;
	root->left = root->right;
	root->right = tmp;
	return root;
}

bool Function::isPowerOfTwo(int n)
{
	if (n == 1)
	{
		return true;
	}
	if (n > 1 && n % 2 == 0)
	{
		return isPowerOfTwo(n / 2);
	}
	return false;
}

bool Function::isPalindromeList(ListNode* head)
{
	if (head == NULL || head->next == NULL)
	{
		return true;
	}
	ListNode* slow = head;
	ListNode* fast = head;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	if (fast != NULL)
	{
		slow->next = reverseList(slow->next);
		slow = slow->next;
	}
	else
	{
		slow = reverseList(slow);
	}
	while (slow != NULL)
	{
		if (head->val != slow->val)
		{
			return false;
		}
		head = head->next;
		slow = slow->next;
	}
	return true;
}

TreeNode* Function::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
	TreeNode* mid = root;
	while (1)
	{
		if (mid->val < p->val && mid->val < q->val)
		{
			mid = mid->right;
		}
		else if (mid->val > p->val && mid->val > q->val)
		{
			mid = mid->left;
		}
		else
		{
			return mid;
		}
	}
}

void Function::deleteNode(ListNode* node)
{
	if (node == NULL)
	{
		return;
	}
	ListNode* tmpNode = node->next;
	node->val = tmpNode->val;
	node->next = tmpNode->next;
	delete tmpNode;
}

bool Function::isAnagram(string s, string t)
{
	if (s.length() != t.length())
	{
		return false;
	}
	map<char, int> sm;
	map<char, int> tm;
	for (int i = 0; i < s.length(); i++)
	{
		sm[s[i]]++;
		tm[t[i]]++;
	}
	map<char, int>::iterator st = sm.begin();
	map<char, int>::iterator tt = tm.begin();
	while (st != sm.end())
	{
		if (st->first != tt->first || st->second != tt->second)
		{
			return false;
		}
		st++;
		tt++;
	}
	return true;
}

vector<string> Function::binaryTreePaths(TreeNode* root)
{
	vector<string> vec;
	if (root == NULL)
	{
		return vec;
	}
	string s = "";
	addTreePaths(root, s, &vec);
	return vec;
}

void Function::addTreePaths(TreeNode* node, string tmpS, vector<string> *vec)
{
	char buffer[20];
	sprintf(buffer, "%d", node->val);
	if (tmpS == "")
	{
		tmpS = buffer;
	}
	else
	{
		tmpS = tmpS + "->" + buffer;
	}
	if (node->left != NULL)
	{
		addTreePaths(node->left, tmpS, vec);
	}
	if (node->right != NULL)
	{
		addTreePaths(node->right, tmpS, vec);
	}
	if (node->left == NULL && node->right == NULL)
	{
		vec->push_back(tmpS);
	}
}

int Function::addDigits(int num)
{
	while (1)
	{
		int sum = 0;
		if (num / 10 == 0)
		{
			return num;
		}
		do
		{
			sum += num % 10;
			num /= 10;
		}while (num != 0);
		num = sum;
	}
}

bool Function::isUgly(int num)
{
	if (num <= 0)
	{
		return false;
	}
	while (1)
	{
		if (num == 1)
		{
			return true;
		}
		if (num % 2 != 0 && num % 3 != 0 && num % 5 != 0)
		{
			return false;
		}
		else if (num % 2 == 0)
		{
			num /= 2;
		}
		else if (num % 3 == 0)
		{
			num /= 3;
		}
		else if (num % 5 == 0)
		{
			num /= 5;
		}
	}
}

int Function::missingNumber(vector<int>& nums)
{
	int r = 0, i;
	for (i = 0; i < nums.size(); i++)
	{
		r ^= i;
		r ^= nums[i];
	}
	r ^= i;
	return r;
}

int Function::firstBadVersion(int n)
{
	if (n == 1)
	{
		return 1;
	}
	int first = 1, end = n;
	int mid;
	while (first < end)
	{
		mid = first + (end - first) / 2;
		if (isBadVersion(mid))
		{
			end = mid;
		}
		else
		{
			first = mid + 1;
		}
	}
	return first;
}

bool Function::isBadVersion(int version)
{
	if (version > 5)
	{
		return true;
	}
	return false;
}

void Function::moveZeroes(vector<int>& nums)
{
	int first = 0;
	int tmp;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[first] != 0 && nums[i] == 0)
		{
			first = i;
		}
		else if (nums[first] == 0 && nums[i] != 0)
		{
			tmp = nums[i];
			nums[i] = nums[first];
			nums[first] = tmp;
			first++;
		}
	}
}

bool Function::wordPattern(string pattern, string str)
{
	map<char, string> tmpMap1;
	map<string, char> tmpMap2;
	map<char, string>::iterator it1;
	map<string, char>::iterator it2;
	int i, j;
	string tmpStr = "";
	for (i = 0, j = 0; j <= str.length(); j++)
	{
		if (j != str.length() && str.at(j) != ' ')
		{
			if (i == pattern.length())
			{
				return false;
			}
			tmpStr.append(1, str.at(j));
		}
		else
		{
			it1 = tmpMap1.find(pattern.at(i));
			it2 = tmpMap2.find(tmpStr);
			if (it1 == tmpMap1.end() && it2 == tmpMap2.end())
			{
				tmpMap1.insert(map<char, string>::value_type(pattern.at(i), tmpStr));
				tmpMap2.insert(map<string, char>::value_type(tmpStr, pattern.at(i)));
			}
			else if (it1 != tmpMap1.end() && it2 != tmpMap2.end())
			{
				if (tmpMap1[pattern.at(i)] != tmpStr || tmpMap2[tmpStr] != pattern.at(i))
				{
					return false;
				}
			}
			else
			{
				return false;
			}
			i++;
			tmpStr = "";
		}
	}
	if (i < pattern.length())
	{
		return false;
	}
	return true;
}

bool Function::canWinNim(int n)
{
	if (n % 4 != 0)
	{
		return true;
	}
	return false;
}

bool Function::isPowerOfTree(int n)
{
	// 如果不用循环，可以用穷举法，把所有3的次方列出来
	while (n > 1)
	{
		if (n % 3 == 0)
		{
			n /= 3;
		}
		else
		{
			return false;
		}
	}
	if (n == 1)
	{
		return true;
	}
	return false;
}

bool Function::isPowerOfFour(int n)
{
	switch(n)
	{
	case 0x00000001:
	case 0x00000004:
	case 0x00000010:
	case 0x00000040:
	case 0x00000100:
	case 0x00000400:
	case 0x00001000:
	case 0x00004000:
	case 0x00010000:
	case 0x00040000:
	case 0x00100000:
	case 0x00400000:
	case 0x01000000:
	case 0x04000000:
	case 0x10000000:
	case 0x40000000:
		return true;
	default:
		return false;
	}
}

string Function::reverseString(string s)
{
	string tmpStr = "";
	for (int i = 0; i < s.length(); i++)
	{
		tmpStr.insert(0, 1, s.at(i));
	}
	return tmpStr;
}

string Function::reverseVowels(string s)
{
	int i = 0, j = s.length() - 1;
	while (i < j)
	{
		if (isVowel(s.at(i)) && isVowel(s.at(j)))
		{
			char tmpC = s.at(i);
			s = s.replace(i, 1, 1, s.at(j));
			s = s.replace(j, 1, 1, tmpC);
			i++;
			j--;
		}
		if (!isVowel(s.at(i)))
		{
			i++;
		}
		if (!isVowel(s.at(j)))
		{
			j--;
		}
	}
	return s;
}

bool Function::isVowel(char c)
{
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
		c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
	{
		return true;
	}
	return false;
}

vector<int> Function::intersection(vector<int>& nums1, vector<int>& nums2)
{
	set<int> tmpSet(nums1.begin(), nums1.end());
	vector<int> vec;
	for (int i = 0; i < nums2.size(); i++)
	{
		if (tmpSet.count(nums2[i]))
		{
			vec.push_back(nums2[i]);
			tmpSet.erase(nums2[i]);
		}
	}
	return vec;
}

vector<int> Function::intersect(vector<int>& nums1, vector<int>& nums2)
{
	multiset<int> tmpSet(nums1.begin(), nums1.end());
	multiset<int>::iterator it;
	vector<int> vec;
	for (int i = 0; i < nums2.size(); i++)
	{
		it = tmpSet.find(nums2[i]);
		if (it != tmpSet.end())
		{
			vec.push_back(nums2[i]);
			tmpSet.erase(it);
		}
	}
	return vec;
}

bool Function::isPerfectSquare(int num)
{
	if (num == 1)
	{
		return true;
	}
	int start = 1, stop = num;
	long long tmp, mid;
	while (start < stop - 1)
	{
		mid = start + (stop - start) / 2;
		tmp = mid * mid;
		if (tmp == num)
		{
			return true;
		}
		else if (tmp < num)
		{
			start = mid;
		}
		else if (tmp > num)
		{
			stop = mid;
		}
	}
	return false;
}

int Function::getSum(int a, int b)
{
	if (a == 0)
	{
		return b;
	}
	return getSum((a & b) << 1, a^b);
}

int Function::guessNumber(int n)
{
	int min = 1, max = n, mid;
	if (guess(1) == 0)
	{
		return 1;
	}
	if (guess(n) == 0)
	{
		return n;
	}
	while (min < max)
	{
		mid = min + (max - min) / 2;
		if (1 == guess(mid))
		{
			min = mid;
		}
		else if (-1 == guess(mid))
		{
			max = mid;
		}
		else
		{
			return mid;
		}
	}
	return 0;
}

int Function::guess(int num)
{
	if (num > 5)
	{
		return -1;
	}
	else if (num < 5)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool Function::canConstruct(string ransomNote, string magazine)
{
	vector<int> tmpVec(26);
	for (int i = 0; i < magazine.length(); i++)
	{
		tmpVec[magazine.at(i) - 'a']++;
	}
	for (int i = 0; i < ransomNote.length(); i++)
	{
		tmpVec[ransomNote.at(i) - 'a']--;
	}
	for (int i = 0; i < 26; i++)
	{
		if (tmpVec[i] < 0)
		{
			return false;
		}
	}
	return true;
}

int Function::firstUniqChar(string s)
{
	map<char, int> tmpMap;
	map<char, int>::iterator it;
	for (int i = 0; i < s.length(); i++)
	{
		it = tmpMap.find(s.at(i));
		if (it == tmpMap.end())
		{
			tmpMap.insert(map<char, int>::value_type(s.at(i), 1));
		}
		else
		{
			tmpMap[s.at(i)]++;
		}
	}
	for (int i = 0; i < s.length(); i++)
	{
		if (tmpMap[s.at(i)] == 1)
		{
			return i;
		}
	}
	return -1;
}

char Function::findTheDifference(string s, string t)
{
	map<char, int> tmpMap;
	map<char, int>::iterator it;
	for (int i = 0; i < s.length(); i++)
	{
		it = tmpMap.find(s.at(i));
		if (it == tmpMap.end())
		{
			tmpMap.insert(map<char, int>::value_type(s.at(i), 1));
		}
		else
		{
			tmpMap[s.at(i)]++;
		}
	}
	for (int i = 0; i < t.length(); i++)
	{
		it = tmpMap.find(t.at(i));
		if (it == tmpMap.end())
		{
			return t.at(i);
		}
		else
		{
			if (tmpMap[t.at(i)] == 0)
			{
				return t.at(i);
			}
			else
			{
				tmpMap[t.at(i)]--;
			}
		}
	}
}

int Function::findNthDigit(int n)
{
	long long num = 9, k = 1 ,i = 1, t, r;
	while (n > num)
	{
		k *= 10;
		i++;
		num += k * 9 * i;
	}
	n = k * 9 * i - (num - n);
	t = i - (n - 1) % i;
	n = (n - 1) / i + k;
	while (t > 0)
	{
		r = n % 10;
		n = n / 10;
		t--;
	}
	return r;
}

vector<string> Function::readBinaryWatch(int num)
{
	vector<string> ret;
	for (int h = 0; h <= num; h++)
	{
		int m = num - h;
		if (h > 4)
		{
			break;
		}
		if (m > 6)
		{
			continue;
		}
		vector<string> hvec = readBinaryNum(h, 12);
		vector<string> mvec = readBinaryNum(m, 60);
		for (int p = 0; p < hvec.size(); p++)
		{
			string sh = hvec[p];
			for (int q = 0; q < mvec.size(); q++)
			{
				string sm = mvec[q];
				if (sm.length() == 1)
				{
					sm = "0" + sm;
				}
				ret.push_back(sh + ":" + sm);
			}
		}
	}
	return ret;
}

vector<string> Function::readBinaryNum(int num, int max)
{
	vector<string> vec;
	for (int i = 0; i < max; i++)
	{
		int tmp = i;
		int sum = 0;
		char s[2];
		while (tmp != 0)
		{
			if (tmp % 2 == 1)
			{
				sum++;
			}
			tmp /= 2;
		}
		if (sum == num)
		{
			sprintf(s, "%d", i);
			vec.push_back(s);
		}
	}
	return vec;
}

int Function::sumOfLeftLeaves(TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		if (root->left != NULL && root->left->left == NULL && root->left->right == NULL)
		{
			return root->left->val + sumOfLeftLeaves(root->right);
		}
		return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
	}
}

string Function::toHex(int num)
{
	char hex[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
	string s = "";
	while (num != 0)
	{
		s.insert(0, 1, hex[num & 15]);
		num = (unsigned)num >> 4;
	}
	return s;
}

int Function::longestPalindrome(string s)
{
	int sum = 0;
	map<char, int> tmpMap;
	map<char, int>::iterator it;
	for (int i = 0; i < s.length(); i++)
	{
		it = tmpMap.find(s.at(i));
		if (it == tmpMap.end())
		{
			tmpMap.insert(map<char, int>::value_type(s.at(i), 1));
		}
		else
		{
			tmpMap[s.at(i)]++;
		}
	}
	it = tmpMap.begin();
	while (it != tmpMap.end())
	{
		if (it->second % 2 == 0 || sum % 2 == 0)
		{
			sum += it->second;
		}
		else
		{
			sum += it->second - 1;
		}
		it++;
	}
	return sum;
}

vector<string> Function::fizzBuzz(int n)
{
	vector<string> vec;
	for (int i = 1; i <= n; i++)
	{
		if (i % 3 == 0 && i % 5 == 0)
		{
			vec.push_back("FizzBuzz");
		}
		else if (i % 3 == 0)
		{
			vec.push_back("Fizz");
		}
		else if (i % 5 == 0)
		{
			vec.push_back("Buzz");
		}
		else
		{
			char buffer[12];
			sprintf(buffer, "%d", i);
			vec.push_back(buffer);
		}
	}
	return vec;
}

int Function::thirdMax(vector<int>& nums)
{
	set<int> tmpSet;
	set<int>::const_iterator it;
	int t = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		tmpSet.insert(nums[i]);
	}
	it = tmpSet.end();
	do
	{
		it--;
		t++;
		if (t == 3)
		{
			return *it;
		}
	}while(it != tmpSet.begin());
	it = --tmpSet.end();
	return *it;
}

string Function::addStrings(string num1, string num2)
{
	string sum;
	int len1 = num1.length() - 1;
	int len2 = num2.length() - 1;
	int k = 0, tmp = 0;
	while (len1 >= 0 || len2 >= 0)
	{
		if (len1 >= 0)
		{
			tmp += num1.at(len1) - '0';
		}
		if (len2 >= 0)
		{
			tmp += num2.at(len2) - '0';
		}
		if (k)
		{
			tmp++;
		}
		k = tmp / 10;
		sum.insert(0, 1, char(tmp % 10 + '0'));
		tmp = 0;
		len1--;
		len2--;
	}
	if (k)
	{
		sum.insert(0, 1, '1');
	}
	return sum;
}

int Function::coutSegments(string s)
{
	int count = 0;
	bool find = false;
	for (int i = 0; i < s.length(); i++)
	{
		if (!find && s.at(i) != ' ')
		{
			count++;
			find = true;
		}
		else if ( s.at(i) == ' ')
		{
			find = false;
		}
	}
	return count;
}

int Function::pathSum(TreeNode* root, int sum)
{
	int count = 0;
	vector<int> vec_sum;
	if (root != NULL)
	{
		pathSumCount(root, vec_sum, count, sum);
	}
	return count;
}

void Function::pathSumCount(TreeNode* node, vector<int> vec_sum, int &count, const int &sum)
{
	for (int i = 0; i < vec_sum.size(); i++)
	{
		vec_sum[i] += node->val;
		if (vec_sum[i] == sum)
		{
			count++;
		}
	}
	if (node->val == sum)
	{
		count++;
	}
	vec_sum.push_back(node->val);
	if (node->left != NULL)
	{
		pathSumCount(node->left, vec_sum, count, sum);
	}
	if (node->right != NULL)
	{
		pathSumCount(node->right, vec_sum, count, sum);
	}
}

vector<int> Function::findAnagrams(string s, string p)
{
	vector<int> pv(26,0), sv(26,0), res;
	if(s.size() < p.size())
	{
		return res;
	}
	for(int i = 0; i < p.size(); ++i)
	{
		++pv[p[i]-'a'];
		++sv[s[i]-'a'];
	}
	if(pv == sv)
	{
		res.push_back(0);
	}
	for(int i = p.size(); i < s.size(); ++i)
	{
		++sv[s[i]-'a'];
		--sv[s[i-p.size()]-'a']; 
		if(pv == sv)
		{
			res.push_back(i-p.size()+1);
		}
	}
	return res;
}

int Function::arrangeCoins(int n)
{
	long long sum = 0;
	int i = 0;
	if (n == 0)
	{
		return 0;
	}
	while (sum <= n)
	{
		i++;
		sum += i;
	}
	return i - 1;
}

int Function::numberOfBoomerangs(vector<pair<int, int>>& points)
{
	int len = points.size(), sum = 0;
	map<int, int> tmpMap;
	map<int, int>::iterator it;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			int x = points[i].first - points[j].first;
			int y = points[i].second - points[j].second;
			tmpMap[x * x + y * y]++;
		}
		it = tmpMap.begin();
		while (it != tmpMap.end())
		{
			sum += (it->second) * (it->second - 1);
			it++;
		}
		tmpMap.clear();
	}
	return sum;
}

vector<int> Function::findDisappearedNumbers(vector<int>& nums)
{
	int len = nums.size();
	vector<int> res;
	vector<int> tmpVec(len + 1, 0);
	for (int i = 0; i < len; i++)
	{
		tmpVec[nums[i]]++;
	}
	for (int i = 1; i <= len; i++)
	{
		if (tmpVec[i] == 0)
		{
			res.push_back(i);
		}
	}
	return res;
}

int Function::minMoves(vector<int>& nums)
{
	int sum = 0, count = 0;
	int min = nums[0];
	for (int i = 0; i < nums.size(); i++)
	{
		if (min <= nums[i])
		{
			sum += nums[i] - min;
		}
		else
		{
			sum += (min - nums[i]) * count;
			min = nums[i];
		}
		count++;
	}
	return sum;
}

int Function::findContentChildren(vector<int>& g, vector<int>& s)
{
	int num = 0, mark = 0;
	sort(g.begin(), g.end());
	sort(s.begin(), s.end());
	for (int i = 0; i < g.size(); i++)
	{
		while (mark < s.size())
		{
			if (g[i] <= s[mark])
			{
				num++;
				mark++;
				break;
			}
			mark++;
		}
		if (mark >= s.size())
		{
			return num;
		}
	}
	return num;
}

int Function::poorPigs(int buckets, int minutesToDie, int minutesToTest)
{
	int n = minutesToTest / minutesToDie;
	int i = 0, sum = 1;
	while (sum < buckets)
	{
		sum *= n + 1;
		i++;
	}
	return i;
}

bool Function::repeatedSubstringPattern(string s)
{
	int len  = s.length();
	for (int i = 1; i < len; i++)
	{
		if (len % i == 0)
		{
			string tmp, t;
			int k = len / i;
			tmp = s.substr(0, i);
			for (int j = 0; j < k; j++)
			{
				t += tmp;
			}
			if (t == s)
			{
				return true;
			}
		}
	}
	return false;
}

int Function::hammingDistance(int x, int y)
{
	int num = 0;
	for (int i = 0; i < 32; i++)
	{
		if (x % 2 != y % 2)
		{
			num++;
		}
		x /= 2;
		y /= 2;
	}
	return num;
}

int Function::islandPerimeter(vector<vector<int>>& grid)
{
	int per = 0, b = 0, lenv, lenh;
	if (grid.empty())
	{
		return 0;
	}
	else
	{
		lenv = grid.size();
		lenh = grid[0].size();
	}
	for (int i = 0; i < lenv; i++)
	{
		b = 0;
		for (int j = 0; j < lenh; j++)
		{
			if (b != grid[i][j])
			{
				per++;
			}
			b = grid[i][j];
		}
		if (b)
		{
			per++;
		}
	}
	for (int j = 0; j < lenh; j++)
	{
		b = 0;
		for (int i = 0; i < lenv; i++)
		{
			if (b != grid[i][j])
			{
				per++;
			}
			b = grid[i][j];
		}
		if (b)
		{
			per++;
		}
	}
	return per;
}

int Function::findRadius(vector<int>& houses, vector<int>& heaters)
{
	int len1 = houses.size(), len2 = heaters.size();
	int red = 0, k = 0;
	sort(houses.begin(), houses.end());
	sort(heaters.begin(), heaters.end());
	for (int i = 0; i < len1; i++)
	{
		int tmp = INT_MAX;
		while (k < len2)
		{
			if (houses[i] >= heaters[k])
			{
				tmp = houses[i] - heaters[k];
			}
			else
			{
				if (heaters[k] - houses[i] <= tmp)
				{
					tmp = heaters[k] - houses[i];
				}
				else
				{
					break;
				}
			}
			k++;
		}
		k--;
		if (k == len2 - 1)
		{
			tmp = abs(houses[i] - heaters[k]);
		}
		red = max(red, tmp);
	}
	return red;
}

int Function::findComplement(int num)
{
	int res = 0, k = 1;
	while (num > 0)
	{
		if (num % 2 == 0)
		{
			res += k;
		}
		num /= 2;
		k *= 2;
	}
	return res;
}

int Function::largestPalindrome(int n)
{
	if (n == 1)
	{
		return 9;
	}
	int high = pow(10.0, n) - 1, low = high / 10;
	for (int i = high; i >= low; i--)
	{
		long long pal = largestPalindromeGet(i);
		for (long long j = high; j >= low; j--)
		{
			if (pal / j > high)
			{
				break;
			}
			if (pal % j == 0 && pal / j >=low)
			{
				return (int)(pal % 1337);
			}
		}
	}
	return -1;
}

long long Function::largestPalindromeGet(int num)
{
	long long tmp = num;
	long long r = 0, k = 1;
	do {
		r = r * 10 + num % 10;
		k *= 10;
	} while(num /= 10);
	long long ret = tmp * k + r;
	return ret;
}

int Function::findMaxConsecutiveOnes(vector<int>& nums)
{
	int ret = 0, tmp = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == 1)
		{
			tmp++;
		}
		else
		{
			ret = (ret >= tmp)?ret:tmp;
			tmp = 0;
		}
	}
	ret = (ret >= tmp)?ret:tmp;
	return ret;
}

vector<int> Function::constructRectangle(int area)
{
	vector<int> vec;
	int mid = sqrt(double(area));
	for (int i = mid; i <= area; i++)
	{
		if (area % i == 0)
		{
			vec.push_back(i);
			vec.push_back(area / i);
			break;
		}
	}
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	return vec;
}

vector<int> Function::nextGreaterElement(vector<int>& findNums, vector<int>& nums)
{
	vector<int> ret;
	map<int ,int> pos;
	for (int i = 0; i < nums.size(); i++)
	{
		int j = i, n = -1;
		for ( ; j < nums.size(); j++)
		{
			if (nums[j] > nums[i])
			{
				n = nums[j];
				break;
			}
		}
		pos[nums[i]] = n;
	}
	for (int i = 0; i < findNums.size(); i++)
	{
		ret.push_back(pos[findNums[i]]);
	}
	return ret;
}

vector<string> Function::findWords(vector<string>& words)
{
	vector<string> vec;
	for (int i = 0; i < words.size(); i++)
	{
		if (wordOnOneRow(words[i]))
		{
			vec.push_back(words[i]);
		}
	}
	return vec;
}

bool Function::wordOnOneRow(string word)
{
	set<char> row1 = {'q','w','e','r','t','y','u','i','o','p'};
	set<char> row2 = {'a','s','d','f','g','h','j','k','l'};
	set<char> row3 = {'z','x','c','v','b','n','m'};
	bool k1 = true, k2 = true, k3 = true;
	set<char>::iterator it;
	for (int i = 0; i < word.length(); i++)
	{
		if (k1)
		{
			it = row1.find(tolower(word[i]));
			if (it == row1.end())
			{
				k1 = false;
			}
		}
		if (k2)
		{
			it = row2.find(tolower(word[i]));
			if (it == row2.end())
			{
				k2 = false;
			}
		}
		if (k3)
		{
			it = row3.find(tolower(word[i]));
			if (it == row3.end())
			{
				k3 = false;
			}
		}
	}
	return k1 || k2 || k3;
}