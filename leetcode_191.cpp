class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0; 
        while(n){
            n = n & (n - 1);
            ret = ret + 1;
        }
        return ret;
        
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0; 
        while(n){
            if (n % 2 == 1) res = res + 1;
            n = (n >> 1);
        }
        return res;
        
    }
};