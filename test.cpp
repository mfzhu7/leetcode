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
    void helper(vector<int>& candidates, int target, int begin, vector<int>& path, vector<vector<int>>& res, int pathSum){
        if (pathSum == target){
            res.push_back(path);
            return;
        }

        set<int> layNum;
        for (int i = begin; i < candidates.size(); i++){
            if ((pathSum + candidates[i] <= target) && layNum.find(candidates[i]) == layNum.end()){
                layNum.insert(candidates[i]);
                pathSum = pathSum + candidates[i];
                path.push_back(candidates[i]);
                helper(candidates,target, i + 1,path,res,pathSum);
                pathSum = pathSum - candidates[i];
                path.pop_back();
            }
        }
        return;
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        int pathSum = 0;
        helper(candidates,target,0,path,res,pathSum);
        return res;

    }
};

int main(){
    vector<int> vec1 = {1,2,2,2,5};
    vector<int> vec2 = {2,5,2,1,2};

    Solution test;
   vector<vector<int>> res =  test.combinationSum2(vec2,5);
    for (auto i : res){
        print(i);
    }
}