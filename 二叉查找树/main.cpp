#include "function.h"

int main() {
	BiTree T = NULL;	//����
	KeyType str[7] = { 54,20,66,40,28,79,58 };	//��Ҫ���������������Ԫ��ֵ
	Creat_BST(T, str, 7);
	InOrder(T);	//��������������������С�����
	printf("\n");
	BiTree search, parent;
	search = BST_Search(T, 40, parent);
	if (search) {
		printf("find key %d.\n", search->key);
	}
	else {
		printf("not find.\n");
	}
	return 0;
}