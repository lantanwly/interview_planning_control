#include <iostream>
#include <stack>
#include <string>
using namespace std;

// class Solution {
// public:
//     // 判断括号字符串是否有效
//     bool isValid(string s) {
//         // 用栈来保存还没有找到匹配右括号的左括号
//         stack<char> st;

//         // 从左到右扫描字符串中的每个字符
//         for (char c : s) {
//             // 如果是左括号，就压入栈中
//             if (c == '(' || c == '[' || c == '{') {
//                 st.push(c);
//             } else {
//                 // 如果遇到右括号，但栈里没有左括号可匹配，说明非法
//                 if (st.empty()) {
//                     return false;
//                 }

//                 // 看栈顶元素是否和当前右括号匹配
//                 char top = st.top();
//                 if ((c == ')' && top != '(') ||
//                     (c == ']' && top != '[') ||
//                     (c == '}' && top != '{')) {
//                     return false;
//                 }

//                 // 匹配成功，弹出栈顶左括号
//                 st.pop();
//             }
//         }

//         // 如果栈为空，说明所有左括号都被正确匹配了
//         return st.empty();
//     }
// };

class Solution{
public:
    bool isValid(string s){
        //使用栈来解决
        stack<char> st;
        for(char c:s){
            if(c=='{'||c=='('||c=='['){
                st.push(c);
            }
            else{
                if(st.empty()){
                    return false;
                }
                char top=st.top();
                if((c==')'&&top!='(')||
                (c=='}'&&top!='{')||
                (c==']'&&top!='[')){
                    return false;
                }
                st.pop();
            }
            
        }
        return st.empty();
    }
};

int main() {
    Solution s;

    cout << boolalpha;

    // 示例 1：() 是有效的
    cout << "()" << " -> " << s.isValid("()") << endl;

    // 示例 2：()[]{} 是有效的
    cout << "()[]{}" << " -> " << s.isValid("()[]{}") << endl;

    // 示例 3：(] 是无效的
    cout << "(]" << " -> " << s.isValid("(]") << endl;

    // 示例 4：([]) 是有效的
    cout << "([])" << " -> " << s.isValid("([])") << endl;

    // 示例 5：([)] 是无效的
    cout << "([)]" << " -> " << s.isValid("([)]") << endl;

    return 0;
}
