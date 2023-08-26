#include "function.h"

int main() {
    
    vector<int> nums = { 9, 5, 7, 1, 3, 10, 2, 8, 4, 6 };

    //打印原数组
    cout << "Original array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    
    ////冒泡排序
    //bubble_sort(nums);

    ////选择排序
    //selection_sort(nums);
    
    ////插入排序
    //insertion_sort(nums);

    ////希尔排序
    //shell_sort(nums);

    //归并排序
    merge_sort(nums);

    //打印排序后的数组
    cout << "Sorted array: ";
    for (int num : nums) {
        cout << num << " ";
    }

    return 0;
}