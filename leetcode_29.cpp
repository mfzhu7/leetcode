class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN){
            if (divisor == 1) return INT_MIN;
            if (divisor == -1) return INT_MAX;
        }
        bool tag = false;
        if(dividend > 0){
            dividend = -1 * dividend;
            tag = !tag;
        }
        if (divisor > 0){
            divisor = -1 * divisor;
            tag = !tag;
        }

        vector<int> vec{divisor};
        while(vec.back() >= dividend - vec.back()){
            vec.push_back(vec.back() + vec.back());
        }
        int ret = 0;
        for (int i = vec.size() - 1;i >= 0; i--){
            if (vec[i] >= dividend){
                ret = ret + (1 << i);
                dividend -= vec[i];
            } 
        }
        return tag ? -1 * ret : ret;

    }
};