class Solution {
public:
    string add(string num1, string num2){
        string ret = "";
        int length = max(num1.size(), num2.size());
        int add = 0;
        for (int i = 0; i < length; i++){
            int first,second;
            first = (i >= num1.size()) ? 0 : num1[i] - '0';
            second = (i >= num2.size()) ? 0 : num2[i] - '0';
            int sum = first + second + add;
            add = (sum > 9) ? 1: 0;
            sum = (add == 1) ? sum % 10 : sum;
            ret.push_back('0' + sum);
        }
        if (add) ret.push_back('1');
        return ret;
    }


    string helper(string str1, char curr, int tag){
        string ret = "";
        int add = 0;
        int num = curr - '0';
        for (int i = str1.size() - 1; i >= 0; i--){
            int sum = (str1[i] - '0') * num + add;
            add = (sum > 9) ? sum / 10 : 0;
            sum = (add >= 1) ? sum % 10: sum;
            ret.push_back(sum + '0');
        }
        if (add) ret.push_back(add + '0');
        
        ret.insert(0, tag, '0');
        return ret;
    }
    string multiply(string num1, string num2) {
        if(num1 == "0" or num2 == "0")  return "0";
        vector<string>vec;
        string ret = "0";
        int tag = 0;
        for (int i = num2.size() - 1; i >= 0; i--){
            string num = helper(num1, num2[i], tag);
            vec.push_back(num);
            tag = tag + 1;
        }
        for (int i = 0; i < vec.size(); i++){
            ret = add(ret, vec[i]);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};