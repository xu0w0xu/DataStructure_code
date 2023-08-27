#include "function.h"

//王道书上的递归写法
int BST_Insert1(BiTree& T, KeyType k) {
	if (NULL == T) {
		//为新节点申请空间
		T = (BiTree)malloc(sizeof(BSTNode));
		T->key = k;
		T->lchild = T->rchild = NULL;
		return 1;
	}
	else if (k == T->key) {
		return 0;	//发现相同节点就不插入
	}
	else if (k < T->key) {	//如果要插入的结点，小于当前结点
		//函数调用结束后，左孩子和原来的父亲会关联起来，巧妙利用了引用机制
		return BST_Insert1(T->lchild, k);
	}
	else{
		return BST_Insert1(T->rchild, k);
	}
}

int BST_Insert(BiTree& T, KeyType k) {
	BiTree TreeNew = (BiTree)calloc(1,sizeof(BSTNode));
	TreeNew->key = k;	//把值放入新节点
	if (NULL == T) {
		T = TreeNew;
		return 1;
	}
	BiTree p = T, parent = p;	//p用来查找树
	while (p) {
		parent = p;	//parent用来存p的父亲
		if (k > p->key) {
			p = p->rchild;
		}
		else if (k < p->key) {
			p = p->lchild;
		}
		else {
			return 0;	//相等的元素不可以放入查找树，考研不会考相等元素放入问题
		}
	}
	//接下来判断放入父亲左还是右
	if (k > parent->key) {
		parent->rchild = TreeNew;
	}
	else {
		parent->lchild = TreeNew;
	}
	return 1;
}

void Creat_BST(BiTree& T, KeyType* str, int len) {
	int i;
	for (i = 0; i < len; i++) {
		BST_Insert(T, str[i]);	//把某一节点放入树中
	}
}

//中序遍历
void InOrder(BiTree T) {
	if (T != NULL) {
		InOrder(T->lchild);
		printf("%3d", T->key);
		InOrder(T->rchild);
	}
}

//二叉树查找
BiTree BST_Search(BiTree T, KeyType k, BiTree& parent) {
	parent = NULL;
	while (T != NULL && k != T->key) {
		parent = T;
		if (k > T->key) {
			T = T->rchild;
		}
		else {
			T = T->lchild;
		}
	}
	return T;
}