#include "function.h"

//�ж϶����Ƿ�Ϊ��
bool IsEmpty(LinkQueue Q)
{
	return Q.rear == Q.front;
}

//���г�ʼ��
void InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next = NULL;
}

//���
void EnQueue(LinkQueue& Q, ElemType x) {
	LinkNode* pnew = (LinkNode*)malloc(sizeof(LinkNode));
	pnew->data = x;
	pnew->next = NULL;
	Q.rear->next = pnew;
	Q.rear = pnew;
}

//����
bool DeQueue(LinkQueue& Q, ElemType& x) {
	if (Q.rear == Q.front) {
		return false;
	}
	LinkNode* q = Q.front->next;//�õ���һ���ڵ� ����q
	x = q->data;
	Q.front->next = q->next;
	if (Q.rear == q) {
		Q.rear = Q.front;
	}
	free(q);
	return true;
}
