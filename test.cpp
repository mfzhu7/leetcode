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
    vector<int> a{1,2,3};
    vector<vector<int>> ret(3,a);
    for (auto i : ret){
        for (auto j:i){
            cout << j << endl;
        }
    }
}