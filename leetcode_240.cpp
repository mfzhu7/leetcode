class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int s_x = row - 1;
        int s_y = 0;
        while(s_x >= 0 && s_y < col){
            if (matrix[s_x][s_y] == target) return true;
            if (matrix[s_x][s_y] < target) s_y += 1;
            else s_x -= 1;
        }
        return false;
        
    }
};