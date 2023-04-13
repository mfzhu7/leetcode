# LeetCode-深度优先遍历篇

[toc]



## Leetcode17

[电话号码的字母组合](https://leetcode.cn/problems/letter-combinations-of-a-phone-number/)

深度优先搜索(DFS)

```c++
输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
```

```c++
class Solution {
public:
    void helper(string digits, map<int, string> hash, int index, vector<string>& res, string path){
        if(path.size() == digits.size()) {
            res.push_back(path);
            return; // 如果已经和代排除的数组一样长了，说明已经搜索到头
        }
        for (int i = 0; i < hash[digits[index] - 48].size(); i++){
            path.push_back(hash[digits[index] - 48][i]);
            helper(digits, hash, index + 1, res, path);
            path.pop_back(); //需要pop掉
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        map<int, string> hash{
            {2, "abc"},
            {3, "def"},
            {4, "ghi"},
            {5, "jkl"},
            {6, "mno"},
            {7, "pqrs"},
            {8, "tuv"},
            {9, "wxyz"},
        };
        vector<string> res;
        if (digits.size() == 0) return res;
        string path = "";
        helper(digits,hash,0,res,path);
        return res;

    }
};
```

## Leetcode 39 

> 深度优先搜索+回溯+剪枝

[组合总数](https://leetcode.cn/problems/combination-sum/)

```c++
输入：candidates = [2,3,6,7], target = 7
输出：[[2,2,3],[7]]
解释：
2 和 3 可以形成一组候选，2 + 2 + 3 = 7 。注意 2 可以使用多次。
7 也是一个候选， 7 = 7 。
仅有这两种组合。
```



```c++
class Solution {
public:
    void helper(vector<int>&candidates, int target, int begin, vector<vector<int>>& res, vector<int>& path, int pathSum){
        if (pathSum == target){
            res.push_back(path);
            return; //当前路径之和等于目标值则存入结果，并且返回
        }
        for (int i = begin; i < candidates.size(); i++){
            if (pathSum + candidates[i] <= target){ //此次过滤掉大于目标值的搜索
                pathSum = pathSum + candidates[i];
                path.push_back(candidates[i]); //推入当前路径记录
                helper(candidates,target,i,res,path,pathSum);
                path.pop_back(); //记得弹出
                pathSum = pathSum - candidates[i];//记得将路径和进行还原
            }
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        int pathSum = 0;
        int begin = 0;
        helper(candidates,target,begin,res,path,pathSum);
        return res;
        //要点在于(1)搜索结束的还原 (2) 非必要搜索的过滤，降低搜索的复杂度
    }
};
```



## Leetcode40 

[组合总和 II](https://leetcode.cn/problems/combination-sum-ii/)

> 深度优先搜索+回溯剪枝

```c++
输入: candidates = [10,1,2,7,6,1,5], target = 8,
输出:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
```



```c++
class Solution {
public:
    void helper(vector<int>& candidates, int target, int begin, vector<int>& path, vector<vector<int>>& res, int pathSum){
        if (pathSum == target){
            res.push_back(path);
            return; //目标值记录并且返回
        }
        set<int> layNum;
        //每一层的搜索进行去重
        for (int i = begin; i < candidates.size(); i++){
            if ((pathSum + candidates[i] <= target) && layNum.find(candidates[i]) == layNum.end()){
                //剪枝，包含是否操作目标值和是否在当前层搜索过的剪枝
                layNum.insert(candidates[i]); //层信息的更新
                pathSum = pathSum + candidates[i];
                path.push_back(candidates[i]);
                helper(candidates,target, i + 1,path,res,pathSum);
                pathSum = pathSum - candidates[i];
                path.pop_back(); //路径的恢复
            }
        }
        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); //排序
        vector<vector<int>> res;
        vector<int> path;
        int pathSum = 0;
        helper(candidates,target,0,path,res,pathSum);
        return res;

    }
};
```

## Leetcode46 

[全排列](https://leetcode.cn/problems/permutations/description/)

> 深度优先搜索

```c++
输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```

```c++
class Solution {
public:
    void dfs(vector<int>& nums, vector<int>& path, vector<vector<int>>& res, vector<int>& flag){
        if(path.size() == nums.size()){
            res.emplace_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++){
            if(flag[i]) continue;
            path.push_back(nums[i]);
            flag[i] = 1;
            dfs(nums,path,res,flag);
            path.pop_back();
            flag[i] = 0; //用flag数组来记录数据是否被访问过，和之前的层去重有相同的作用
            			//因为已经排序过了，无须再进行排序
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        vector<int> flag(nums.size(),0);
        dfs(nums, path, res, flag);
        return res;
    }
};
```

## Leetcode47 

[全排列 II](https://leetcode.cn/problems/permutations-ii/)

```c++
输入：nums = [1,1,2]
输出：
[[1,1,2],
 [1,2,1],
 [2,1,1]]
```

```c++
class Solution {
public:
    void dfs(vector<int>& nums, vector<int>& path, vector<vector<int>>& res, vector<int>& flag){
        if(path.size() == nums.size()){
            res.emplace_back(path);
            return;
        }
        for (int i = 0 ; i < nums.size(); i++){
            if(flag[i] == 1|| (i > 0 && nums[i] == nums[i - 1] && flag[i - 1])) continue;
            //除去判断是否已经被使用过以外，并且需要判断和前一个值是否相同
            path.push_back(nums[i]);
            flag[i] = 1;
            dfs(nums,path,res,flag);
            flag[i] = 0;
            path.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        vector<int> flag(nums.size(), 0);
        sort(nums.begin(), nums.end()); //先进行排序
        dfs(nums,path,res,flag);
        return res;
    }
```

## Leetcode77

[组合](https://leetcode.cn/problems/combinations/)

> 深度优先遍历+回溯

```c++
输入：n = 4, k = 2
输出：
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
```



```c++
class Solution {
public:
    void helper(int n, int k, int begin, vector<vector<int>>& res, vector<int>& path){
        if (path.size() == k){
            res.push_back(path);
            return;
        }
        for (int i = begin; i <= n; i++){
            if (path.size() <= k){
                path.push_back(i);
                helper(n, k, i + 1, res, path);
                path.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;
        helper(n,k,1,res,path);
        return res;

    }
};
```

## Leetcode78

[子集](https://leetcode.cn/problems/subsets/)

> 深度优先遍历+条件终止

```c++
输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
```



````c++
class Solution {
public:
    void helper(vector<int>& nums, int begin, vector<int> path, vector<vector<int>>& ret){
        if(path.size() <= nums.size()) ret.push_back(path);
            
        for(int i = begin; i < nums.size(); i++){
            path.push_back(nums[i]);
            helper(nums, i + 1, path, ret);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> ret;
        helper(nums, 0, path,ret);
        return ret;

    }
};
````

## Leetcode79

[单词搜索](https://leetcode.cn/problems/word-search/)

> 深度优先遍历+条件终止

```c++
输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true
```



```c++
class Solution {
public:
    bool helper(vector<vector<char>>& board, string word, int x, int y, int index, vector<vector<int>>& record){
        if (x < 0 or y < 0 or x >= board.size() or y >= board[0].size() or record[x][y] == 1) return false;
        if (word[index] != board[x][y]) return false;
        if (word[index] == board[x][y] && index == word.size() - 1) return true;

        record[x][y] = 1;
        bool up = helper(board,word,x - 1,y,index + 1,record);
        bool down = helper(board,word,x + 1,y,index + 1,record);
        bool left = helper(board,word,x,y - 1,index + 1,record);
        bool right = helper(board,word,x,y + 1,index + 1,record);
        record[x][y] = 0;

        return up||down||left||right;

    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<int> row(board[0].size(), 0);
        vector<vector<int>> record(board.size(), row);

        for(int i = 0; i < board.size(); i++){
            for (int j = 0;j < board[0].size();j++){
                bool res = helper(board,word,i,j,0,record);
                if(res) return res;
            }
        }
        return false;

    }
};
```

## Leetcode90

[子集II](https://leetcode.cn/problems/subsets-ii/)

> 深度优先遍历+剪枝

```c++
输入：nums = [1,2,2]
输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
```



```c++
class Solution {
public:
    void helper(vector<int>& nums, int begin, vector<int> path, vector<vector<int>>& ret){
        if (path.size() <= nums.size()) ret.push_back(path);
        
        set<int> layer;
        for (int i = begin; i < nums.size(); i++){
            if (layer.find(nums[i]) == layer.end()){
                layer.insert(nums[i]);
                path.push_back(nums[i]);
                helper(nums, i + 1, path, ret);
                path.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> path;
        vector<vector<int>> ret;
        helper(nums, 0, path, ret);
        return ret;
    }
};
```



## LeetCode93 

[复原 IP 地址](https://leetcode.cn/problems/restore-ip-addresses/)

> 深度优先遍历+剪枝，注意辅助函数的实现

```c++
输入：s = "101023"
输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
```

```c++
class Solution {
public:
    bool check(string s){
        if (s[0] == '0' && s.size() >= 2){
            return false;
        }
        return stoi(s) <= 255; //判断是不是一个合理的单个ip数字
    }
    string join(vector<string> vec){
        string ret = "";
        for (auto str : vec){
            ret = ret + str + ".";
        }
        return ret.substr(0, ret.size() - 1);
    } //将分割好的字符连接
    
    void helper(string s, vector<string>& ret, vector<string>& path, int index){
        if (path.size() == 4){
            
            if (index == s.size()){
                string ip = join(path);
                ret.push_back(ip);
            }
            return;
        }
        for (int i = index; i < index + 3 && i < s.size(); i++){
            string temp = s.substr(index, i - index + 1);
            if (check(temp)){
                path.push_back(temp);
                helper(s,ret,path,i + 1);
                path.pop_back();
            }
        }
        return; //深度优先遍历
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        vector<string> path;
        int index = 0;
        helper(s,ret,path,index);
        return ret;

    }
};
```



## LeetCode207

[课程表](https://leetcode.cn/problems/course-schedule/)

> 拓扑排序

```c++
输入：numCourses = 2, prerequisites = [[1,0]]
输出：true
解释：总共有 2 门课程。学习课程 1 之前，你需要完成课程 0 。这是可能的。
```

```c++
class Solution {
public:
    vector<vector<int>> edges;
    vector<int> inedg;
    vector<int> result;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        edges.resize(numCourses);
        inedg.resize(numCourses);

        for(auto info: prerequisites){
            edges[info[1]].push_back(info[0]);
            inedg[info[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++){
            if(inedg[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            result.push_back(u);

            for (auto v: edges[u]){
                --inedg[v];
                if(inedg[v] == 0){
                    q.push(v);
                }
            }
        }
        if (result.size() != numCourses){
            return false;
        } else {
            return true;
        }

    }
};
```



## LeetCode210

[课程表 II](https://leetcode.cn/problems/course-schedule-ii/)

```c++
输入：numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
输出：[0,2,1,3]
解释：总共有 4 门课程。要学习课程 3，你应该先完成课程 1 和课程 2。并且课程 1 和课程 2 都应该排在课程 0 之后。
因此，一个正确的课程顺序是 [0,1,2,3] 。另一个正确的排序是 [0,2,1,3] 。
```



```c++
class Solution {
public:
    vector<vector<int>> edges;
    vector<int> inedg;
    vector<int> result;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        inedg.resize(numCourses);

        for(auto info : prerequisites){
            edges[info[1]].push_back(info[0]);
            ++inedg[info[0]];
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++){
            if(inedg[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            result.push_back(u);

            for(auto v: edges[u]){
                --inedg[v];
                if(inedg[v] == 0){
                    q.push(v);
                }
            }
        }
        if(result.size() != numCourses){
            return {};
        } else {
            return result;
        }
    }
};
```



## LeetCode216

[组合总和 III](https://leetcode.cn/problems/combination-sum-iii/)

> 深度优先遍历+剪枝



```c++
输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]
解释:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
没有其他符合的组合了。
```



```c++
class Solution {
public:
    void helper(int k, int n, int layer, int begin, vector<int>& path, int pathSum, vector<vector<int>>& res){
        if (pathSum == n && layer == k){
            res.push_back(path);
            return; //return条件的设置
        }
        for (int i = begin; i <= 9; i++){ //for循环从begin开始
            if (layer <= k && ((pathSum + i) <= n)){ //判断是否符合进入下一层的要求
                pathSum = pathSum + i;
                path.push_back(i);
                helper(k,n,layer + 1,i + 1,path,pathSum,res);
                pathSum = pathSum - i;
                path.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> path;
        helper(k,n,0,1,path,0,res);
        return res;
    }
};
```



## LeetCode377

[组合总和 Ⅳ](https://leetcode.cn/problems/combination-sum-iv/)



```c++
输入：nums = [1,2,3], target = 4
输出：7
解释：
所有可能的组合为：
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
请注意，顺序不同的序列被视作不同的组合。
```

```c++
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {

        vector<unsigned int> dp(target + 1);
        dp[0] = 1;
        for (int j = 1; j <= target; j++){
        for (auto num: nums){
            if (j - num >= 0){
                dp[j] = dp[j] + dp[j - num];
            }
        }
        }
        return *(dp.end() - 1);
 
    }
};
```

