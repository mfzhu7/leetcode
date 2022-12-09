#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    string str = "abcd";
    string res = "";
    for (char i: str){
        res += tolower(i);
    }
    cout << res << endl;
    reverse(res.begin(), res.end());
    cout << res << endl;
    // cout << typeid(res).name() << endl;
    // cout << reverse(res.begin(), res.end()) << endl;
    
}