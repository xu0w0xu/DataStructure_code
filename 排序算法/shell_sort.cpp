#include"function.h"

void shell_sort(vector<int>& nums) {
	int n = nums.size();
	
	//使用希尔增量排序
	for (int gap = n / 2; gap > 0; gap /= 2) {
		//对每个子数组进行插入排序
		for (int i = gap; i < n; i++) {
			int temp = nums[i];
			int j = i;
			while (j >= gap && nums[j - gap] > temp) {
				nums[j] = nums[j - gap];
				j -= gap;
			}
			nums[j] = temp;

			////逐步显示输出
			//for (int num : nums) {
			//	cout << num << " ";
			//}
			//cout << endl;
		}
	}
}