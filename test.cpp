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
    uint32_t a = 13;
    while(a){
        uint32_t b = a % 2;
        a = a >> 1;
        cout << b << endl;
    }
    return 0;
    

}