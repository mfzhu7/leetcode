/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        odd->next = nullptr;

        ListNode* curr1 = odd;
        ListNode* curr2 = even;
        ListNode* curr = even->next;
        even->next = nullptr;
        int pos = 1;
        while(curr){
            if(pos % 2){
                curr1->next = curr;
                curr = curr->next;
                curr1 = curr1->next;
                curr1->next = nullptr;
            } else {
                curr2->next = curr;
                curr = curr->next;
                curr2 = curr2->next;
                curr2->next = nullptr;
            }
            pos++;         
        }
        curr1->next = even;
        return odd;
    }
};


class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* eventHead = even;
        while(even && even->next){
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = eventHead;
        return head;

    }
};