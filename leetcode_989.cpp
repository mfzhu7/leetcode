class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        reverse(num.begin(), num.end());
        int add = 0;
        int idx = 0;
        while(idx < num.size() || k){
            int temp = k % 10;
            int n = (idx < num.size()) ? num[idx] : 0;
            int ans = n + temp + add;
            add = (ans > 9) ? 1 : 0;
            k = (k - temp) / 10;
            if (idx < num.size()){
                num[idx] = (ans % 10);
            } else {
                num.push_back(ans % 10);
            }
            idx = idx + 1;
        }
        if (add) num.push_back(1);
        reverse(num.begin(), num.end());
        return num;
    }
};