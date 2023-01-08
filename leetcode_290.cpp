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