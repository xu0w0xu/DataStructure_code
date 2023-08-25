#include "function.h"

//判断队列是否为空
bool IsEmpty(LinkQueue Q)
{
	return Q.rear == Q.front;
}

//队列初始化
void InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next = NULL;
}

//入队
void EnQueue(LinkQueue& Q, ElemType x) {
	LinkNode* pnew = (LinkNode*)malloc(sizeof(LinkNode));
	pnew->data = x;
	pnew->next = NULL;
	Q.rear->next = pnew;
	Q.rear = pnew;
}

//出队
bool DeQueue(LinkQueue& Q, ElemType& x) {
	if (Q.rear == Q.front) {
		return false;
	}
	LinkNode* q = Q.front->next;//拿到第一个节点 存入q
	x = q->data;
	Q.front->next = q->next;
	if (Q.rear == q) {
		Q.rear = Q.front;
	}
	free(q);
	return true;
}
