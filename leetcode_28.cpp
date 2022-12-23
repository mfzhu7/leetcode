class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> index;
        int ret = 0;
        for (int i = 0; i < haystack.size(); i++){
            if (haystack[i] == needle[0]) index.push_back(i);
        }
        for (auto i: index){
            if (haystack.substr(i, needle.size()) == needle){
                ret = i;
                return ret;
            }
        }
        return -1;

    }
};

//kmp算法需要了解