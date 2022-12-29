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


void helper(vector<vector<int>>& matrix, int x1, int y1, int x2, int y2, vector<int>& path){
        if (x1 > x2 || y1 > y2) return;

        if (x1 == x2 && y1 != y2){
            for (int i = y1; i <= y2; i++){
            path.push_back(matrix[x1][i]);
            }
        } 
        else if (x1 != x2 && y1 == y2){
            for (int i = x1; i <= x2; i++){
                path.push_back(matrix[i][y1]);
                }   
        } 
        else if (x1 == x1 && y1 == y2){
            path.push_back(matrix[x1][y1]);
        } else {
            for (int i = y1; i <= y2; i++){
                path.push_back(matrix[x1][i]);
            }
            for (int i = x1 + 1; i <= x2; i++){
                path.push_back(matrix[i][y2]);
            }
            for (int i = y2 - 1; i >= y1; i--){
                path.push_back(matrix[x2][i]);
            }
            for (int i = x2 - 1; i > x1; i--){
                path.push_back(matrix[i][y1]);
            }
        }
        helper(matrix, x1 + 1,y1 + 1,x2 - 1, y2 - 1, path);
        return;

    };
int main(){
    vector<vector<int>> vec{{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> path;
    helper(vec,0,0,2,3,path);
    print(path);
    
}
