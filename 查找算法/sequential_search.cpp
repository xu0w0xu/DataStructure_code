#include "function.h"

//˳�����
int sequential_search(SSTable ST, ElemType key) {
	ST.elem[0] = key;
	int i;
	for (i = ST.TableLen - 1; ST.elem[i] != key; i--);	//�Ӻ���ǰ���ҵ��˾ͷ���i
	return i;
}