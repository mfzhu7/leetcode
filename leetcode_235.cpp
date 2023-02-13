class Solution {
public:
    vector<TreeNode*> getPath(TreeNode* root, TreeNode* p){
        vector<TreeNode*> path;
        while(root){
            path.push_back(root);
            if(root->val > p->val){
                root = root->left;
            } else if (root->val < p->val){
                root = root->right;
            } else {
                break;
            }
        }
        return path;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1 = getPath(root, p);
        vector<TreeNode*> path2 = getPath(root, q);

        int l1 = path1.size() - 1;
        int l2 = path2.size() - 1;
        TreeNode* ancestor;
        for (int i = 0; i <= l1 && i <= l2; i++){
            if(path1[i] == path2[i]){
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
        TreeNode* ancestor;
        while(root){
            if(root->val > p->val && root->val > q->val){
                root = root->left;
            } else if (root->val < p->val && root->val < q->val){
                root = root->right;
            } else {
                ancestor = root;
                break;
            }
        }
        return ancestor;
        
    }
};