class Solution {
public:
    int compareVersion(string version1, string version2) {

        int idx1 = 0;
        int idx2 = 0;
        int length1 = version1.size();
        int length2 = version2.size();

        while(idx1 < length1 || idx2 < length2){
            int s1 = idx1;
            int s2 = idx2;
            while(idx1 < length1 && version1[idx1] != '.') { idx1++;}
            while(idx2 < length2 && version2[idx2] != '.') { idx2++;}
            string str1 = (idx1 == s1) ? "0" : version1.substr(s1, idx1 - s1);
            string str2 = (idx2 == s2) ? "0" : version2.substr(s2, idx2 - s2);

            int num1 = stoi(str1);
            int num2 = stoi(str2);
            if (num1 != num2) { return (num1 > num2) ? 1: -1; }
            idx1 = (idx1 < length1) ? idx1 + 1: idx1;
            idx2 = (idx2 < length2) ? idx2 + 1: idx2;
        }
        return 0;
    }
};


class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1;
        vector<int> v2;
        stringstream  ss;
        string s;
        ss << version1;
        while(getline(ss, s, '.')){
            v1.push_back(stoi(s));
        }
        ss.clear();

        ss << version2;
        while(getline(ss, s, '.')){
            v2.push_back(stoi(s));
        }
        while(v1.size() < v2.size()) v1.push_back(0);
        while(v2.size() < v1.size()) v2.push_back(0);

        for (int i = 0; i < v1.size(); i++){
            if (v1[i] > v2[i]) return 1;
            else if (v1[i] < v2[i]) return -1;
        }
        return 0;


    }
};