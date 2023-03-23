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

