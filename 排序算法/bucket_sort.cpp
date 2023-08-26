#include "function.h"

void bucket_sort(vector<int>& nums) {
	int n = nums.size();

	//����Ͱ
	vector<vector<int>> buckets(n);
	
	//��Ԫ�ط��䵽Ͱ��
	for (int i = 0; i < n; i++) {
		int bucketIndex = nums[i]/10;	//ӳ�亯��Ϊ�ؼ�������������Ϊnums[i]/10
		buckets[bucketIndex].push_back(nums[i]);
	}

	//��ÿ��Ͱ�ڵ�Ԫ�ؽ�������
	for (int i = 0; i < n; i++) {
		sort(buckets[i].begin(), buckets[i].end());
	}

	//��������Ԫ�طŻ�ԭʼ����
	int index = 0;
	for (int i = 0; i < n; i++) {
		for (int num : buckets[i]) {
			nums[index++] = num;
		}
	}
}
