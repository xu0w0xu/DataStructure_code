#include "function.h"

void merge(vector<int>& nums, int left, int mid, int right) {
	int n1 = mid - left;
	int n2 = right - mid + 1;

	//创建临时数组来存储左右两个数组
	vector<int> L(n1);
	vector<int> R(n2);

	//将数据复制到临时数组中
	for (int i = 0; i < n1; i++) {
		L[i] = nums[left + i];
	}
	for (int j = 0; j < n2; j++) {
		R[j] = nums[mid + j];
	}

	//归并临时数组到原始数组
	int i = 0;	//左子数组的索引
	int j = 0;	//右子数组的索引
	int k = left;	//原始数组的索引

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			nums[k] = L[i];
			i++;
		}
		else {
			nums[k] = R[j];
			j++;
		}
		k++;
	}

	//处理剩余元素
	while (i < n1) {
		nums[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		nums[k] = R[j];
		j++;
		k++;
	}
}

void merge_sort(vector<int>& nums) {
	int n = nums.size();
	if (n <= 1) {
		return;
	}
	int mid = n / 2;

	vector<int> left(nums.begin(), nums.begin() + mid);
	vector<int> right(nums.begin() + mid, nums.end());

	merge_sort(left);
	merge_sort(right);

	nums = left; // 将 left 向量赋值给 nums 向量
	nums.insert(nums.end(), right.begin(), right.end());  // 将 right 向量中的元素插入到 nums 向量的末尾

	merge(nums, 0, mid , n - 1);
}