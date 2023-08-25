#ifndef FUCTION_H
#define FUCTION_H
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef char BiElemType;
//�������Ľṹ��
typedef struct BiTNode {
	BiElemType c;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}BiTNode,*BiTree;

//tag�ṹ��������������ʹ��
typedef struct tag {
	BiTree p;	//����ĳһ�ڵ�ĵ�ֵַ
	struct tag* pnext;
}tag_t,*ptag_t;

//���нṹ�壬���ڱ�����
typedef BiTree ElemType;
typedef struct LinkNode {
	ElemType data;
	struct LinkNode* next;
}LinkNode;
typedef struct {
	LinkNode* front, * rear;	//��ͷ��β
}LinkQueue;

void InitQueue(LinkQueue& Q);
bool IsEmpty(LinkQueue Q);
void EnQueue(LinkQueue& Q, ElemType x);
bool DeQueue(LinkQueue& Q, ElemType& x);

#endif // !FUCTION_H
