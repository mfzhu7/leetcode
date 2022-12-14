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
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> row;
        set<int> col;
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[0].size(); j++){
                if (matrix[i][j] == 0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[0].size(); j++){
                if (row.find(i) != row.end() || col.find(j) != col.end()){
                    matrix[i][j] == 0;
                    cout << i << j << endl;
                }
            }
        }
        return;
    }
};


int main(){
    vector<vector<int>> vec = {
        {1,1,1},{1,0,1},{1,1,1}
    };
    Solution test;
    test.setZeroes(vec);
}