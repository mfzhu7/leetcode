class Solution {
public:
    void deleteNode(ListNode* node) {
        while(node->next){
            if (node->next->next == nullptr){
                node->val = node->next->val;
                node->next = nullptr;
                break;

            } else {
                node->val = node->next->val;
                node = node->next;
            }

        }
        return;
    }
};