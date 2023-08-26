#include "function.h"

//��ȡĳλ�ϵ�ֵ
int getDigit(int num, int digit) {
	int divisor = 1;
	for (int i = 0; i < digit; i++) {
		divisor *= 10;
	}
	return (num / divisor) % 10;
}

void radix_sort(vector<int>& nums) {
	int n = nums.size();

	//�ҵ��������ֵ
	int maxNum = *max_element(nums.begin(), nums.end());

	//�������ֵ��λ��
	int maxDigits = 0;
	while (maxNum > 0) {
		maxNum /= 10;
		maxDigits++;
	}

	//����10��Ͱ
	vector<vector<int>> buckets(10);

	//����λ����������
	for (int digit = 0; digit < maxDigits; digit++) {
		//��Ԫ�ط��䵽Ͱ��
		for (int i = 0; i < n; i++) {
			int bucketIndex = getDigit(nums[i], digit);
			buckets[bucketIndex].push_back(nums[i]);
		}

		//��Ͱ��Ԫ�طŻ�ԭʼ����
		int index = 0;
		for (int i = 0; i < 10; i++) {
			for (int num : buckets[i]) {
				nums[index++] = num;
			}
			buckets[i].clear();
		}
	}
}