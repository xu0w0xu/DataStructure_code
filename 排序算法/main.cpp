#include "function.h"

int main() {
    
    vector<int> nums = { 9, 5, 7, 1, 3, 10, 2, 8, 4, 6 };

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

    //�鲢����
    merge_sort(nums);

    //��ӡ����������
    cout << "Sorted array: ";
    for (int num : nums) {
        cout << num << " ";
    }

    return 0;
}