#include <iostream>
#include <string>

using namespace std;

// class Solution {
// public:
//     // 判断 t 是否是 s 的字母异位词
//     bool isAnagram(string s, string t) {
//         // 长度不同，直接不是异位词
//         if (s.size() != t.size()) {
//             return false;
//         }

//         // 统计 26 个小写字母出现的次数
//         int count[26] = {0};

//         // 先统计 s 中每个字母出现次数
//         for (char c : s) {
//             ++count[c - 'a'];
//         }

//         // 再从 t 中减去对应字母次数
//         // 如果某个字母在 t 中出现次数超过 s 中的次数，就会变成负数
//         for (char c : t) {
//             --count[c - 'a'];
//             if (count[c - 'a'] < 0) {
//                 return false;
//             }
//         }

//         // 最后检查所有字母计数是否都回到了 0
//         for (int i = 0; i < 26; ++i) {
//             if (count[i] != 0) {
//                 return false;
//             }
//         }

//         return true;
//     }
// };

// class Solution{
// public:
//     bool isAnagram(string s,string t){
//         int count[26]={0};
//         for(char c:s){
//             ++count[c-'a'];
//         }
//         for(char c:t){
//             --count[c-'a'];
//             if(count[c-'a']<0){
//                 return false;
//             }
//         }
//         for(int i=0;i<26;i++){
//             if(count[i]!=0){
//                 return false;
//             }
//         }
//         return true;
//     }
// };
class Solution{
public:
    bool isAnagram(string s,string t){
        int count[26]={0}; //新建一个数组用来存储字母的个数
        for(char c:s){
            ++count[c-'a'];
        }
        for(char c:t){
            --count[c-'a'];
            if(count[c-'a']<0){
                return false;
            }
        }
        //判断一下，还有没有不为0的
        for(int i=0;i<26;i++){
            if(count[i]!=0){
                return false;
            }
        }
        return true;

    }

};

int main() {
    Solution solution;

    // 让输出显示 true/false，而不是 1/0
    cout << boolalpha;

    // 示例 1：anagram 和 nagaram 是异位词
    cout << solution.isAnagram("anagram", "nagaram") << '\n';

    // 示例 2：rat 和 car 不是异位词
    cout << solution.isAnagram("rat", "car") << '\n';

    return 0;
}