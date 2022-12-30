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
};

int multiply(int A, int B) {
    int ans = 0;
    for(; B != 0; B >>= 1){
        if(B & 1){
            ans += A;
        }
        A <<= 1;
        cout << B << endl;
        cout << A << endl;
    }
    return ans;
}

int main(){
    int a = 3;
    int b = 6;
    multiply(a,b);

    
}
