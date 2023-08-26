#include "function.h"

//调整堆的函数
void heapify(vector<int>& nums, int n, int i) {
	int largest = i;	//初始化最大元素为根节点
	int left = 2 * i + 1;	//左子节点的索引
	int right = 2 * i + 2;	//右子节点的索引

	//如果左子节点大于根节点，将最大元素索引更新为左子节点的索引
	if (left<n && nums[left]>nums[largest]) {
		largest = left;
	}

	// 如果右子节点大于当前最大元素，将最大元素索引更新为右子节点索引
	if (right < n && nums[right] > nums[largest]) {
		largest = right;
	}

	//	如果最大元素不是根节点，交换根节点和最大元素
	if (largest != i) {
		swap(nums[i], nums[largest]);

		//递归调整被交换的节点的子节点
		heapify(nums, n, largest);
	}
}

void heap_sort(vector<int>& nums) {
	int n = nums.size();

	//构建最大堆，从最后一个非叶子结点开始调整堆的结构
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(nums, n, i);
	}

	//从堆的末尾开始，逐个将最大元素放到已排序部分的末尾
	for (int i = n - 1; i > 0; i--) {
		//将当前根节点(最大元素）与未排序部分的最后一个元素交换
		swap(nums[0], nums[i]);

		//重新调整堆结构，仅对根节点进行调整
		heapify(nums, i, 0);
	}
}