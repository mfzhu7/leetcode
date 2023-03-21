# LeetCode-位操作篇



## LeetCode136

[只出现一次的数字](https://leetcode.cn/problems/single-number/)

```c++
输入：nums = [2,2,1]
输出：1
```



```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (auto i: nums){
            res = res ^ i;
            //两个相同的数进行异或，结果为0
            //任何数和0进行异或，结果为原始数据
        }
        return res;
    }
};
```



## LeetCode137

[只出现一次的数字 II](https://leetcode.cn/problems/single-number-ii/)

```c++
输入：nums = [0,1,0,1,0,1,99]
输出：99
```



```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; i++){
            int total = 0;
            for (int num: nums){
                total += ((num >> i) & 1);
                //把每个数的每一位加和
            }
            if (total % 3){
                //判断其和3的求余即可得到唯一的那个数
                ans |= (1 << i);
            }
        }
        return ans;

    }
};
```

