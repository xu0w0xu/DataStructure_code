#include "function.h"

int main() {
	vector<int> nums = { 45, 50, 12, 73, 20, 65, 83, 50, 12, 73, 45, 20, 65, 83, 50, 12, 73, 45, 20, 65 };

	//´òÓ¡Ô­Êý×é
	cout << "Original array: ";
	for (int num : nums) {
		cout << num << " ";
	}
	cout << endl;

	////Ã°ÅÝÅÅÐò
	//bubble_sort(nums);

	////Ñ¡ÔñÅÅÐò
	//selection_sort(nums);

	////²åÈëÅÅÐò
	//insertion_sort(nums);

	////Ï£¶ûÅÅÐò
	//shell_sort(nums);

	////¹é²¢ÅÅÐò
	//merge_sort(nums);

	////¿ìËÙÅÅÐò
	//quick_sort(nums);

	////¶ÑÅÅÐò
	//heap_sort(nums);

	////¼ÆÊýÅÅÐò
	//counting_sort(nums);

	////Í°ÅÅÐò
	//bucket_sort(nums);

	//»ùÊýÅÅÐò
	radix_sort(nums);

	//´òÓ¡ÅÅÐòºóµÄÊý×é
	cout << "Sorted array: ";
	for (int num : nums) {
		cout << num << " ";
	}

	return 0;
}