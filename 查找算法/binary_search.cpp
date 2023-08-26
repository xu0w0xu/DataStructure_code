#include "function.h"

int binary_Search(SSTable L, ElemType key) {
	int low = 1;
	int high = L.TableLen - 1;
	int mid;
	while (low <= high) {	//low<=high��������mid����ȡ��low��Ҳ��ȡ��high
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

//�������д洢���Ǻ�������ڵ�ַ��Ҳ��һ��ָ�룬�Ǻ���ָ������
//leftָ���rightָ����ָ�������е���������Ԫ��
//qsort�涨���leftָ��ָ���ֵ����rightָ��ָ���ֵ��������ֵ��С�ڣ����ظ�ֵ����ȷ���0
int compare(const void* left, const void* right)
{
	return *(int*)left - *(int*)right;
	//return *(ElemType*)right - *(ElemType*)left;//�Ӵ�С����
}