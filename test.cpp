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
    bool isValidSerialization(string preorder) {
        if(preorder == "#") return true;
        stack<char> stk;
        for (int i = 0; i < preorder.size(); i++){
            if(isdigit(preorder[i])){
                stk.push(preorder[i]);
            } else if (preorder[i] == ','){
                continue;
            } else {
                if(stk.empty()) return false;
                if(stk.top() == '#'){
                    while(!stk.empty() && stk.top() == '#'){
                        stk.pop();
                        stk.pop();
                    }
                    if(!stk.empty()){
                        stk.push(preorder[i]);
                    } else {
                        if(i == preorder.size() - 1){
                            return true;
                        } else {
                            return false;
                        }
                    }     
                } else {
                    stk.push(preorder[i]);
                }
            }
        }
        return stk.empty();
    }
};
int main(){
    string test= "9,#,92,#,#";
    stringstream ss(test);
    string s;

    while(getline(ss, s, ',')){
        cout << s << endl;
        cout << isdigit(s[0]) << endl;
    }
    // Solution test1;
    // test1.isValidSerialization(test);
}
