#include "function.h"

void selection_sort(vector<int>& nums) {
	int n = nums.size();
	
	for (int i = 0; i < n - 1; i++) {
		//��¼��С����
		int minIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (nums[j] < nums[minIndex]) {	// Ѱ����С����
				minIndex = j;	// Ѱ����С����
			}
		}
		if (minIndex != i) {
			swap(nums[i], nums[minIndex]);
		}
	}
}