#include "function.h"

void bubble_sort(vector<int>& nums) {
	int n = nums.size();

	//����n-1������
	for (int i = 0; i < n - 1; i++) {
		//ÿ�ֱȽ���������Ԫ��
		//ÿ�ֽ�����Ԫ��ð�ݵ������
		for (int j = 0; j < n - i - 1; j++) {
			if (nums[j] > nums[j + 1]) {
				swap(nums[j], nums[j + 1]);
			}
		}
	}
}