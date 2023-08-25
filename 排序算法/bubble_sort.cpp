#include "function.h"

void bubble_sort(vector<int>& nums) {
	int n = nums.size();

	//进行n-1轮排序
	for (int i = 0; i < n - 1; i++) {
		//每轮比较相邻两个元素
		//每轮将最大的元素冒泡到最后面
		for (int j = 0; j < n - i - 1; j++) {
			if (nums[j] > nums[j + 1]) {
				swap(nums[j], nums[j + 1]);
			}
		}
	}
}