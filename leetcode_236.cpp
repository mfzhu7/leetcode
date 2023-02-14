class Solution {
public:
    bool getPath(TreeNode* root, TreeNode* p, vector<TreeNode*>& path){
        if (!root) return false;
        path.push_back(root);
        bool found = false;
        if(root->val == p->val) return true;
        if (!found && root->left){
            found = getPath(root->left, p, path);
        }
        if (!found && root->right){
            found = getPath(root->right, p, path);
        }
        if(!found) path.pop_back();
        return found;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;

        getPath(root, p, path1);
        getPath(root, q, path2);

        TreeNode* ancestor;
        int l1 = path1.size();
        int l2 = path2.size();

        for (int i = 0; i < l1 && i < l2; i++){
            if (path1[i] == path2[i]){
                ancestor = path1[i];
            } else {
                break;
            }
        }
        return ancestor;
        
    }
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || p == root || q == root){
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left == nullptr && right == nullptr){
            return nullptr;
        }
        if(left == nullptr){
            return right;
        }
        if(right == nullptr){
            return left;
        }
        return root;
        
    }
};