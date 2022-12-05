class Solution {
public:
    void  helper(vector<vector<int>>& res, int rows){
        if (rows <= 2) return;
        vector<int> tmp = {1};
        for (int i = 0; i <= res[res.size() - 1].size() - 2; i++){
            tmp.push_back(res[res.size() - 1][i] + res[res.size() - 1][i + 1]);
        }
        tmp.push_back(1);
        res.push_back(tmp);
        helper(res, rows - 1);
        return;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> v1 = {1};
        vector<int> v2 = {1,1};
        if (numRows == 1){
            res.push_back(v1);
            return res;
        }
        if (numRows == 2){
            res.push_back(v1);
            res.push_back(v2);
            return res;
        }
        
        res.push_back(v1);
        res.push_back(v2);
        helper(res, numRows);
        return res;
    }
};



class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        for (int i = 0; i < numRows; ++i){
            res[i].resize(i + 1);
            res[i][0] = res[i][i] = 1;
            for (int j = 1; j < i; ++j){
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j]; 
            }
        }
        return res;

    }
};