#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
//二叉树结构
typedef struct BSTNode {
	KeyType key;
	struct BSTNode* lchild, * rchild;
}BSTNode, * BiTree;

//创建二叉树
void Creat_BST(BiTree& T, KeyType* str, int len);
//中序遍历
void InOrder(BiTree T);
//二叉树查找
BiTree BST_Search(BiTree T, KeyType k, BiTree& parent);
#endif // !FUNCTION_H
