#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // removeElement 函数：原地移除 nums 中等于 val 的元素。
    // 返回值 k 表示移除后，数组中不等于 val 的元素个数。
    int removeElement(vector<int>& nums, int val) {
        int write = 0; // write 指针指向下一个写入位置

        // 遍历数组 nums 的每个元素
        for (int read = 0; read < static_cast<int>(nums.size()); ++read) {
            // 如果当前元素不等于 val，则将它写入 write 位置
            if (nums[read] != val) {
                nums[write] = nums[read];
                write++; // 写入后，write 向右移动一位
            }
            // 如果 nums[read] == val，则跳过该元素，不改变 write
        }

        // write 正好是不等于 val 的元素数量 k
        return write;
    }
};

int main() {
    // 测试用例：待处理数组 nums 和要移除的值 val
    vector<int> nums = {31, 12, 76, 9, 10, 4, 6};
    int val = 10;

    Solution solution;
    int k = solution.removeElement(nums, val); // 调用方法，获得不等于 val 的元素数量

    // 输出结果 k
    cout << "k = " << k << "\n";

    // 输出 nums 的前 k 个元素，这些元素都是不等于 val 的
    cout << "nums[0..k-1] = ";
    for (int i = 0; i < k; ++i) {
        cout << nums[i] << " ";
    }
    cout << "\n";

    return 0;
}
