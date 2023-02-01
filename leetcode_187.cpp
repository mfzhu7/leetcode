class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> hash;
        int length = s.size();
        vector<string> ret;

        for (int i = 0; i <= length - 10; i++){
            hash[s.substr(i, 10)]++;
        }
        for (auto it: hash){
            if (it.second >= 2){
                ret.push_back(it.first);
            }
        }
        return ret;

    }
};