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
    int helper(string str1, char curr, int tag){
        long long ret = 0;
        long long add = 1;
        int num = curr - '0';
        for (int i = str1.size() - 1; i >= 0; i--){
            int temp = str1[i] - '0';
            ret = ret + temp * add * num;
            add = add * 10;
        }
        return ret * tag;
    }
    string multiply(string num1, string num2) {
        long long ret = 0;
        long long tag = 1;
        for (int i = num2.size() - 1; i >= 0; i--){
            int temp = helper(num1, num2[i], tag);
            ret = ret + temp;
            tag = tag * 10;
        }
        return to_string(ret);
    }
};


int main(){
    string a = "123456789";
    string b = "987654321";
    Solution test;
    test.multiply(a,b);

}