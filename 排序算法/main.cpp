#include "function.h"

int main() {
	vector<int> nums = { 45, 50, 12, 73, 20, 65, 83, 50, 12, 73, 45, 20, 65, 83, 50, 12, 73, 45, 20, 65 };

	//��ӡԭ����
	cout << "Original array: ";
	for (int num : nums) {
		cout << num << " ";
	}
	cout << endl;

	////ð������
	//bubble_sort(nums);

	////ѡ������
	//selection_sort(nums);

	////��������
	//insertion_sort(nums);

	////ϣ������
	//shell_sort(nums);

	////�鲢����
	//merge_sort(nums);

	////��������
	//quick_sort(nums);

	////������
	//heap_sort(nums);

	////��������
	//counting_sort(nums);

	////Ͱ����
	//bucket_sort(nums);

	//��������
	radix_sort(nums);

	//��ӡ����������
	cout << "Sorted array: ";
	for (int num : nums) {
		cout << num << " ";
	}

	return 0;
}