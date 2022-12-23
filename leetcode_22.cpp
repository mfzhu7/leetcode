class Solution {
public:
    void dfs(int n, int left, int right, string path, vector<string>& ret){
        if (left > n or right > n or right > left) return;
        if (right == n){
            ret.push_back(path);
            return;
        }
        path.push_back('(');
        dfs(n, left + 1, right, path, ret);
        path.pop_back();
        path.push_back(')');
        dfs(n, left, right + 1, path, ret);
        return;
    }
    vector<string> generateParenthesis(int n) {
        string path;
        vector<string> ret; 
        dfs(n, 0, 0, path, ret);
        return ret;
    }
};

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
    }
};