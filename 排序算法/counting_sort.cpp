#include "function.h"

void counting_sort(vector<int>& nums) {
	int n = nums.size();

	//�ҵ���������ֵ����Сֵ
	int maxNum = *max_element(nums.begin(), nums.end());
	int minNum = *min_element(nums.begin(), nums.end());

	int range = maxNum - minNum + 1;	//������ֵ��Χ

	vector<int> count(range, 0);	//�����������鲢��ʼ��Ϊ0
	vector<int> output(n);	//�����������

	//ͳ��ÿ��Ԫ�صĳ��ִ���
	for (int i = 0; i < n; i++) {
		count[nums[i] - minNum]++;
	}

	//����ÿ��Ԫ�ص��ۼƴ���
	for (int i = 1; i < range; i++) {
		count[i] += count[i - 1];
	}

	//���ݼ������齫Ԫ�ط��õ���ȷ��λ����
	for (int i = n - 1; i >= 0; i--) {
		output[count[nums[i] - minNum] - 1] = nums[i];
		count[nums[i] - minNum]--;
	}

	//�����������鸴�ƻ�ԭ����
	for (int i = 0; i < n; i++) {
		nums[i] = output[i];
	}
}