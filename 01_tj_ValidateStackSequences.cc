#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// class Solution {
// public:
//     bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
//         stack<int> st;
//         int n = pushed.size();
//         for (int i = 0, j = 0; i < n; i++) {
//             st.emplace(pushed[i]);  //将数据压入栈内
//             //循环使用栈顶去匹配popped数组
//             //!empty()主要是处理st.pop()之后为空，避免st.top()错误
//             while (!st.empty() && st.top() == popped[j]) {
//                 st.pop();
//                 j++;
//             }
//         }
//         return st.empty();
//     }
// };

class Solution{
public:
    bool validateStackSequences(vector<int> &pushed,vector<int> &poped){
        int n=pushed.size();
        stack<int> st;
        for(int i=0,j=0;i<n;i++){
            st.emplace(pushed[i]);
            while(!st.empty()&&st.top()==poped[j]){
                st.pop();
                j++;
            }
        }
        return st.empty();
    }
};

int main() {
    Solution solution;

    // 示例 1：可以通过栈操作得到
    vector<int> pushed1 = {1, 2, 3, 4, 5};
    vector<int> popped1 = {4, 5, 3, 2, 1};
    cout << boolalpha << solution.validateStackSequences(pushed1, popped1) << '\n';

    // 示例 2：不可能得到
    vector<int> pushed2 = {1, 2, 3, 4, 5};
    vector<int> popped2 = {4, 3, 5, 1, 2};
    cout << boolalpha << solution.validateStackSequences(pushed2, popped2) << '\n';

    return 0;
}
