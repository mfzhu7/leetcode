class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int r = x ;
        int ans = -1;
        while(l <= r){
            long long mid = l + (r - l) / 2 ;
            if (mid * mid <= x){
                l = mid + 1;
                ans = mid;
            } else {
                 r = mid - 1;
            }
        }
        return ans ;

    }
};