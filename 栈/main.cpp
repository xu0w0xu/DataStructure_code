#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef int ElemType;

//����ջ���ݽṹ
typedef struct {
	ElemType data[MaxSize];	//����
	int top;	//���鶥��
}SqStack;

//��ʼ��ջ
//ջ��-1��ʾջΪ��
void InitStack(SqStack& S) {
	S.top = -1;
}

//ջ�п�
bool StackEmpty(SqStack S) {
	if (-1 == S.top) {
		return true;
	}
	else {
		return false;
	}
}

//��ջ
bool Push(SqStack& S, ElemType x) {
	//�ж��Ƿ�ջ��
	if (S.top == MaxSize - 1) {
		return false;
	}
	S.data[++S.top] = x;
	return true;
}

//��ȡջ��Ԫ��
bool GetTop(SqStack S, ElemType& m) {
	if (StackEmpty(S)) {
		return false;
	}
	m = S.data[S.top];
	return true;
}

//��ջ
bool Pop(SqStack& S,ElemType &m) {
	if (StackEmpty(S)) {	//�ж��Ƿ�Ϊ��
		return false;
	}
	m = S.data[S.top--];	//��ջ���ҽ�Ԫ�ر��浽m
	return true;
}

int main() {
	SqStack S;
	InitStack(S);
	bool flag;

	//�ж�ջ�Ƿ�Ϊ��
	flag = StackEmpty(S);
	if (flag) {
		printf("Stack is empty\n");
	}

	//��ջ3,4,5
	Push(S, 3);
	Push(S, 4);
	Push(S, 5);

	//��ȡջ��Ԫ��
	ElemType m;	//���ڻ�ȡԪ��
	flag = GetTop(S, m);
	if (flag) {
		printf("The top element is %d\n", m);
	}
	else {
		printf("get top failed.\n");
	}

	//��ջ
	flag = Pop(S, m);
	if (flag) {
		printf("Pop element %d\n", m);
	}
	else {
		printf("Pop failed.\n");
	}

	return 0;
}
