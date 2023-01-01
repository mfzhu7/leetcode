class Solution {
public:
    int helper(int n){
        int ret = 0;
        while(n){
            ret = ret + (n % 10) * (n % 10) ;
            n = (n - n % 10) / 10;
        }
        return ret;
    }
    bool isHappy(int n) {
        unordered_set<int> hash;
        while(n){
            int temp = helper(n);
            if (temp == 1) return true;
            if (hash.find(temp) != hash.end()) return false;
            hash.insert(temp);
            n = temp;
        }
        return true;

    }
};