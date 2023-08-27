#include "function.h"

int main() {
	BiTree T = NULL;	//树根
	KeyType str[7] = { 54,20,66,40,28,79,58 };	//将要进入二叉排序树的元素值
	Creat_BST(T, str, 7);
	InOrder(T);	//中序遍历二叉查找树是由小到大的
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