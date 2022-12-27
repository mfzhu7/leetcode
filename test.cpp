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
    int removeDuplicates(vector<int>& nums) {

        int first = 0;
        int second = 1;
        while(nums[second] == nums[first]){
            second = second + 1;
        }
        int left = nums.size();
        while(first < second && second < left){
            if (second - first > 2){
                int temp = first;
                int diff = second - first;
                for (int i = second; i < left; i++){
                    nums[first + 2] = nums[i];
                    first = first + 1;
                }
                left = left - (diff - 2);
                first = temp + 2;
                second = first;
                while(nums[second] == nums[first]){
                    second = second + 1;
                }
            } else {
                first = second;
                while(second < left && nums[second] == nums[first]){
                    second = second + 1;
                }
            }
        }
        return left;

    }
};
int main(){
    vector<int> vec = {0,0,1,1,1,1,2,3,3};
    Solution test;
    test.removeDuplicates(vec);
    
}
