#include "function.h"

//���ŷָ��
int partition(vector<int>& nums, int low, int high) {
	int pivot = nums[high];	//ѡȡ���һ��Ԫ��Ϊ��׼Ԫ��
	int i = low - 1;	//i��¼С�ڻ�׼Ԫ�ص�λ��

	for (int j = low; j < high; j++) {
		if (nums[j] <= pivot) {
			i++;
			swap(nums[i], nums[j]);	//��С�ڻ�׼Ԫ�ص�Ԫ�ؽ��������
		}
	}

	swap(nums[i + 1], nums[high]);	//���û�׼Ԫ��
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