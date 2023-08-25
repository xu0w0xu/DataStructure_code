#ifndef FUCTION_H
#define FUCTION_H
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef char BiElemType;
//定义树的结构体
typedef struct BiTNode {
	BiElemType c;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}BiTNode,*BiTree;

//tag结构体用来辅助队列使用
typedef struct tag {
	BiTree p;	//树的某一节点的地址值
	struct tag* pnext;
}tag_t,*ptag_t;

//队列结构体，用于遍历树
typedef BiTree ElemType;
typedef struct LinkNode {
	ElemType data;
	struct LinkNode* next;
}LinkNode;
typedef struct {
	LinkNode* front, * rear;	//队头队尾
}LinkQueue;

void InitQueue(LinkQueue& Q);
bool IsEmpty(LinkQueue Q);
void EnQueue(LinkQueue& Q, ElemType x);
bool DeQueue(LinkQueue& Q, ElemType& x);

#endif // !FUCTION_H
