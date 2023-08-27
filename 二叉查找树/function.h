#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
//�������ṹ
typedef struct BSTNode {
	KeyType key;
	struct BSTNode* lchild, * rchild;
}BSTNode, * BiTree;

//����������
void Creat_BST(BiTree& T, KeyType* str, int len);
//�������
void InOrder(BiTree T);
//����������
BiTree BST_Search(BiTree T, KeyType k, BiTree& parent);
#endif // !FUNCTION_H
