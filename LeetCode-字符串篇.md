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

