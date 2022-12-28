class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 1) {
            vector<int> ret = {0, 1};
            return ret;
        }
        vector<int> ret = grayCode(n - 1);
        vector<int> first(ret.size(), 0);
        vector<int> second(ret.size(), 0);

        for (int i = 0; i < ret.size(); i++){
            first[i] = (ret[i] << 1);
            second[i] = ((ret[i] << 1) + 0x1);
        }
        reverse(second.begin(), second.end());
        first.insert(first.end(),second.begin(),second.end());
        return first;

    }
};