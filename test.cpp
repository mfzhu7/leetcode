#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>


using namespace std;

void print(vector<int> nums){
    for (auto i: nums){
        cout << i << " ";
    }
    cout << endl;
    return;
}


class Solution {
public:
    string add(string num1, string num2){
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string ret = "";
        int length = max(num1.size(), num2.size());
        int add = 0;
        for (int i = 0; i < length; i++){
            char temp1,temp2;
            if (i >= num1.size()) {
                temp1 = '0';
            } else {
                temp1 = num1[i];
            }
            if (i >= num2.size()) {
                temp2 = '0';
            } else {
                temp2 = num2[i];
            }
            int temp = (temp1 - '0') + (temp2 - '0') + add;
            if (temp > 9){
                add = 1;
                temp = temp % 10;
            } else {
                add = 0;
            }
            ret.push_back('0' + temp);
        }
        if (add) ret.push_back('1');
        reverse(ret.begin(), ret.end());
        return ret;
    }
    string helper(string str1, char curr, int tag){
        string ret = "";
        int add = 0;
        int num = curr - '0';
        for (int i = str1.size() - 1; i >= 0; i--){
            int temp = (str1[i] - '0') * num + add;
            if(temp > 9){
                add = temp / 10;
                temp = temp % 10;
            } else {
                add = 0;
            }
            ret.push_back(temp + '0');
        }
        if (add > 0) ret.push_back(add + '0');
        reverse(ret.begin(), ret.end());
        for (int i = 0; i < tag; i++){
            ret.push_back('0');
        }
        return ret;
    }
    string multiply(string num1, string num2) {
        if(num1 == "0" or num2 == "0")  return "0";

        vector<string>vec;
        string ret = "0";
        int tag = 0;
        for (int i = num2.size() - 1; i >= 0; i--){
            string temp = helper(num1, num2[i], tag);
            vec.push_back(temp);
            tag = tag + 1;
        }
        for (int i = 0; i < vec.size(); i++){
            // cout << vec[i] << "  " << ret << endl;

            ret = add(ret, vec[i]);
            // cout << ret << endl;
        }
        return ret;
    }
};

int main(){
    string test = "123";
    test.insert(0, 0,'0');
    cout << test << endl;
    
}
