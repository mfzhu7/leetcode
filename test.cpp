#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>

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
    string convertToTitle(int columnNumber) {
        string res = "";
        map<int, char> hash;
        hash[0] = 'Z';
        for (int i = 1; i <= 25; i++){
            hash[i] = i + 64;
        }

        while(columnNumber){
            res = hash[columnNumber % 26] + res;
            columnNumber = (columnNumber - columnNumber % 26) / 26;
        }
        return res;

    }
};

int main(){
    Solution test;
    test.convertToTitle(701);
   
}