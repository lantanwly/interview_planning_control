#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         // 1) 统计每个数字出现的频次
//         //    例如 nums = [1,1,2,2,2,3]，那么 freq[1]=2, freq[2]=3, freq[3]=1
//         //    使用 unordered_map 让查找/插入的平均时间复杂度为 O(1)
//         unordered_map<int, int> freq;
//         for (int x : nums) {
//             ++freq[x];
//         }

//         // 2) 用小顶堆维护当前“前 k 高频元素”
//         //    堆中保存的是 {频次, 数字}，这样堆顶一定是当前最小频次的元素。
//         //    例如：如果 k = 2，堆中最多保存 2 个元素；若当前要加入第 3 个元素，
//         //    那么堆顶最小频次的元素就应该被弹出，确保堆中始终保留最高频的 k 个元素。
//         //    注意：priority_queue 默认是大顶堆；但通过 greater<pair<int,int>> 指定为小顶堆。
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

//         // 3) 遍历频次表，把每个数字和其出现次数放入堆中
//         //    这里使用 auto& [num, cnt] 进行结构化绑定，等价于：
//         //    for (const auto& entry : freq) {
//         //        int num = entry.first;
//         //        int cnt = entry.second;
//         //    }
//         for (auto& [num, cnt] : freq) {
//             minHeap.push({cnt, num});

//             // 只保留 k 个元素：如果堆太大，则把当前最小频次的元素弹掉
//             // 这样可以保证堆中保留的是“出现频率最高的 k 个元素”
//             if (minHeap.size() > static_cast<size_t>(k)) {
//                 minHeap.pop();
//             }
//         }

//         // 4) 从堆中取出剩余元素，构造返回结果
//         //    由于小顶堆的堆顶是最小频次，所以最终堆中元素就是前 k 高频元素。
//         //    但题目返回值不要求有序，因此这里直接取出即可。
//         vector<int> result;
//         result.reserve(k);//预留空间
//         while (!minHeap.empty()) {
//             result.push_back(minHeap.top().second);  // second 是数字本身
//             minHeap.pop();
//         }

//         return result;
//     }
// };
class Solution{
    public:
    vector<int> topKFrequent(vector<int>&nums ,int k){
        unordered_map<int,int> freq;
        for(int x:nums){
            freq[x]++;
        }
        //建立一个小顶堆
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>  miniHeap;
        //把freq取出来
        for(auto&[num,cnt]:freq){
            miniHeap.push({cnt,num});
            //只保留k个元素
            if(miniHeap.size()>static_cast<size_t>(k)){
                miniHeap.pop();
            }
        }
        vector<int> result;
        //预留空间
        result.reserve(k);
        while(!miniHeap.empty()){
            result.push_back(miniHeap.top().second);
            miniHeap.pop();
        }
        return result;


    }
};

int main() {
    Solution s;

    // 示例 1：nums = [1,1,1,2,2,3], k = 2
    // 频次为：1->3, 2->2, 3->1，结果应为 [1,2]（顺序不固定）
    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    vector<int> ans1 = s.topKFrequent(nums1, 2);
    for (int x : ans1) {
        cout << x << ' ';
    }
    cout << '\n';

    // 示例 2：nums = [1], k = 1
    // 只有一个元素，直接返回 [1]
    vector<int> nums2 = {1};
    vector<int> ans2 = s.topKFrequent(nums2, 1);
    for (int x : ans2) {
        cout << x << ' ';
    }
    cout << '\n';

    // 示例 3：nums = [1,2,1,2,1,2,3,1,3,2], k = 2
    // 频次为：1->4, 2->4, 3->2，所以结果为 [1,2] 或 [2,1]
    vector<int> nums3 = {1, 2, 1, 2, 1, 2, 3, 1, 3, 2};
    vector<int> ans3 = s.topKFrequent(nums3, 2);
    for (int x : ans3) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}
