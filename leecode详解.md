## Leetcode详解

[toc]



## LeetCode1

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





##  LeetCode3  



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



## LeetCode5

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

## LeetCode6 

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

## LeetCode7 



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

## LeetCode8



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



## LeetCode9



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

## LeetCode11

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

## LeetCode12



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



## LeetCode13



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



## LeetCode14



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

## LeetCode15

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

## LeetCode16

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


​                        

## LeetCode18

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





## LeetCode20

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



## LeetCode22

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



## LeetCode26

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

## LeetCode27

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



## LeetCode28

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

## LeetCode29

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

## LeetCode 31

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

## LeetCode33

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

## LeetCode34

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

## LeetCode35 

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

## LeetCode38

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





## LeetCode43 

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







## LeetCode49 

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

## LeetCode50

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





## LeetCode56

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

## LeetCode57

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



## LeetCode58

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







## LeetCode66

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



## LeetCode67

[二进制求和](https://leetcode.cn/problems/add-binary/)

> 字符串加法模拟

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



## LeetCode69 

[ x 的平方根](https://leetcode.cn/problems/sqrtx/)

> 二分法找到平方根

```c++
输入：x = 8
输出：2
解释：8 的算术平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。
```

```c++
class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int r = x ;
        int ans = -1;
        while(l <= r){
            long long mid = l + (r - l) / 2 ;
            if (mid * mid <= x){
                l = mid + 1;
                ans = mid;
            } else {
                 r = mid - 1;
            }
        }
        return ans ;
    }
};
```



## LeetCode71

[简化路径](https://leetcode.cn/problems/simplify-path/)

> 堆栈+字符串分割

```c++
输入：path = "/a/./b/../../c/"
输出："/c"
```



```c++
class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss;
        stack<string> stk;
        string str;
        ss << path;
        while(getline(ss, str, '/')){ //重点在于通过getline和stringstream函数对字符串按照/进行分割
            if (str == ".."){
                if (!stk.empty()) stk.pop(); //此处要判断栈内此时是否为空
            } else if (str == "." || str == ""){
                continue;
            } else {
                stk.push(str);
            }
        }
        if (stk.empty()) return "/";
        string ans;
        while(!stk.empty()){
            ans = "/" + stk.top() + ans;
            stk.pop();
        }
        return ans;
    }
};
```



## LeetCode75



[颜色分类](https://leetcode.cn/problems/sort-colors/)




```c++
输入：nums = [2,0,2,1,1,0]
输出：[0,0,1,1,2,2]
```



```c++
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int  temp = 0;
        int  size2 = 0;
        for (int i = nums.size() - 1; i >= 0; i--){
            int place2 = - 1;
            for (int j = 0; j < i; j++){
                if (nums[j] == 2) {place2 = j;break;}
            }
            if (place2 == - 1) {size2 = i; break;}
            else {
                temp = nums[i];
                nums[i] = nums[place2];
                nums[place2] = temp; 
            }
        }
        for (int i = 0; i <= size2; i++){
            int place0 = -1;
            for (int j = i; j <= size2; j++){
                if (nums[j] == 0) {place0 = j; break;}
            }
            if (place0 == - 1) {break;}
            else {
                temp = nums[i];
                nums[i] = nums[place0];
                nums[place0] = temp;
            }
        }
        return;
    }
};
```



```




````



```



## leetcode80(待研究)

[删除有序数组中的重复项 II](https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/)

> 快慢指针

```c++
输入：nums = [0,0,1,1,1,1,2,3,3]
输出：7, nums = [0,0,1,1,2,3,3]
解释：函数应返回新长度 length = 7, 并且原数组的前五个元素被修改为 0, 0, 1, 1, 2, 3, 3 。 不需要考虑数组中超出新长度后面的元素
```



```c++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return n;
        } //如果只有2个元素的情况下，直接返回 
        int slow = 2, fast = 2;
        while (fast < n) {
            if (nums[slow - 2] != nums[fast]) {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};
```



## LeetCode81

[搜索旋转排序数组 II](https://leetcode.cn/problems/search-in-rotated-sorted-array-ii/)

> 二分法变形

```c++
输入：nums = [2,5,6,0,0,1,2], target = 0
输出：true
```



```c++
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return true;
            if (nums[mid] == nums[l]) {
                l = l + 1;
                continue;
            } //因为存在重复值，需要过滤
            if (nums[mid] > nums[0]) {
                if (target >= nums[0] && target <nums[mid]){
                    r = mid - 1;
                } else {
                    l = mid + 1; //找到部分有序的地方，对这段序列进行二分查找，确保目标值在序列内
                }
            } else {
                if (target > nums[mid] && target <= nums[nums.size() - 1]){
                    // 同理
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return false;

    }
};
```












## LeetCode88

[合并两个有序数组](https://leetcode.cn/problems/merge-sorted-array/)

> 双指针，或者逆向双指针

```c++
输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
输出：[1,2,2,3,5,6]
解释：需要合并 [1,2,3] 和 [2,5,6] 。
合并结果是 [1,2,2,3,5,6] ，其中斜体加粗标注的为 nums1 中的元素。
```

```c++
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res(m + n, 0); //将结果存储到新的表格中
        int index_m = 0;
        int index_n = 0;
        int curr;
        while(index_m < m || index_n < n){
            if (index_m == m){
                curr = nums2[index_n];
                index_n = index_n + 1;
            } else if (index_n == n){
                curr = nums1[index_m];
                index_m = index_m + 1;
            } else if (nums1[index_m] > nums2[index_n]){
                curr = nums2[index_n];
                index_n = index_n + 1;
            } else {
                curr = nums1[index_m];
                index_m = index_m + 1;
            }
            res[index_m + index_n - 1] = curr; 
            //两个指针遍历不同的数组，判断其大小
        }
        for (int i = 0; i < m + n; i++){
            nums1[i] = res[i];
        } 

    }
};
```



## LeetCode89

[格雷编码](https://leetcode.cn/problems/gray-code/)

> 位运算题目，考虑n=3的情况；在n=2的情况下，先将n=2的全部左移一位，然后反转；再将n=2的结果左移，末尾加1,二者拼接在一起，就是结果。



```c++
输入：n = 2
输出：[0,1,3,2]
解释：
[0,1,3,2] 的二进制表示是 [00,01,11,10] 。
- 00 和 01 有一位不同
- 01 和 11 有一位不同
- 11 和 10 有一位不同
- 10 和 00 有一位不同
[0,2,3,1] 也是一个有效的格雷码序列，其二进制表示是 [00,10,11,01] 。
- 00 和 10 有一位不同
- 10 和 11 有一位不同
- 11 和 01 有一位不同
- 01 和 00 有一位不同
```



```c++
class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 1) {
            vector<int> ret = {0, 1};
            return ret;
        }
        vector<int> ret = grayCode(n - 1); //递归
        vector<int> first(ret.size(), 0);
        vector<int> second(ret.size(), 0);

        for (int i = 0; i < ret.size(); i++){
            first[i] = (ret[i] << 1); //左移
            second[i] = ((ret[i] << 1) + 0x1); //左移+1
        }
        reverse(second.begin(), second.end()); 
        first.insert(first.end(),second.begin(),second.end()); //反转拼接
        return first;

    }
};
```







## LeetCode91

[解码方法](https://leetcode.cn/problems/decode-ways/)

> 动态规划；dp[i]有两种情况，如果前一位不为0，那么至少有前一位的可能性；如果前一位+当前位<=26，可以组合成新的可能，那么即dp[i-2]的可能性也都在里面。

```c++
输入：s = "226"
输出：3
解释：它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
```



```c++
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> ret(n + 1, 0);
        ret[0] = 1; //此处，注意多设置前头1的情况。
        for (int i = 1; i <= n; i++){
            if (s[i - 1] != '0'){
                ret[i] += ret[i - 1];
            }
            if (i > 1 && s[i - 2] != '0' && (s[i - 2] - '0') *10 + (s[i - 1] - '0') <= 26){
                ret[i] += ret[i - 2];
            }
        }
        return ret[n];

    }
};
```





## LeetCode133



[克隆图](https://leetcode.cn/problems/clone-graph/)

> 图+广度优先遍历

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/02/01/133_clone_graph_question.png)

```c++
输入：adjList = [[2,4],[1,3],[2,4],[1,3]]
输出：[[2,4],[1,3],[2,4],[1,3]]
解释：
图中有 4 个节点。
节点 1 的值是 1，它有两个邻居：节点 2 和 4 。
节点 2 的值是 2，它有两个邻居：节点 1 和 3 。
节点 3 的值是 3，它有两个邻居：节点 2 和 4 。
节点 4 的值是 4，它有两个邻居：节点 1 和 3 。
```



```c++
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;

        unordered_map<Node*, Node*> visited;
        visited[node] = new Node(node->val);
        queue<Node*> q;
        q.push(node);
        
        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            vector<Node*> nbr = front->neighbors;
            //利用队列进行广度优先遍历
            for (auto &n : nbr){
                if (visited.find(n) == visited.end()){
                    visited[n] = new Node(n->val);
                    q.push(n);
                }
                visited[front]->neighbors.emplace_back(visited[n]);
            }
        }
        return visited[node];
        
    }
};
```



## LeetCode172

[阶乘后的零](https://leetcode.cn/problems/factorial-trailing-zeroes/)

> 计算5的个数，即为0的个数



```c++
输入：n = 5
输出：1
解释：5! = 120 ，有一个尾随 0
```

```c++
class Solution {
public:
    int trailingZeroes(int n) {
        int ret = 0;
        for (int i = 5; i <= n; i = i + 5){
            for (int j = i; j % 5 == 0; j = j / 5){
                ret = ret + 1;
            }
        }
        return ret;
    }
};
```



## LeetCode202

[快乐数](https://leetcode.cn/problems/happy-number/)



> 直接实现过程

```c++
输入：n = 19
输出：true
解释：
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
```





```c++
class Solution {
public:
    int helper(int n){
        int ret = 0;
        while(n){
            ret = ret + (n % 10) * (n % 10) ;
            n = (n - n % 10) / 10;
        } //求出每一位的平方和
        return ret;
    }
    bool isHappy(int n) {
        unordered_set<int> hash;
        while(n){
            int temp = helper(n);
            if (temp == 1) return true;
            if (hash.find(temp) != hash.end()) return false;
            hash.insert(temp);
            n = temp;
        }
        return true;

    }
};
```



## LeetCode204(待完善)

[计数质数](https://leetcode.cn/problems/count-primes/)

> 存储已有的质数，并且在平方根内进行寻找即可



```c++
输入：n = 10
输出：4
解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
```



```c++
class Solution {
public:
    int countPrimes(int n) {
        vector<int> isPrime(n, 1);
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                ans += 1;
                if ((long long)i * i < n) {
                    for (int j = i * i; j < n; j += i) {
                        isPrime[j] = 0;
                    }
                }
            }
        }
        return ans;
    }
};

```



## LeetCode223

[矩形面积](https://leetcode.cn/problems/rectangle-area/)



```c++
输入：ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2
输出：45
```



```c++
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = (ax2 - ax1 ) * (ay2 - ay1);
        int area2 = (bx2 - bx1) * (by2 - by1);

        int overlapWidth = min(bx2, ax2) - max(bx1, ax1);
        int overlapHeight = min(by2, ay2) - max(by1, ay1);

        int overlapArea = max(overlapHeight, 0) * max(overlapWidth, 0);
        return (area1 + area2) - overlapArea;
    }
};
```



## LeetCode227

[基本计算器 II](https://leetcode.cn/problems/basic-calculator-ii/)

```c++
输入：s = "3+2*2"
输出：7
```



```c++
class Solution {
public:
    int calculate(string s) {
        vector<int> stk;
        char preSign = '+';
        int n = s.size();
        int num = 0;
        for (int i = 0; i < n; i++){
            if(isdigit(s[i])){
                num = num * 10 + int(s[i] - '0');
            }
            if(!isdigit(s[i]) && s[i] != ' ' || i == n - 1){
                switch(preSign){
                    case '+':
                        stk.push_back(num);
                        break;
                    case '-':
                        stk.push_back(-num);
                        break;
                    case '*':
                        stk.back() *= num;
                        break;
                    default:
                        stk.back() /= num;
                        break;
                }
                num = 0;
                preSign = s[i];
            }
        }

        return accumulate(stk.begin(), stk.end(), 0);
    }
};
```



## LeetCode258

[各位相加](https://leetcode.cn/problems/add-digits/)

```c++
输入: num = 38
输出: 2 
解释: 各位相加的过程为：
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2
由于 2 是一位数，所以返回 2。
```



```c++
class Solution {
public:
    int addDigits(int num) {
        
        while(num >= 10){
            int sum = 0;
            while(num){
                sum += num % 10;
                num = num / 10;
            }
            num = sum;
        }
        return num;

    }
};
```



## LeetCode263

[丑数](https://leetcode.cn/problems/ugly-number/)

```c++
输入：n = 6
输出：true
解释：6 = 2 × 3
```

```c++
class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false;
        while(n){
            if (n % 2 == 0) n = n / 2;
            else if  (n % 3 == 0){
                n = n / 3;
            } else if (n % 5 == 0){
                n = n / 5;
            } else {
                if (n == 1) return true;
                else return false;
            }
        }
        return true;

    }
};
```





## LeetCode264

[丑数 II](https://leetcode.cn/problems/ugly-number-ii/)

```c++
输入：n = 10
输出：12
解释：[1, 2, 3, 4, 5, 6, 8, 9, 10, 12] 是由前 10 个丑数组成的序列。
```

```c++
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n+1);
        dp[1] = 1;
        int p2 = 1;
        int p3 = 1;
        int p5 = 1;
        for (int i = 2;i <= n; i++){
            int num2 = dp[p2] * 2;
            int num3 = dp[p3] * 3;
            int num5 = dp[p5] * 5;
            dp[i] = min(min(num2, num3), num5);
            if(dp[i] == num2){
                p2++;
            }
            if(dp[i] == num3){
                p3++;
            }
            if(dp[i] == num5){
                p5++;
            }
        }
        return dp[n];

    }
};
```



## LeetCode278

[第一个错误的版本](https://leetcode.cn/problems/first-bad-version/)

```c++
输入：n = 5, bad = 4
输出：4
解释：
调用 isBadVersion(3) -> false 
调用 isBadVersion(5) -> true 
调用 isBadVersion(4) -> true
所以，4 是第一个错误的版本。
```

```c++
class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) right = mid - 1;
            else left = mid + 1;
        }
        return left;
        
    }
};
```



## LeetCode279

[完全平方数](https://leetcode.cn/problems/perfect-squares/)

```c++
输入：n = 12
输出：3 
解释：12 = 4 + 4 + 4
```

```c++
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1);
        dp[0] = 0;

        for (int i = 1; i <= n; i++){
            int minn = INT_MAX;
            for(int j = 1; j * j <= i; j++){
                minn = min(minn, dp[i - j*j]);
            }
            dp[i] = minn + 1;
        }
        return dp[n];

    }
};
```



## LeetCode292

[Nim 游戏](https://leetcode.cn/problems/nim-game/)

```c++
输入：n = 4
输出：false 
解释：以下是可能的结果:
1. 移除1颗石头。你的朋友移走了3块石头，包括最后一块。你的朋友赢了。
2. 移除2个石子。你的朋友移走2块石头，包括最后一块。你的朋友赢了。
3.你移走3颗石子。你的朋友移走了最后一块石头。你的朋友赢了。
在所有结果中，你的朋友是赢家。
```

```c++
class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;

    }
};
```



## LeetCode299

[猜数字游戏](https://leetcode.cn/problems/bulls-and-cows/)

```c++
输入：secret = "1807", guess = "7810"
输出："1A3B"
解释：数字和位置都对（公牛）用 '|' 连接，数字猜对位置不对（奶牛）的采用斜体加粗标识。
"1807"
  |
"7810"
```

```c++
class Solution {
public:
    string getHint(string secret, string guess) {
        map<int, int> hash;
        vector<int> pos1(10,0);
        vector<int> pos2(10,0);
        int bull = 0;
        int cow = 0;

        for (int i = 0; i < secret.size(); i++){
            pos1[secret[i] - '0']++;
            pos2[guess[i] - '0']++;
            if(secret[i] == guess[i]){
                hash[secret[i] - '0']++;
                bull++;
            }
        }
        for(int i = 0; i < 10; i++){
            if(pos1[i] == 0){
                continue;
            } else{
                cow = cow + min(pos1[i] - hash[i], pos2[i] - hash[i]);
            }
        }
        string ans = to_string(bull) + "A" + to_string(cow) + "B";
        return ans; 
    }
};
```



## LeetCode319

[灯泡开关](https://leetcode.cn/problems/bulb-switcher/)

```c++
输入：n = 3
输出：1 
解释：
初始时, 灯泡状态 [关闭, 关闭, 关闭].
第一轮后, 灯泡状态 [开启, 开启, 开启].
第二轮后, 灯泡状态 [开启, 关闭, 开启].
第三轮后, 灯泡状态 [开启, 关闭, 关闭]. 

你应该返回 1，因为只有一个灯泡还亮着。
```

```c++
class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};
```



## LeetCode357

[统计各位数字都不同的数字个数](https://leetcode.cn/problems/count-numbers-with-unique-digits/)

```c++
输入：n = 2
输出：91
解释：答案应为除去 11、22、33、44、55、66、77、88、99 外，在 0 ≤ x < 100 范围内的所有数字。 
```



```c++
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 10;

        for(int i = 2; i <= n; i++){
            dp[i] = dp[i - 1] + (dp[i - 1] - dp[i - 2]) * (10 -(i - 1));
        }
        return dp[n];

    }
};
```



## LeetCode495

[提莫攻击](https://leetcode.cn/problems/teemo-attacking/)

```c++
输入：timeSeries = [1,4], duration = 2
输出：4
解释：提莫攻击对艾希的影响如下：
- 第 1 秒，提莫攻击艾希并使其立即中毒。中毒状态会维持 2 秒，即第 1 秒和第 2 秒。
- 第 4 秒，提莫再次攻击艾希，艾希中毒状态又持续 2 秒，即第 4 秒和第 5 秒。
艾希在第 1、2、4、5 秒处于中毒状态，所以总中毒秒数是 4 。
```

```c++
using namespace std;
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.size() == 0) return 0;
        int Sum = duration;
        int current = timeSeries[0] + duration;
        for (int i = 1; i < timeSeries.size(); i++){
            if (timeSeries[i] >= current) { Sum = Sum + duration;}
            else {Sum = Sum + (timeSeries[i] - timeSeries[i-1]);}
            
            current = timeSeries[i] + duration;
        }
        return Sum;

    }
};
```



## LeetCode739

[每日温度](https://leetcode.cn/problems/daily-temperatures/)

```c++
输入: temperatures = [73,74,75,71,69,72,76,73]
输出: [1,1,4,2,1,1,0,0]
```

```c++
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ans(T.size(), 0);
        stack<int> stk;

        for (int i = 0; i < T.size(); i++){
            if (stk.empty()){
                stk.push(i);
            }else {
                while(!stk.empty() && T[stk.top()] < T[i] ){
                    ans[stk.top()] = i - stk.top();
                    stk.pop();
                }
                stk.push(i);
            }
        }
        return ans;

    }
};
```



## LeetCode784

[字母大小写全排列](https://leetcode.cn/problems/letter-case-permutation/)

```c++
输入：s = "a1b2"
输出：["a1b2", "a1B2", "A1b2", "A1B2"]
```

```c++
class Solution {
public:
    void helper(string s, vector<string>& ret, int pos){
        while(pos < s.size() && isdigit(s[pos])){
            pos++;
        }
        if (s.size() == pos){
            ret.push_back(s);
            return;
        }
        s[pos] = tolower(s[pos]);
        helper(s, ret, pos + 1);
        s[pos] = toupper(s[pos]);
        helper(s, ret, pos + 1);
        return ;
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ret;
        helper(s, ret, 0);
        return ret;
    }
};
```



## LeetCode989

[数组形式的整数加法](https://leetcode.cn/problems/add-to-array-form-of-integer/)

```c++
输入：num = [1,2,0,0], k = 34
输出：[1,2,3,4]
解释：1200 + 34 = 1234
```



```c++
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        reverse(num.begin(), num.end());
        int add = 0;
        int idx = 0;
        while(idx < num.size() || k){
            int temp = k % 10;
            int n = (idx < num.size()) ? num[idx] : 0;
            int ans = n + temp + add;
            add = (ans > 9) ? 1 : 0;
            k = (k - temp) / 10;
            if (idx < num.size()){
                num[idx] = (ans % 10);
            } else {
                num.push_back(ans % 10);
            }
            idx = idx + 1;
        }
        if (add) num.push_back(1);
        reverse(num.begin(), num.end());
        return num;
    }
};
```





## LeetCode228

[汇总区间](https://leetcode.cn/problems/summary-ranges/)

```c++
输入：nums = [0,1,2,4,5,7]
输出：["0->2","4->5","7"]
解释：区间范围是：
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"
```



```c++
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        int n = nums.size();
        int idx = 0;
        while(idx < n){
            if ((idx == n - 1) || (idx + 1 < n && nums[idx] + 1 != nums[idx + 1])){
                ret.push_back(to_string(nums[idx]));
                idx = idx + 1;
            } else {
                int start = idx;
                while(idx + 1 < n && nums[idx] + 1 == nums[idx + 1]){
                    idx = idx + 1;
                }
                ret.push_back(to_string(nums[start]) + "->" + to_string(nums[idx]));
                idx = idx + 1;
            }
        }
        return ret;

    }
};
```

