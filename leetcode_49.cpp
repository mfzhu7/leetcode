class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for (auto str: strs){
            string key = str;
            sort(key.begin(), key.end());
            hash[key].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto it: hash){
            ans.push_back(it.second);
        }
        return ans;

    }
};