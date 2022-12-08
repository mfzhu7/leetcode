class Solution {
public:
    void helper(int nums, vector<int>& lastRow){
        if (nums == 1) return;
        for (int i = 0; i < lastRow.size() - 1; i++){
            lastRow[i] = lastRow[i] + lastRow[i + 1];
        }
        lastRow.emplace(lastRow.begin(), 1);
        helper(nums - 1, lastRow);
        return;

    }
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0){
            vector<int> res = {1};
            return res;
        }
        if (rowIndex == 1){
            vector<int> res = {1,1};
            return res;
        }
        vector<int> res = {1,1};
        helper(rowIndex, res);
        return res;
    }
};