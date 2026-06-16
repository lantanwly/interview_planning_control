#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	// 返回移除 val 后数组中不等于 val 的元素个数 k
	int removeElement(vector<int>& nums, int val) {
		int j = 0; // 慢指针，指向下一个写入位置
		for (int i = 0; i < (int)nums.size(); ++i) {
			if (nums[i] != val) {
				nums[j++] = nums[i];
			}
		}
		return j;
	}
};

int main() {
	vector<int> nums = {3, 2, 2, 3};
	int val = 3;
	Solution sol;
	int k = sol.removeElement(nums, val);

	cout << "k = " << k << "\n";
	cout << "nums (first k elements): ";
	for (int i = 0; i < k; ++i) cout << nums[i] << (i + 1 < k ? ' ' : '\n');

	// 简单断言（仅用于本地验证）
	vector<int> expected = {2, 2};
	sort(nums.begin(), nums.begin() + k);
	sort(expected.begin(), expected.end());
	if (k == (int)expected.size()) {
		bool ok = true;
		for (int i = 0; i < k; ++i) if (nums[i] != expected[i]) ok = false;
		cout << (ok ? "Test passed\n" : "Test failed\n");
	} else {
		cout << "Test failed\n";
	}

	return 0;
}

