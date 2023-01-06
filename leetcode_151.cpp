class Solution {
public:
    string reverseWords(string s) {
        int left = 0; 
        int right = s.size() - 1;
        while(left <= right && s[left] == ' ') left++;
        while(right >= 0 && s[right] == ' ') right --;

        deque<string> d;
        string word;

        while(left <= right){
            char c = s[left];
            if (word.size() && c == ' '){
                d.push_front(word);
                word = "";
            } else if (c != ' '){
                word += c;
            }
            left++;
        }
        d.push_front(word);

        string ans;

        while(!d.empty()){
            ans = ans + d.front();
            d.pop_front();
            if (!d.empty()) ans = ans + " ";
        }
        return ans;
    }
};



class Solution {
public:
    string reverseWords(string s) {
        stack<string> stk;
        string temp, res;
         istringstream ss(s); 

         while(ss >> temp){
             stk.push(temp);
             stk.push(" ");
         }
         if (!stk.empty()) stk.pop();

         while(!stk.empty()){
             res += stk.top();
             stk.pop();
         }
         return res;

    }
};