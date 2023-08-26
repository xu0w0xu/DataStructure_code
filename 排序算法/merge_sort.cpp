#include "function.h"

void merge(vector<int>& nums, int left, int mid, int right) {
	int n1 = mid - left;
	int n2 = right - mid + 1;

	//������ʱ�������洢������������
	vector<int> L(n1);
	vector<int> R(n2);

	//�����ݸ��Ƶ���ʱ������
	for (int i = 0; i < n1; i++) {
		L[i] = nums[left + i];
	}
	for (int j = 0; j < n2; j++) {
		R[j] = nums[mid + j];
	}

	//�鲢��ʱ���鵽ԭʼ����
	int i = 0;	//�������������
	int j = 0;	//�������������
	int k = left;	//ԭʼ���������

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

	//����ʣ��Ԫ��
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

	nums = left; // �� left ������ֵ�� nums ����
	nums.insert(nums.end(), right.begin(), right.end());  // �� right �����е�Ԫ�ز��뵽 nums ������ĩβ

	merge(nums, 0, mid , n - 1);
}