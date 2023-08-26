#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//1.ð������
void bubble_sort(vector<int> &nums);
//2.ѡ������
void selection_sort(vector<int>& nums);
//3.��������
void insertion_sort(vector<int>& nums);
//4.ϣ������
void shell_sort(vector<int>& nums);
//5.�鲢����
void merge_sort(vector<int>& nums);
//6.��������
void quick_sort(vector<int>& nums);
//7.������
void heap_sort(vector<int>& nums);
//8.��������
void counting_sort(vector<int>& nums);
//9.Ͱ����
void bucket_sort(vector<int>& nums);
//10.��������
void radix_sort(vector<int>& nums);
#endif // !FUNCTION_H
