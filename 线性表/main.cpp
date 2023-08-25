#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MaxSize 50
typedef int ElemType;

typedef struct {
	ElemType data[MaxSize];
	int length;//˳�����
}SqList;

//˳������
bool ListInsert(SqList& L, int i, ElemType element) {
	if (i<1 || i>L.length) { return false; }	//�ŵ�λ�ò��Ϸ�
	if (L.length == MaxSize) { return false; }	//˳�������
	for (int j = L.length; j >= i; j--) {	//�����ƶ�����λ�ú��Ԫ��
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = element;	//����Ԫ��
	L.length++;
	return true;
}

//��ӡ˳���
bool ListPrint(SqList L) {
	for (int i = 0; i < L.length; i++) {
		printf("%3d", L.data[i]);
	}
	printf("\n");
}

//��λɾ��
bool ListDelete(SqList& L, int i, ElemType& e) {	//ɾ��L�е�iλ�������浽e
	if (i<1 || i>L.length) { return false; }
	e = L.data[i - 1];	//����Ҫɾ����Ԫ��
	for (int j = i; j < L.length; j++) {
		L.data[j - 1] = L.data[j];
	}
	L.length--;
	return true;
}

//��ֵ���ң�����λֵ
int LocateElem(SqList L, ElemType element) {
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == element) { return i + 1; }
	}
	return 0;
}

int main() {
	//��ʼ��˳���
	SqList L;
	bool ret;	//����װ��������ֵ
	L.data[0] = 1;
	L.data[1] = 2;
	L.data[2] = 3;
	L.length = 3;

	//Insert����
	ret = ListInsert(L, 2, 60);
	if (ret) {
		printf("Insert SqList success! \n");
		ListPrint(L);
	}
	else {
		printf("Insert SqList failed! \n");
	}
	printf("----------------------------- \n");

	//Delete����
	ElemType del;	//����װ��ɾ������
	ret = ListDelete(L, 1, del);
	if (ret) {
		printf("Delete SqList success! \n");
		printf("Delete element = %d \n", del);
		ListPrint(L);
	}
	else {
		printf("Delete SqList failed! \n");
	}

	//���Ҳ���
	ElemType pos;	//����Ԫ��λ��
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