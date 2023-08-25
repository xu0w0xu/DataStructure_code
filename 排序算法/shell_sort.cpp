#include"function.h"

void shell_sort(vector<int>& nums) {
	int n = nums.size();
	
	//ʹ��ϣ����������
	for (int gap = n / 2; gap > 0; gap /= 2) {
		//��ÿ����������в�������
		for (int i = gap; i < n; i++) {
			int temp = nums[i];
			int j = i;
			while (j >= gap && nums[j - gap] > temp) {
				nums[j] = nums[j - gap];
				j -= gap;
			}
			nums[j] = temp;

			////����ʾ���
			//for (int num : nums) {
			//	cout << num << " ";
			//}
			//cout << endl;
		}
	}
}