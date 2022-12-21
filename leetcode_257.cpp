class Solution {
public:
    void helper(TreeNode* root, vector<string>& ret, string path){
        if (!root) return;
        if (!root->left && !root->right){
            path = path + to_string(root->val);
            ret.push_back(path);
            return;
        }
        path = path + to_string(root->val);
        path = path + "->";
        helper(root->left, ret, path);
        helper(root->right, ret, path);
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        string path;
        helper(root, ret, path);
        return ret;
    }
};