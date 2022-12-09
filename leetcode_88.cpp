class Solution {
public:
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int curr = nums1.size() - 1;
    int index1 = m - 1;
    int index2 = n - 1;
    while(index2 >= 0){
        if (index1 >= 0 && nums1[index1] >= nums2[index2]){
            nums1[curr] = nums1[index1];
            index1 = index1 - 1;
            curr = curr - 1;
        } else{
            nums1[curr] = nums2[index2];
            curr = curr - 1;
            index2 = index2 - 1;
        }
    }
}
};


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res(m + n, 0);
        int index_m = 0;
        int index_n = 0;
        int curr;
        while(index_m < m || index_n < n){
            if (index_m == m){
                curr = nums2[index_n];
                index_n = index_n + 1;
            } else if (index_n == n){
                curr = nums1[index_m];
                index_m = index_m + 1;
            } else if (nums1[index_m] > nums2[index_n]){
                curr = nums2[index_n];
                index_n = index_n + 1;
            } else {
                curr = nums1[index_m];
                index_m = index_m + 1;
            }
            res[index_m + index_n - 1] = curr; 
        }
        for (int i = 0; i < m + n; i++){
            nums1[i] = res[i];
        } 

    }
};