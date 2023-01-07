class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss;
        stack<string> stk;
        string str;
        ss << path;
        while(getline(ss, str, '/')){
            if (str == ".."){
                if (!stk.empty()) stk.pop();
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