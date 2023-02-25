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







