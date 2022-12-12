class Solution {
public:
    string getNext(string num){
        string next = "";
        int index = 0;
        while(index < num.size()){
            int count = 1;
            while(index + 1 < num.size() && num[index] == num[index + 1]){
                count = count + 1;
                index = index + 1;
            }
            next += to_string(count) + num[index];
            index = index + 1;
            
        }
        return next;
    }
    string countAndSay(int n) {
        int index = 1;
        string res = "1";
        while(index < n){
            res = getNext(res);
            index = index + 1;
        }
        return res;


    }
};