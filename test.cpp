#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<sstream>

using namespace std;


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
        for (auto i : ans){
            cout << i << " ";
        }
        cout << endl;

        for (int i = 0; i <= right; i++){
            // cout << ans[idx % n] << endl;
            matrix[left][i] = ans[idx % n];
            idx = idx + 1;
        }
        for (int i = left + 1; i <= right; i++){
            // cout << ans[idx % n] << endl;

            matrix[i][right] = ans[idx % n];
            idx = idx + 1;
        }
        for (int i = right - 1; i >= 0; i--){
            // cout << ans[idx % n] << endl;

            matrix[right][i] = ans[idx % n];
            idx = idx + 1;
        }
        for (int i = right - 1; i > left; i--){
            // cout << ans[idx % n] << endl;

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

int main(){
    vector<vector<int>> vec {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    Solution test;
    test.rotate(vec);


}
