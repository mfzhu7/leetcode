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
    
    int calculate(string s) {
        deque<string> deq; 
        int i = 0; 
        while(i < s.size()){
            if(isdigit(s[i])){
                int curr = i;
                while(i < s.size() && isdigit(s[i])){
                    i = i + 1;
                }
                string temp = s.substr(curr, i - curr);
                deq.push_back(temp);
            } else if (s[i] == '+'){
                deq.push_back("+");
                i = i + 1;
            } else if (s[i] == '-'){
                deq.push_back("-");
                i = i + 1;
            } else if (s[i] == ' '){
                i = i + 1;
                continue;
            } else if (s[i] == '/'){
                deq.push_back("/");
                i = i + 1;
            } else {
                deq.push_back("*");
                i = i + 1;
            }
            
        }

        deque<string> deq1;
        while(!deq.empty()){
            if(deq.front() != "*" && deq.front() != "/"){
                deq1.push_back(deq.front());
                deq.pop_front();
            } else {
                string op = deq.front();
                deq.pop_front();
                int before = stoi(deq1.back());
                int next = stoi(deq.front());
                deq.pop_front();
                int res = 0;
                if (op == "/"){
                    res = before / next;
                } else {
                    res = before * next;
                }
                deq1.push_back(to_string(res));
            }
        }

        int ans = stoi(deq1.front());
        deq1.pop_front();
        while(!deq1.empty()){
            if(deq1.front() == "-"){
                deq1.pop_front();
                ans = ans - stoi(deq1.front());
                deq1.pop_front();
            } else {
                deq1.pop_front();
                ans = ans + stoi(deq1.front());
                deq1.pop_front();
            }
        }
        return ans;

    }
};


int main(){
    string test1 = " 3+5 / 2 ";
    Solution test;
    test.calculate(test1);
}
