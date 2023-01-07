class Solution {
public:
    void helper(vector<vector<int>>& matrix, int left, int right){
        if (left == right) return;
        vector<int> ans;
        for (int i = left; i <= right; i++){
            ans.push_back(matrix[left][i]);
        }
        for (int i = left + 1; i <= right; i++){
            ans.push_back(matrix[i][right]);
        }
        for (int i = right - 1; i >= left; i--){
            ans.push_back(matrix[right][i]);
        }
        for (int i = right - 1; i > left; i--){
            ans.push_back(matrix[i][left]);
        }
        int n = ans.size();
        int idx = ans.size() - (right - left);

        for (int i = left; i <= right; i++){
            matrix[left][i] = ans[idx % n];
            idx = idx + 1;
        }
        for (int i = left + 1; i <= right; i++){
            matrix[i][right] = ans[idx % n];
            idx = idx + 1;
        }
        for (int i = right - 1; i >= left; i--){
            matrix[right][i] = ans[idx % n];
            idx = idx + 1;
        }
        for (int i = right - 1; i > left; i--){
            matrix[i][left] = ans[idx % n];
            idx = idx + 1;
        }
        return;
    }
    void rotate(vector<vector<int>>& matrix) {
        int left = 0;
        int right = matrix.size() - 1;
        while(left <= right){
            helper(matrix, left, right);
            left = left + 1;
            right = right - 1;
        }
        return;
    }
};


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size() - 1;
        auto  matrix_new = matrix;
        for (int i = 0; i <= n; i++){
            for (int j = 0; j <= n; j++){
                matrix_new[j][n - i] = matrix[i][j];
            }
        }
        matrix = matrix_new;
        return;

    }
};


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++){
            for (int j = 0; j < (n + 1)/ 2; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = temp;
            }
        }
        return;

    }
};