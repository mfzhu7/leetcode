/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode* root, int& num){
        if (!root) return;
        num = num + 1;
        helper(root->left, num);
        helper(root->right, num);
        return ;
    }
    int countNodes(TreeNode* root) {
        int num = 0;
        helper(root, num);
        return num;
    }
};


class Solution {
public:
    int countLevel(TreeNode* root){
        int level = 0;
        while(root){
            level = level + 1;
            root = root->left;
        }
        return level;
    }
    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int left = countLevel(root->left);
        int right = countLevel(root->right);

        if (left == right){
            return countNodes(root->right) + (1 << left);
        } else {
            return countNodes(root->left) + (1 << right);
        }
    }
};