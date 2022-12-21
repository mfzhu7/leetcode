class Solution {
public:
    void helper(string s, vector<string>& ret, int index, string path){
        if (s.size() == path.size()){
            ret.push_back(path);
            return;
        }

        while(index < s.size()){
            if (isdigit(s[index])){
                path.push_back(s[index]);
                index = index + 1;
            } else {
                path.push_back(tolower(s[index]));
                helper(s, ret, index + 1, path);
                path.pop_back();
                path.push_back(toupper(s[index]));
                helper(s, ret, index + 1, path);
                break;
            }
        }
        if (index == s.size()) ret.push_back(path);
        return ;
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ret;
        string path;
        helper(s, ret, 0, path);
        return ret;
    }
};


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