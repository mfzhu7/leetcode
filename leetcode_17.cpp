class Solution {
public:
    void helper(string digits, map<int, string> hash, int index, vector<string>& res, string path){
        if(path.size() == digits.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < hash[digits[index] - 48].size(); i++){
            path.push_back(hash[digits[index] - 48][i]);
            helper(digits, hash, index + 1, res, path);
            path.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;
        
        map<int, string> hash{
            {2, "abc"},
            {3, "def"},
            {4, "ghi"},
            {5, "jkl"},
            {6, "mno"},
            {7, "pqrs"},
            {8, "tuv"},
            {9, "wxyz"},
        };
        string path = "";
        helper(digits,hash,0,res,path);
        return res;

    }
};