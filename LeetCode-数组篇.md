# LeetCode-数组篇

[toc]



## LeetCode118

[ 杨辉三角](https://leetcode.cn/problems/pascals-triangle/)

**题干**

给定一个非负整数 *`numRows`，*生成「杨辉三角」的前 *`numRows`* 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。

![img](https://pic.leetcode-cn.com/1626927345-DZmfxB-PascalTriangleAnimated2.gif)



**示例**

> ```c++
> 输入: numRows = 5
> 输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
> ```

**解题思路**

- 直接按照题目所述，建立数组，遍历每一层的数组，d(i,j) = d(i-1,j) + d(i-1,j-1)
- 注意的点在于，每一层的数组大小不一致，可以在每一层的遍历的时候resize即可。

```c++
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        for (int i = 0; i < numRows; ++i){
            res[i].resize(i + 1);
            res[i][0] = res[i][i] = 1;
            for (int j = 1; j < i; ++j){
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j]; 
            }
        }
        return res;

    }
};
```





## LeetCode119

[杨辉三角 II](https://leetcode.cn/problems/pascals-triangle-ii/)

**题干**

给定一个非负索引 `rowIndex`，返回「杨辉三角」的第 `rowIndex` 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。



![img](https://pic.leetcode-cn.com/1626927345-DZmfxB-PascalTriangleAnimated2.gif)

**示例**

```c++
输入: rowIndex = 3
输出: [1,3,3,1]
```

**解题思路**

- 解题思路以[1,2,1]->[1,3,3,1]
- 首先得到[3,3,1]，然后在头部插入1，得到[1,3,3,1]



```c++
class Solution {
public:
    void helper(int nums, vector<int>& lastRow){
        if (nums == 1) return;
        for (int i = 0; i < lastRow.size() - 1; i++){
            lastRow[i] = lastRow[i] + lastRow[i + 1];
        }
        lastRow.emplace(lastRow.begin(), 1);
        helper(nums - 1, lastRow);
        return;

    }
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0){
            vector<int> res = {1};
            return res;
        }
        if (rowIndex == 1){
            vector<int> res = {1,1};
            return res;
        }
        vector<int> res = {1,1};
        helper(rowIndex, res);
        return res;
    }
};
```



## LeetCode128(待研究)

[最长连续序列](https://leetcode.cn/problems/longest-consecutive-sequence/)

**题干**

给定一个未排序的整数数组 `nums` ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

请你设计并实现时间复杂度为 `O(n)` 的算法解决此问题。

**示例**

```c++
输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
```

**解题思路**



```c++
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ret = 0;
        for (int i = 0; i < nums.size(); i++){
            int curr = nums[i] + 1;
            while(true){
                bool flag = false;
                for (int j = 0;j < nums.size();j++){          
                    if (nums[j] == curr){
                        flag = true;
                        break;
                    }
                }
                curr = curr + 1;
                if (!flag) break;
            }
            
            ret = max(ret, curr - nums[i] - 1);
        }
        return ret;

    }
};
```



## Leetcode134(待研究)

[加油站](https://leetcode.cn/problems/gas-station/)

**题干**

在一条环路上有 `n` 个加油站，其中第 `i` 个加油站有汽油 `gas[i]` 升。

你有一辆油箱容量无限的的汽车，从第 `i` 个加油站开往第 `i+1` 个加油站需要消耗汽油 `cost[i]` 升。你从其中的一个加油站出发，开始时油箱为空。

给定两个整数数组 `gas` 和 `cost` ，如果你可以按顺序绕环路行驶一周，则返回出发时加油站的编号，否则返回 `-1` 。如果存在解，则 **保证** 它是 **唯一** 的。

 

**示例**

```c++
输入: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
输出: 3
解释:
从 3 号加油站(索引为 3 处)出发，可获得 4 升汽油。此时油箱有 = 0 + 4 = 4 升汽油
开往 4 号加油站，此时油箱有 4 - 1 + 5 = 8 升汽油
开往 0 号加油站，此时油箱有 8 - 2 + 1 = 7 升汽油
开往 1 号加油站，此时油箱有 7 - 3 + 2 = 6 升汽油
开往 2 号加油站，此时油箱有 6 - 4 + 3 = 5 升汽油
开往 3 号加油站，你需要消耗 5 升汽油，正好足够你返回到 3 号加油站。
因此，3 可为起始索引。
```

**解题思路**



```c++
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int idx = 0;

        while(idx < n){
            int sumGas = 0;
            int sumCost = 0;
            int cnt = 0;
            while(cnt < n){
                int j = (idx + cnt) % n;
                sumCost += cost[j];
                sumGas += gas[j];
                if (sumCost > sumGas) break;
                cnt = cnt + 1;
            }
            if (cnt == n) return idx;
            else {
                idx = idx + cnt + 1;
            }
        }
        return -1;
        
    }
};
```



## LeetCode152 

[乘积最大的子数组](https://leetcode.cn/problems/maximum-product-subarray/)

**题干**

给你一个整数数组 `nums` ，请你找出数组中乘积最大的非空连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。

测试用例的答案是一个 **32-位** 整数。

**子数组** 是数组的连续子序列。

 **示例**

```c++
输入: nums = [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
```

**解题思路**

- max_dp[i]和min_dp[i] 分别存储着以当前数为结尾的最大值和最小值
- 每次遍历新的位置的时候，更新最大值和最小值，并记录下最大值的情况
- 注意dp的设置是以包含当前位置的最小值和最大值

```c++
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int currMax = nums[0];
        int max_p = nums[0];
        int min_p = nums[0];
		//核心点在于，在每一步都算好当前的最大值和最小值；
        //在遍历新一步的时候，计算最大值和最小值和新的值的结果，找到最大值
        //计算最小值的原因是因为有可能存在负数，乘积负数得到最大
        for (int i = 1; i < nums.size(); i++){
            int temp = max_p;
            max_p = max(max(max_p * nums[i], nums[i]), min_p * nums[i]);
            min_p = min(min(temp * nums[i], nums[i]), min_p * nums[i]);
            currMax = max(currMax, max_p);
        }
        return currMax;
    }
};
```



## LeetCode153 

[寻找旋转排序数组中的最小值](https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/)

**题干**

已知一个长度为 `n` 的数组，预先按照升序排列，经由 `1` 到 `n` 次 **旋转** 后，得到输入数组。例如，原数组 `nums = [0,1,2,4,5,6,7]` 在变化后可能得到：

- 若旋转 `4` 次，则可以得到 `[4,5,6,7,0,1,2]`
- 若旋转 `7` 次，则可以得到 `[0,1,2,4,5,6,7]`

注意，数组 `[a[0], a[1], a[2], ..., a[n-1]]` **旋转一次** 的结果为数组 `[a[n-1], a[0], a[1], a[2], ..., a[n-2]]` 。

给你一个元素值 **互不相同** 的数组 `nums` ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 **最小元素** 。

你必须设计一个时间复杂度为 `O(log n)` 的算法解决此问题。

**示例**

```c++
输入：nums = [4,5,6,7,0,1,2]
输出：0
解释：原数组为 [0,1,2,4,5,6,7] ，旋转 4 次得到输入数组。
```

**解题思路**

- 有序数组查找的情况下，我们一般考虑二分查找来降低计算复杂度
- [3,4,5,6,7,8,1,2]的情况下，nums[mid] = 7，7>3的情况下，说明[3,4,5,6,7]为有序数组，最小值为最左侧的值；记录最小值并且更新l的位置
- 更新后[8,1,2]的中间数为1，说明当前值为最小值，因为[1,2]为递增序列

```c++
class Solution {
public:
    int findMin(vector<int>& nums) {
        int ret = INT_MAX;
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if (nums[mid] >= nums[0]){
                ret = min(ret, nums[0]);
                l = mid + 1; //[3,4,5,6,7,8,1,2]
            } else {
                ret = min(ret, nums[mid]); //[7,8,1,2,3,4,5,6]
                r = mid - 1;
            }
        }
        return ret;
    }
};
```



## LeetCode162	

[寻找峰值](https://leetcode.cn/problems/find-peak-element/)

**题干**

峰值元素是指其值严格大于左右相邻值的元素。

给你一个整数数组 `nums`，找到峰值元素并返回其索引。数组可能包含多个峰值，在这种情况下，返回 **任何一个峰值** 所在位置即可。

你可以假设 `nums[-1] = nums[n] = -∞` 。

你必须实现时间复杂度为 `O(log n)` 的算法来解决此问题。

**示例**

```c++
输入：nums = [1,2,1,3,5,6,4]
输出：1 或 5 
解释：你的函数可以返回索引 1，其峰值元素为 2；
     或者返回索引 5， 其峰值元素为 6。
```

**解题思路**

- 提示用logn的算法，常见用二分法来解决
- 当nums[mid] <= nums[mid + 1]的时候，说明我们在上坡的路上，必定存在峰值；所以我们的左值设置为left = mid + 1
- 反之，则说明向左侧走，可以找到峰值，设置right = mid；



```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int idx = 0;
        for (int i = 0; i < nums.size(); i++){
            int left = (i - 1 >= 0) ? nums[i - 1] : INT_MIN;
            int right= (i + 1 < nums.size()) ? nums[i + 1]: INT_MIN;
            if (nums[i] > left && nums[i] > right) {
                idx = i;
                break;
            }
        }
        return idx;
    }
};

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] <= nums[mid + 1]){
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;

    }
};
```



## LeetCode167

[ 两数之和 II - 输入有序数组](https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/)

**题干**

给你一个下标从 **1** 开始的整数数组 `numbers` ，该数组已按 **非递减顺序排列** ，请你从数组中找出满足相加之和等于目标数 `target` 的两个数。如果设这两个数分别是 `numbers[index1]` 和 `numbers[index2]` ，则 `1 <= index1 < index2 <= numbers.length` 。

以长度为 2 的整数数组 `[index1, index2]` 的形式返回这两个整数的下标 `index1` 和 `index2`。

你可以假设每个输入 **只对应唯一的答案** ，而且你 **不可以** 重复使用相同的元素。

你所设计的解决方案必须只使用常量级的额外空间。

**示例**

```c++
输入：numbers = [2,7,11,15], target = 9
输出：[1,2]
解释：2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。返回 [1, 2] 。
```

**解题思路**

- 首先有序数组的情况下，我们一般考虑二分法，加快查找的速度
- 我们先定义左右节点，然后判断和目标值的关系
- 如果是大于目标值，则将右节点移动；如果是小于目标值，则左节点移动

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        vector<int> ret(2);
        while(left <= right){
            if (numbers[left] + numbers[right] == target){
                ret[0] = left + 1;
                ret[1] = right + 1;
                break;
            } else if (numbers[left] + numbers[right] > target) {
                right = right - 1;
            } else {
                left = left + 1;
            }
        }
        return ret;
    }
};
```



## LeetCode169(其他方法待实现)

[多数元素](https://leetcode.cn/problems/majority-element/)

**题干**

给定一个大小为 `n` 的数组 `nums` ，返回其中的多数元素。多数元素是指在数组中出现次数 **大于** `⌊ n/2 ⌋` 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

**示例**

```c++
输入：nums = [2,2,1,1,1,2,2]
输出：2
```
**解题思路**

- 思路1：将所有数的出现次数用字典存储即可，而后判断是否出现的次数大于n/2


```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (auto i: nums){
            if (hash.find(i) == hash.end()){
                hash[i] = 1;
            } else {
                hash[i] = hash[i] + 1;
            }
        }
        int res;
        for (auto it: hash){
            if (it.second > nums.size() / 2){
                res = it.first;
            }
        }
        return res;

    }
};
```



## LeetCode179

[ 最大数](https://leetcode.cn/problems/largest-number/)

**题干**

给定一组非负整数 `nums`，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。

**注意：**输出结果可能非常大，所以你需要返回一个字符串而不是整数。

**示例**

```c++
输入：nums = [3,30,34,5,9]
输出："9534330"
```

**解题思路**

- 本题的核心问题是排序，如何知道3和30的先后顺序；我们可以看到330和303的结果中，3是靠前的；
- 同理3430>3034的话，那么34靠前于30。所以我们只要自定好好排序的函数，将排序后的结果整合在一起即可。

```c++
class Solution {
public:
    static bool compare(int num1, int num2){
        string str1 = to_string(num1) + to_string(num2);
        string str2 = to_string(num2) + to_string(num1);

        double val1 = stod(str1);
        double val2 = stod(str2);

        return (val1 > val2);
    }
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), compare);
        if (nums[0] == 0) return "0";
        string ans = "";
        for (int i = 0; i < n; i++){
            ans = ans + to_string(nums[i]);
        }
        return ans;
    }
};
```



## LeetCode189(其他解法待完善)

[轮转数组](https://leetcode.cn/problems/rotate-array/)

> 数组+双指针

```c++
输入: nums = [1,2,3,4,5,6,7], k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右轮转 1 步: [7,1,2,3,4,5,6]
向右轮转 2 步: [6,7,1,2,3,4,5]
向右轮转 3 步: [5,6,7,1,2,3,4]
```



```c++
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int length = nums.size(); 
        k = k % length;
        vector<int> array(length);
        for (int i = 0; i < length; i++){
            array[(i + k) % length] = nums[i];
        }

        nums.assign(array.begin(), array.end());
        return;
    }
};
```



## LeetCode198

[打家劫舍](https://leetcode.cn/problems/house-robber/)

**题干**

你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，**如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警**。

给定一个代表每个房屋存放金额的非负整数数组，计算你 **不触动警报装置的情况下** ，一夜之内能够偷窃到的最高金额。

**示例**

```c++
输入：[1,2,3,1]
输出：4
解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。
```

**题解**

- 在每个数组的位置上，我们都有两种可能，一种是偷当前位置的钱，一种是不偷当前位置的钱
- dp[i]表示，到当前位置为止，在不触动警报的情况下，能够偷到的金额的最大值
- dp[i] = max(dp[i-2] + nums[i], dp[i-1])

```c++
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int>dp(nums.size(),0);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);

        for (int i = 2; i < nums.size(); i++){
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[nums.size() - 1];
    }
};
```



## LeetCode209

[长度最小的子数组](https://leetcode.cn/problems/minimum-size-subarray-sum/)

**题干**

给定一个含有 `n` 个正整数的数组和一个正整数 `target` **。**

找出该数组中满足其和 `≥ target` 的长度最小的 **连续子数组** `[numsl, numsl+1, ..., numsr-1, numsr]` ，并返回其长度**。**如果不存在符合条件的子数组，返回 `0` 。

**示例**

```c++
输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。
```

**题解**

- 首先是不断增加子数组的长度，直到子数组之和满足>=target
- 在满足条件的情况下，左侧的下标开始向右移动，计算最短的子数组长度
- 如果不满足条件即不断增加右侧的数据即可
- 滑动窗口的思想



```c++
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0;
        int end = 0;
        int length = nums.size();
        int currSum = 0;
        int minLength = INT_MAX;
        while(end < length){
            currSum += nums[end];
            if(currSum >= target){
                while(currSum >= target){
                minLength = min(minLength, end - start + 1);
                currSum = currSum - nums[start];
                start++;
                }
                end++;
            }else {
                end = end + 1;
            }
        }
        return minLength == INT_MAX ? 0 : minLength;
    }
};
```



## Leetcode215(待完善)

[数组中的第K个最大元素](https://leetcode.cn/problems/kth-largest-element-in-an-array/)

> 基于快排的实现

```c++
输入: [3,2,3,1,2,4,5,5,6], k = 4
输出: 4
```

```c++
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
        
    }
};
```



## LeetCode217

[存在重复元素](https://leetcode.cn/problems/contains-duplicate/)

**题干**

给你一个整数数组 `nums` 。如果任一值在数组中出现 **至少两次** ，返回 `true` ；如果数组中每个元素互不相同，返回 `false` 。

**示例**

```c++
输入：nums = [1,1,1,3,3,4,3,2,4,2]
输出：true
```

**解题思路**

- 思路1：哈希表存储不同数据出现的次数即可
- 思路2：

```c++
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() == 1) return false;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] == nums[i - 1]) return true;
        }
        return false;

    }
};
```



## LeetCode219

[存在重复元素 II](https://leetcode.cn/problems/contains-duplicate-ii/)

**题干**

给你一个整数数组 `nums` 和一个整数 `k` ，判断数组中是否存在两个 **不同的索引** `i` 和 `j` ，满足 `nums[i] == nums[j]` 且 `abs(i - j) <= k` 。如果存在，返回 `true` ；否则，返回 `false` 。

**示例**

```c++
输入：nums = [1,2,3,1,2,3], k = 2
输出：false
```

**解题思路**

- 用哈希表存储着k个数，每滑动一个位置，判断哈希表中是否超过k个数，如果超过k个，则删除最先加入的数
- 每滑动一次，即判断是否出现过当前数，出现则返回true；反之则继续添加数

```c++
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> hash;
        for (int i = 0; i < nums.size(); i++){
            if (i > k){
                hash.erase(nums[i - k - 1]);
            }
            if (hash.count(nums[i])) return true;
            hash.emplace(nums[i]);
        }
        return false;
    }
};
```



## LeetCode229

[ 多数元素 II](https://leetcode.cn/problems/majority-element-ii/)

```c++
输入：nums = [3,2,3]
输出：[3]
```

```c++
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int element1 = 0;
        int element2 = 0;
        int vote1 = 0;
        int vote2 = 0;
        for (auto num: nums){
            if (vote1 > 0 && element1 == num){
                vote1++;
            } else if (vote2 > 0 && element2 == num){
                vote2++;
            } else if (vote1 == 0){
                vote1++;
                element1 = num;
            } else if (vote2 == 0){
                vote2++;
                element2 = num;
            } else {
                vote1--;
                vote2--;
            }
        }
        int cnt1 = 0;
        int cnt2 = 0;
        for (auto num: nums){
            if (vote1 > 0 && num == element1) cnt1++;
            if (vote2 > 0 && num == element2) cnt2++;
        }
        vector<int> ret;
        if (vote1 > 0 && cnt1 > nums.size() / 3) ret.push_back(element1);
        if (vote2 > 0 && cnt2 > nums.size() / 3) ret.push_back(element2);
        return ret;
    }
};
```



## LeetCode238

[除自身以外数组的乘积](https://leetcode.cn/problems/product-of-array-except-self/)

**题干**

给你一个整数数组 `nums`，返回 *数组 `answer` ，其中 `answer[i]` 等于 `nums` 中除 `nums[i]` 之外其余各元素的乘积* 。

题目数据 **保证** 数组 `nums`之中任意元素的全部前缀元素和后缀的乘积都在 **32 位** 整数范围内。

请**不要使用除法，**且在 `O(*n*)` 时间复杂度内完成此题。

**示例**

```c++
输入: nums = [1,2,3,4]
输出: [24,12,8,6]
```

**解题思路**

- 要求不能使用除法，我们可以定义一个每个位置上，分别包含左侧的乘积结果和右侧乘积结果的数组
- 而后将数组的对应位置进行乘积即可。

```c++
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>L(n, 1);
        for (int i = 1; i < n; i++){
            L[i] = L[i - 1] * nums[i - 1];
        }
        int right = 1;
        vector<int> ret(n, 0);
        for(int i = n - 1; i >= 0; i--){
            ret[i] = L[i] * right;
            right = right * nums[i];
        }
        return ret;


    }
};
```



## LeetCode274

[ H 指数](https://leetcode.cn/problems/h-index/)

**题干**

给你一个整数数组 `citations` ，其中 `citations[i]` 表示研究者的第 `i` 篇论文被引用的次数。计算并返回该研究者的 **`h` 指数**。

根据维基百科上 [h 指数的定义](https://baike.baidu.com/item/h-index/3991452?fr=aladdin)：`h` 代表“高引用次数” ，一名科研人员的 `h` **指数** 是指他（她）至少发表了 `h` 篇论文，并且每篇论文 **至少** 被引用 `h` 次。如果 `h` 有多种可能的值，**`h` 指数** 是其中最大的那个。

**示例**

```c++
输入：citations = [3,0,6,1,5]
输出：3 
解释：给定数组表示研究者总共有 5 篇论文，每篇论文相应的被引用了 3, 0, 6, 1, 5 次。
     由于研究者有 3 篇论文每篇 至少 被引用了 3 次，其余两篇论文每篇被引用 不多于 3 次，所以她的 h 指数是 3。
```
**解题思路**

- 将数组进行排序，而后从数组末尾进行遍历[0,1,3,5,6]；h指数从0开始递增
- 6 > 0所以h + 1 = 1；遍历到5的时候，判断5是否大于1，即说明至少有2篇大于1，所以h = 2
- 这里面从后往前遍历的隐含因素有，6大于的情况下，5一定大于。

```c++
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int h = 0;
        int i = citations.size() - 1;
        while(i >= 0 && citations[i] > h){
            h++;
            i--;
        }
        return h;
    }
};
```



## LeetCode275 

[ H 指数 II](https://leetcode.cn/problems/h-index-ii/)

**题干**

给你一个整数数组 `citations` ，其中 `citations[i]` 表示研究者的第 `i` 篇论文被引用的次数，`citations` 已经按照 **升序排列** 。计算并返回该研究者的 h 指数。

[h 指数的定义](https://baike.baidu.com/item/h-index/3991452?fr=aladdin)：h 代表“高引用次数”（high citations），一名科研人员的 `h` 指数是指他（她）的 （`n` 篇论文中）**总共**有 `h` 篇论文分别被引用了**至少** `h` 次。

请你设计并实现对数时间复杂度的算法解决此问题。

**示例**

```c++
输入：citations = [0,1,3,5,6]
输出：3 
解释：给定数组表示研究者总共有 5 篇论文，每篇论文相应的被引用了 0, 1, 3, 5, 6 次。
     由于研究者有 3 篇论文每篇 至少 被引用了 3 次，其余两篇论文每篇被引用 不多于 3 次，所以她的 h 指数是 3 。
```
**解题思路**

- 本质上是要找到数组c[n-x] >= x的最小的x即可
- 在有序数组的情况下，用二分查找能够更快的找到边界


```c++
 class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        int left = 0;
        int right = citations.size() - 1;
        int h = 0;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if (citations[mid] >= size - mid){
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return size - left;

    }
};
```



## LeetCode283

[ 移动零](https://leetcode.cn/problems/move-zeroes/)

**题干**

给定一个数组 `nums`，编写一个函数将所有 `0` 移动到数组的末尾，同时保持非零元素的相对顺序。

**请注意** ，必须在不复制数组的情况下原地对数组进行操作。

**示例**

```c++
输入: nums = [0,1,0,3,12]
输出: [1,3,12,0,0]
```

**解题思路**

- 用j来标的目前非0数存储的位置，表示到该位置为止，已经完成了正确放置 
- 而后遍历数组，遇到非0的数字和放置完成的位置进行交换即可。

```c++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] != 0){
                int tmp = nums[j];
                nums[j] = nums[i];
                nums[i] = tmp;
                j++;
            }
        }
        return;

    }
};
```



## LeetCode287

[寻找重复数](https://leetcode.cn/problems/find-the-duplicate-number/)

**题干**

给定一个包含 `n + 1` 个整数的数组 `nums` ，其数字都在 `[1, n]` 范围内（包括 `1` 和 `n`），可知至少存在一个重复的整数。

假设 `nums` 只有 **一个重复的整数** ，返回 **这个重复的数** 。

你设计的解决方案必须 **不修改** 数组 `nums` 且只用常量级 `O(1)` 的额外空间。

**示例**

```
输入：nums = [1,3,4,2,2]
输出：2
```

**解题思路**

- 

```
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> hash;
        for (auto i : nums){
            if (hash.find(i) == hash.end()){
                hash[i] = 1;
            } else {
                ans = i;
                break;
            }
        }
        return ans;

    }
};
```



## LeetCode300

[最长递增子序列](https://leetcode.cn/problems/longest-increasing-subsequence/)

**题干**

给你一个整数数组 `nums` ，找到其中最长严格递增子序列的长度。

**子序列** 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，`[3,6,2,7]` 是数组 `[0,3,1,6,2,2,7]` 的子序列。

**示例**

```c++
输入：nums = [10,9,2,5,3,7,101,18]
输出：4
解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
```

**题解**

- 定义dp[i]为以nums[i]为结尾的最长严格递增子序列的长度
- 如果遍历到数组的第i个位置的时候，我们需要从第0-i的位置进行遍历，如果nums[i]>nums[j]，说明当前值可以加入到nums[i]的子序列中形成递增，从而更新dp[i]的值
- 以遍历到7为例，从10开始从头遍历，发现10和9均不满足，2的dp[2]=1，5的dp[3] = 2, 3的dp[4] = 2，7>2和5和3，所以其最长子序列为max(dp[2], dp[3],d p[4] ) + 1;

```c++
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        int ans = 1;
        for (int i = 1; i < n; i++){
            int temp = 1;
            for (int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    temp = max(temp, dp[j] + 1);
                }
            }
            dp[i] = temp;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
```



## LeetCode303

[区域和检索 - 数组不可变](https://leetcode.cn/problems/range-sum-query-immutable/)

```c++
输入：
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
输出：
[null, 1, -1, -3]

解释：
NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
numArray.sumRange(0, 2); // return 1 ((-2) + 0 + 3)
numArray.sumRange(2, 5); // return -1 (3 + (-5) + 2 + (-1)) 
numArray.sumRange(0, 5); // return -3 ((-2) + 0 + 3 + (-5) + 2 + (-1))
```



```c++
class NumArray {
public:
    vector<int> sum;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        sum.resize(n + 1);
        for (int i = 0; i < n; i++){
            sum[i + 1] = sum[i] + nums[i];
        }

    }
    
    int sumRange(int left, int right) {
        return sum[right + 1] - sum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
```



## LeetCode322

[零钱兑换](https://leetcode.cn/problems/coin-change/)

**题干**

给你一个整数数组 `coins` ，表示不同面额的硬币；以及一个整数 `amount` ，表示总金额。

计算并返回可以凑成总金额所需的 **最少的硬币个数** 。如果没有任何一种硬币组合能组成总金额，返回 `-1` 。

你可以认为每种硬币的数量是无限的。

 **示例**

```c++
输入：coins = [1, 2, 5], amount = 11
输出：3 
解释：11 = 5 + 5 + 1
```

**解题思路**

- 我们定义dp[i]为用数组中的硬币组成金额i的最小硬币数
- 对于dp[i + 1] 而言，dp[i + 1] = min(dp[i + 1 - coins[j]] + 1)，遍历其中的j，即数组中的任意一个银币
- 其中需要判断当前的coins[j]是否大于目标值，大于的情况下，无需计算

```c++
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
            // sort(coins.begin(), coins.end());
            int MAX = amount + 1;
            vector<int> dp(amount + 1, MAX);
            dp[0] = 0;
            for (int i = 1;i <= amount; i++){
                for (int j = 0; j < (int)coins.size(); j++){
                    if(i >= coins[j]){
                        dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
                    }
                }
            }

            return dp[amount] > amount? -1: dp[amount]; 

    }
};
```





## LeetCode349

[两个数组的交集](https://leetcode.cn/problems/intersection-of-two-arrays/)

**题干**

给定两个数组 `nums1` 和 `nums2` ，返回 *它们的交集* 。输出结果中的每个元素一定是 **唯一** 的。我们可以 **不考虑输出结果的顺序** 。

**示例**

```c++
输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2]
```
**解题思路**

- 用哈希表存储两个数组的元素
- 而后遍历其中一个哈希表结果，判断其在另外一个哈希表中的情况
- 如果存在，即加入到结果中即可

```c++
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        vector<int> ans;     
        unordered_set<int> hash1{nums1.begin(), nums1.end()};
        unordered_set<int> hash2{nums2.begin(), nums2.end()};

        for(auto it = hash1.begin(); it != hash1.end(); it++){
            if (hash2.find(*it) != hash1.end()){
                ans.push_back(*it);
            }
        }
        return ans;

    }
};
```



