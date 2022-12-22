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
    string s = " 123";
    cout << s[0] << endl;
    if(s[0] == ' ')
    {
        cout << "true" << endl;
    }

}