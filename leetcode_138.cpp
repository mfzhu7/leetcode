class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* h1 = head;
        unordered_map<Node*, Node*> hash;
        while(h1){
            Node* temp = new Node(h1->val);
            hash.insert({h1,temp});
            h1 = h1->next;
        }
        h1 = head;
        while(h1){
            hash[h1]->next = hash[h1->next];
            hash[h1]->random = hash[h1->random];
            h1 = h1->next;
        }
        return hash[head];
    }
};