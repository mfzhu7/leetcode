class Solution {
public:
    int count(int n){
        int ret = 0;
        while(n != 0 && n % 5 == 0){
            ret = ret + 1;
            n = n / 5;
        }
        return ret;
    }
    int trailingZeroes(int n) {
        int ret = 0;
        for (int i = 0; i <= n; i++){
            if (i % 5 == 0){
                int temp = count(i);
                ret = ret + temp;
            }
        }
        return ret;
    }
};

class Solution {
public:
    int trailingZeroes(int n) {
        int ret = 0;
        for (int i = 5; i <= n; i = i + 5){
            for (int j = i; j % 5 == 0; j = j / 5){
                ret = ret + 1;
            }
        }
        return ret;
    }
};