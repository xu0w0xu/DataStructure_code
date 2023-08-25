#include<stdio.h>
#include<stdlib.h>

#define MaxSize 5
typedef int ElemType;
typedef struct {
	ElemType data[MaxSize];	//可存MaxSize-1个元素
	int front, rear;	//队首队尾
}SqQueue;

//初始化队列
void InitQueue(SqQueue& Q) {
	Q.front = Q.rear = 0;	//队首队尾置0
}

//队列判空
bool isEmpty(SqQueue Q) {
	return Q.front == Q.rear;
}

//入队
bool EnQueue(SqQueue& Q, ElemType x) {
	if ((Q.rear + 1) % MaxSize == Q.front) {	//队列已满
		return false;
	}
	Q.data[Q.rear] = x;	//放入元素
	Q.rear = (Q.rear + 1) % MaxSize;	//rear+1,如果满了就回到数组开头
	return true;
}

//出队
bool DeQueue(SqQueue& Q, ElemType& x) {
	if (Q.rear == Q.front) {	//队列为空
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

	//判空
	ret = isEmpty;
	if (ret) {
		printf("Queue is empty.\n");
	}
	else {
		printf("Queue is not empty.\n");
	}

	//入队
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

	//出队
	ElemType element;	//存储出队元素
	ret = DeQueue(Q, element);
	if (ret)
	{
		printf("DeQueue success\n");
	}
	else {
		printf("DeQueue failed\n");
	}

	//再入队
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