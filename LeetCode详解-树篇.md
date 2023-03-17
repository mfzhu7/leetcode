# LeetCode详解-树篇



[toc]



## leetcode94(迭代法待实现)

[二叉树的中序遍历](https://leetcode.cn/problems/binary-tree-inorder-traversal/)

> 树相关，中序遍历，递归。

```c++
输入：root = [1,null,2,3]
输出：[1,3,2]
```

```c++
class Solution {
public:
    void help(TreeNode* root, vector<int> &res){
            if(root == nullptr) return ;
            help(root->left, res);
            res.push_back(root->val);
            help(root->right, res);
            return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
            vector<int> res;
            help(root, res);
            return res;
    }
```

## leetcode95

[ 不同的二叉搜索树 II](https://leetcode.cn/problems/unique-binary-search-trees-ii/)

> 递归+树结构

```c++
输入：n = 3
输出：[[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
```



```c++
class Solution {
public:
    vector<TreeNode*> generateTrees(int start, int end){
        if (start > end){
            return {nullptr} ;
        }
        vector<TreeNode*> allTreeNodes;
        for (int i = start; i <= end; i++){
            vector<TreeNode*> left = generateTrees(start, i - 1);
            vector<TreeNode*> right = generateTrees(i + 1, end);

            for (auto& l: left){
                for (auto& r: right){
                    TreeNode* curr = new TreeNode(i);
                    curr->left = l;
                    curr->right = r;
                    allTreeNodes.push_back(curr);
                }
            }
        }
        return allTreeNodes;
    }
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1, n);
    }
```

## leetcode96

[不同的二叉搜索树](不同的二叉搜索树)

> 树+动态规划

```c++
输入：n = 3
输出：5
```

```c++
class Solution {
public:
    
    int numTrees(int n) {
        vector<int> vec(n + 1,0);
        vec[0]= 1;
        vec[1] = 1;
        for (int i = 2; i <= n; i++ ){
            for (int j = 1; j <= i; j++){
                vec[i] += vec[j - 1] * vec[i - j];
            }
        }
        return vec[n];

    }
};
```

## leetcode98(中序遍历待实现)

[验证二叉搜索树](https://leetcode.cn/problems/validate-binary-search-tree/)

> 树+递归

```c++
输入：root = [2,1,3]
输出：true
```



```c++
class Solution {
public:
    bool helper(TreeNode* node, long long lower, long long upper){
        if (!node) return true;
        if (node->val <= lower || node->val >= upper) return false;
        return helper(node->left,lower,node->val) && helper(node->right,node->val, upper);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};
```

## leetcode99(待完善)

[恢复二叉搜索树](https://leetcode.cn/problems/recover-binary-search-tree/)

> 递归+树

```c++
输入：root = [1,3,null,null,2]
输出：[3,1,null,null,2]
解释：3 不能是 1 的左孩子，因为 3 > 1 。交换 1 和 3 使二叉搜索树有效。
```



```c++
class Solution {
public:
    void help(TreeNode* node, vector<TreeNode*>& path){
        if(!node) return;
        help(node->left, path);
        path.push_back(node);
        help(node->right, path);
        return;
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> vec;
        help(root, vec);
        vector<int> place;
        for(int i = 0; i < vec.size() - 1; i++){
            if (vec[i]->val > vec[i + 1]->val){
                place.push_back(i);
            }

        }
        int sec = (place.size() == 2) ? place[1] + 1 : place[0] + 1;
        int temp = vec[place[0]]->val;
        vec[place[0]]->val = vec[sec]->val; 
        vec[sec]->val = temp;
        return ;

    }
```

## leetcode100

[相同的树](https://leetcode.cn/problems/same-tree/description/)

> 树+递归

```c++
输入：p = [1,2,3], q = [1,2,3]
输出：true
```



```c++
class Solution {
public:
    bool help(TreeNode* left, TreeNode* right){
        if (!left && !right) return true;
        if (!left || !right) return false;
        return (left->val == right->val) && help(left->left, right->left) && help(left->right, right->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return help(p,q);
    }
};
```