class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) return false;
        int ret = 0;
        while(n){
            if(n & 1){
                ret = ret + 1;
            }
            if (ret > 1) return false;
            n >>= 1;
        }
        return true;
    }
};
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};