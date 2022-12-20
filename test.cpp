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
    map<char, string> hash{
        {'2', "abc"}
        ,{'3', "def"}
    };
    string a = "123";
    cout << a.substr(0, a.size() - 1);

}