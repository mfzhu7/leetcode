class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits[digits.size()-1] != 9){
            digits[digits.size()-1] = digits[digits.size()-1] + 1;
            return digits;
        }

        long long  temp = 1;
        long long total = 0;
        for (int i = digits.size() - 1; i >= 0; i--){
            total = total + temp * digits[i];
            temp = temp * 10;
        }
        total = total + 1;
        vector<int> vec; 
        while(total) {
            int temp = total % 10;
            vec.push_back(temp);
            total = (total - temp) / 10;
        }
        reverse(vec.begin(), vec.end());
        return vec;

    }
};