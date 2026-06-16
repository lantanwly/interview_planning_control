#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int, int> map; // 哈希表：数字 → 下标

//         for (int i = 0; i < nums.size(); i++) {
//             int x = nums[i];
//             int y = target - x;
//             //边查边放，避免重复，自己找的自己
//             // 1. 查 y 在不在表里
//             if (map.find(y) != map.end()) {  //map.end是队尾的空位，如果结果是这个空位，说明没找到
//                 return {map[y], i}; // 找到了！
//             }

//             // 2. 没找到就把 x 存进去
//             map[x] = i;
//         }

//         return {};
//     }
// };










class Solution{
public:
    vector<int> twoSum(vector<int>&nums,int target){
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            int y=target-x;
            if(map.find(y)!=map.end()){
                return{map[y],i};  //找到了这个值
            }
            //mot found,put x into map
            map[x]=i;
        }
        return {};

    }

};

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 18;
    Solution sol;
    vector<int> res = sol.twoSum(nums, target);
    // 打印结果
    cout << "Result: ";
    for (size_t i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i < res.size() - 1) cout << " ";
    }
    cout << endl;
    return 0;
}