#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        // m 行，n 列
        int m = grid.size();
        int n = grid[0].size();

        // answer[r][c] 表示当前格子在矩阵中的答案
        // 计算方法：|左上对角线不同值个数 - 右下对角线不同值个数|
        vector<vector<int>> answer(m, vector<int>(n, 0));

        // 逐个枚举每个位置 (r, c)
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                // 1) 统计左上对角线上的不同值个数
                //    左上对角线指的是当前格子向左上方向延伸的同一条对角线
                //    例如：当前点 (r, c)，它的左上方向是 (r-1, c-1), (r-2, c-2), ...
                //    这些点都满足：行 - 列 = 常数（即同一条对角线）
                unordered_set<int> topLeft;
                for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; --i, --j) {
                    topLeft.insert(grid[i][j]);
                }
                
                // 2) 统计右下对角线上的不同值个数
                //    右下对角线指的是当前格子向右下方向延伸的同一条对角线
                //    例如：当前点 (r, c)，它的右下方向是 (r+1, c+1), (r+2, c+2), ...
                //    这些点也满足：行 - 列 = 常数
                unordered_set<int> bottomRight;
                for (int i = r + 1, j = c + 1; i < m && j < n; ++i, ++j) {
                    bottomRight.insert(grid[i][j]);
                }

                // 3) 绝对值差就是当前格子的答案
                answer[r][c] = abs(static_cast<int>(topLeft.size()) - static_cast<int>(bottomRight.size()));
            }
        }

        return answer;
    }
};

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int x : row) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}

int main() {
    Solution s;

    // 示例 1
    vector<vector<int>> grid1 = {
        {1, 2, 3},
        {3, 1, 5},
        {3, 2, 1}
    };
    cout << "示例 1:\n";
    printMatrix(s.differenceOfDistinctValues(grid1));

    // 示例 2
    vector<vector<int>> grid2 = {{1}};
    cout << "\n示例 2:\n";
    printMatrix(s.differenceOfDistinctValues(grid2));

    return 0;
}
