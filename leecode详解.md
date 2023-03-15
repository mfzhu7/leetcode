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

leetcode6 

[N字形变换](https://leetcode.cn/problems/zigzag-conversion/description/)

```c++
输入：s = "PAYPALISHIRING", numRows = 4
输出："PINALSIGYAHRPI"
解释：
P     I    N
A   L S  I G
Y A   H R
P     I
```

解法:

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        int flag = 1;
        int idx = 0;
        vector<string> rows(numRows);
        for(int i = 0; i < s.size(); i++){
            rows[idx].push_back(s[i]);
            idx = idx + flag;
            if (idx == numRows - 1 || idx == 0){
                flag = flag * (-1);
            }
        } //重点在于此处的设置。
         // idx用来标记当前属于哪一行
         // 用flag来标记什么时候进行row的递增还是递减，从而实现z字形的变化
        string res;
        for (auto row: rows){
            res += row;
        }
        return res;

    }
};
```

leetcode7 

[整数反转](https://leetcode.cn/problems/reverse-integer/description/)

```c++
输入：x = -123
输出：-321
```

```cpp
class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN || x == 0) return 0; //INT_MIN的反转超过最大值，需要设置为0
        int flag = 1; //标记是否为负数
        if (x < 0){
            flag = -1 * flag;
            x = -1 * x;
        }
        double res = 0;
        while(x){
            int temp = x % 10;
            x = (x - temp) / 10;
            res = res * 10 + temp; //使用长除法得到正数 
        }
        res = res * flag; //恢复负号
        if(res < INT_MIN || res > INT_MAX){
            return 0; //超过阈值判断
        } else {
            return (int)res; //类型转换
        }
    }
};

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while(x != 0){
            if( rev < INT_MIN / 10 || rev > INT_MAX / 10){
                return 0; //重点在于判断在计算过程中是否超过了整型数据的范围
            }
            int digit = x % 10;
            x = x / 10;
            rev = rev * 10 +digit;

        }
        return rev;

    }
};
```

[证明的细节](https://leetcode.cn/problems/reverse-integer/solutions/755611/zheng-shu-fan-zhuan-by-leetcode-solution-bccn/)

leetcode8

[字符串转换整数](https://leetcode.cn/problems/string-to-integer-atoi/)

```c++
输入：s = "4193 with words"
输出：4193
解释：
第 1 步："4193 with words"（当前没有读入字符，因为没有前导空格）
         
第 2 步："4193 with words"（当前没有读入字符，因为这里不存在 '-' 或者 '+'）
         
第 3 步："4193 with words"（读入 "4193"；由于下一个字符不是一个数字，所以读入停止）
             
解析得到整数 4193 。
由于 "4193" 在范围 [-231, 231 - 1] 内，最终结果为 4193 。
```

```c++
class Solution {
public:
    int myAtoi(string s) {
        int index = 0;
        int neg = 1;
        int ret = 0;

        while(index < s.size() && s[index] == ' '){
            index++;
        } //首先去掉前序空格
        if (index < s.size() && (s[index] == '+' or s[index] == '-')){
            if (s[index] == '-'){
                neg = neg * -1;
            }
            index = index + 1;
        } //找到符号 
        while(index < s.size() && isdigit(s[index])){
            int num = s[index] - '0';
            if( ret > INT_MAX/10 || (ret == INT_MAX/10 && num > INT_MAX % 10 ) )
            {//关键在于此处，判断是否已经大于(INT_MAX/10)以及等于(INT_MAX/10)的情况
                return 1==neg ? INT_MAX : INT_MIN;    
            }
            ret = ret * 10 + num;
            index++;
        }
        return ret * neg;
    }
};
```



leetcode9

[回文数](https://leetcode.cn/problems/palindrome-number/)

```c++
输入：x = 10
输出：false
解释：从右向左读, 为 01 。因此它不是一个回文数。
```



```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false; //小于0的情况下，肯定不是回文数
        vector<int> vec;
        int left = x;
        while(left){
            vec.push_back(left%10);
            left = left - left % 10;
            left = left / 10;
        } //通过求余和除法得到最低位的每一位数字并且存储下来
        int i = 0;
        int j = vec.size() - 1;
        while( i != j && i <= j) {
            if(vec[i] != vec[j]) return false;
            i++;
            j--;
        } //判断数组的头尾是否相同来知道是否是回文数
        return true;
    }
};
```



```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0)) return false;

        int revertedNumber = 0;
        while(x > revertedNumber){
            revertedNumber = revertedNumber * 10 + x % 10;
            x = x / 10;
            //只反转一半的数字和剩余数字进行对比；偶数情况相同，奇数情况需要判断/10
        }
        return x == revertedNumber || revertedNumber / 10 == x;
    }
};
```

leetcode11

[盛最多水的容器](https://leetcode.cn/problems/container-with-most-water/)

```c++
输入：[1,8,6,2,5,4,8,3,7]
输出：49 
解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
```

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size() - 1;
        int maxarea = 0;
        while(start < end) {
            maxarea = max(maxarea, (end - start) * min(height[start], height[end]));
            // end - start是长方形的宽
            //高取的二者的max
            if (height[start] > height[end]){
                end = end - 1;
            } else {
                start = start + 1;
                //双指针的做法
                //理解双指针移动的逻辑：
                //(1)移动指针，势必会导致宽降低，不管是移动长板还是短板
                //(2)移动长板得到的新的矩形面积一定小于上一次的面积
            }
        }
        return maxarea;
    }
};
```

[贪心的正确性证明](https://leetcode.cn/problems/container-with-most-water/solutions/11491/container-with-most-water-shuang-zhi-zhen-fa-yi-do/)

leetcode12

[整数转罗马数字](https://leetcode.cn/problems/integer-to-roman/)

```c++
输入: num = 1994
输出: "MCMXCIV"
解释: M = 1000, CM = 900, XC = 90, IV = 4.
```

```c++
class Solution {
public:
    string intToRoman(int num) {
        map<int, string> hash = {
            {1,"I"},{2,"II"},{3,"III"},{4,"IV"},{5, "V"},{6, "VI"},{7, "VII"},{8, "VIII"},{9, "IX"},
            {10,"X"},{20,"XX"},{30,"XXX"},{40,"XL"},{50,"L"},{60,"LX"},{70,"LXX"},{80,"LXXX"},{90,"XC"},
            {100,"C"},{200,"CC"},{300,"CCC"},{400,"CD"},{500,"D"},{600,"DC"},{700,"DCC"},{800,"DCCC"},{900,"CM"},
            {1000,"M"},{2000,"MM"},{3000,"MMM"}
        };
    int add = 1;
    string ret = "";
    while(num){
        int left = num % 10;
        num = (num - left) / 10; 
        ret = hash[left * add] + ret;
        add = add * 10;
    }
    return ret;
    }
};
```



leetcode13

[罗马数字转整数](https://leetcode.cn/problems/roman-to-integer/)

```c++
输入: s = "MCMXCIV"
输出: 1994
解释: M = 1000, CM = 900, XC = 90, IV = 4.
```

```cpp
class Solution {
public:
    int romanToInt(string s) {
        map<string,int> hash = {
            {"I",1},
            {"V",5},
            {"X",10},
            {"L",50},
            {"C",100},
            {"D",500},
            {"M",1000},
            {"IV",4},
            {"IX",9},
            {"XL",40},
            {"XC",90},
            {"CD",400},
            {"CM",900}
        };
        int res = 0;
        int i = 0;
        while(i < s.size()){
            if(i < s.size() - 1){
                if(hash.find(s.substr(i,2)) != hash.end())
                {
                    res = res + hash[s.substr(i,2)];
                    i = i + 2; //优先判断向右找2位的
                } else {
                    res = res + hash[s.substr(i,1)];
                    i = i + 1; //找不到就找一位的
                }
            } else {
                    res = res + hash[s.substr(i,1)];
                    i = i + 1; //找两位的情况下，需要考虑边界值
            } 
        }
        return res;
    }
};
```



```c++
class Solution {
private:
    unordered_map<char, int> symbolValues = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };

public:
    int romanToInt(string s) {
        int ans = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            int value = symbolValues[s[i]];
            if (i < n - 1 && value < symbolValues[s[i + 1]]) {
                //判断下一位和当前位的数值大小，小的情况下减去当前值
                ans -= value;
            } else {
                ans += value;
            }
        }
        return ans;
    }
};

```



leetcode14

[最长公共前缀](https://leetcode.cn/problems/longest-common-prefix/description/)

```c++
输入：strs = ["flower","flow","flight"]
输出："fl"
```

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
            int length = 0;
            for (int i = 0; i < strs[0].size(); i++){
                int count = 0;
                for (int j = 1; j < strs.size();j++){
                    if(strs[j][i] != strs[0][i]) break;
                    else count = count + 1;
                }
                if(count == strs.size() - 1) length = length+1;
                else break;
            }
            return strs[0].substr(0,length);
    }
};
//垂直扫描，暴力解法
```

leetcode15

[三数之和](https://leetcode.cn/problems/3sum/)

排序+双指针解法

```cpp
输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
解释：
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
注意，输出的顺序和三元组的顺序并不重要。
```

```c++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int index = 0;
        vector<vector<int>> ret; //存储结果
        sort(nums.begin(), nums.end()); //进行排序
        while(index < nums.size() - 2){ //因为是三元组，所以只要计算到倒数第二个
            if (nums[index] > 0) return ret; //如果固定的数已经>0了，那么就无须继续遍历了
            if (index > 0 && nums[index] == nums[index - 1]) {
                index = index + 1;
                continue;
            }; //如果当前数和之前的数一样，则表明已经遍历过了，无须重复遍历
            int L = index + 1; 
            int R = nums.size() - 1; //定义左右双指针
            while(L < R){
                if (nums[L] + nums[R] + nums[index] == 0){
                    ret.push_back({nums[L],nums[R],nums[index]});
                    //如果已经找到了目标值，则存储结果
                    while(L < R && nums[L] == nums[L + 1]) L = L + 1;
                    while(L < R && nums[R] == nums[R - 1]) R = R - 1;
                    //对相同的数进行过滤判断，可能存在多个结果为0的组合
                    L = L + 1;
                    R = R - 1;
                    //改变双指针
                } else if (nums[L] + nums[R] + nums[index] > 0){
                    R = R - 1;
                    //过大的情况
                } else {
                    L = L + 1;
                    //太小的情况
                }
            }
            index = index + 1;
            //改变固定值
        }
        return ret;

    }
};
```

leetcode16

[最接近的三数之和](https://leetcode.cn/problems/3sum-closest/)

排序+双指针                                                                                        

```c++
输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
```

```c++
class Solution {
public:

    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ret = 1e7;

        for (int i = 0; i < nums.size() - 2; i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int l = i + 1;
            int r = nums.size() - 1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if (abs(sum - target) < abs(ret - target)) ret = sum;
                if (sum == target) return sum;
                if (sum > target){
                    r = r - 1;
                } else { 
                    l = l + 1;
                }
            }
        } // 不同于15题，这边就不用做多重判断了
        return ret;

    }
};
```

​                 

leetcode17

[电话号码的字母组合](https://leetcode.cn/problems/letter-combinations-of-a-phone-number/)

深度优先搜索(DFS)

```c++
输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
```

```c++
class Solution {
public:
    void helper(string digits, map<int, string> hash, int index, vector<string>& res, string path){
        if(path.size() == digits.size()) {
            res.push_back(path);
            return; // 如果已经和代排除的数组一样长了，说明已经搜索到头
        }
        for (int i = 0; i < hash[digits[index] - 48].size(); i++){
            path.push_back(hash[digits[index] - 48][i]);
            helper(digits, hash, index + 1, res, path);
            path.pop_back(); //需要pop掉
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        map<int, string> hash{
            {2, "abc"},
            {3, "def"},
            {4, "ghi"},
            {5, "jkl"},
            {6, "mno"},
            {7, "pqrs"},
            {8, "tuv"},
            {9, "wxyz"},
        };
        vector<string> res;
        if (digits.size() == 0) return res;
        string path = "";
        helper(digits,hash,0,res,path);
        return res;

    }
};
```

​                        

leetcode18

[四数之和](https://leetcode.cn/problems/4sum/)

排序+双指针

```c++
输入：nums = [1,0,-1,0,-2,2], target = 0
输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
```

```c++
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        if (nums.size() < 4) return ret;
        sort(nums.begin(), nums.end()); //排序
        for (int i = 0; i < nums.size() - 3; i++){ //固定掉一个数，只要搜索到倒数第三个
            if (i > 0 && nums[i] == nums[i - 1]) continue; //重复数不在搜索
            for (int j = i + 1; j < nums.size() - 2; j++){ //再固定一个数，搜索到倒数第二个
                if (j > i + 1 && nums[j] == nums[j-1]) continue;//重复数不在搜索
                int l = j + 1;
                int r = nums.size() - 1; //设定左右指针
                while(l < r){
                     long sum = (long)nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum == target){
                        ret.push_back({nums[i],nums[j],nums[l], nums[r]});
                        while(l < r && nums[l] == nums[l + 1]) l++;
                        while(l < r && nums[r] == nums[r - 1]) r--;
                        l = l + 1;
                        r = r - 1;
                    } else if (sum > target){
                        r = r - 1;
                    } else {
                        l = l + 1; //双指针变化
                    }
                }
            }
        }
        return ret;

    }
};
```



leetcode19

[删除链表的倒数第 N 个结点](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/)

快慢指针

```cpp
输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]
```

```c++
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy->next;
        //注意虚拟节点的设置
        while(n - 1 > 0){
            second = second->next;
            n = n - 1;
        } //快慢指针写法，快指针先走n-1步
        while(second->next){
            second = second->next;
            first = first->next;
        }//快慢指针同时走，直到快指针到对尾巴
        first->next = first->next->next;
        //改变节点连接
        return dummy->next;
        //返回头结点

    }
};
```

leetcode20

[有效的括号](https://leetcode.cn/problems/valid-parentheses/)

用堆来判断括号的有效性，堆的使用

```cpp
输入：s = "()[]{}"
输出：true
```

```cpp
class Solution {
    public:
        bool isValid(string s) {
            if (s.size() % 2 != 0) return false;
            stack<char> stk;
            for(int i = 0 ; i < s.size(); i++){
                if(s[i] == '(' or s[i] == '[' or s[i] == '{'){
                    stk.push(s[i]);
                } else {
                    if (stk.empty()) return false; //堆为空，且当前为右括号
                    if ((s[i] == ')' && stk.top() == '(') || (s[i] == ']' && stk.top() == '[') || (s[i] == '}' && stk.top() == '{')){
                        stk.pop();//有效的状态
                    } else {
                        return false;
                    }
                }
            }
            return stk.empty();
    
        }
    };
```

leetcode21 

[合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists/)

```c++
输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]
```

```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 || !list2) return list1?list1:list2; //判空处理
        ListNode* res = list1->val > list2->val ? list2 : list1;
        //保存头结点，把数据保存在头结点较小的链表中
        ListNode* curr1 = res; 
        ListNode* curr2 = list1->val > list2->val ? list1:list2;
		//遍历过程的2个链表的指针
        while(curr1 && curr1->next && curr2){
            //保证curr1和curr1的下一个节点不为空
            if (curr1->next->val >= curr2->val){
                //如果curr1的下一个节点的数值较大，即curr2要插入其中
                ListNode* temp = curr1->next;
                //记录curr1的下一个节点
                curr1->next = curr2;
                //重新指向curr1->next
                curr2 = curr2->next;
               	//curr2进行移动
                curr1->next->next = temp;
                //curr1的next的next节点进行移动
                curr1 = curr1->next;
                //curr1移动
            } else {
                curr1 = curr1->next;
            }
        }
        if (curr2){
            curr1->next = curr2; //需要判断curr2是否已经结束
        }
        return res;
    }
};

//递归写法
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        } else if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};


```

leetcode22

[括号生成](https://leetcode.cn/problems/generate-parentheses/)

```c++
输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]
```

```c++
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 1){
            vector<string> ret = {"()"};
            return ret;
        }
        set<string> hash;
        vector<string> last = generateParenthesis(n - 1);
        for (int i = 0; i < last.size(); i++){
            for (int j = 0; j < last[i].size();j++){
                string temp = last[i].substr(0, j) + "()" + last[i].substr(j);
                hash.insert(temp);
            }
        }
        vector<string> ret(hash.begin(), hash.end());
        return ret;
        //核心思想在于上一轮的有效字符串的任意位置加上"()"即成为新的有效字符串
        //利用set进行去重即可
    }
}
```

leetcode24

[两两交换链表中的节点](https://leetcode.cn/problems/swap-nodes-in-pairs/)

```c++
输入：head = [1,2,3,4]
输出：[2,1,4,3]
```

```cpp
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;//判空处理
        ListNode* dummy = new ListNode(-1);
        dummy->next = head; //虚拟节点设置
        ListNode* pre = dummy;
        ListNode* curr = dummy->next; //设置先后节点

        while(curr && curr->next) {
            ListNode* temp = curr->next;
            curr->next = curr->next->next;
            pre->next = temp;
            temp->next = curr;
            pre = curr; //节点变更操作，主要在于要有prev节点的记录，便于链表进行操作
            curr = curr->next;
        }
        return dummy->next;
    }
};

//递归的官方解法
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* newHead = head->next;
        head->next = swapPairs(newHead->next);
        newHead->next = head;
        return newHead;
    }
};

```

leetcode26

[删除有序数组中的重复项](https://leetcode.cn/problems/remove-duplicates-from-sorted-array/)

```c++
输入：nums = [0,0,1,1,1,2,2,3,3,4]
输出：5, nums = [0,1,2,3,4]
解释：函数应该返回新的长度 5 ， 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4 。不需要考虑数组中超出新长度后面的元素。
```

```c++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1) return 1;
        int slow = 0;
        int fast = 0; 
        //快慢指针
        while(fast < nums.size()){
            if (nums[slow] != nums[fast]){
                nums[slow + 1] = nums[fast];
                slow = slow + 1;//slow记录当前非重复数字的位置
            }
            fast = fast + 1; //充当遍历指针
        }
        return slow + 1;

    }
};
```

leetcode27

[移除元素](https://leetcode.cn/problems/remove-element/)

```c++
输入：nums = [0,1,2,2,3,0,4,2], val = 2
输出：5, nums = [0,1,4,0,3]
解释：函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。注意这五个元素可为任意顺序。你不需要考虑数组中超出新长度后面的元素。
```

```c++
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        for (int right = 0; right < nums.size(); right++){
            if (nums[right] != val){
                nums[left] = nums[right];
                left = left + 1;
            }
        }
        return left; //和26题类似的想法，利用快慢指针，一个记录非目标值位置的数据当前位置，一个遍历数组

    }
};
```



leetcode28

[找出字符串中第一个匹配项的下标](https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/)

```c++
输入：haystack = "sadbutsad", needle = "sad"
输出：0
解释："sad" 在下标 0 和 6 处匹配。
第一个匹配项的下标是 0 ，所以返回 0 。
```

```c++
class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> index;
        int ret = 0;
        for (int i = 0; i < haystack.size(); i++){
            if (haystack[i] == needle[0]) index.push_back(i);
            //首先记录在字符串中，和目标首字母一直的位置
        }
        for (auto i: index){
            if (haystack.substr(i, needle.size()) == needle){
                ret = i;
                return ret;
                //在这些位置上进行判断是否和目标值一致
            }
        }
        return -1;

    }
};
```

leetcode29

[两数相除](https://leetcode.cn/problems/divide-two-integers/)

```c++
输入: dividend = 10, divisor = 3
输出: 3
解释: 10/3 = 3.33333.. ，向零截断后得到 3 。
```

```c++
class Solution {
public:
    bool helper(int x, int y, int z){
        int res = 0;
        for (; z != 0; z >>= 1){
            if (z & 1){
                if (res < x - y) {
                    return false;
                }
                res += y;
            }
            if (z != 1){
                if (y < x - y) return false;
                y += y;
            }
        }
        return true;
    }
    int divide(int dividend, int divisor) {
        cout << dividend << divisor << endl;
        if (dividend == INT_MIN){
            if (divisor == 1) return INT_MIN;
            if (divisor == -1) return INT_MAX;
        }
        bool tag = false;
        if(dividend > 0){
            dividend = -1 * dividend;
            tag = !tag;
        }
        if (divisor > 0){
            divisor = -1 * divisor;
            tag = !tag;
        }
        int left  = 1;
        int right = INT_MAX;
        int ret = 0;
        while(left <= right){
            int mid = left + ((right - left) >> 1);
            bool check = helper(dividend, divisor, mid);
            if (check){
                ret = mid;
                if (ret == INT_MAX) break;
                left = mid + 1;
            } else {
                right = mid -1;
            }
        }
        return tag ? -1 * ret : ret;

    }
};
```

## leecode 31

[下一个排列](https://leetcode.cn/problems/next-permutation/)

```c++
输入：nums = [1,1,5]
输出：[1,5,1]
```

```c++
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx1 = n - 2;
        while(idx1 >= 0 && nums[idx1] >= nums[idx1 + 1]){
            idx1 = idx1 - 1;
        }
        if (idx1 < 0){
            reverse(nums.begin(), nums.end());
            return;
        }
        int idx2 = n - 1;
        while(idx2 > idx1 && nums[idx2] <= nums[idx1]){
            idx2--;
        }
        int temp = nums[idx1];
        nums[idx1] = nums[idx2];
        nums[idx2] = temp;

        reverse(nums.begin() + idx1 + 1, nums.end());
        return;

    }
};
```

leetcode33

[搜索旋转排序数组](https://leetcode.cn/problems/search-in-rotated-sorted-array/)

```c++
输入：nums = [4,5,6,7,0,1,2], target = 0
输出：4
```

```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ret = -1;
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] >= nums[0]){
                if (target >= nums[0] && target < nums[mid]){ //处于有序序列中
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[nums.size() - 1]) { //处于有序序列中
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            } //变相的二分法，因为原始的数组有序，旋转之后数组在旋转点左右2侧各自有序
              //所以找到中间点后，判断是否处在有序部分，利用有序的性质进行二分
        }
        return ret;
    }
};
```

leetcode34

[在排序数组中查找元素的第一个和最后一个位置](https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/)

> 二分查找变形

```c++
输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]
```

```c++
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret{-1, -1};
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if (nums[mid] == target){
                ret[0] = mid;
                r = mid - 1;} //找到左边界
            else {
                if (nums[mid] > target) r = mid - 1;
                if (nums[mid] < target) l = mid  + 1;
            }
        }
        l = 0;
        r = nums.size() - 1;

        while(l <= r){
            int mid = l + (r - l) / 2;
            if (nums[mid] == target){
                ret[1] = mid;
                l = mid + 1; //找到右边界
            }
            else {
                if (nums[mid] > target) r = mid - 1;
                if (nums[mid] < target) l = mid  + 1;
            }
        }

        return ret;
    }
};
```

leetcode35 

[搜索插入位置](https://leetcode.cn/problems/search-insert-position/description/)

> 二分查找

```c++
输入: nums = [1,3,5,6], target = 2
输出: 1
```

```c++
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0; 
        int end = nums.size() - 1;
        while(start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] > target){
                end = mid - 1;
            }else {
                start = mid + 1;
            }
        }
        return start;
    }
};
```

leetcode36 

[有效的数独](https://leetcode.cn/problems/valid-sudoku/)

> 矩阵操作

```c++
输入：board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
输出：true
```



```c++
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][10] = {0}; //记录行信息
        int col[9][10] = {0}; //记录列信息
        int box[9][10] = {0}; //记录斜对角信息，当然也可以用3*3*9
        
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (board[i][j] == '.') continue; //空格跳过
                int currNum = board[i][j] - '0';
                if(row[i][currNum]) return false; //i行信息判断是否已经出现相同数字
                if(col[j][currNum]) return false; //j列信息判断是否已经出现相同信息
                if(box[j/3+ (i/3)*3][currNum]) return false;
                //关键点在于此次，j/3+ (i/3)*3表示第几个9*9的子矩阵
                row[i][currNum] = 1;
                col[j][currNum] = 1;
                box[j/3+ (i/3)*3][currNum] = 1; //如果不曾出现，赋值对应位置，记录表明已经出现
            }
        }
        return true;
    }
};
```

leetcode38

[外观数列](https://leetcode.cn/problems/count-and-say/)

```c++
输入：n = 4
输出："1211"
解释：
countAndSay(1) = "1"
countAndSay(2) = 读 "1" = 一 个 1 = "11"
countAndSay(3) = 读 "11" = 二 个 1 = "21"
countAndSay(4) = 读 "21" = 一 个 2 + 一 个 1 = "12" + "11" = "1211"
```



```c++
class Solution {
public:
    string getNext(string num){
        string next = "";
        int index = 0;
        while(index < num.size()){
            int count = 1;
            while(index + 1 < num.size() && num[index] == num[index + 1]){
                //重点在于此次，判断是否已经到达字符串末尾，并且判断和后面字符相等
                count = count + 1;
                index = index + 1;
            }
            next += to_string(count) + num[index];
            //此处的字符串相加操作
            index = index + 1;    
        }
        return next;
    }
    string countAndSay(int n) {
        int index = 1;
        string res = "1";
        while(index < n){
            res = getNext(res);
            index = index + 1;
        }
        return res;
    }
};
```



leetcode 39 

> 深度优先搜索+回溯+剪枝

[组合总数](https://leetcode.cn/problems/combination-sum/)

```c++
输入：candidates = [2,3,6,7], target = 7
输出：[[2,2,3],[7]]
解释：
2 和 3 可以形成一组候选，2 + 2 + 3 = 7 。注意 2 可以使用多次。
7 也是一个候选， 7 = 7 。
仅有这两种组合。
```



```c++
class Solution {
public:
    void helper(vector<int>&candidates, int target, int begin, vector<vector<int>>& res, vector<int>& path, int pathSum){
        if (pathSum == target){
            res.push_back(path);
            return; //当前路径之和等于目标值则存入结果，并且返回
        }
        for (int i = begin; i < candidates.size(); i++){
            if (pathSum + candidates[i] <= target){ //此次过滤掉大于目标值的搜索
                pathSum = pathSum + candidates[i];
                path.push_back(candidates[i]); //推入当前路径记录
                helper(candidates,target,i,res,path,pathSum);
                path.pop_back(); //记得弹出
                pathSum = pathSum - candidates[i];//记得将路径和进行还原
            }
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        int pathSum = 0;
        int begin = 0;
        helper(candidates,target,begin,res,path,pathSum);
        return res;
        //要点在于(1)搜索结束的还原 (2) 非必要搜索的过滤，降低搜索的复杂度
    }
};
```

leetcode40 

[组合总和 II](https://leetcode.cn/problems/combination-sum-ii/)

> 深度优先搜索+回溯剪枝

```c++
输入: candidates = [10,1,2,7,6,1,5], target = 8,
输出:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
```



```c++
class Solution {
public:
    void helper(vector<int>& candidates, int target, int begin, vector<int>& path, vector<vector<int>>& res, int pathSum){
        if (pathSum == target){
            res.push_back(path);
            return; //目标值记录并且返回
        }
        set<int> layNum;
        //每一层的搜索进行去重
        for (int i = begin; i < candidates.size(); i++){
            if ((pathSum + candidates[i] <= target) && layNum.find(candidates[i]) == layNum.end()){
                //剪枝，包含是否操作目标值和是否在当前层搜索过的剪枝
                layNum.insert(candidates[i]); //层信息的更新
                pathSum = pathSum + candidates[i];
                path.push_back(candidates[i]);
                helper(candidates,target, i + 1,path,res,pathSum);
                pathSum = pathSum - candidates[i];
                path.pop_back(); //路径的恢复
            }
        }
        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); //排序
        vector<vector<int>> res;
        vector<int> path;
        int pathSum = 0;
        helper(candidates,target,0,path,res,pathSum);
        return res;

    }
};
```

leetcode 43 

[字符串相乘](https://leetcode.cn/problems/multiply-strings/)

```c++
输入: num1 = "123", num2 = "456"
输出: "56088"
```

```c++
class Solution {
public:
    string add(string num1, string num2){
        string ret = "";
        int length = max(num1.size(), num2.size());
        int add = 0;
        for (int i = 0; i < length; i++){
            int first,second;
            first = (i >= num1.size()) ? 0 : num1[i] - '0';
            second = (i >= num2.size()) ? 0 : num2[i] - '0';
            int sum = first + second + add;
            add = (sum > 9) ? 1: 0;
            sum = (add == 1) ? sum % 10 : sum;
            ret.push_back('0' + sum);
        }
        if (add) ret.push_back('1');
        return ret;
        // 定义字符串的加法 
    }
    string helper(string str1, char curr, int tag){
        string ret = "";
        int add = 0;
        int num = curr - '0';
        for (int i = str1.size() - 1; i >= 0; i--){
            int sum = (str1[i] - '0') * num + add;
            add = (sum > 9) ? sum / 10 : 0;
            sum = (add >= 1) ? sum % 10: sum;
            ret.push_back(sum + '0');
        }
        if (add) ret.push_back(add + '0');
        
        ret.insert(0, tag, '0');
        return ret;
        //定义字符串的乘法 
    }
    string multiply(string num1, string num2) {
        if(num1 == "0" or num2 == "0")  return "0";
        vector<string>vec;
        string ret = "0";
        int tag = 0;
        for (int i = num2.size() - 1; i >= 0; i--){
            string num = helper(num1, num2[i], tag);
            vec.push_back(num);
            tag = tag + 1;
        }
        for (int i = 0; i < vec.size(); i++){
            ret = add(ret, vec[i]);
        }
        reverse(ret.begin(), ret.end());
        //将每个单字符的结果记录下来，而后进行相加
        return ret;
    }
};
```

leetcode45 

[跳跃游戏 II](https://leetcode.cn/problems/jump-game-ii/)

> 动态规划/贪心

```c++
输入: nums = [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
```



```c++
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int maxpos = 0;
        int end = 0;
        int step = 0;
        for (int i = 0; i < n - 1; i++){
            if (i <= maxpos){
                maxpos = max(maxpos, i + nums[i]);
            }
            if (i == end){
                end = maxpos;
                step = step + 1;
            }
        }
        return step;
        //维护一个当前能够到达的最远边界
        //如果遍历已经到达边界，更新边界值
    }
};
```

leetcode46 

[全排列](https://leetcode.cn/problems/permutations/description/)

> 深度优先搜索

```c++
输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```

```c++
class Solution {
public:
    void dfs(vector<int>& nums, vector<int>& path, vector<vector<int>>& res, vector<int>& flag){
        if(path.size() == nums.size()){
            res.emplace_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++){
            if(flag[i]) continue;
            path.push_back(nums[i]);
            flag[i] = 1;
            dfs(nums,path,res,flag);
            path.pop_back();
            flag[i] = 0; //用flag数组来记录数据是否被访问过，和之前的层去重有相同的作用
            			//因为已经排序过了，无须再进行排序
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        vector<int> flag(nums.size(),0);
        dfs(nums, path, res, flag);
        return res;
    }
};
```

leetcode47 

[全排列 II](https://leetcode.cn/problems/permutations-ii/)

```c++
输入：nums = [1,1,2]
输出：
[[1,1,2],
 [1,2,1],
 [2,1,1]]
```

```c++
class Solution {
public:
    void dfs(vector<int>& nums, vector<int>& path, vector<vector<int>>& res, vector<int>& flag){
        if(path.size() == nums.size()){
            res.emplace_back(path);
            return;
        }
        for (int i = 0 ; i < nums.size(); i++){
            if(flag[i] == 1|| (i > 0 && nums[i] == nums[i - 1] && flag[i - 1])) continue;
            //除去判断是否已经被使用过以外，并且需要判断和前一个值是否相同
            path.push_back(nums[i]);
            flag[i] = 1;
            dfs(nums,path,res,flag);
            flag[i] = 0;
            path.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        vector<int> flag(nums.size(), 0);
        sort(nums.begin(), nums.end()); //先进行排序
        dfs(nums,path,res,flag);
        return res;
    }
```

leetcode 48 

[旋转图像](https://leetcode.cn/problems/rotate-image/)

```c++
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[[7,4,1],[8,5,2],[9,6,3]]
```

```c++
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++){
            for (int j = 0; j < (n + 1)/ 2; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = temp;
            }
        } 
 		// 通过分析旋转的规律，可以知道(i,j)->(j, n-i-1)
        return;
    }
};
```

leetcode49 

[字母异位词分组](https://leetcode.cn/problems/group-anagrams/)

```c++
输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
```

```c++
class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for (auto str: strs){
            string key = str;
            sort(key.begin(), key.end());
            //对每个单词都进行了排序，这样具有相同字母数量排序不同的字符串会变成一样
            hash[key].emplace_back(str);
            //输入到字典中
        }
        vector<vector<string>> ans;
        for (auto it: hash){
            ans.push_back(it.second);
            //将字典中的结果数组进行保存后返回
        }
        return ans;
    }
};
```

leetcode50

> 位运算相关题目

[Pow(x,n)](https://leetcode.cn/problems/powx-n/)

```c++
输入：x = 2.00000, n = -2
输出：0.25000
解释：2-2 = 1/22 = 1/4 = 0.25
```

```c++
class Solution {
public:
    double myPow(double x, int n) {
        double ret = 1;
        bool tag = false;
        long long n1 = n;
        if (n1 < 0){
            n1 = (long)(-1 * n1);
            tag = true;
        }
        while(n1 > 0){
            if (n1 & 1){
                ret = ret * x;
            }
            x *= x;
            n1 >>= 1;
        }
        if (tag){
            ret = 1 / ret;
        }
        return ret;
    }
};
```

leetcode53

[最大子数组和](https://leetcode.cn/problems/maximum-subarray/)

> 动态规划，定义为以num[i]为结尾的最大子数组和作为寻优目标。

```c++
输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
```



```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) { 
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int ret = nums[0]; 
        for (int i = 1; i < nums.size(); i++){
            dp[i] = max(dp[i - 1] + nums[i], nums[i]); //必须取num[i]
            //只有2种情况，一种前面大于0，一种前面小于0 
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};
```

leetcode 54 

[螺旋矩阵](https://leetcode.cn/problems/spiral-matrix/)

> 矩阵遍历

```c++
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
```

```c++
class Solution {
public:
void helper(vector<vector<int>>& matrix, int x1, int y1, int x2, int y2, vector<int>& path){
        if (x1 > x2 || y1 > y2) return;

        if (x1 == x2 && y1 != y2){
            for (int i = y1; i <= y2; i++){
            path.push_back(matrix[x1][i]);
            }
        } 
        else if (x1 != x2 && y1 == y2){
            for (int i = x1; i <= x2; i++){
                path.push_back(matrix[i][y1]);
                }   
        } 
        else if (x1 == x1 && y1 == y2){
            path.push_back(matrix[x1][y1]);
        } else {
            for (int i = y1; i <= y2; i++){
                path.push_back(matrix[x1][i]);
            }
            for (int i = x1 + 1; i <= x2; i++){
                path.push_back(matrix[i][y2]);
            }
            for (int i = y2 - 1; i >= y1; i--){
                path.push_back(matrix[x2][i]);
            }
            for (int i = x2 - 1; i > x1; i--){
                path.push_back(matrix[i][y1]);
            }
        }
        helper(matrix, x1 + 1,y1 + 1,x2 - 1, y2 - 1, path);
        return;
    };
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>path;
        helper(matrix,0,0,matrix.size() - 1, matrix[0].size() - 1,path);
        return path;
    }
};
```

leetcode 55

[跳跃游戏](https://leetcode.cn/problems/jump-game/)

> 动态规划，参考跳跃游戏II的做法

```c++
输入：nums = [2,3,1,1,4]
输出：true
解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。
```

```c++
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int rightmost = 0;
        for (int i = 0; i < nums.size(); i++){
            if (i <= rightmost){
                rightmost = max(rightmost, i + nums[i]);
            }
            if (rightmost >= nums.size() - 1) return true;
        }
        return false;

    }
};
```

leetcode 56

[合并区间](https://leetcode.cn/problems/merge-intervals/)

> 用sort排序后，判断头尾相连的可能性

```c++
输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
```



```c++
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return {};
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        vector<int> curr = intervals[0];
        for (int i = 1; i < intervals.size(); i++){
            if (intervals[i][0] <= curr[1]){
                if (intervals[i][1] >= curr[1]) curr[1] = intervals[i][1];
            } else {
                ans.push_back(curr);
                curr = intervals[i];
            }
        }
        ans.push_back(curr);
        return ans;

    }
};
```

## leetcode57

[插入区间](https://leetcode.cn/problems/insert-interval/solutions/)

```c++
输入：intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
输出：[[1,2],[3,10],[12,16]]
解释：这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
```

```c++
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left = newInterval[0];
        int right = newInterval[1];
        vector<vector<int>> ans;
        bool place = false;

        for (auto interval: intervals){
            if (interval[0] > right){
                if (!place){
                    ans.push_back({left, right});
                    place = true;
                }
                ans.push_back(interval);
            } else if (interval[1] < left){
                ans.push_back(interval);
            } else {
                left = min(left, interval[0]); 
                right = max(right, interval[1]);
            }
        }
        if (!place){
            ans.push_back({left, right});
        }
        return ans;

    }
};
```



## leetcode58

[最后一个单词长度](https://leetcode.cn/problems/length-of-last-word/description/)

```c++
输入：s = "   fly me   to   the moon  "
输出：4
解释：最后一个单词是“moon”，长度为4。
```



```c++
class Solution {
public:
    int lengthOfLastWord(string s) {
            int end = s.size() - 1;
            int start = 0;
            while(s[end] == ' '){
                end = end - 1; 
            }
            start = end;
            while(start >= 0){
                if (s[start] != ' ') 
                {
                start = start - 1;
                }
                else{
                        break;
                }
            }
            return end - start;

    }
};
```

## leetcode59 

[螺旋矩阵 II](https://leetcode.cn/problems/spiral-matrix-ii/)

> 矩阵遍历操作

```c++
输入：n = 3
输出：[[1,2,3],[8,9,4],[7,6,5]]
```

```c++
class Solution {
public:
void helper(vector<vector<int>>& matrix, int x1, int y1, int x2, int y2, int& curr){
        if (x1 > x2 || y1 > y2) return;
        
        if (x1 == x1 && y1 == y2){
            matrix[x1][y1] = curr;
            return;
        } else {
            for (int i = y1; i <= y2; i++){
                matrix[x1][i] = curr;
                curr = curr + 1;
            }
            for (int i = x1 + 1; i <= x2; i++){
                matrix[i][y2] = curr;
                curr = curr + 1;
            }
            for (int i = y2 - 1; i >= y1; i--){
                matrix[x2][i] = curr;
                curr =curr + 1;
            }
            for (int i = x2 - 1; i > x1; i--){
                matrix[i][y1] = curr;
                curr = curr + 1;
            }
        }
        helper(matrix,x1+1,y1+1,x2-1,y2-1,curr);
        return;

    };
    vector<vector<int>> generateMatrix(int n) {
        vector<int> row(n,0);
        vector<vector<int>> ret(n, row);
        int curr = 1;
        helper(ret,0,0,n-1,n-1,curr);
        return ret;
    }
};
```



## leetcode61 

[旋转链表](https://leetcode.cn/problems/rotate-list/)

> 链表操作

```c++
输入：head = [1,2,3,4,5], k = 2
输出：[4,5,1,2,3]
```



```c++
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head||!head->next) return head;
        ListNode* curr = head;
        int length = 1;
        while(curr->next){
            length += 1;
            curr = curr->next;
        } // 计算链表长度，为了求余k
        curr->next = head; //链表末尾连接头部
        k = length -  k % length;
        curr = head;
        while(k > 1){
            curr = curr->next;
            k = k - 1;
        }  //找到位置断开
        ListNode* res = curr->next;
        curr->next = nullptr;
        return res;

    }
};
```

## LeetCode62 

[不同路径](https://leetcode.cn/problems/unique-paths/)

> 动态规划

```c++
输入：m = 3, n = 2
输出：3
解释：
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右
3. 向下 -> 向右 -> 向下
```



```c++
class Solution {
public:
    int uniquePaths(int m, int n) {
        int matrix[m][n];
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                matrix[i][j] = 1;
            }
        } // 这步其实只要把第一行和第一列的数据设置为1，方便后面的计算
        
        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){
                matrix[i][j] = matrix[i-1][j] + matrix[i][j-1];
                //动态规划，即到达当前点的路径数量 = 到达当前点的上方的路径数量 + 到达当前点左侧的路径的数量
            }
        }
        return matrix[m-1][n-1];
    }
```

## leetcode63 

[不同路径 II](https://leetcode.cn/problems/unique-paths-ii/)

> 和62题类似的动态规划

```c++
输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
输出：2
解释：3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 2 条不同的路径：
1. 向右 -> 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右 -> 向右
```



```c++
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();

        vector<vector<int>> matrix(row, vector<int>(col, 0));
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(obstacleGrid[i][j] == 1){ matrix[i][j] = 0; continue; }
                // 判断是不是被堵住了
                if(i + j == 0) {matrix[0][0] = 1; continue;}
                //设定初始值
                int left = (i - 1 >= 0 ? matrix[i - 1][j] : 0);
                int up = (j - 1 >= 0 ? matrix[i][j - 1] : 0);
                //计算左侧和上方的路径数，记得判断边界值
                matrix[i][j] = left + up;
            }
        }
        return matrix[row - 1][col - 1];
    }
};
```



## LeetCode64

[最小路径和](https://leetcode.cn/problems/minimum-path-sum/)

> 动态规划 + 贪心

```c++
输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
输出：7
解释：因为路径 1→3→1→1→1 的总和最小。
```

```c++
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for(int i = 1; i < grid.size(); i++){
            grid[i][0] = grid[i][0] + grid[i - 1][0];
        }
        for(int j = 1; j < grid[0].size(); j++){
            grid[0][j] = grid[0][j] + grid[0][j - 1];
        } // 上述分别计算了第一行和第一列的最小值，第一行和第一列只存在一个路径
        for (int i = 1; i < grid.size(); i++){
            for(int j = 1; j < grid[0].size(); j++){
                grid[i][j] = min(grid[i-1][j], grid[i][j - 1]) + grid[i][j];
            }
        } //贪心，到达当前点的方法只有从上方和左侧，计算其最小值即可
        int row = grid.size() - 1;
        int col = grid[0].size() - 1;
        return grid[row][col];
    }
};
```



## Leetcode66

[ 加一](https://leetcode.cn/problems/plus-one/)

```c++
输入：digits = [1,2,3]
输出：[1,2,4]
解释：输入数组表示数字 123。
```

```c++
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--){
            if (digits[i] == 9){
                digits[i] = 0;
                // 从末尾开始遍历，逢9变0
            }else {
                digits[i] = digits[i] + 1;
                return digits;
                //非9加1返回
            }
        }
        digits.emplace(digits.begin(), 1);
        //上述遍历过程未返回，说明全是9，需要补进位
        return digits;
    }
};
```



## leetcode67

[二进制求和](https://leetcode.cn/problems/add-binary/)

```c++
输入：a = "1010", b = "1011"
输出："10101"
```

```c++
class Solution {
public:
    string addBinary(string a, string b) {
        int l_a = a.size() - 1;
        int l_b = b.size() - 1;
        int add = 0;
        string res = "";
        while(l_a >= 0 || l_b >= 0){
            int a1 = l_a >= 0 ? a[l_a] : '0';
            int b1 = l_b >= 0 ? b[l_b] : '0';

            int temp = a1 + b1 - 96 + add;
            add = temp >= 2 ? 1 : 0;
            if (temp == 3){ res = "1" + res;}
            if (temp == 2){ res = "0" + res;}
            if (temp == 1){ res = "1" + res;}
            if (temp == 0){ res = "0" + res;}
            l_a = l_a - 1;
            l_b = l_b - 1;
        }
        if (add) {
            return "1" + res;
        }
        return res;

    }
};
```

