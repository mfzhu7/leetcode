class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int i = 0;
        int j = 0;
        while(i < row && j < col){
            if (matrix[i][j] == target) return true;
            if (i == row - 1 && j == col - 1) return false;
            if (i == row - 1 || j == col - 1){
                if (i == row - 1){
                    j = j + 1;
                } else {
                    i = i + 1;
                }
            } else {
                if (matrix[i][j + 1] > target) i = i + 1;
                else if (matrix[i + 1][j] > target) j = j + 1;
                else if (target - matrix[i][j + 1] > target - matrix[i + 1][j]){
                    i = i + 1;
                } else if (target - matrix[i][j + 1] <=  target - matrix[i + 1][j]) {
                    j = j + 1;
                }
            }

        }
        return false;

    }
};


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int i = 0;
        int j = col - 1;
        while(i < row && j >= 0){
            if (matrix[i][j] == target) return true;
            if (matrix[i][j] > target){
                j = j - 1;
            } else {
                i = i + 1;
            }
        }
        return false;

    }
};

class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int start = 0;
        int end = matrix.size() * matrix[0].size() - 1;

        while(start <= end){
            int mid = start + (end - start) / 2;
            int i = mid / col;
            int j = mid % col;
            if (matrix[i][j] == target) return true;
            if (matrix[i][j] > target){
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return false;

    }
};