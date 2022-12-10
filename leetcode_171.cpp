class Solution {
public:
    int titleToNumber(string columnTitle) {
        long  add = 1;
        int res = 0;
        int index = columnTitle.size() - 1;
        while(index >= 0){
            int tmp = columnTitle[index] - 64;
            res = res + tmp * add;
            add = add * 26;
            index = index - 1;
        }
        return res;

    }
};