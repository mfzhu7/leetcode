#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>


using namespace std;

void print(vector<int> nums){
    for (auto i: nums){
        cout << i << " ";
    }
    cout << endl;
    return;
}


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
            cout << i << " " <<  j << endl;

        }
        return false;

    }
};


int main(){
    // vector<vector<int>> vec = {
    //     {1,3,5,7},{10,11,16,20},{23,30,34,60}
    // };
    vector<int> vec{1,2,3};
    cout << vec[-1] << endl;
    // Solution test;
    // test.searchMatrix(vec, 23);
}