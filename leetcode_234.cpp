class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> vec;
        while(head){
            vec.push_back(head->val);
            head = head->next;
        }
        int left = 0;
        int right = vec.size() - 1;
        while(left < right){
            if (vec[left] != vec[right]) return false;
            left = left + 1;
            right = right - 1;
        }
        return true;

    }
};