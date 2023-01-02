#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>

using namespace std;


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int length = nums.size();
        k = k % length;
        if (k == 0) return;
        vector<int> first(nums.begin(), nums.begin() + k);
        vector<int> second(nums.begin() + k, nums.end());
        reverse(first.begin(), first.end());
        for (int i = 0; i < length - k; i++){
            nums[i] = second[i];
        }
        for (int i = length - k; i < length; i++){
                nums[i] = first[i - length + k];
        }
        return;
    }
};


int main(){
    vector<int> vec{1,2,3,4,5,6,7};
    Solution test;
    test.rotate(vec,3);
    for (auto i: vec){
        cout << i << endl;
    }
}
