#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// class Solution {
// public:
//     // 使用广度优先搜索 (BFS) 统计岛屿数量
//     // 主要步骤：
//     // 1. 遍历网格，遇到 '1'（未访问的陆地）时，说明发现了一个新的岛屿，计数 +1。
//     // 2. 以该格子为起点做 BFS（或 DFS），将该岛屿上所有相连的陆地全部标记为已访问（这里直接改为 '0' 表示水），
//     //    以免以后重复计数。
//     // 3. 继续扫描剩余格子，直到遍历完整个网格。
//     // 采用迭代的 BFS 可以避免递归深度问题（grid 最大 300x300 时递归深度可能过大）。
//     // 参数：grid - m x n 网格，'1' 表示陆地，'0' 表示水。
//     int numIslands(vector<vector<char>>& grid) {
//         int m = grid.size();//行数
//         if (m == 0) return 0;            // 空网格没有岛屿
//         int n = grid[0].size();//列数

//         int islands = 0;                 // 最终岛屿数量

//         // 方向向量，按上下左右四个方向扩展
//         const int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

//         // 遍历网格的每个位置
//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 // 发现一个未访问的陆地，说明找到了新的岛屿
//                 if (grid[i][j] == '1') {
//                     ++islands;                 // 岛屿计数加一

//                     // 将该格标记为已访问，避免入队重复
//                     grid[i][j] = '0';

//                     // 使用队列做 BFS，从 (i,j) 开始将整个连通块标记为已访问
//                     queue<pair<int,int>> q;
//                     q.emplace(i,j);

//                     while (!q.empty()) {
//                         auto [r,c] = q.front(); q.pop();

//                         // 检查四个邻居位置
//                         for (int k = 0; k < 4; ++k) {
//                             int nr = r + dirs[k][0];
//                             int nc = c + dirs[k][1];

//                             // 边界检查以及是否为未访问的陆地
//                             if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == '1') {
//                                 grid[nr][nc] = '0'; // 标记为已访问，防止重复入队
//                                 q.emplace(nr,nc);
//                             }
//                         }
//                     }
//                     // 到这里，整个岛屿已经被标记完毕，继续扫描下一个位置
//                 }
//             }
//         }

//         return islands;
//     }
// };

// class Solution{
// public:
//     int numIslands(vector<vector<char>>& grid){
//         //行数
//         int m=grid.size();
//         if(m==0){
//             return 0;
//         }
//         //列数
//         int n=grid[0].size();
//         //开始遍历所有数
//         //岛屿数
//         int island=0;
//         //四个方向向量
//         const int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(grid[i][j]=='1'){
//                     island++;
//                     grid[i][j]='0';  //将当前值改为0,避免重复计数
//                     queue<pair<int,int>> q;
//                     q.emplace(i,j);
//                     while(!q.empty()){
//                         auto [r,c]=q.front();q.pop();
//                         for(int k=0;k<4;k++){
//                             //遍历周围的点
//                             int nr=r+dir[k][0];
//                             int nc=c+dir[k][1];
//                             if(nr>=0&&nr<m&&nc>=0&&nc<n&&grid[nr][nc]=='1'){
//                                 grid[nr][nc]='0';
//                                 q.emplace(nr,nc);
//                             }
//                         }
//                     }
//                 }
                
//             }
//         }
//         return island;
        
//     }

// };

class Solution{
    public:
    int numIslands(vector<vector<char>>&grid){
        //行数,列数
        int m=grid.size();
        if(m==0){
            return 0;
        }
        int n=grid[0].size();
        int island=0;
        //方向向量
        const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    island++;
                    grid[i][j]='0';
                    //BFS寻找周边的1
                    queue<pair<int,int>> q;
                    q.emplace(i,j);
                    while(!q.empty()){
                        auto [r,c]=q.front();q.pop();
                        for(int k=0;k<4;k++){
                            int nr=r+dir[k][0];
                            int nc=c+dir[k][1];
                            if(nr>=0&&nr<m&&nc>=0&&nc<n&&grid[nr][nc]=='1'){
                                grid[nr][nc]='0';
                                q.emplace(nr,nc);
                            }
                        }
                    }
                }
            }
        }

        return island;

    }
};

// 主函数：包含示例测试，方便手动验证
int main() {
    Solution sol;

    vector<vector<char>> grid1 = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };

    vector<vector<char>> grid2 = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    // 运行并打印结果，分别对应题目示例 1 和示例 2
    cout << sol.numIslands(grid1) << '\n'; // 期望输出 1
    cout << sol.numIslands(grid2) << '\n'; // 期望输出 3

    return 0;
}
