class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder == "#") return true;
        stringstream ss(preorder);
        string s;
        vector<string> vec;
        while(getline(ss, s, ',')){
            vec.push_back(s);
        }

        stack<char> stk;
        for (int i = 0; i < vec.size(); i++){
            if(isdigit(vec[i][0])){
                stk.push(vec[i][0]);
            } else {
                if(stk.empty()) return false;
                if(stk.top() == '#'){
                    while(!stk.empty() && stk.top() == '#'){
                        stk.pop();
                        stk.pop();
                    }
                    if(!stk.empty()){
                        stk.push(vec[i][0]);
                    } else {
                        if(i == vec.size() - 1){
                            return true;
                        } else {
                            return false;
                        }
                    }     
                } else {
                    stk.push(vec[i][0]);
                }
            }
        }
        return stk.empty();
    }
};