# LeetCode-字符串篇

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

