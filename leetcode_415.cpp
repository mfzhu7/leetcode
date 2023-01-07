class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int id1 = 0;
        int id2 = 0;
        int add = 0;
        string ret = "";
        while(id1 < num1.size() || id2 < num2.size()){
            int n1 = (id1 >= num1.size()) ? 0 : num1[id1] - '0';
            int n2 = (id2 >= num2.size()) ? 0 : num2[id2] - '0';
            int ans = (n1 + n2 + add);
            add = (ans > 9) ? 1 : 0;
            ans = ans % 10;
            ret.push_back(ans + '0');
            id1 = id1 + 1;
            id2 = id2 + 1;
        }
        if (add) ret.push_back('1');
        reverse(ret.begin(), ret.end());
        return ret;


    }
};