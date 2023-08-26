#include "function.h"

//顺序查找
int sequential_search(SSTable ST, ElemType key) {
	ST.elem[0] = key;
	int i;
	for (i = ST.TableLen - 1; ST.elem[i] != key; i--);	//从后往前找找到了就返回i
	return i;
}