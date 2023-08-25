#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MaxSize 50
typedef int ElemType;

typedef struct {
	ElemType data[MaxSize];
	int length;//顺序表长度
}SqList;

//顺序表插入
bool ListInsert(SqList& L, int i, ElemType element) {
	if (i<1 || i>L.length) { return false; }	//放的位置不合法
	if (L.length == MaxSize) { return false; }	//顺序表已满
	for (int j = L.length; j >= i; j--) {	//依次移动插入位置后的元素
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = element;	//插入元素
	L.length++;
	return true;
}

//打印顺序表
bool ListPrint(SqList L) {
	for (int i = 0; i < L.length; i++) {
		printf("%3d", L.data[i]);
	}
	printf("\n");
}

//按位删除
bool ListDelete(SqList& L, int i, ElemType& e) {	//删除L中第i位，并保存到e
	if (i<1 || i>L.length) { return false; }
	e = L.data[i - 1];	//保留要删除的元素
	for (int j = i; j < L.length; j++) {
		L.data[j - 1] = L.data[j];
	}
	L.length--;
	return true;
}

//按值查找，返回位值
int LocateElem(SqList L, ElemType element) {
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == element) { return i + 1; }
	}
	return 0;
}

int main() {
	//初始化顺序表
	SqList L;
	bool ret;	//用来装函数返回值
	L.data[0] = 1;
	L.data[1] = 2;
	L.data[2] = 3;
	L.length = 3;

	//Insert测试
	ret = ListInsert(L, 2, 60);
	if (ret) {
		printf("Insert SqList success! \n");
		ListPrint(L);
	}
	else {
		printf("Insert SqList failed! \n");
	}
	printf("----------------------------- \n");

	//Delete测试
	ElemType del;	//用来装被删除数据
	ret = ListDelete(L, 1, del);
	if (ret) {
		printf("Delete SqList success! \n");
		printf("Delete element = %d \n", del);
		ListPrint(L);
	}
	else {
		printf("Delete SqList failed! \n");
	}

	//查找测试
	ElemType pos;	//储存元素位置
	pos = LocateElem(L, 60);
	if (pos) {
		printf("Find the element! \n");
		printf("Element position = %d \n", pos);
	}
	else {
		printf("Don't find this element! \n");
	}
	return 0;
}