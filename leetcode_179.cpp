class Solution {
public:
    bool compare(int num1, int num2){
        string str1 = to_string(num1) + to_string(num2);
        string str2 = to_string(num2) + to_string(num1);

        double val1 = stod(str1);
        double val2 = stod(str2);

        return (val1 >= val2);
    }
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n- 1; i++){
            for (int j = 0; j < n - i - 1; j++){
                if (compare(nums[j], nums[j + 1])){
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }
        if (nums[n - 1] == 0) return "0";
        string ans = "";
        for (int i =n - 1; i >= 0; i--){
            ans = ans + to_string(nums[i]);
        }
        return ans;
    }
};



class Solution {
public:
    static bool compare(int num1, int num2){
        string str1 = to_string(num1) + to_string(num2);
        string str2 = to_string(num2) + to_string(num1);

        double val1 = stod(str1);
        double val2 = stod(str2);

        return (val1 > val2);
    }
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), compare);
        if (nums[0] == 0) return "0";
        string ans = "";
        for (int i = 0; i < n; i++){
            ans = ans + to_string(nums[i]);
        }
        return ans;
    }
};