class Solution {
public:
    string addBinary(string a, string b) {
        int l_a = a.size() - 1;
        int l_b = b.size() - 1;
        int add = 0;
        string res = "";
        while(l_a >= 0 || l_b >= 0){
            int a1 = l_a >= 0 ? a[l_a] : '0';
            int b1 = l_b >= 0 ? b[l_b] : '0';

            int temp = a1 + b1 - 96 + add;
            add = temp >= 2 ? 1 : 0;
            if (temp == 3){ res = "1" + res;}
            if (temp == 2){ res = "0" + res;}
            if (temp == 1){ res = "1" + res;}
            if (temp == 0){ res = "0" + res;}
            l_a = l_a - 1;
            l_b = l_b - 1;
        }
        if (add) {
            return "1" + res;
        }
        return res;

    }
};