#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>

using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> src(128, 0);
        if (s.size() != t.size()) return false;

        for (int i = 0; i < s.size(); i++){
            if (src[s[i]] == 0){
                src[s[i]] = t[i];
            } else {
                if (src[s[i]] != t[i]) return false;
            }

        }
        return true;

    }
};

int main(){
    Solution test;
    test.isIsomorphic("foo", "bar");
}
