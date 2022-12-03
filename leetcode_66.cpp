#include<vector>

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int add = 0;
        bool tag = true;
        int place = digits.size() - 1;
        while((tag || add) && place >= 0 ){
            int temp = digits[place] + 1;
            add = (temp == 10) ? 1 : 0;
            temp = temp % 10;
            digits[place] = temp;
            tag = false;
            place = place - 1;
        }
        if(add){
            digits.emplace(digits.begin(), 1);
        }
        return digits;
    }
};


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--){
            if (digits[i] == 9){
                digits[i] = 0;
            }else {
                digits[i] = digits[i] + 1;
                return digits;
            }
        }
        digits.emplace(digits.begin(), 1);
        return digits;
    }
};


