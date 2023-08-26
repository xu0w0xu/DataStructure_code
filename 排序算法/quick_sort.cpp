#include "function.h"

//快排分割函数
int partition(vector<int>& nums, int low, int high) {
	int pivot = nums[high];	//选取最后一个元素为基准元素
	int i = low - 1;	//i记录小于基准元素的位置

	for (int j = low; j < high; j++) {
		if (nums[j] <= pivot) {
			i++;
			swap(nums[i], nums[j]);	//将小于基准元素的元素交换到左侧
		}
	}

	swap(nums[i + 1], nums[high]);	//放置基准元素
	return i + 1;
}

void quickSort(vector<int>& nums, int low, int high) {
	if (low < high) {
		int pi = partition(nums, low, high);
		quickSort(nums, low, pi - 1);
		quickSort(nums, pi + 1, high);
	}
}

void quick_sort(vector<int> &nums) {
	quickSort(nums, 0, nums.size() - 1);
}