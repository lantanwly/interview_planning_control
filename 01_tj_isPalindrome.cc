#include <cctype>   // isalnum, tolower
#include <iostream>  // cout
#include <string>
#include <vector>

using namespace std;

// class Solution {
// public:
//     // 判断字符串是否为回文串，忽略非字母数字字符，并且不区分大小写
//     bool isPalindrome(string s) {
//         int i = 0;
//         int j = int(s.size()) - 1;

//         // 从字符串两端向中间逼近
//         while (i < j) {
//             // 左指针遇到非字母数字字符时跳过
//             while (i < j && !isalnum(static_cast<unsigned char>(s[i]))) {
//                 ++i;
//             }
//             // 右指针遇到非字母数字字符时跳过
//             while (i < j && !isalnum(static_cast<unsigned char>(s[j]))) {
//                 --j;
//             }
//             // 此时 i <= j，比较当前两个字符的小写形式
//             if (tolower(static_cast<unsigned char>(s[i])) != tolower(static_cast<unsigned char>(s[j]))) {
//                 return false;
//             }
//             ++i;
//             --j;
//         }

//         // 所有可比较字符都匹配，则为回文串
//         return true;
//     }
// };

// class Solution{
//     public:
//     bool isPalindrome(string s){
//         int i=0;
//         int j=int(s.size())-1;
//         while(i<j){
//             while(i<j&&!isalnum(static_cast<unsigned char>(s[i]))){
//                 i++;
//             }
//             while(i<j&&!isalnum(static_cast<unsigned char>(s[j]))){
//                 j--;
//             }
//             if(tolower(static_cast<unsigned char>(s[i]))!=tolower(static_cast<unsigned char>(s[j]))){
//                 return false;
//             }
//             i++;
//             j--;
//         }
//         return true;
//     }
// };

class Solution{
public:
    bool isPalindrome(string s){
        int i=0;
        int j=int(s.size())-1;
        while(i<j){
            while(i<j&&!isalnum(static_cast<unsigned char>(s[i]))){
                i++;
            }
            while(i<j&&!isalnum(static_cast<unsigned char>(s[j]))){
                j--;
            }
            if(tolower(static_cast<unsigned char>(s[i]))!=tolower(static_cast<unsigned char>(s[j]))){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};


int main() {
    Solution solution;

    // 测试样例
    vector<string> tests = {
        "A man, a plan, a canal: Panama",  // true
        "race a car",                      // false
        " ",                               // true
        "0P"                               // false
    };

    for (auto &test : tests) {
        bool result = solution.isPalindrome(test);
        cout << "Input: \"" << test << "\" -> " << (result ? "true" : "false") << '\n';
    }

    return 0;
}
