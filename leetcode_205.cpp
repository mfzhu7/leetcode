class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> vec1(128,0);
        vector<int> vec2(128,0);

        for (int i = 0; i < s.size(); i++){
            if (vec1[s[i]] == 0 && vec2[t[i]] == 0){
                vec1[s[i]] = t[i];
                vec2[t[i]] = s[i];
            }
            else {
                if (vec1[s[i]] != t[i] || vec2[t[i]] != s[i]) return false;
            }
        }
        return true;

    }
};