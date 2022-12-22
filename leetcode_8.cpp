class Solution {
public:
    int myAtoi(string s) {
        int index = 0;
        int neg = 1;
        int ret = 0;

        while(index < s.size() && s[index] == ' '){
            index++;
        }
        if (index < s.size() && (s[index] == '+' or s[index] == '-')){
            if (s[index] == '-'){
                neg = neg * -1;
            }
            index = index + 1;
        }
        while(index < s.size() && isdigit(s[index])){
            int num = s[index] - '0';
            if( ret > INT_MAX/10 || (ret == INT_MAX/10 && num > INT_MAX % 10 ) )
            {
                return 1==neg ? INT_MAX : INT_MIN;    
            }
            ret = ret * 10 + num;
            index++;
        }
        return ret * neg;



    }
};

//核心代码在于如何判断数据越界的情况 if( ret > INT_MAX/10 || (ret == INT_MAX/10 && num > INT_MAX % 10 ) )