class BSTIterator {
public:
    void inorder(TreeNode* root, vector<int>& ret){
        if (!root) return;
        inorder(root->left, ret);
        ret.push_back(root->val);
        inorder(root->right,ret);
        return;
    }
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> ret;
        inorder(root, ret);
        return ret;
    }
    vector<int> arr;
    int idx;

    BSTIterator(TreeNode* root): idx(0), arr(inorderTraversal(root)) {}
    
    int next() {
        return arr[idx++];
    }
    
    bool hasNext() {
        return idx < arr.size();
    }
};

class BSTIterator {
public:
    stack<TreeNode*> stk;
    TreeNode* curr;
    BSTIterator(TreeNode* root): curr(root) {

    }
    
    int next() {
        while(curr){
            stk.push(curr);
            curr = curr->left;
        }
        curr = stk.top();
        int ret = curr->val;
        stk.pop();
        curr = curr->right;
        return ret;
    }
    
    bool hasNext() {
        return curr != nullptr || !stk.empty();
    }
};