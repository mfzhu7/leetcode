# LeetCode-矩阵操作篇

leetcode36 

[有效的数独](https://leetcode.cn/problems/valid-sudoku/)

> 矩阵操作

```c++
输入：board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
输出：true
```



```c++
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][10] = {0}; //记录行信息
        int col[9][10] = {0}; //记录列信息
        int box[9][10] = {0}; //记录斜对角信息，当然也可以用3*3*9
        
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (board[i][j] == '.') continue; //空格跳过
                int currNum = board[i][j] - '0';
                if(row[i][currNum]) return false; //i行信息判断是否已经出现相同数字
                if(col[j][currNum]) return false; //j列信息判断是否已经出现相同信息
                if(box[j/3+ (i/3)*3][currNum]) return false;
                //关键点在于此次，j/3+ (i/3)*3表示第几个9*9的子矩阵
                row[i][currNum] = 1;
                col[j][currNum] = 1;
                box[j/3+ (i/3)*3][currNum] = 1; //如果不曾出现，赋值对应位置，记录表明已经出现
            }
        }
        return true;
    }
};
```

leetcode 48 

[旋转图像](https://leetcode.cn/problems/rotate-image/)

```c++
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[[7,4,1],[8,5,2],[9,6,3]]
```

```c++
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++){
            for (int j = 0; j < (n + 1)/ 2; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = temp;
            }
        } 
 		// 通过分析旋转的规律，可以知道(i,j)->(j, n-i-1)
        return;
    }
};
```

leetcode 54 

[螺旋矩阵](https://leetcode.cn/problems/spiral-matrix/)

> 矩阵遍历

```c++
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
```

```c++
class Solution {
public:
void helper(vector<vector<int>>& matrix, int x1, int y1, int x2, int y2, vector<int>& path){
        if (x1 > x2 || y1 > y2) return;

        if (x1 == x2 && y1 != y2){
            for (int i = y1; i <= y2; i++){
            path.push_back(matrix[x1][i]);
            }
        } 
        else if (x1 != x2 && y1 == y2){
            for (int i = x1; i <= x2; i++){
                path.push_back(matrix[i][y1]);
                }   
        } 
        else if (x1 == x1 && y1 == y2){
            path.push_back(matrix[x1][y1]);
        } else {
            for (int i = y1; i <= y2; i++){
                path.push_back(matrix[x1][i]);
            }
            for (int i = x1 + 1; i <= x2; i++){
                path.push_back(matrix[i][y2]);
            }
            for (int i = y2 - 1; i >= y1; i--){
                path.push_back(matrix[x2][i]);
            }
            for (int i = x2 - 1; i > x1; i--){
                path.push_back(matrix[i][y1]);
            }
        }
        helper(matrix, x1 + 1,y1 + 1,x2 - 1, y2 - 1, path);
        return;
    };
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>path;
        helper(matrix,0,0,matrix.size() - 1, matrix[0].size() - 1,path);
        return path;
    }
};
```

## leetcode59 

[螺旋矩阵 II](https://leetcode.cn/problems/spiral-matrix-ii/)

> 矩阵遍历操作

```c++
输入：n = 3
输出：[[1,2,3],[8,9,4],[7,6,5]]
```

```c++
class Solution {
public:
void helper(vector<vector<int>>& matrix, int x1, int y1, int x2, int y2, int& curr){
        if (x1 > x2 || y1 > y2) return;
        
        if (x1 == x1 && y1 == y2){
            matrix[x1][y1] = curr;
            return;
        } else {
            for (int i = y1; i <= y2; i++){
                matrix[x1][i] = curr;
                curr = curr + 1;
            }
            for (int i = x1 + 1; i <= x2; i++){
                matrix[i][y2] = curr;
                curr = curr + 1;
            }
            for (int i = y2 - 1; i >= y1; i--){
                matrix[x2][i] = curr;
                curr =curr + 1;
            }
            for (int i = x2 - 1; i > x1; i--){
                matrix[i][y1] = curr;
                curr = curr + 1;
            }
        }
        helper(matrix,x1+1,y1+1,x2-1,y2-1,curr);
        return;

    };
    vector<vector<int>> generateMatrix(int n) {
        vector<int> row(n,0);
        vector<vector<int>> ret(n, row);
        int curr = 1;
        helper(ret,0,0,n-1,n-1,curr);
        return ret;
    }
};
```

## leetcode73

[矩阵置零](https://leetcode.cn/problems/set-matrix-zeroes/)

> 矩阵操作

```c++
输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
```



```c++
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> row;
        set<int> col;
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[0].size(); j++){
                if (matrix[i][j] == 0){
                    row.insert(i);
                    col.insert(j);
                }
            } //找到所有出现过0的行和列
        }
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[0].size(); j++){
                if (row.find(i) != row.end() || col.find(j) != col.end()){
                    matrix[i][j] = 0;
                }
            }
        } //对行和列进行置0操作
        return;
    }
};
```

## LeetCode74 

[搜索二维矩阵](https://leetcode.cn/problems/search-a-2d-matrix/)

> 矩阵操作

```c++
输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
输出：false
```



```c++
class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int start = 0;
        int end = matrix.size() * matrix[0].size() - 1;

        while(start <= end){
            int mid = start + (end - start) / 2;
            int i = mid / col;
            int j = mid % col;
            if (matrix[i][j] == target) return true;
            if (matrix[i][j] > target){
                end = mid - 1;
            } else {
                start = mid + 1; //二分查找，主要是行和列的变化
            }
        }
        return false;

    }
};
```