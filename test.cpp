#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int curr = nums1.size() - 1;
        int index1 = m - 1;
        int index2 = n - 1;
        while(curr >= 0 && index2 >= 0){
            if(nums2[index2] > nums1[index1]){
                nums1[curr] = nums2[index2];
                index2 = index2 - 1;
            } else {
                nums1[curr] = nums1[index1];
                index1 = index1 - 1;
            }
            curr = curr - 1;
        }

    }
};

int main(){
    vector<int> num1 = {1,2,3,0,0,0};
    vector<int> num2 = {2,5,6};
    int m = 3;
    int n = 3;
    Solution test;
    test.merge(num1,m, num2,n);
    for (auto i: num1){
        cout << i << endl;
    }
    vector<int> a(10,0);
    for (auto i:a){
        cout <<i << endl;
    }
    
}