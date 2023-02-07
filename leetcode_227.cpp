class Solution {
public:
    
    int calculate(string s) {
        deque<string> deq1; 
        int i = 0; 
        while(i < s.size()){
            if(isdigit(s[i])){
                int curr = i;
                while(i < s.size() && isdigit(s[i])){
                    i = i + 1;
                }
                string temp = s.substr(curr, i - curr);
                deq1.push_back(temp);
            } else if (s[i] == '+'){
                deq1.push_back("+");
                i = i + 1;
            } else if (s[i] == '-'){
                deq1.push_back("-");
                i = i + 1;
            } else if (s[i] == ' '){
                i = i + 1;
                continue;
            } else if (s[i] == '/'){
                deq1.push_back("/");
                i = i + 1;
            } else {
                deq1.push_back("*");
                i = i + 1;
            }
            
        }

        deque<string> deq2;
        while(!deq1.empty()){
            if(deq1.front() != "*" && deq1.front() != "/"){
                deq2.push_back(deq1.front());
                deq1.pop_front();
            } else {
                string op = deq1.front();
                deq1.pop_front();
                int before = stoi(deq2.back());
                int next = stoi(deq1.front());
                deq1.pop_front();
                deq2.pop_back();
                int res = 0;
                if (op == "/"){
                    res = before / next;
                } else {
                    res = before * next;
                }
                deq2.push_back(to_string(res));
            }
        }

        int ans = stoi(deq2.front());
        deq2.pop_front();
        while(!deq2.empty()){
            if(deq2.front() == "-"){
                deq2.pop_front();
                ans = ans - stoi(deq2.front());
                deq2.pop_front();
            } else {
                deq2.pop_front();
                ans = ans + stoi(deq2.front());
                deq2.pop_front();
            }
        }
        return ans;

    }
};



class Solution {
public:
    int calculate(string s) {
        vector<int> stk;
        char preSign = '+';
        int n = s.size();
        int num = 0;
        for (int i = 0; i < n; i++){
            if(isdigit(s[i])){
                num = num * 10 + int(s[i] - '0');
            }
            if(!isdigit(s[i]) && s[i] != ' ' || i == n - 1){
                switch(preSign){
                    case '+':
                        stk.push_back(num);
                        break;
                    case '-':
                        stk.push_back(-num);
                        break;
                    case '*':
                        stk.back() *= num;
                        break;
                    default:
                        stk.back() /= num;
                        break;
                }
                num = 0;
                preSign = s[i];
            }
        }

        return accumulate(stk.begin(), stk.end(), 0);
    }
};