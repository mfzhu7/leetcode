# LeetCode-字符串篇

[toc]



## LeetCode125 

[验证回文串](https://leetcode.cn/problems/valid-palindrome/)

> 字符串反转之后和原字符串一致，即为回文字符串



```c++
输入: s = "A man, a plan, a canal: Panama"
输出：true
解释："amanaplanacanalpanama" 是回文串。
```



```c++
class Solution {
public:
    bool isPalindrome(string s) {
        string res = "";
        for (auto i:s){
            if(isalnum(i)){
                res += tolower(i);
            }
        }
        string old = res;
        reverse(res.begin(), res.end());
        return old == res;
    }
};
```



## LeetCode131

[分割回文串](https://leetcode.cn/problems/palindrome-partitioning/)

> 字符串+深度优先搜索；注意辅助判断函数的实现。

```c++
输入：s = "aab"
输出：[["a","a","b"],["aa","b"]]
```



```c++
class Solution {
public:
    bool isPalindrome(string s){
        string r_s = s;
        reverse(r_s.begin(), r_s.end());
        return s == r_s;
    }
    void helper(string s, vector<string>& path, int index, vector<vector<string>>& ret){
        if (index >= s.size()){
            ret.push_back(path);
            return;
        } 
        for (int i = 1; i <= s.size() - index; i++){
            if(isPalindrome(s.substr(index,i))){
                path.push_back(s.substr(index,i));
                helper(s,path,index + i, ret);
                path.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ret;
        vector<string> path;
        helper(s,path,0,ret);
        return ret;
    }
};
```



## LeetCode150 

[逆波兰表达式求值](https://leetcode.cn/problems/evaluate-reverse-polish-notation/)

> 字符串求值+堆栈



```c++
输入：tokens = ["2","1","+","3","*"]
输出：9
解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
```



```c++
class Solution {
public:
    bool isNumber(string s){
        return !(s == "+" || s == "-" || s == "*"  || s == "/" );
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for (int i = 0; i < tokens.size(); i++){
            string& token = tokens[i];
            if (isNumber(token)){
                stk.push(stoi(token));
            } else {
                int num2 = stk.top();
                stk.pop();
                int num1 = stk.top();
                stk.pop();
                switch(token[0]){
                    case '+':
                        stk.push(num1 + num2);
                        break;
                    case '-':
                        stk.push(num1 - num2);
                        break;
                    case '*':
                        stk.push(num1 * num2);
                        break;
                    case '/':
                        stk.push(num1 / num2);
                        break;
                }
            }
        }
        return stk.top();

    }
};
```



## LeetCode151

> 字符串操作

```c++
输入：s = "the sky is blue"
输出："blue is sky the"
```



```c++
class Solution {
public:
    string reverseWords(string s) {
        stack<string> stk;
        string temp, res;
         istringstream ss(s);  

         while(ss >> temp){
             stk.push(temp);
             stk.push(" "); //主要在于用stream对字符串进行空格切割
         }
         if (!stk.empty()) stk.pop(); //将栈顶空元素弹出

         while(!stk.empty()){
             res += stk.top();
             stk.pop(); //进行连接
         }
         return res;

    }
};
```



## LeetCode165

[比较版本号](https://leetcode.cn/problems/compare-version-numbers/)

> 字符串切割



```c++
输入：version1 = "1.01", version2 = "1.001"
输出：0
解释：忽略前导零，"01" 和 "001" 都表示相同的整数 "1"
```



```c++
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1;
        vector<int> v2;
        stringstream  ss;
        string s;
        ss << version1;
        while(getline(ss, s, '.')){
            v1.push_back(stoi(s));
        }
        ss.clear();

        ss << version2;
        while(getline(ss, s, '.')){
            v2.push_back(stoi(s));
        }
        //用stringstream来进行固定分割
        while(v1.size() < v2.size()) v1.push_back(0);
        while(v2.size() < v1.size()) v2.push_back(0);
		//先判断长短
        for (int i = 0; i < v1.size(); i++){
            if (v1[i] > v2[i]) return 1;
            else if (v1[i] < v2[i]) return -1;
        }//判断版本号
        return 0;


    }
};
```



## LeetCode168

[ Excel表列名称](https://leetcode.cn/problems/excel-sheet-column-title/)

> 字符串操作

```c++
输入：columnNumber = 28
输出："AB"
```



```c++
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";
        while(columnNumber > 0){
            --columnNumber; //因为从1开始，所以需要减一操作
            char ans = columnNumber % 26 + 'A';
            res = ans + res; //字符串+字符操作
            columnNumber = columnNumber / 26; 
        }
        return res;

    }
};
```



## LeetCode171

[Excel 表列序号](https://leetcode.cn/problems/excel-sheet-column-number/)

```c++
输入: columnTitle = "AB"
输出: 28
```

```c++
class Solution {
public:
    int titleToNumber(string columnTitle) {
        long  add = 1;
        int res = 0;
        int index = columnTitle.size() - 1;
        while(index >= 0){
            int tmp = columnTitle[index] - 64;
            res = res + tmp * add;
            add = add * 26;
            index = index - 1;
        }
        return res;

    }
};
```



## LeetCode187(其他方法待研究)

[重复的DNA序列](https://leetcode.cn/problems/repeated-dna-sequences/)

> 字符串+哈希表

```c++
输入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
输出：["AAAAACCCCC","CCCCCAAAAA"]
```

```c++
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> hash;
        int length = s.size();
        vector<string> ret;

        for (int i = 0; i <= length - 10; i++){
            hash[s.substr(i, 10)]++;
        }
        for (auto it: hash){
            if (it.second >= 2){
                ret.push_back(it.first);
            }
        }
        return ret;

    }
};
```



## LeetCode205

[同构字符串](https://leetcode.cn/problems/isomorphic-strings/)

> 用数组存储映射关系

```c++
输入：s = "egg", t = "add"
输出：true
```



```c++
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> vec1(128,0);
        vector<int> vec2(128,0);

        for (int i = 0; i < s.size(); i++){
            if (vec1[s[i]] == 0 && vec2[t[i]] == 0){
                vec1[s[i]] = t[i];
                vec2[t[i]] = s[i];
            }
            else {
                if (vec1[s[i]] != t[i] || vec2[t[i]] != s[i]) return false;
            }
        }
        return true;

    }
};
```



## LeetCode242

[有效的字母异位词](https://leetcode.cn/problems/valid-anagram/)

```c++
输入: s = "anagram", t = "nagaram"
输出: true
```



```c++
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int vec1[26] = {};
        int vec2[26] = {};

        for (int i = 0; i < s.size(); i++){
            vec1[s[i] - 'a'] += 1;
        }
        for (int i = 0; i < t.size(); i++){
            vec2[t[i] - 'a'] += 1;
        }

        for (int i = 0; i < 26; i++){
            if (vec1[i] != vec2[i]) return false;
        }
        return true;
    }
};
```



## LeetCode290

[单词规律](https://leetcode.cn/problems/word-pattern/)

```c++
输入:pattern = "abba", s = "dog cat cat fish"
输出: false
```

```c++
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> vec;
        stringstream ss;
        string str;
        ss << s;
        unordered_map<char, string> hash1;
        unordered_map<string, char> hash2;

        while(getline(ss, str, ' ')){
            vec.push_back(str);
        }
        if (pattern.size() != vec.size()) return false;
        for (int i = 0; i < vec.size(); i++){
            if (hash1.find(pattern[i]) == hash1.end()){
                if (hash2.find(vec[i]) != hash2.end()) return false;
                hash1[pattern[i]] = vec[i];
                hash2[vec[i]] = pattern[i];
            } else {
                if (hash1[pattern[i]] != vec[i]) return false;
            }
        }
        return true;
    }
};
```



## LeetCode344

[反转字符串](https://leetcode.cn/problems/reverse-string/)

```c++
输入：s = ["h","e","l","l","o"]
输出：["o","l","l","e","h"]
```

```c++
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        while(left < right){
            char c = s[left];
            s[left] = s[right];
            s[right] = c;
            left++;
            right--;
        }
        return;

    }
};
```



## LeetCode389

[ 找不同](https://leetcode.cn/problems/find-the-difference/)

```c++
输入：s = "abcd", t = "abcde"
输出："e"
解释：'e' 是那个被添加的字母。
```

```c++
class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> hash1(26, 0);
        vector<int> hash2(26, 0);

        for (int i = 0; i < s.size(); i++){
            hash1[s[i] - 'a'] += 1;
            hash2[t[i] - 'a'] += 1;
        }
        hash2[t.back() - 'a'] += 1;

        char ans = 'a';
        for (int i = 0; i < 26; i++){
            if(hash1[i] != hash2[i]){
                ans += i;
                break;
            }
        }
        return ans;

    }
};
```



## LeetCode415

[字符串相加](https://leetcode.cn/problems/add-strings/)

```c++
输入：num1 = "11", num2 = "123"
输出："134"
```

```c++
class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int id1 = 0;
        int id2 = 0;
        int add = 0;
        string ret = "";
        while(id1 < num1.size() || id2 < num2.size()){
            int n1 = (id1 >= num1.size()) ? 0 : num1[id1] - '0';
            int n2 = (id2 >= num2.size()) ? 0 : num2[id2] - '0';
            int ans = (n1 + n2 + add);
            add = (ans > 9) ? 1 : 0;
            ans = ans % 10;
            ret.push_back(ans + '0');
            id1 = id1 + 1;
            id2 = id2 + 1;
        }
        if (add) ret.push_back('1');
        reverse(ret.begin(), ret.end());
        return ret;


    }
};
```



## LeetCode520

[ 检测大写字母](https://leetcode.cn/problems/detect-capital/)

```c++
输入：word = "USA"
输出：true
```

```c++
class Solution {
public:
    bool detectCapitalUse(string word) {
        bool ans = true;
        int b_cnt = 0;
        int l_cnt = 0;
        int place = 0;

        for (int i = 0;i < word.size(); i++){
            if(word[i] - 'a' >= 0 && word[i]  - 'a' <= 25){
                l_cnt++;
                
            } else {
                b_cnt++;
                place = i;
            }
        }
        if(b_cnt == word.size()) return true;
        if (l_cnt == word.size()) return true;
        if (b_cnt >= 2) return false;
        if (place != 0) return false;
        return ans;
    }
};
```

