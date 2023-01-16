#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<sstream>
#include<stack>
#include<unordered_map>

using namespace std;


class Solution {
public:
    double myPow(double x, int n) {
        double ret = 1;
        bool tag = false;
        if (n < 0){
            n = (-1 * n);
            tag = true;
        }
        while(n > 0){
            if (n & 1){
                ret = ret * x;
            }
            x *= x;
            n >>= 1;
        }
        if (tag){
            ret = 1 / ret;
        }
        return ret;
    }
};


int main(){
    Solution test;
    double a = test.myPow(2,10);
    cout << a << endl;
}
