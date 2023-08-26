#include "function.h"

//获取某位上的值
int getDigit(int num, int digit) {
	int divisor = 1;
	for (int i = 0; i < digit; i++) {
		divisor *= 10;
	}
	return (num / divisor) % 10;
}

void radix_sort(vector<int>& nums) {
	int n = nums.size();

	//找到数组最大值
	int maxNum = *max_element(nums.begin(), nums.end());

	//计算最大值的位数
	int maxDigits = 0;
	while (maxNum > 0) {
		maxNum /= 10;
		maxDigits++;
	}

	//创建10个桶
	vector<vector<int>> buckets(10);

	//根据位数进行排序
	for (int digit = 0; digit < maxDigits; digit++) {
		//将元素分配到桶中
		for (int i = 0; i < n; i++) {
			int bucketIndex = getDigit(nums[i], digit);
			buckets[bucketIndex].push_back(nums[i]);
		}

		//将桶中元素放回原始数组
		int index = 0;
		for (int i = 0; i < 10; i++) {
			for (int num : buckets[i]) {
				nums[index++] = num;
			}
			buckets[i].clear();
		}
	}
}