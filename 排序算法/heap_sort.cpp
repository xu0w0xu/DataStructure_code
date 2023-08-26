#include "function.h"

//�����ѵĺ���
void heapify(vector<int>& nums, int n, int i) {
	int largest = i;	//��ʼ�����Ԫ��Ϊ���ڵ�
	int left = 2 * i + 1;	//���ӽڵ������
	int right = 2 * i + 2;	//���ӽڵ������

	//������ӽڵ���ڸ��ڵ㣬�����Ԫ����������Ϊ���ӽڵ������
	if (left<n && nums[left]>nums[largest]) {
		largest = left;
	}

	// ������ӽڵ���ڵ�ǰ���Ԫ�أ������Ԫ����������Ϊ���ӽڵ�����
	if (right < n && nums[right] > nums[largest]) {
		largest = right;
	}

	//	������Ԫ�ز��Ǹ��ڵ㣬�������ڵ�����Ԫ��
	if (largest != i) {
		swap(nums[i], nums[largest]);

		//�ݹ�����������Ľڵ���ӽڵ�
		heapify(nums, n, largest);
	}
}

void heap_sort(vector<int>& nums) {
	int n = nums.size();

	//�������ѣ������һ����Ҷ�ӽ�㿪ʼ�����ѵĽṹ
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(nums, n, i);
	}

	//�Ӷѵ�ĩβ��ʼ����������Ԫ�طŵ������򲿷ֵ�ĩβ
	for (int i = n - 1; i > 0; i--) {
		//����ǰ���ڵ�(���Ԫ�أ���δ���򲿷ֵ����һ��Ԫ�ؽ���
		swap(nums[0], nums[i]);

		//���µ����ѽṹ�����Ը��ڵ���е���
		heapify(nums, i, 0);
	}
}