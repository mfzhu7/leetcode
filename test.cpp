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

class Solution {
public:
    void helper(string s, vector<vector<string>>& ret, vector<string>& path, int index){
        
        if (index == s.size() && path.size() == 4){
            ret.push_back(path);
            return;
        }
        if (index >= s.size() || path.size() >= 4) return;
        if (s[index] == '0'){
            path.push_back("0");
            helper(s,ret,path,index + 1);
            return;
        } else {
            path.push_back(s.substr(index,1));
            helper(s,ret,path,index+1);
            path.pop_back();
            path.push_back(s.substr(index,2));
            helper(s,ret,path,index+2);
            path.pop_back();
            if (stoi(s.substr(index,3)) <= 255){
                path.push_back(s.substr(index,3));
                helper(s,ret,path,index+3);
                path.pop_back();
            }   
            return;
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<vector<string>> ret;
        vector<string> path;
        int index = 0;
        vector<string> IP;
        helper(s,ret,path,index);
        for(auto vec: ret){
            string temp = vec[0] + "." + vec[1] + "." + vec[2] + "." + vec[3];
            IP.push_back(temp);
        }
        return IP;
    }
};


int main(){
    string test = "101023";
    Solution a;
    a.restoreIpAddresses(test);
    
}
