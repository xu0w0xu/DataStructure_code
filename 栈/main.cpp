#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef int ElemType;

//定义栈数据结构
typedef struct {
	ElemType data[MaxSize];	//数组
	int top;	//数组顶部
}SqStack;

//初始化栈
//栈顶-1表示栈为空
void InitStack(SqStack& S) {
	S.top = -1;
}

//栈判空
bool StackEmpty(SqStack S) {
	if (-1 == S.top) {
		return true;
	}
	else {
		return false;
	}
}

//入栈
bool Push(SqStack& S, ElemType x) {
	//判断是否栈满
	if (S.top == MaxSize - 1) {
		return false;
	}
	S.data[++S.top] = x;
	return true;
}

//获取栈顶元素
bool GetTop(SqStack S, ElemType& m) {
	if (StackEmpty(S)) {
		return false;
	}
	m = S.data[S.top];
	return true;
}

//弹栈
bool Pop(SqStack& S,ElemType &m) {
	if (StackEmpty(S)) {	//判断是否为空
		return false;
	}
	m = S.data[S.top--];	//出栈，且将元素保存到m
	return true;
}

int main() {
	SqStack S;
	InitStack(S);
	bool flag;

	//判断栈是否为空
	flag = StackEmpty(S);
	if (flag) {
		printf("Stack is empty\n");
	}

	//入栈3,4,5
	Push(S, 3);
	Push(S, 4);
	Push(S, 5);

	//获取栈顶元素
	ElemType m;	//用于获取元素
	flag = GetTop(S, m);
	if (flag) {
		printf("The top element is %d\n", m);
	}
	else {
		printf("get top failed.\n");
	}

	//弹栈
	flag = Pop(S, m);
	if (flag) {
		printf("Pop element %d\n", m);
	}
	else {
		printf("Pop failed.\n");
	}

	return 0;
}
