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


class Solution {
public:
    bool helper(int x, int y, int z){
        int res = 0;
        for (; z != 0; z >>= 1){
            if (z & 1){
                if (res < x - y) {
                    return false;
                }
                res += y;
            }
            if (z != 1){
                if (y < x - y) return false;
                y += y;
            }
        }
        return true;
    }
    int divide(int dividend, int divisor) {
        cout << dividend << divisor << endl;
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
        int left  = 1;
        int right = INT_MAX;
        int ret = 0;
        while(left <= right){
            int mid = left + ((right - left) >> 1);
            bool check = helper(dividend, divisor, mid);
            if (check){
                ret = mid;
                if (ret == INT_MAX) break;
                left = mid + 1;
            } else {
                right = mid -1;
            }
        }
        return tag ? -1 * ret : ret;

    }
};
