#include<iostream>
#include<vector>
using namespace std;

// class Solution {
// public:
//     int Search(vector<int>& nums, int target) {
//         // 二分查找，时间复杂度 O(log n)
//         int left = 0;
//         int right = nums.size() - 1;

//         while (left <= right) {
//             int mid = left + (right - left) / 2;
//             if (nums[mid] == target) {
//                 return mid;
//             } else if (nums[mid] < target) {
//                 left = mid + 1;
//             } else {
//                 right = mid - 1;
//             }
//         }

//         return -1;
//     }
// };

class Solution{
public:
    int Search(vector<int> &nums,int target){
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            int mid=left+(right-left);
            if(nums[mid]==target){
                return mid;
            }else if (nums[mid]<target){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return 0;
    }

};

//主函数
int main() {
    vector<int> nums = {2, 7, 11, 15,18};
    int target = 11;
    Solution sol;
    int res = sol.Search(nums, target);
    // 打印结果
    // cout << "Result: ";
    // for (size_t i = 0; i < res.size(); i++) {
    //     cout << res[i];
    //     if (i < res.size() - 1) cout << " ";
    // }
    cout<<res;
    cout << endl;
    return 0;
}