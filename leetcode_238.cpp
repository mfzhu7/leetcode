class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>L(n, 1);
        vector<int>R(n, 1);

        for (int i = 1; i < n; i++){
            L[i] = L[i - 1] * nums[i - 1];
        }
        for (int i = n - 2; i >= 0; i--){
            R[i] = R[i + 1] * nums[i + 1];
        }

        vector<int> ret(n, 0);
        for(int i = 0; i < n; i++){
            ret[i] = L[i] * R[i];
        }
        return ret;


    }
};


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>L(n, 1);
        for (int i = 1; i < n; i++){
            L[i] = L[i - 1] * nums[i - 1];
        }
        int right = 1;
        vector<int> ret(n, 0);
        for(int i = n - 1; i >= 0; i--){
            ret[i] = L[i] * right;
            right = right * nums[i];
        }
        return ret;


    }
};