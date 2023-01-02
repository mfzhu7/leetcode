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