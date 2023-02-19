class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> hash1(26, 0);
        vector<int> hash2(26, 0);

        for (int i = 0; i < s.size(); i++){
            hash1[s[i] - 'a'] += 1;
            hash2[t[i] - 'a'] += 1;
        }
        hash2[t.back() - 'a'] += 1;

        char ans = 'a';
        for (int i = 0; i < 26; i++){
            if(hash1[i] != hash2[i]){
                ans += i;
                break;
            }
        }
        return ans;

    }
};