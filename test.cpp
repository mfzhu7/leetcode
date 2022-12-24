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
    void helper(vector<vector<int>>& triangle, int& ret, int pathSum, int row, int col){
        if(row >= triangle.size()){
            cout << pathSum << endl;
            ret = pathSum > ret ? pathSum : ret;
            return;
        }
        helper(triangle, ret, pathSum + triangle[row][col], row + 1, col);
        helper(triangle, ret, pathSum + triangle[row][col], row + 1, col + 1);
        return;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int ret = 0;
        helper(triangle,ret,0,0,0);
        return ret;
    }
};



int main(){
    for (int i = 0; i < 9; i = i + 3){
        for (int j = 0; j < 9; j = j + 3){
            cout << i << "," << j << endl;
        }
    }
}