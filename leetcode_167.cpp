class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        vector<int> ret(2);
        while(left <= right){
            if (numbers[left] + numbers[right] == target){
                ret[0] = left + 1;
                ret[1] = right + 1;
                break;
            } else if (numbers[left] + numbers[right] > target) {
                right = right - 1;
            } else {
                left = left + 1;
            }
        }
        return ret;
    }
};