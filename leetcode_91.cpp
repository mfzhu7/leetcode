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

class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        map<string, char> hash;
        int num = 1;
        for (char i = 'A'; i <= 'Z'; i++){
            hash[to_string(num)] = i;
            num = num + 1;
        }
        vector<int> vec(s.size(), 0);
        if(s[0] != '0') vec[0] = 1;
        for (int i = 1; i < vec.size(); i++){
            if (hash.find(s.substr(i,1)) != hash.end()){
                if(hash.find(s.substr(i - 1, 2)) != hash.end()){
                    if(i - 2 >= 0){
                        vec[i] = vec[i - 1] + vec[i - 2];
                    } else{
                        vec[i] = vec[i - 1] + 1;
                    } 
                } else {
                    vec[i] = vec[i - 1];
                }
            }
            else{
                if (hash.find(s.substr(i - 1, 2)) != hash.end()){
                    if (i - 2 >= 0){
                        vec[i] = vec[i - 2];
                    } else {
                        vec[i] = 1;
                    }
                } else {
                    return 0;
                }
            }
        }
        return vec[vec.size() - 1];
    }
};



class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> ret(n + 1, 0);
        ret[0] = 1;
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