class Solution {
public:
void helper(vector<vector<int>>& matrix, int x1, int y1, int x2, int y2, int& curr){
        if (x1 > x2 || y1 > y2) return;
        
        if (x1 == x1 && y1 == y2){
            matrix[x1][y1] = curr;
            return;
        } else {
            for (int i = y1; i <= y2; i++){
                matrix[x1][i] = curr;
                curr = curr + 1;
            }
            for (int i = x1 + 1; i <= x2; i++){
                matrix[i][y2] = curr;
                curr = curr + 1;
            }
            for (int i = y2 - 1; i >= y1; i--){
                matrix[x2][i] = curr;
                curr =curr + 1;
            }
            for (int i = x2 - 1; i > x1; i--){
                matrix[i][y1] = curr;
                curr = curr + 1;
            }
        }
        helper(matrix,x1+1,y1+1,x2-1,y2-1,curr);
        return;

    };
    vector<vector<int>> generateMatrix(int n) {
        vector<int> row(n,0);
        vector<vector<int>> ret(n, row);
        int curr = 1;
        helper(ret,0,0,n-1,n-1,curr);
        return ret;
    }
};