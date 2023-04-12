# LeetCode-位操作篇

[toc]



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



## LeetCode190

[颠倒二进制位](https://leetcode.cn/problems/reverse-bits/)

> 位操作



```c++
输入：n = 00000010100101000001111010011100
输出：964176192 (00111001011110000010100101000000)
解释：输入的二进制串 00000010100101000001111010011100 表示无符号整数 43261596，
     因此返回 964176192，其二进制表示形式为 00111001011110000010100101000000。
```



```c++
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

        uint32_t res = 0;
        long long  tag = 2147483648;
        while(n){
            uint32_t tmp = n % 2;
            res = res + tmp * tag;
            n = n >> 1;
            tag = tag / 2;
        }
        return res;
        
    }
};
```



## LeetCode191

[ 位1的个数](https://leetcode.cn/problems/number-of-1-bits/)

> 位操作

```c++
输入：n = 00000000000000000000000000001011
输出：3
解释：输入的二进制串 00000000000000000000000000001011 中，共有三位为 '1'。
```

```c++
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0; 
        while(n){
            n = n & (n - 1); //常用操作需要注意
            ret = ret + 1;
        }
        return ret;
        
    }
};
```



## LeetCode201(没看懂)

[[数字范围按位与](https://leetcode.cn/problems/bitwise-and-of-numbers-range/)]

> 数组+位操作

```c++
输入：left = 5, right = 7
输出：4
```

```c++
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        while(left < right){
            left >>= 1;
            right >>= 1;
            shift = shift + 1;
        }
        return left << shift;

    }
};
```



## LeetCode231

[2 的幂](https://leetcode.cn/problems/power-of-two/)

```c++
输入：n = 1
输出：true
解释：20 = 1
```



```c++
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};
```



## LeetCode260

[只出现一次的数字 III](https://leetcode.cn/problems/single-number-iii/)

```c++
输入：nums = [1,2,1,3,2,5]
输出：[3,5]
解释：[5, 3] 也是有效的答案。
```



```c++
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorsum = 0;
        for (auto i :nums){
            xorsum ^= i;
        }

        xorsum = (xorsum == INT_MIN) ? xorsum : xorsum & (-1 * xorsum);
        int type1 = 0;
        int type2 = 0;
        for (auto i : nums){
            if (xorsum & i){
                type1 ^= i;
            } else {
                type2 ^= i; 
            }
        }
        return {type1,type2};

    }
};
```



## LeetCode268

[丢失的数字](https://leetcode.cn/problems/missing-number/)

```c++
输入：nums = [0,1]
输出：2
解释：n = 2，因为有 2 个数字，所以所有的数字都在范围 [0,2] 内。2 是丢失的数字，因为它没有出现在 nums 中。
```

```c++
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++){
            ans ^= nums[i];
        }
        for (int i = 0; i <= nums.size(); i++){
            ans ^= i;
        }
        return ans;

    }
};
```

