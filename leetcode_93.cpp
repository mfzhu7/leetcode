class Solution {
public:
    void helper(string s, vector<vector<string>>& ret, vector<string>& path, int index){
        
        if (index == s.size() && path.size() == 4){
            ret.push_back(path);
            return;
        }
        if (index >= s.size() || path.size() >= 4) return;
        if (s[index] == '0'){
            path.push_back("0");
            helper(s,ret,path,index + 1);
            path.pop_back();
            return;
        } else {
            path.push_back(s.substr(index,1));
            helper(s,ret,path,index+1);
            path.pop_back();
            path.push_back(s.substr(index,2));
            helper(s,ret,path,index+2);
            path.pop_back();
            if (stoi(s.substr(index,3)) <= 255){
                path.push_back(s.substr(index,3));
                helper(s,ret,path,index+3);
                path.pop_back();
            }   
            return;
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<vector<string>> ret;
        vector<string> path;
        int index = 0;
        vector<string> IP;
        helper(s,ret,path,index);
        for(auto vec: ret){
            string temp = vec[0] + "." + vec[1] + "." + vec[2] + "." + vec[3];
            IP.push_back(temp);
        }
        return IP;
    }
};




class Solution {
public:
    bool check(string s){
        if (s[0] == '0' && s.size() >= 2){
            return false;
        }
        return stoi(s) <= 255;
    }
    string join(vector<string> vec){
        string ret = "";
        for (auto str : vec){
            ret = ret + str + ".";
        }
        return ret.substr(0, ret.size() - 1);
    }
    void helper(string s, vector<string>& ret, vector<string>& path, int index){
        if (path.size() == 4){
            
            if (index == s.size()){
                string ip = join(path);
                ret.push_back(ip);
            }
            return;
        }
        for (int i = index; i < index + 3 && i < s.size(); i++){
            string temp = s.substr(index, i - index + 1);
            if (check(temp)){
                path.push_back(temp);
                helper(s,ret,path,i + 1);
                path.pop_back();
            }
        }
        return;
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        vector<string> path;
        int index = 0;
        helper(s,ret,path,index);
        return ret;

    }
};