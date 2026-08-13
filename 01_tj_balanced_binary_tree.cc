#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// class Solution {
// public:
//     // 返回当前子树的高度；如果发现某个节点的左右子树高度差 > 1，说明整棵树不平衡
//     // 这里用 -1 作为“异常/不平衡”的标记
//     int height(TreeNode* root) {
//         // 空树高度为 0
//         if (root == nullptr) {
//             return 0;
//         }

//         // 递归求左子树高度
//         int leftHeight = height(root->left);
//         if (leftHeight == -1) {
//             return -1;  // 左子树已经不平衡，直接向上返回
//         }

//         // 递归求右子树高度
//         int rightHeight = height(root->right);
//         if (rightHeight == -1) {
//             return -1;  // 右子树已经不平衡，直接向上返回
//         }

//         // 如果左右子树高度差大于 1，当前节点所在子树不平衡
//         if (abs(leftHeight - rightHeight) > 1) {
//             return -1;
//         }

//         // 当前子树高度是左右子树最大高度 + 1
//         return max(leftHeight, rightHeight) + 1;
//     }

//     // 判断整棵树是否平衡
//     bool isBalanced(TreeNode* root) {
//         return height(root) != -1;
//     }
// };
// class Solution{
// public:
//     int height(TreeNode* root){
//         if(root==nullptr){
//             return 0;
//         }
//         if(height(root->left)==-1){
//             return -1;
//         }
//         if(height(root->right)==-1){
//             return -1;
//         }
//         int leftheight=height(root->left);
//         int rightheight=height(root->right);
//         if(abs(leftheight-rightheight)>1){
//             return -1;
//         }
//         return max(leftheight,rightheight)+1;
//     }
//     bool isBalanced(TreeNode*root){
//         return (height(root)!=-1);
//     }
// };

class Solution{
public:
    int height(TreeNode*root){
        if(root==nullptr){
            return 0;
        }
        TreeNode*leftheight=root->left;
        TreeNode*rightheight=root->right;
        //当左右是非平衡树时，返回-1
        if(height(rightheight)==-1){
            return -1;
        }
        if(height(leftheight)==-1){
            return -1;
        }
        if(abs(height(leftheight)-height(rightheight))>1){
            return -1;
        }
        return max(height(leftheight),height(rightheight))+1;
    }

    bool isBalanced(TreeNode*root){
        return (height(root)!=-1);
    }
};


int main() {
    Solution solution;
    cout << boolalpha;

    // 示例 1：平衡二叉树
    //       3
    //      / \
    //     9  20
    //       /  \
    //      15  7
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);
    cout << solution.isBalanced(root1) << '\n';

    // 示例 2：不平衡二叉树
    //        1
    //       / \
    //      2   2
    //     / \
    //    3   3
    //   / \
    //  4   4
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(2);
    root2->left->left = new TreeNode(3);
    root2->left->right = new TreeNode(3);
    root2->left->left->left = new TreeNode(4);
    root2->left->left->right = new TreeNode(4);
    cout << solution.isBalanced(root2) << '\n';

    // 示例 3：空树，按题意算平衡
    TreeNode* root3 = nullptr;
    cout << solution.isBalanced(root3) << '\n';

    return 0;
}

