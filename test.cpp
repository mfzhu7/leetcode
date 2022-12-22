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
    map<int, string> hash =  {{1, "add"}, {2, "ddd"}};
    for (auto it: hash){
        cout << it.first << endl;
    }
}