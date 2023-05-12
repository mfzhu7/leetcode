# LeetCode详解-树篇

[toc]



## LeetCode94(迭代法待实现)

[二叉树的中序遍历](https://leetcode.cn/problems/binary-tree-inorder-traversal/)

**题干**

给定一个二叉树的根节点 `root` ，返回 *它的 **中序** 遍历*

![img](https://assets.leetcode.com/uploads/2020/09/15/inorder_1.jpg)

**样例**

```c++
输入：root = [1,null,2,3]
输出：[1,3,2]
```



**解题思路**

- 树的中序遍历，使用递归
- 先左再中后右
- 非递归的做法，在于维护一个栈来实现，迭代实现

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
}
//非递归写法
  class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        while(root != nullptr || !stk.empty()){
            while(root != nullptr){
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;

    }
};
```

## LeetCode95

[ 不同的二叉搜索树 II](https://leetcode.cn/problems/unique-binary-search-trees-ii/)

**题干**

给你一个整数 `n` ，请你生成并返回所有由 `n` 个节点组成且节点值从 `1` 到 `n` 互不相同的不同 **二叉搜索树** 。可以按 **任意顺序** 返回答案。



![img](https://assets.leetcode.com/uploads/2021/01/18/uniquebstn3.jpg)



**样例**

```c++
输入：n = 3
输出：[[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
```

**解题思路**

- 使用递归的思路来解这个题
- 遍历[1,n]之间的所有切分点，每个切分点作为根节点
- 则[1,j]为左子树的节点，j节点为根节点，[j + 1, n]为右子树的节点
- 递归保证左子树的节点和右子树的节点也是二叉搜索树即可



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

[不同的二叉搜索树](https://leetcode.cn/problems/unique-binary-search-trees/)

**题干**

给你一个整数 `n` ，求恰由 `n` 个节点组成且节点值从 `1` 到 `n` 互不相同的 **二叉搜索树** 有多少种？返回满足题意的二叉搜索树的种数。

![img](https://assets.leetcode.com/uploads/2021/01/18/uniquebstn3.jpg)

**样例**

```c++
输入：n = 3
输出：5
```

**解题思路**
$$
我们定义如下：\\
1.G(n):\\
2.F(i,n):\\
$$











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

**题干**

给你一个二叉树的根节点 `root` ，判断其是否是一个有效的二叉搜索树。

**有效** 二叉搜索树定义如下：

- 节点的左子树只包含 **小于** 当前节点的数。
- 节点的右子树只包含 **大于** 当前节点的数。
- 所有左子树和右子树自身必须也是二叉搜索树。



![img](https://assets.leetcode.com/uploads/2020/12/01/tree2.jpg)

**示例**

```c++
输入：root = [5,1,4,null,null,3,6]
输出：false
解释：根节点的值是 5 ，但是右子节点的值是 4 。
```

**解题思路**

- 新建一个辅助函数，辅助函数中包含左右节点上下边界
- 不断递归的判断左右节点是否符合搜索树的要求
- 当然也可以进行中序遍历，在遍历过程中，判断存储的遍历路径是否是递增的

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

**题干**

给你二叉搜索树的根节点 `root` ，该树中的 **恰好** 两个节点的值被错误地交换。*请在不改变其结构的情况下，恢复这棵树* 。

![img](https://assets.leetcode.com/uploads/2020/10/28/recover1.jpg)

**示例**

```c++
输入：root = [1,3,null,null,2]
输出：[3,1,null,null,2]
解释：3 不能是 1 的左孩子，因为 3 > 1 。交换 1 和 3 使二叉搜索树有效。
```

**解题思路**

- 二叉搜索树在中序遍历的情况下是递增的；如果存在两个节点交换，即不符合递增规律
- 因此可以进行中序遍历，而后找到不符合规律的节点进行交换



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

**题干**

给你两棵二叉树的根节点 `p` 和 `q` ，编写一个函数来检验这两棵树是否相同。

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

![img](https://assets.leetcode.com/uploads/2020/12/20/ex1.jpg)



**示例**

```c++
输入：p = [1,2,3], q = [1,2,3]
输出：true
```

**解题思路**

- 递归的判断两个树对应的节点是否相同即可
- 首先进行判空处理，同时为空即为TRUE；只有一个为空为FALSE
- 而后递归调用判断当前节点和左右子节点即可
- 也可以同步进行广度优先遍历，遍历过程中判断二者是否是相同的

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

**题干**

给你一个二叉树的根节点 `root` ， 检查它是否轴对称。

![img](https://assets.leetcode.com/uploads/2021/02/19/symtree1.jpg)

**示例**

```c++
输入：root = [1,2,2,3,4,4,3]
输出：true
```

**解题思路**

- 和判断是否相同树的思路类似；
- 差别在于递归判断左右节点的时候，左侧选用右节点和右侧的左节点进行判断即可
- 迭代的方式待实现

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

**题干**

给你二叉树的根节点 `root` ，返回其节点值的 **层序遍历** 。 （即逐层地，从左到右访问所有节点）。

![img](https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg)



**示例**

```c++
输入：root = [3,9,20,null,null,15,7]
输出：[[3],[9,20],[15,7]]
```

**解题思路**

- 利用队列来进行层序遍历
- 具体做法，将当前层节点的遍历存入队列；而后下一层通过遍历队列节点的每个左右节点来得到
- 代码中用了2个队列来分别保存上一层的遍历结果和当前层的结果

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

**题干**

给你二叉树的根节点 `root` ，返回其节点值的 **锯齿形层序遍历** 。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

![img](https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg)



**示例**

```c++
输入：root = [3,9,20,null,null,15,7]
输出：[[3],[20,9],[15,7]]
```



**解题思路**

* 借鉴层序遍历的方式，用栈存储遍历的结果
* 新增遍历flag来决定从左到右还是从右到左
* 可以使用双端队列来进行遍历，降低操作的复杂度



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

**题干**

给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

**说明:** 叶子节点是指没有子节点的节点。

**示例：**
给定二叉树 `[3,9,20,null,null,15,7]`，

```
    3
   / \
  9  20
    /  \
   15   7
```

返回它的最大深度 3 。

**解题思路** 

- 递归求解
- 层序遍历，层的遍历次数即为最大深度

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

**题干**

给定两个整数数组 `preorder` 和 `inorder` ，其中 `preorder` 是二叉树的**先序遍历**， `inorder` 是同一棵树的**中序遍历**，请构造二叉树并返回其根节点。

![img](https://assets.leetcode.com/uploads/2021/02/19/tree.jpg)



**示例**

```c++
输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
输出: [3,9,20,null,null,15,7]
```

**解题思路**

- 递归的求解方式
- 先序遍历节点3可以将中序遍历中的节点分为左右两个子树的遍历结果
- 在左右子树内递归求解即可
- 迭代的求解方式待实现

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

**题干**

给定两个整数数组 `inorder` 和 `postorder` ，其中 `inorder` 是二叉树的中序遍历， `postorder` 是同一棵树的后序遍历，请你构造并返回这颗 *二叉树* 。

 ![img](https://assets.leetcode.com/uploads/2021/02/19/tree.jpg)



**示例**

```c++
输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
输出：[3,9,20,null,null,15,7]
```

**解题思路**

- 将后续遍历从尾部开始遍历，即和上一题的先序遍历类似
- 需要注意左右子树的建立，此处需要先建立右子树，再建立左子树
- 迭代的方式待实现



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

**题干**

给你二叉树的根节点 `root` ，返回其节点值 **自底向上的层序遍历** 。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

![img](https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg)



**示例**

```c++
输入：root = [3,9,20,null,null,15,7]
输出：[[15,7],[9,20],[3]]
```

**解题思路**

- 层序遍历的变种
- 自顶向下层序遍历完成后，进行反转即可得到答案

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

**题干**

给你一个整数数组 `nums` ，其中元素已经按 **升序** 排列，请你将其转换为一棵 **高度平衡** 二叉搜索树。

**高度平衡** 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。

![img](https://assets.leetcode.com/uploads/2021/02/18/btree1.jpg)



**示例**

```c++
输入：nums = [-10,-3,0,5,9]
输出：[0,-3,9,-10,null,5]
解释：[0,-10,5,null,-3,null,9] 也将被视为正确答案：
```

**解题思路**

- 每次从数组的中间挑选作为根节点，数组左右两侧的数据即为左右子树
- 在左右子树数据上按照相同的方式递归建立树



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

**题干**

给定一个单链表的头节点  `head` ，其中的元素 **按升序排序** ，将其转换为高度平衡的二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树*每个节点* 的左右两个子树的高度差不超过 1。

![img](https://assets.leetcode.com/uploads/2020/08/17/linked.jpg)

**示例**

```c++
输入: head = [-10,-3,0,5,9]
输出: [0,-3,9,-10,null,5]
解释: 一个可能的答案是[0，-3,9，-10,null,5]，它表示所示的高度平衡的二叉搜索树。
```

**解题思路**

- 取巧的方式是将链表数据存储，使用108题的解题方式即可。
- 待完善

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

**题干**

给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

> 一个二叉树*每个节点* 的左右两个子树的高度差的绝对值不超过 1 。



![img](https://assets.leetcode.com/uploads/2020/10/06/balance_1.jpg)



**示例**

```c++
输入：root = [3,9,20,null,null,15,7]
输出：true
```

**解题思路**

- 开发计算树深度的子函数
- 判断左右节点高度差是否<=1，并且递归调用判断左右子树是不是平衡二叉树
- 可以改变子函数调用方式，自底向上调用，避免多次重复调用，降低复杂度

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

**题干**

给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

**说明：**叶子节点是指没有子节点的节点。

![img](https://assets.leetcode.com/uploads/2020/10/12/ex_depth.jpg)

**示例**

```c++
输入：root = [3,9,20,null,null,15,7]
输出：2
```

**解题思路**

- 递归
- 广度优先搜索



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

**题干**

给你二叉树的根节点 `root` 和一个表示目标和的整数 `targetSum` 。判断该树中是否存在 **根节点到叶子节点** 的路径，这条路径上所有节点值相加等于目标和 `targetSum` 。如果存在，返回 `true` ；否则，返回 `false` 。

**叶子节点** 是指没有子节点的节点。

![img](https://assets.leetcode.com/uploads/2021/01/18/pathsum1.jpg)



**示例**

```c++
输入：root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
输出：true
解释：等于目标和的根节点到叶节点路径如上图所示。
```

**解题思路**

- 开发辅助函数，记录当前遍历节点和路径和
- 设置各种递归调用返回的条件，以及进行递归调用



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

**题干**

给你二叉树的根节点 `root` 和一个整数目标和 `targetSum` ，找出所有 **从根节点到叶子节点** 路径总和等于给定目标和的路径。

**叶子节点** 是指没有子节点的节点。

![img](https://assets.leetcode.com/uploads/2021/01/18/pathsumii1.jpg)



**示例**

```c++
输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
输出：[[5,4,11,2],[5,8,4,5]]
```

**解题思路**

- 开发辅助函数，记录当前的遍历路径，和结果路径
- 如果是目标路径结果，记录到结果路径中
- 注意的是每次push数据后，也有pop数据

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

**题干**

给你二叉树的根结点 `root` ，请你将它展开为一个单链表：

- 展开后的单链表应该同样使用 `TreeNode` ，其中 `right` 子指针指向链表中下一个结点，而左子指针始终为 `null` 。
- 展开后的单链表应该与二叉树 [**先序遍历**](https://baike.baidu.com/item/先序遍历/6442839?fr=aladdin) 顺序相同。

 ![img](https://assets.leetcode.com/uploads/2021/01/14/flaten.jpg)**示例**

```c++
输入：root = [1,2,5,3,4,null,6]
输出：[1,null,2,null,3,null,4,null,5,null,6]
```

**解题思路**

- 先序遍历把树进行遍历存储
- 对于存储的节点进行左右子树的连接变更

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

**题干**

给定一个 **完美二叉树** ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

```
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
```

填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 `NULL`。

初始状态下，所有 next 指针都被设置为 `NULL`。

![img](https://assets.leetcode.com/uploads/2019/02/14/116_sample.png)



**示例**

```c++
输入：root = [1,2,3,4,5,6,7]
输出：[1,#,2,3,#,4,5,6,7,#]
解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。序列化的输出按层序遍历排列，同一层节点由 next 指针连接，'#' 标志着每一层的结束。
```

**解题思路**

- 层序遍历树
- 每次层序遍历结束，对于同一层的数据进行链接即可
- 新方法待实现

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

**题干**

给定一个二叉树：

```
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
```

填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 `NULL` 。

初始状态下，所有 next 指针都被设置为 `NULL` 。

 ![img](https://assets.leetcode.com/uploads/2019/02/15/117_sample.png)



**示例**

```c++
输入：root = [1,2,3,4,5,null,7]
输出：[1,#,2,3,#,4,5,7,#]
解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。序列化输出按层序遍历顺序（由 next 指针连接），'#' 表示每层的末尾。
```

**解题思路**

- 层序遍历法同上一题
- bfs方法待实现

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

**题干**

给你一个二叉树的根节点 `root` ，树中每个节点都存放有一个 `0` 到 `9` 之间的数字。

每条从根节点到叶节点的路径都代表一个数字：

- 例如，从根节点到叶节点的路径 `1 -> 2 -> 3` 表示数字 `123` 。

计算从根节点到叶节点生成的 **所有数字之和** 。

**叶节点** 是指没有子节点的节点。

![img](https://assets.leetcode.com/uploads/2021/02/19/num1tree.jpg)



**示例**

```c++
输入：root = [1,2,3]
输出：25
解释：
从根到叶子节点路径 1->2 代表数字 12
从根到叶子节点路径 1->3 代表数字 13
因此，数字总和 = 12 + 13 = 25
```

**解题思路**

- 记录每条从根节点到叶子节点路径形成的数字，最后对所有的数据相加即可
- 注意在辅助函数中，每加一层，当前值*10+节点值；在左右节点遍历结束后，需要恢复到原始值；

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



## LeetCode144

[二叉树的前序遍历](https://leetcode.cn/problems/binary-tree-preorder-traversal/)

**题干**

给你二叉树的根节点 `root` ，返回它节点值的 **前序** 遍历。

![img](https://assets.leetcode.com/uploads/2020/09/15/inorder_1.jpg)

**示例**

```c++
输入：root = [1,null,2,3]
输出：[1,2,3]
```

```c++
class Solution {
public:
    void help(TreeNode* root, vector<int>& path){
        if(!root) return;
        path.push_back(root->val);
        help(root->left, path);
        help(root->right,path);
        return;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>res;
        help(root,res);
        return res;
    }
};
```





## LeetCode145

[ 二叉树的后序遍历](https://leetcode.cn/problems/binary-tree-postorder-traversal/)

**题干**

给你一棵二叉树的根节点 `root` ，返回其节点值的 **后序遍历** 。

![img](https://assets.leetcode.com/uploads/2020/08/28/pre1.jpg)

**示例**

```c++
输入：root = [1,null,2,3]
输出：[3,2,1]
```



```c++
class Solution {
public:
    void help(TreeNode* root, vector<int>& path){
        if(!root) return;
        help(root->left,path);
        help(root->right,path);
        path.push_back(root->val);
        return;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        help(root,res);
        return res;
    }
};
```



## LeetCode199

[二叉树的右视图](https://leetcode.cn/problems/binary-tree-right-side-view/)

**题干**

给定一个二叉树的 **根节点** `root`，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。



![img](https://assets.leetcode.com/uploads/2021/02/14/tree.jpg)

**示例**

```c++
输入: [1,2,3,null,5,null,4]
输出: [1,3,4]
```

**解题思路**

* 层序遍历每次的末尾进行保存即可
* 广度优先搜索待实现

```c++
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        queue<TreeNode*> q;
        vector<int> level;
        int size = 1;
        q.push(root);
        while(!q.empty()){
            int temp = 0;
            for (int i = 0; i < size; i++){
                level.push_back(q.front()->val);
                if(q.front()->left) { q.push(q.front()->left); temp += 1;}
                if(q.front()->right) { q.push(q.front()->right); temp += 1;}
                q.pop();
            }
            res.push_back(level[level.size() - 1]);
            level.clear();
            size = temp;
        }
        return res;
    }
};
```



## LeetCode222

[完全二叉树的节点个数](https://leetcode.cn/problems/count-complete-tree-nodes/)

**题干**

给你一棵 **完全二叉树** 的根节点 `root` ，求出该树的节点个数。

[完全二叉树](https://baike.baidu.com/item/完全二叉树/7773232?fr=aladdin) 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 `h` 层，则该层包含 `1~ 2h` 个节点。

![img](https://assets.leetcode.com/uploads/2021/01/14/complete.jpg)

**示例**

```c++
输入：root = [1,2,3,4,5,6]
输出：6
```

**解题思路**

- 待完成

```c++
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
```



## LeetCode226 

[翻转二叉树](https://leetcode.cn/problems/invert-binary-tree/)

**题干**

给你一棵二叉树的根节点 `root` ，翻转这棵二叉树，并返回其根节点。

![img](https://assets.leetcode.com/uploads/2021/03/14/invert1-tree.jpg)

**示例**

```c++
输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]
```

**解题思路**

- 递归求解

```c++
class Solution {
public:

    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
```





## LeetCode230 

[二叉搜索树中第K小的元素](https://leetcode.cn/problems/kth-smallest-element-in-a-bst/)

**题干**

给定一个二叉搜索树的根节点 `root` ，和一个整数 `k` ，请你设计一个算法查找其中第 `k` 个最小元素（从 1 开始计数）。

![img](https://assets.leetcode.com/uploads/2021/01/28/kthtree1.jpg)

**示例**

```c++
输入：root = [3,1,4,null,2], k = 1
输出：1
```

**解题思路**

- 二叉搜索树，中序遍历是递增的
- 中序遍历到第k个元素即为目标值


```c++
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
```



## LeetCode235

[二叉搜索树的最近公共祖先](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/)

**题干**

给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

[百度百科](https://baike.baidu.com/item/最近公共祖先/8918834?fr=aladdin)中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（**一个节点也可以是它自己的祖先**）。”

例如，给定如下二叉搜索树: root = [6,2,8,0,4,7,9,null,null,3,5]

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/binarysearchtree_improved.png)

**示例**

```c++
输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
输出: 6 
解释: 节点 2 和节点 8 的最近公共祖先是 6。
```

**解题思路**

- 利用二叉搜索树的性质；如果当前节点值均大于p和q，则公共祖先在其左侧
- 均小于的情况，则在右侧；最后分散两侧，则为目标公共祖先节点
- 两次遍历解法待实现


```c++
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
```





## LeetCode236

[二叉树的最近公共祖先](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/)

**题干**

给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

[百度百科](https://baike.baidu.com/item/最近公共祖先/8918834?fr=aladdin)中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（**一个节点也可以是它自己的祖先**）。”

 

![img](https://assets.leetcode.com/uploads/2018/12/14/binarytree.png)

**示例**


```c++
输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出：3
解释：节点 5 和节点 1 的最近公共祖先是节点 3 。
```

**解题思路**

- 待实现

```c++
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
```



## LeetCode257

[二叉树的所有路径](https://leetcode.cn/problems/binary-tree-paths/)

**题干**

给你一个二叉树的根节点 `root` ，按 **任意顺序** ，返回所有从根节点到叶子节点的路径。

**叶子节点** 是指没有子节点的节点。

![img](https://assets.leetcode.com/uploads/2021/03/12/paths-tree.jpg)

**示例**

```c++
输入：root = [1,2,3,null,5]
输出：["1->2->5","1->3"]
```

**题解**

- 深度优先搜索
- 广度优先搜索待实现

```c++
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
```





## LeetCode331

[验证二叉树的前序序列化](https://leetcode.cn/problems/verify-preorder-serialization-of-a-binary-tree/)

**题干**

序列化二叉树的一种方法是使用 **前序遍历** 。当我们遇到一个非空节点时，我们可以记录下这个节点的值。如果它是一个空节点，我们可以使用一个标记值记录，例如 `#`。

![img](https://assets.leetcode.com/uploads/2021/03/12/pre-tree.jpg)

例如，上面的二叉树可以被序列化为字符串 `"9,3,4,#,#,1,#,#,2,#,6,#,#"`，其中 `#` 代表一个空节点。

给定一串以逗号分隔的序列，验证它是否是正确的二叉树的前序序列化。编写一个在不重构树的条件下的可行算法。

**保证** 每个以逗号分隔的字符或为一个整数或为一个表示 `null` 指针的 `'#'` 。

你可以认为输入格式总是有效的

- 例如它永远不会包含两个连续的逗号，比如 `"1,,3"` 。

**注意：**不允许重建树。

**示例**

```c++
输入: preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#"
输出: true
```

**解题思路**

- 待实现



```c++
class Solution {
public:
    bool isValidSerialization(string preorder) 
    {
        vector<string> stk;         // 使用一个数组模拟栈
        stringstream ss(preorder);  // 使用 stringstream与getline 分割字符串
        string temp;
        // getline（输入流，暂存从流中读取的字符串，读取终止符）
        while (getline(ss, temp, ','))
        {
            stk.push_back(temp);
            int len = stk.size();
            // 用「#」替换 「数字##」
            while (len >= 3 && stk[len - 1] == "#" && stk[len - 2] == "#" && stk[len - 3] != "#")
            {
                stk.pop_back();
                stk.pop_back();
                stk.pop_back();
                stk.push_back("#");
                len = stk.size();
            }
        }
        // 如果最后模拟栈中只剩一个#，说明是合法的序列
        return stk.size() == 1 && stk[0] == "#";
    }
};
```



## LeetCode404

[左叶子之和](https://leetcode.cn/problems/sum-of-left-leaves/)

**题干**

给定二叉树的根节点 `root` ，返回所有左叶子之和。

![img](https://assets.leetcode.com/uploads/2021/04/08/leftsum-tree.jpg)

**示例**

```c++
输入: root = [3,9,20,null,null,15,7] 
输出: 24 
解释: 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
```

**解题思路**

- 待实现

```c++
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
```



## LeetCode429

[N 叉树的层序遍历](https://leetcode.cn/problems/n-ary-tree-level-order-traversal/)

**题干**

给定一个 N 叉树，返回其节点值的*层序遍历*。（即从左到右，逐层遍历）。

树的序列化输入是用层序遍历，每组子节点都由 null 值分隔（参见示例）。

![img](https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png)

**示例**

```c++
输入：root = [1,null,3,2,4,null,5,6]
输出：[[1],[3,2,4],[5,6]]
```

**解题思路**

- 参考层序遍历方式

```c++
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root){
            return {};
        }
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int cnt = q.size();
            vector<int> level;
            for (int i = 0; i < cnt; i++){
                Node* curr = q.front();
                q.pop();
                level.push_back(curr->val);
                for (auto it: curr->children){
                    q.push(it);
                }
            }
            ans.push_back(move(level));
        }
        return ans;
        
    }
};
```

