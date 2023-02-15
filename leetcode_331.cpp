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