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


    string getNext(int n){
        string num = to_string(n);
        string res = "";
        int index = 0;
        while(index < num.size()){
            int count = 1;
            while(index + 1 < num.size() && num[index] == num[index + 1]){
                count = count + 1;
                index = index + 1;
            }
            res = res + to_string(count) + num[index];
            index = index + 1;
            
        }
        return res;
    }
int main(){
    int a = 332251;
    string result = getNext(a);
    cout << result << endl;
}