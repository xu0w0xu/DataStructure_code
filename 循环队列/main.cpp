#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}*LinkList, LNode;

//���
void EnQueue(LinkList front, LinkList& rear, ElemType val) {
	LinkList pnew;
	if (rear->next == front) {
		//������������һ�����Ŀռ䣬�������
		pnew = (LinkList)malloc(sizeof(LNode));
		rear->data = val;//�����Ԫ�ط���rearָ����
		rear->next = pnew;//����һ����㣬���൱�����˷ָ�
		pnew->next = front;
		rear = pnew;
	}
	else {
		rear->data = val;
		rear = rear->next;
	}
}

//����
void DeQueue(LinkList& front, LinkList rear) {
	if (front == rear) {
		printf("Queue is empty.\n");
	}
	else {
		printf("DeQueue %d\n", front->data);
		front = front->next;
	}
}

//ѭ�����в�������
void CircleQueue(LinkList& front, LinkList& rear) {
	//����ͷ�Ͷ���β��ָ��һ����㣬��ʱ���м��ǿյģ�Ҳ������
	front = (LinkList)malloc(sizeof(LNode));
	rear = front;
	rear->next = front;	//����ѭ������
	//���
	EnQueue(front, rear, 3);
	EnQueue(front, rear, 4);
	//����
	DeQueue(front, rear);
	DeQueue(front, rear);
	DeQueue(front, rear);
}

int main() {
	LinkList front, rear;
	CircleQueue(front, rear);
	return 0;
}