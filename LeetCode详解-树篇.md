# LeetCode详解-树篇

[toc]



## LeetCode94(迭代法待实现)

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

## LeetCode95

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

## LeetCode96

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

## LeetCode98(中序遍历待实现)

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

## LeetCode99(待完善)

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

## LeetCode100

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





## LeetCode101(迭代待实现)

[对称二叉树](https://leetcode.cn/problems/symmetric-tree/)

> 递归+树结构

```c++
输入：root = [1,2,2,3,4,4,3]
输出：true
```



```c++
class Solution {
public:
    bool help(TreeNode* left, TreeNode* right){
            if (!left && !right) return true;
            if (!left || !right) return false;
            if (left->val != right->val) return false;

            return  help(left->right, right->left) && help(left->left, right->right);

    }
    bool isSymmetric(TreeNode* root) {
            return help(root->left, root->right);
    }
```



## LeetCode102

[ 二叉树的层序遍历](https://leetcode.cn/problems/binary-tree-level-order-traversal/)

> 树结构+队列解答(广度优先遍历)

```c++
输入：root = [3,9,20,null,null,15,7]
输出：[[3],[9,20],[15,7]]
```



```c++
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> old_q;
        queue<TreeNode*> new_q;
        vector<int> level;
        old_q.push(root);
        level.push_back(root->val);
        res.push_back(level);
        level.clear();
        while(!old_q.empty() || !new_q.empty()){
            if (old_q.empty()){
                res.push_back(level);
                level.clear();
                old_q = new_q;
                queue<TreeNode*> temp;
                new_q = temp;
            } else {
                TreeNode* node = old_q.front();
                if (node->left) {
                    new_q.push(node->left);
                    level.push_back(node->left->val);
                    }
                if (node->right) {
                    new_q.push(node->right);
                    level.push_back(node->right->val);
                }
                old_q.pop();
            }
        }
        return res;

    }
};
```



## LeetCode103

[ 二叉树的锯齿形层序遍历](https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/)

> 树结构+堆栈遍历

```c++
输入：root = [3,9,20,null,null,15,7]
输出：[[3],[20,9],[15,7]]
```



```c++
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        stack<TreeNode*> stk1;
        stack<TreeNode*> stk2;
        stk1.push(root);
        vector<int> level;
        bool flag = true;
        while(!stk1.empty() || !stk2.empty()){
            if (!stk1.empty()){
                while(!stk1.empty() && flag){
                    level.push_back(stk1.top()->val);
                    if (stk1.top()->left)  {stk2.push(stk1.top()->left);}
                    if (stk1.top()->right) {stk2.push(stk1.top()->right);}
                    stk1.pop();
                }
                while(!stk1.empty() && !flag){
                    level.push_back(stk1.top()->val);
                    if (stk1.top()->right)  {stk2.push(stk1.top()->right);}
                    if (stk1.top()->left) {stk2.push(stk1.top()->left);}
                    stk1.pop();
                }
                flag = !flag;
                res.push_back(level);
                level.clear();       
            } else {
                stack<TreeNode*> temp = stk2;
                stk2 = stk1;
                stk1 = temp;
            }
        }
        return res;

    }
};
```



## LeetCode104

[ 二叉树的最大深度](https://leetcode.cn/problems/maximum-depth-of-binary-tree/)

> 树+递归

```c++
给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。
```



```c++
class Solution {
public: 
    int help(TreeNode* node){
            if (!node) return 0;
            return max(help(node->left) + 1, help(node->right) + 1);
    }
    int maxDepth(TreeNode* root) {
            return help(root);
    }
};
```



## LeetCode105(迭代待实现)

[从前序与中序遍历序列构造二叉树](https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

> 树结构+递归

```c++
输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
输出: [3,9,20,null,null,15,7]
```



```c++
class Solution {
public:
    TreeNode* help(vector<int>& preorder, vector<int>& inorder,int& curr, int start, int end){
        if (start > end) return {nullptr};
        TreeNode* node = new TreeNode(preorder[curr]);
        if (start == end) {
            curr = curr + 1;
            return node;
        }
        int place = -1;
        for (int i = start; start <= end; i++){
            if (inorder[i] == preorder[curr]){
                place = i;
                break;
            }
        }
        curr = curr + 1;
        node->left = help(preorder,inorder,curr,start,place - 1);
        node->right = help(preorder,inorder,curr, place + 1, end);
        return node;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int start = 0;
        int end = preorder.size() - 1;
        int curr = 0;
        return help(preorder,inorder,curr,start,end);

    }
};
```



## LeetCode106

[从中序与后序遍历序列构造二叉树](https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)

> 树结构+递归

```c++
输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
输出：[3,9,20,null,null,15,7]
```



```c++
class Solution {
public: 
    TreeNode* help(vector<int>& inorder, vector<int>& postorder, int& curr, int start, int end){
        if (start > end) return {nullptr};
        TreeNode* node = new TreeNode(postorder[curr]);
        if (start == end){
            curr = curr - 1;
            return node;
        }
        int place = -1;
        for (int i = start; start <= end; i++){
            if (inorder[i] == postorder[curr]){
                place = i;
                break;
            }
        }
        curr = curr - 1;
        node->right = help(inorder,postorder,curr,place + 1, end);
        node->left = help(inorder,postorder,curr,start, place - 1);
        return node;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int curr = postorder.size() - 1;
        int start = 0 ;
        int end = postorder.size() - 1;
        TreeNode* res = help(inorder,postorder,curr,start, end);
        return res;
    }
};
```



## LeetCode107

[二叉树的层序遍历 II](https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/)

> 树结构+队列



```c++
输入：root = [3,9,20,null,null,15,7]
输出：[[15,7],[9,20],[3]]
```



```c++
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> level;
        int size = 1;
        while(!q.empty()){
            int temp = 0;
            for (int i = 0; i < size; i++){
                level.push_back(q.front()->val);
                if(q.front()->left) { q.push(q.front()->left); temp += 1;}
                if(q.front()->right) {q.push(q.front()->right); temp += 1;}
                q.pop();
            }
            res.push_back(level);
            level.clear();
            size = temp;
        }
        reverse(res.begin(),res.end());
        return res;

    }
};
```



## LeetCode108

[将有序数组转换为二叉搜索树](https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/)

> 树结构+递归

```c++
输入：nums = [-10,-3,0,5,9]
输出：[0,-3,9,-10,null,5]
解释：[0,-10,5,null,-3,null,9] 也将被视为正确答案：
```



```c++
class Solution {
    public:
    TreeNode* help(vector<int>& nums, int start, int end){
        if (start > end) return {nullptr};
        if(start == end) {
            TreeNode* res = new TreeNode(nums[end]);
            return res;
        }
        int index = (start + end) / 2;
        TreeNode* res = new TreeNode(nums[index]);
        res->left = help(nums, start, index - 1);
        res->right = help(nums, index + 1, end);
        return res;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums){
        return help(nums,0, nums.size() - 1);
    }
} ;
```



## LeetCode109(待完善)

[有序链表转换二叉搜索树](https://leetcode.cn/problems/convert-sorted-list-to-binary-search-tree/)

> 树结构+递归

```c++
输入: head = [-10,-3,0,5,9]
输出: [0,-3,9,-10,null,5]
解释: 一个可能的答案是[0，-3,9，-10,null,5]，它表示所示的高度平衡的二叉搜索树。
```



```c++
class Solution {
public:
    TreeNode* help(vector<int>& nums, int start, int end) {
        if (start > end) return {nullptr};
        if (start == end){
            TreeNode* res = new TreeNode(nums[start]);
            return res;
        }
        int index = (start + end) / 2;
        TreeNode* res = new TreeNode(nums[index]);
        res->left = help(nums,start, index - 1);
        res->right = help(nums, index + 1, end);
        return res;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return {nullptr};
        vector<int> nums;
        while(head){
            nums.push_back(head->val);
            head = head->next;
        }
        return help(nums,0,nums.size() - 1);
    }
};
```



## LeetCode110

[平衡二叉树](https://leetcode.cn/problems/balanced-binary-tree/)

> 树结构+递归

```c++
输入：root = [3,9,20,null,null,15,7]
输出：true
```



```c++
class Solution {
public:
    int height(TreeNode* root){
        if (!root) return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};
```



## LeetCode 111(广度优先搜索待实现)

[二叉树的最小深度](https://leetcode.cn/problems/minimum-depth-of-binary-tree/)

> 树结构+递归解法

```c++
输入：root = [3,9,20,null,null,15,7]
输出：2
```

```c++
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;

        if (!root->left && !root->right) return 1;

        int min_depth = INT_MAX;
        if (root->left){
            min_depth = min(minDepth(root->left), min_depth);
        }
        if (root->right){
            min_depth = min(minDepth(root->right), min_depth);
        }
        return min_depth + 1;

    }
};
```



## LeetCode112(广度优先搜索)

[路径总和](https://leetcode.cn/problems/path-sum/)

> 树结构+递归

```c++
输入：root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
输出：true
解释：等于目标和的根节点到叶节点路径如上图所示。
```



```c++
class Solution {
public:
    bool help(TreeNode* node, int curr, int target){
        if (!node) return false;
        if (!node->left && !node->right && curr + node->val == target) return true;
        if (!node->left && !node->right && curr + node->val != target) return false;

        return help(node->left,curr + node->val, target) || help(node->right, curr + node->val, target);

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        int curr = 0;
        return help(root,curr,targetSum);

    }
};
```





## LeetCode113

[路径总和 II](https://leetcode.cn/problems/path-sum-ii/description/)

> 树结构+递归

```c++
输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
输出：[[5,4,11,2],[5,8,4,5]]
```



```c++
class Solution {
public:
    void help(TreeNode* node, int targetSum,int curr,vector<int>& path, vector<vector<int>>& res){
            if (!node) return;
            path.push_back(node->val);
            if (!node->left && !node->right && curr + node->val == targetSum){
                    res.push_back(path);
                    path.pop_back();
                    return;
            }
            help(node->left,targetSum,curr + node->val,path,res);
            help(node->right,targetSum,curr + node->val, path, res);
            path.pop_back();
            return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
            vector<vector<int>> res;
            vector<int> path;
            int curr = 0;
            help(root,targetSum,curr,path,res);
            return res;
        

    }
};
```





## LeetCode114(待完善)

[ 二叉树展开为链表](https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/)

> 树结构+递归

```c++
输入：root = [1,2,5,3,4,null,6]
输出：[1,null,2,null,3,null,4,null,5,null,6]
```



```c++
class Solution {
public:
    void help(TreeNode* root, vector<TreeNode*>& vec){
        if (!root) return;
        vec.push_back(root);
        help(root->left, vec);
        help(root->right,vec);
        return;
    }
    void flatten(TreeNode* root) {
        if (!root) return;
        vector<TreeNode*> res;
        help(root,res);
        for (int i = 0; i < res.size() - 1; i++){
            res[i]->left = nullptr;
            res[i]->right = res[i + 1];
        }
        res.back()->left = nullptr;
        res.back()->right= nullptr;
        return ;

    }
};
```



## LeetCode116

[填充每个节点的下一个右侧节点指针](https://leetcode.cn/problems/populating-next-right-pointers-in-each-node/)

> 树结构+层序遍历变形



```c++
输入：root = [1,2,3,4,5,6,7]
输出：[1,#,2,3,#,4,5,6,7,#]
解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。序列化的输出按层序遍历排列，同一层节点由 next 指针连接，'#' 标志着每一层的结束。
```



```c++
class Solution {
    public:
    Node* connect(Node* root){
        if (!root) return root;
        queue<Node*> q;
        vector<Node*> level;
        int size = 1;
        q.push(root);
        while(!q.empty()){
            int temp = 0;
            for(int i = 0; i < size; i++){
                level.push_back(q.front());
                if(q.front()->left) { q.push(q.front()->left); temp += 1;}
                if(q.front()->right) { q.push(q.front()->right); temp += 1;}
                q.pop();
            }
            for (int i = 0; i < level.size() - 1; i++){
                level[i]->next = level[i + 1];
            }
            size = temp;
            level.clear();
        }
        return root;
    }
} ;
```



## LeetCode117

[填充每个节点的下一个右侧节点指针 II](https://leetcode.cn/problems/populating-next-right-pointers-in-each-node-ii/)

> 树结构+层序遍历



```c++
输入：root = [1,2,3,4,5,null,7]
输出：[1,#,2,3,#,4,5,7,#]
解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。序列化输出按层序遍历顺序（由 next 指针连接），'#' 表示每层的末尾。
```



```c++
class Solution {
    public:
    Node* connect(Node* root){
        if (!root) return root;
        queue<Node*> q;
        vector<Node*> level;
        int size = 1;
        q.push(root);
        while(!q.empty()){
            int temp = 0;
            for(int i = 0; i < size; i++){
                level.push_back(q.front());
                if(q.front()->left) { q.push(q.front()->left); temp += 1;}
                if(q.front()->right) { q.push(q.front()->right); temp += 1;}
                q.pop();
            }
            for (int i = 0; i < level.size() - 1; i++){
                level[i]->next = level[i + 1];
            }
            level.back()->next = nullptr;
            size = temp;
            level.clear();
        }
        return root;
    }
} ;
```



## LeetCode129

[求根节点到叶节点数字之和](https://leetcode.cn/problems/sum-root-to-leaf-numbers/description/)

> 树的结构+深度优先搜索

```c++
输入：root = [1,2,3]
输出：25
解释：
从根到叶子节点路径 1->2 代表数字 12
从根到叶子节点路径 1->3 代表数字 13
因此，数字总和 = 12 + 13 = 25
```



```c++
class Solution {
public:
    void help(TreeNode* root, int& curr, vector<int>& pathSum){
        if(!root) return;
        if(!root->left && !root->right){
            pathSum.push_back(curr * 10 + root->val);
            return;
        }
        curr = curr * 10 + root->val;
        help(root->left, curr, pathSum);
        help(root->right, curr, pathSum);
        curr = (curr - root->val) / 10;
        return;

    }
    int sumNumbers(TreeNode* root) {
        int curr = 0;
        vector<int> res;
        if(!root) return 0;
        help(root, curr, res);
        int total = 0;
        for (auto &i: res){
            total += i;
        }
        return total;
    }
};
```

