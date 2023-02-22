## Leetcode详解



leetcode1

[两数之和](https://leetcode.cn/problems/two-sum/description/)

>```c++
>输入：nums = [2,7,11,15], target = 9
>输出：[0,1]
>解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
>```

解法1： 

		1. 创建字典map，其中key为nums[i] - target, value为下标index
		1. 遍历循环nums，如果当前nums[i]在map中，则（i，map[nums[i]]）即为所求
		1. 需要注意的点为输入为[3,3]，target=6的情况下；因此需要判断当前的i和map[nums[i]]是否一致进行排除 



代码如下：

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++){
            if(hash.find(nums[i]) != hash.end()){
                res.push_back(i);
                res.push_back(hash[nums[i]]);
                break;
            } else {
                hash[target - nums[i]] = i;
            }
        }
        return res;
        
    }
};
```



leetcode2 

[两数相加](https://leetcode.cn/problems/add-two-numbers/)

题干信息

```c++
输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.
```

题解如下：

```c++
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* n1 = l1;
        ListNode* n2 = l2;
        ListNode* dummy = new ListNode(-1); //虚拟头节点的处理
        ListNode* temp = dummy;
        int carry = 0;
        int l1_val = 0;
        int l2_val = 0;
        while(n1 || n2){
            l1_val = n1?n1->val:0;
            l2_val = n2?n2->val:0;
            ListNode* tmp = new ListNode((l1_val+l2_val+carry) % 10);
            carry = (l1_val+l2_val+carry) / 10; //进位的处理
            temp->next = tmp;
            temp = temp->next;
            n1 = n1?n1->next:n1;
            n2 = n2?n2->next:n2;
        }
        if (carry){
            ListNode* tmp = new ListNode(1);
            temp->next = tmp;
            return dummy->next;
        }else {
            return dummy->next; //最后是否进位的判断
        }
    
    }
};
```



leetcode3 

[无重复字符的最长子串](https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/)

```c++
输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
注意子串和子序列不同，子串要求连续。
```

滑动窗口思想，双指针做法

```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> hash;
        int max_length = 0;

        for(int i = 0; i < s.size(); i++){
            hash.insert(s[i]); //将当天字符插入哈希表中
            int rk = i + 1; //从后一个字符开始遍历
            while(rk < s.size() && !hash.count(s[rk])){
                hash.insert(s[rk]);
                rk = rk + 1; //如果遍历字符不在哈希表中，则长度+1；直到排查到重复的停止
            }
            max_length = max(max_length, rk - i); //记录当前的最长子序列长度
            hash.clear();
        }
        return max_length;

    }
};
```



leetcode5

[最长回文子串](https://leetcode.cn/problems/longest-palindromic-substring/description/)

```c++
输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
```

```c++
class Solution {
public:
    string help(string s, int i){
        int odd = 1;
        while(i - odd >= 0 && i + odd < s.size() && s[i - odd] == s[i + odd]){
            odd = odd + 1;
        }
        string str1 = s.substr(i - odd + 1, 2*(odd - 1) + 1);
       	//回文子串长度为奇数的情况
        int even = 1;
        string str2 = "";
        if (i + 1 < s.size() && s[i] == s[i + 1]){
        while(i - even >= 0 && i + even + 1 < s.size() && s[i - even] == s[i + even + 1]){
            even = even + 1;
        }
        str2 = s.substr(i - even + 1, 2*(even));
        } else {
            str2 = s.substr(i,even);
        }
        //回文子串长度为偶数的情况
        return str1.size() > str2.size() ? str1 : str2;
    }
    string longestPalindrome(string s) {
        string max_string = "";
        for (int i = 0 ; i < s.size(); i++){
            string temp = help(s,i);
            max_string = max_string.size() < temp.size() ? temp:max_string;
            //循环的过程是以当前字符为中心，直到最长的回文子串的过程
        }
        return max_string;
    }
};
```







