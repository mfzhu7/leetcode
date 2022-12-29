class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();
        int maxpos = 0;
        int end = 0;
        int step = 0;
        for (int i = 0; i < n - 1; i++){
            if (i <= maxpos){
                maxpos = max(maxpos, i + nums[i]);
            }
            if (i == end){
                end = maxpos;
                step = step + 1;
            }
        }
        return step;

    }
};