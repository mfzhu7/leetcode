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
#include<stdlib.h>
#include<memory>
#include<string.h>
#include<tuple>
#include<functional>

using namespace std;

void helloworld(string name){
    cout << "hello world " << name << endl;
}
;

// void addAndPrint(int value){
//     cout << "value add 1 equals " << value + 1 << endl;
// }

void forEach(const vector<int>& values,const function<void(int)>& func){
    for(auto value: values){
        func(value);
    }
};
int main() {
    vector<int> values = {1,2,3,4};
    int a = 5;
    auto lambda = [=](int value){ cout << "values is " << a << endl;};
    forEach(values, lambda);
}
;

 
