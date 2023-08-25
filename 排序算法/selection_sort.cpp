#include "function.h"

void selection_sort(vector<int>& nums) {
	int n = nums.size();
	
	for (int i = 0; i < n - 1; i++) {
		//记录最小索引
		int minIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (nums[j] < nums[minIndex]) {	// 寻找最小的数
				minIndex = j;	// 寻找最小的数
			}
		}
		if (minIndex != i) {
			swap(nums[i], nums[minIndex]);
		}
	}
}