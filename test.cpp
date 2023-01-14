#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<sstream>
#include<stack>
#include<unordered_map>

using namespace std;


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx1 = n - 2;
        while(idx1 >= 0 && nums[idx1] > nums[idx1 + 1]){
            idx1 = idx1 - 1;
        }
        int idx2 = n - 1;
        while(idx2 > idx1 && nums[idx2] < nums[idx1]){
            idx2--;
        }
        int temp = nums[idx1];
        nums[idx1] = nums[idx2];
        nums[idx2] = temp;

        reverse(nums.begin() + idx1 + 1, nums.end());
        return;

    }
};

int main(){
    Solution test;
    vector<int> vec{1,5,1};
    test.nextPermutation(vec);

}
