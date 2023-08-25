#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
//����ṹ
typedef struct LinkNode {
	ElemType data;
	struct LinkNode* next;
}LinkNode;

//���нṹ
typedef struct {
	LinkNode* front, * rear;	//��ͷ��β
}LinkQueue;

//���г�ʼ��
void InitQueue(LinkQueue &Q){
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