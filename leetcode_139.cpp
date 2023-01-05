class Solution {
public:
    bool helper(string s, unordered_map<char, vector<string>> hash, int idx){
        if (s.size() == idx) return true;
        if (hash.find(s[idx]) == hash.end()) return false;

        bool ret = false;
        vector<string> list = hash[s[idx]];
        for (int i = 0; i < list.size(); i++){
                int len = list[i].size();
                if (s.substr(idx, len) == list[i]){
                    bool ans = helper(s, hash, idx + len);
                    ret = ret || ans;
                }
            }
        return ret;
        }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<char, vector<string>> hash;
        for (int i = 0; i < wordDict.size(); i++){
            if (hash.find(wordDict[i][0]) == hash.end()){
                hash[wordDict[i][0]] = {wordDict[i]};
            } else {
                hash[wordDict[i][0]].push_back(wordDict[i]);
            }
        }
        bool ans = helper(s, hash, 0);
        return ans;
    }
};


class Solution {
public:
    bool helper(string s, unordered_set<string> hash, int idx, vector<int>& visited){
        if (idx == s.size()) return true;
        if (visited[idx] != -1) return visited[idx];

        int length = s.size();
        for (int i = 1; i <= length; i++){
            if (hash.find(s.substr(idx, i)) != hash.end() && helper(s, hash, idx + i, visited)){
                visited[idx] = 1;
                return true;
            }
        }
        visited[idx] = 0;
        return false;

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hash(wordDict.begin(), wordDict.end());
        vector<int> visited(s.size(), -1);
        return  helper(s, hash, 0, visited);
    }
};



class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>wordDictSet(wordDict.begin(), wordDict.end());

        auto dp = vector <bool> (s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};