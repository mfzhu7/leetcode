class Solution {
public:
    void helper(string s, int index, int& ret, map<string, char> hash){
        if (index >= s.size()){
            ret = ret + 1;
            return;
        }
        if (hash.find(s.substr(index,1)) != hash.end()){
            helper(s, index + 1, ret, hash);
        }
        if (index < s.size() - 1 && hash.find(s.substr(index, 2)) != hash.end()){
            helper(s,index + 2, ret, hash);
        }
        return;
    }
    int numDecodings(string s) {
        map<string, char> hash;
        int num = 1;
        for (char i = 'A'; i <= 'Z'; i++){
            hash[to_string(num)] = i;
            num = num + 1;
        }
        int ret = 0;
        helper(s, 0, ret, hash);
        return ret;
    }
};