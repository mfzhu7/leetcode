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



int main(){

    int a = 1000000000;
    int b = 2000000000;
    long long c = a + b;
    cout << c << endl;
}