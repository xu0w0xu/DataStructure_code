#include "function.h"

int binary_Search(SSTable L, ElemType key) {
	int low = 1;
	int high = L.TableLen - 1;
	int mid;
	while (low <= high) {	//low<=high，可以让mid既能取到low，也能取到high
		mid = (low + high) / 2;
		if (key > L.elem[mid]) {
			low = mid + 1;
		}
		else if (key < L.elem[mid]) {
			high = mid - 1;
		}
		else {
			return mid;
		}
	}
	return -1;
}

//函数名中存储的是函数的入口地址，也是一个指针，是函数指针类型
//left指针和right指针是指向数组中的任意两个元素
//qsort规定如果left指针指向的值大于right指针指向的值，返回正值，小于，返回负值，相等返回0
int compare(const void* left, const void* right)
{
	return *(int*)left - *(int*)right;
	//return *(ElemType*)right - *(ElemType*)left;//从大到小排序
}