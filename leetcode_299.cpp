class Solution {
public:
    string getHint(string secret, string guess) {
        map<int, int> hash;
        vector<int> pos1(10,0);
        vector<int> pos2(10,0);
        int bull = 0;
        int cow = 0;

        for (int i = 0; i < secret.size(); i++){
            pos1[secret[i] - '0']++;
            pos2[guess[i] - '0']++;
            if(secret[i] == guess[i]){
                hash[secret[i] - '0']++;
                bull++;
            }
        }
        for(int i = 0; i < 10; i++){
            if(pos1[i] == 0){
                continue;
            } else{
                cow = cow + min(pos1[i] - hash[i], pos2[i] - hash[i]);
            }
        }
        string ans = to_string(bull) + "A" + to_string(cow) + "B";
        return ans; 
    }
};