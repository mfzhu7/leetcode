class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hash1;
        unordered_set<int> hash2;
        vector<int> ans;


        for (int i = 0; i < nums1.size(); i++){
            hash1.insert(nums1[i]);
        }
        for (int i = 0; i < nums2.size(); i++){
            hash2.insert(nums2[i]);
        }

        for(auto it = hash1.begin(); it != hash1.end(); it++){
            if (hash2.find(*it) != hash1.end()){
                ans.push_back(*it);
            }
        }
        return ans;

    }
};


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        vector<int> ans;     
        unordered_set<int> hash1{nums1.begin(), nums1.end()};
        unordered_set<int> hash2{nums2.begin(), nums2.end()};

        for(auto it = hash1.begin(); it != hash1.end(); it++){
            if (hash2.find(*it) != hash1.end()){
                ans.push_back(*it);
            }
        }
        return ans;

    }
};