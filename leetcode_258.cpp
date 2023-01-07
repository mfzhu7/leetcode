class Solution {
public:
    int addDigits(int num) {
        int ans = 0;
        while(num){
            while(num){
                int k = num % 10;
                ans = ans + k;
                num = (num - k) / 10;
            }
            num = ans;
            ans = 0;
            if (num < 10) break;
        }
        return num;

    }
};