class Solution {
public:
    double myPow(double x, int n) {
        double ret = 1;
        bool tag = false;
        long long n1 = n;
        if (n1 < 0){
            n1 = (long)(-1 * n1);
            tag = true;
        }
        while(n1 > 0){
            if (n1 & 1){
                ret = ret * x;
            }
            x *= x;
            n1 >>= 1;
        }
        if (tag){
            ret = 1 / ret;
        }
        return ret;
    }
};