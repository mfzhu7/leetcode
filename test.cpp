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
    bool isInterleave(string s1, string s2, string s3) {
        auto f = vector < vector <int> > (s1.size() + 1, vector <int> (s2.size() + 1, false));

        int n = s1.size(), m = s2.size(), t = s3.size();

        if (n + m != t) {
            return false;
        }

        f[0][0] = true;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                int p = i + j - 1;
                if (i > 0) {
                    f[i][j] |= (f[i - 1][j] && s1[i - 1] == s3[p]);
                }
                if (j > 0) {
                    f[i][j] |= (f[i][j - 1] && s2[j - 1] == s3[p]);
                }
            }
        }

        return f[n][m];
    }
};



int main(){
    Solution test;
    string str1 = "aabcc";
    string str2 = "dbbca";
    string str3 = "aadbbcbcac";
    test.isInterleave(str1, str2, str3);
}
