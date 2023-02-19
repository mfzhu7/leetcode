class Solution {
public:
    void helper(TreeNode* root, int& sum, bool pos){
        if(!root){
            return;
        }
        if(pos && !root->left && !root->right){
            sum += root->val;
            return;
        }
        helper(root->left, sum, true);
        helper(root->right, sum, false);

        return;

    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        helper(root, ans, false);
        return ans;
    }
};