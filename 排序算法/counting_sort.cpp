#include "function.h"

void counting_sort(vector<int>& nums) {
	int n = nums.size();

	//找到数组的最大值和最小值
	int maxNum = *max_element(nums.begin(), nums.end());
	int minNum = *min_element(nums.begin(), nums.end());

	int range = maxNum - minNum + 1;	//计算数值范围

	vector<int> count(range, 0);	//创建计数数组并初始化为0
	vector<int> output(n);	//创建输出数组

	//统计每个元素的出现次数
	for (int i = 0; i < n; i++) {
		count[nums[i] - minNum]++;
	}

	//计算每个元素的累计次数
	for (int i = 1; i < range; i++) {
		count[i] += count[i - 1];
	}

	//根据计数数组将元素放置到正确的位置上
	for (int i = n - 1; i >= 0; i--) {
		output[count[nums[i] - minNum] - 1] = nums[i];
		count[nums[i] - minNum]--;
	}

	//将排序后的数组复制回原数组
	for (int i = 0; i < n; i++) {
		nums[i] = output[i];
	}
}