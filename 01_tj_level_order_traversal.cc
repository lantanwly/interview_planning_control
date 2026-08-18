#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;              // 节点值
    TreeNode* left;       // 左子树指针
    TreeNode* right;      // 右子树指针

    // 默认构造函数：创建一个值为 0 的空节点
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    // 单值构造函数：只给当前节点赋值，左右子树为空
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    // 三参数构造函数：给当前节点及左右子树一起构造
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         // result 是最终返回的二维数组；它的形式类似：
//         // [[3], [9,20], [15,7]]
//         // 外层 vector 表示不同层，内层 vector 表示某一层的节点值
//         vector<vector<int>> result;

//         // 如果根节点为空，说明这棵树没有任何节点
//         // 层序遍历当然返回空数组 []
//         if (root == nullptr) {
//             return result;
//         }

//         // 使用队列实现 BFS（Breadth-First Search，广度优先搜索）
//         // 关键思想：先访问当前层节点，再访问下一层节点
//         // 队列中保存的是“待处理的节点”，顺序遵循先进先出（FIFO）
//         queue<TreeNode*> q;

//         // 先把根节点加入队列，作为第一层的开始
//         q.push(root);

//         // 只要队列不为空，就说明还存在待处理的节点
//         while (!q.empty()) {
//             // 这一行非常关键：获取当前层的节点数量
//             // 因为队列中可能包含下一层节点，所以不能直接把整个队列都拿来处理
//             // 这里的 levelSize 表示“当前层有多少个节点”
//             int levelSize = q.size();

//             // 用于存放当前层所有节点的值
//             vector<int> levelValues;

//             // 预先给当前层分配 levelSize 大小的空间，减少扩容开销
//             levelValues.reserve(levelSize);

//             // 处理当前层的所有节点
//             for (int i = 0; i < levelSize; ++i) {
//                 // 取出队头节点（当前层最左边的节点）
//                 TreeNode* node = q.front();
//                 q.pop();

//                 // 把当前节点的值加入当前层的数组
//                 levelValues.push_back(node->val);

//                 // 把左右孩子加入队列，准备下一层处理
//                 // 如果某个孩子为空，就不入队
//                 if (node->left != nullptr) {
//                     q.push(node->left);
//                 }
//                 if (node->right != nullptr) {
//                     q.push(node->right);
//                 }
//             }

//             // 当前层所有节点都处理完了，把这一层结果放进总结果里
//             result.push_back(levelValues);
//         }

//         // 返回二维数组，表示逐层遍历结果
//         return result;
//     }
// };

class Solution{
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        //使用容器存放结果
        vector<vector<int>> result;
        if(root==nullptr){
            return result;
        }
        //使用一个队列存放Node
        queue<TreeNode*> q;
        //将root压入
        q.push(root);
        while (!q.empty())
        {   
            //记录当前层的节点数
            int levelsize=q.size();
            vector<int> team;  //用于存放当前层的值
            team.reserve(levelsize);  //节省空间
            for(int i=0;i<levelsize;i++){
                TreeNode*Node=q.front();
                q.pop();
                team.push_back(Node->val);
                //将子节点压入队列
                if(Node->left!=nullptr){
                    q.push(Node->left);
                }
                if(Node->right!=nullptr){
                    q.push(Node->right);
                }

            }
            result.push_back(team);
        }
        return result;
        
    }
};

// 打印二维数组，方便在 main 中看结果
// 例如输出：[[3], [9, 20], [15, 7]]
void printLevelOrder(const vector<vector<int>>& ans) {
    cout << "[";
    for (size_t i = 0; i < ans.size(); ++i) {
        if (i > 0) cout << ", ";
        cout << "[";
        for (size_t j = 0; j < ans[i].size(); ++j) {
            if (j > 0) cout << ", ";
            cout << ans[i][j];
        }
        cout << "]";
    }
    cout << "]" << endl;
}

int main() {
    Solution s;

    // 示例 1：
    //      3
    //     / \
    //    9  20
    //      /  \
    //     15  7
    // 层序遍历结果应为 [[3], [9,20], [15,7]]
    TreeNode* root1 = new TreeNode(3,
        new TreeNode(9),
        new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    vector<vector<int>> ans1 = s.levelOrder(root1);
    printLevelOrder(ans1);

    // 示例 2：只有一个节点
    // 结果：[[1]]
    TreeNode* root2 = new TreeNode(1);
    vector<vector<int>> ans2 = s.levelOrder(root2);
    printLevelOrder(ans2);

    // 示例 3：空树
    // 结果：[]
    TreeNode* root3 = nullptr;
    vector<vector<int>> ans3 = s.levelOrder(root3);
    printLevelOrder(ans3);

    return 0;
}
