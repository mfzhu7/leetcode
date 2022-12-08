class Solution {
public:
    bool isPalindrome(string s) {
        string res = "";
        for (char i:s){
            if(isalnum(i)){
                res += tolower(i);
            }
        }
        int l = 0;
        int r = res.size() - 1;
        while(l <= r){
            if (res[l] != res[r])  return false;
            else {
                l = l + 1;
                r = r - 1;
            }
        }
        return true;

    }
};