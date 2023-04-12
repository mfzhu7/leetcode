# LeetCode-数组篇

[toc]



## LeetCode118

[ 杨辉三角](https://leetcode.cn/problems/pascals-triangle/)

> ```c++
> 输入: numRows = 5
> 输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
> ```



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

```c++
输入: rowIndex = 3
输出: [1,3,3,1]
```



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

> 

```c++
输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
```



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

> 数组+贪心算法

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

> 数组+动态规划

```c++
输入: nums = [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
```



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

> 数据+变形二分查找



```c++
输入：nums = [4,5,6,7,0,1,2]
输出：0
解释：原数组为 [0,1,2,4,5,6,7] ，旋转 4 次得到输入数组。
```



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



## LeetCode162(待添加二分版本)

[寻找峰值](https://leetcode.cn/problems/find-peak-element/)

> 数组+二分查找



```c++
输入：nums = [1,2,1,3,5,6,4]
输出：1 或 5 
解释：你的函数可以返回索引 1，其峰值元素为 2；
     或者返回索引 5， 其峰值元素为 6。
```



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
```



## LeetCode167

[ 两数之和 II - 输入有序数组](https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/)

> 数组+二分查找

```c++
输入：numbers = [2,7,11,15], target = 9
输出：[1,2]
解释：2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。返回 [1, 2] 。
```



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

> 数组+二分查找

```c++
输入：nums = [2,2,1,1,1,2,2]
输出：2
```

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



## LeetCode179(待研究)

[ 最大数](https://leetcode.cn/problems/largest-number/)

```c++
输入：nums = [3,30,34,5,9]
输出："9534330"
```



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

> 数组+动态规划



```c++
输入：[1,2,3,1]
输出：4
解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。
```



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

> 数组+二分查找

```c++
输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。
```



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

> 排序或者哈希表

```c++
输入：nums = [1,1,1,3,3,4,3,2,4,2]
输出：true
```



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

> 滑动窗口+哈希表

```c++
输入：nums = [1,2,3,1,2,3], k = 2
输出：false
```



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

```c++
输入: nums = [1,2,3,4]
输出: [24,12,8,6]
```

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

```c++
输入：citations = [3,0,6,1,5]
输出：3 
解释：给定数组表示研究者总共有 5 篇论文，每篇论文相应的被引用了 3, 0, 6, 1, 5 次。
     由于研究者有 3 篇论文每篇 至少 被引用了 3 次，其余两篇论文每篇被引用 不多于 3 次，所以她的 h 指数是 3。
```

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

```c++
输入：citations = [0,1,3,5,6]
输出：3 
解释：给定数组表示研究者总共有 5 篇论文，每篇论文相应的被引用了 0, 1, 3, 5, 6 次。
     由于研究者有 3 篇论文每篇 至少 被引用了 3 次，其余两篇论文每篇被引用 不多于 3 次，所以她的 h 指数是 3 。
```

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

```c++
输入: nums = [0,1,0,3,12]
输出: [1,3,12,0,0]
```

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



```
输入：nums = [1,3,4,2,2]
输出：2
```



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

```c++
输入：nums = [10,9,2,5,3,7,101,18]
输出：4
解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
```

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

