#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
//链表结构
typedef struct LinkNode {
	ElemType data;
	struct LinkNode* next;
}LinkNode;

//队列结构
typedef struct {
	LinkNode* front, * rear;	//队头队尾
}LinkQueue;

//队列初始化
void InitQueue(LinkQueue &Q){
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

int main() {
	LinkQueue Q;
	InitQueue(Q);
	EnQueue(Q, 3);
	EnQueue(Q, 4);
	EnQueue(Q, 5);
	EnQueue(Q, 6);
	EnQueue(Q, 7);
	ElemType element;
	bool ret;
	ret = DeQueue(Q, element);
	if (ret) {
		printf("DeQueue success element = %d\n", element);
	}
	else {
		printf("DeQueue failed.\n");
	}
	DeQueue(Q, element);
	ret = DeQueue(Q, element);
	if (ret)
	{
		printf("DeQueue success element = %d\n", element);
	}
	else {
		printf("DeQueue failed\n");
	}
	return 0;
}