#include "function.h"

void bucket_sort(vector<int>& nums) {
	int n = nums.size();

	//创建桶
	vector<vector<int>> buckets(n);
	
	//将元素分配到桶中
	for (int i = 0; i < n; i++) {
		int bucketIndex = nums[i]/10;	//映射函数为关键，在这里设置为nums[i]/10
		buckets[bucketIndex].push_back(nums[i]);
	}

	//对每个桶内的元素进行排序
	for (int i = 0; i < n; i++) {
		sort(buckets[i].begin(), buckets[i].end());
	}

	//将排序后的元素放回原始数组
	int index = 0;
	for (int i = 0; i < n; i++) {
		for (int num : buckets[i]) {
			nums[index++] = num;
		}
	}
}
