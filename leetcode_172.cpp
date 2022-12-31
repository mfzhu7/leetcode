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
                cout << temp << endl;
                ret = ret + temp;
            }
        }
        return ret;
    }
};