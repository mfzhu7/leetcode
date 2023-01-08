class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> hash1;
        unordered_map<char, int> hash2;

        for (int i = 0; i < s.size(); i++){
            if (hash1.find(s[i]) == hash1.end()){
                hash1[s[i]] = 1;
            } else {
                hash1[s[i]] += 1;
            }
        }

        for (int i = 0; i < t.size(); i++){
            if (hash2.find(t[i]) == hash2.end()){
                hash2[t[i]] = 1;
            } else {
                hash2[t[i]] += 1;
            }
        }
        for (auto it: hash1){
            if (hash2[it.first] != it.second) return false;
        }
        return true;

    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int vec1[26] = {};
        int vec2[26] = {};

        for (int i = 0; i < s.size(); i++){
            vec1[s[i] - 'a'] += 1;
        }
        for (int i = 0; i < t.size(); i++){
            vec2[t[i] - 'a'] += 1;
        }

        for (int i = 0; i < 26; i++){
            if (vec1[i] != vec2[i]) return false;
        }
        return true;
    }
};