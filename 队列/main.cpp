#include<stdio.h>
#include<stdlib.h>

#define MaxSize 5
typedef int ElemType;
typedef struct {
	ElemType data[MaxSize];	//�ɴ�MaxSize-1��Ԫ��
	int front, rear;	//���׶�β
}SqQueue;

//��ʼ������
void InitQueue(SqQueue& Q) {
	Q.front = Q.rear = 0;	//���׶�β��0
}

//�����п�
bool isEmpty(SqQueue Q) {
	return Q.front == Q.rear;
}

//���
bool EnQueue(SqQueue& Q, ElemType x) {
	if ((Q.rear + 1) % MaxSize == Q.front) {	//��������
		return false;
	}
	Q.data[Q.rear] = x;	//����Ԫ��
	Q.rear = (Q.rear + 1) % MaxSize;	//rear+1,������˾ͻص����鿪ͷ
	return true;
}

//����
bool DeQueue(SqQueue& Q, ElemType& x) {
	if (Q.rear == Q.front) {	//����Ϊ��
		return false;
	}
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;
	return true;
}

int main() {
	SqQueue Q;
	InitQueue(Q);
	bool ret;

	//�п�
	ret = isEmpty;
	if (ret) {
		printf("Queue is empty.\n");
	}
	else {
		printf("Queue is not empty.\n");
	}

	//���
	EnQueue(Q, 3);
	EnQueue(Q, 4);
	EnQueue(Q, 5);
	ret = EnQueue(Q, 6);
	ret = EnQueue(Q, 7);
	if (ret)
	{
		printf("EnQueue success\n");
	}
	else {
		printf("EnQueue failed\n");
	}

	//����
	ElemType element;	//�洢����Ԫ��
	ret = DeQueue(Q, element);
	if (ret)
	{
		printf("DeQueue success\n");
	}
	else {
		printf("DeQueue failed\n");
	}

	//�����
	ret = EnQueue(Q, 8);
	if (ret)
	{
		printf("EnQueue success\n");
	}
	else {
		printf("EnQueue failed\n");
	}
	return 0;
}