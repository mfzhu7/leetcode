class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";
        while(columnNumber > 0){
            --columnNumber;
            char ans = columnNumber % 26 + 'A';
            res = ans + res;
            columnNumber = columnNumber / 26; 
        }
        return res;

    }
};

//注意26进制中从1开始 不是从0开始