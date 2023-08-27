#include "function.h"

//�������ϵĵݹ�д��
int BST_Insert1(BiTree& T, KeyType k) {
	if (NULL == T) {
		//Ϊ�½ڵ�����ռ�
		T = (BiTree)malloc(sizeof(BSTNode));
		T->key = k;
		T->lchild = T->rchild = NULL;
		return 1;
	}
	else if (k == T->key) {
		return 0;	//������ͬ�ڵ�Ͳ�����
	}
	else if (k < T->key) {	//���Ҫ����Ľ�㣬С�ڵ�ǰ���
		//�������ý��������Ӻ�ԭ���ĸ��׻�����������������������û���
		return BST_Insert1(T->lchild, k);
	}
	else{
		return BST_Insert1(T->rchild, k);
	}
}

int BST_Insert(BiTree& T, KeyType k) {
	BiTree TreeNew = (BiTree)calloc(1,sizeof(BSTNode));
	TreeNew->key = k;	//��ֵ�����½ڵ�
	if (NULL == T) {
		T = TreeNew;
		return 1;
	}
	BiTree p = T, parent = p;	//p����������
	while (p) {
		parent = p;	//parent������p�ĸ���
		if (k > p->key) {
			p = p->rchild;
		}
		else if (k < p->key) {
			p = p->lchild;
		}
		else {
			return 0;	//��ȵ�Ԫ�ز����Է�������������в��ῼ���Ԫ�ط�������
		}
	}
	//�������жϷ��븸��������
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
		BST_Insert(T, str[i]);	//��ĳһ�ڵ��������
	}
}

//�������
void InOrder(BiTree T) {
	if (T != NULL) {
		InOrder(T->lchild);
		printf("%3d", T->key);
		InOrder(T->rchild);
	}
}

//����������
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