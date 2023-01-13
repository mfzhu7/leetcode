class Solution {
public:
    void helper(TreeNode* node, vector<int>& path){
        if (!node) return;
        helper(node->left, path);
        path.push_back(node->val);
        helper(node->right, path);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> path;
        helper(root, path);
        return path[k - 1];
    }
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;

        while(root != nullptr || !stk.empty()){
            while(root != nullptr){
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            k--;
            if (k == 0) break;
            root = root->right;
        }
        return root->val;

    }
};