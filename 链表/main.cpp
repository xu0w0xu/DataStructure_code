#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
//��������ṹ
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;

//ͷ�巨�½�����(��ͷ���)
bool list_head_insert(LNode*& L) {
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	ElemType x;
	scanf("%d", &x);
	LNode* s; //s�ṹ���������µĽڵ�
	while (x != 9999) {
		s = (LinkList)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;	//��ͷ������
		scanf("%d", &x);
	}
	return true;
}

//β�巨�½�����(��ͷ���)
bool list_tail_insert(LNode*& L) {
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	ElemType x;
	scanf("%d", &x);
	LNode* s, * r = L;	//rָ������ָ��β��
	while (x != 9999) {
		s = (LinkList)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;	//��������s����
		r = s;	//��β��ָ���ƶ���s
		scanf("%d", &x);
	}
	r->next = NULL;	//β��ָ��nextָ��NULL
	return true;
}

//��ӡ����
bool ListPrint(LinkList L) {
	L = L->next;	//����ͷ���
	while (L != NULL) {	//�������ֱ��Ϊ��
		printf("%3d", L->data);
		L = L->next;
	}
	printf("\n");
	return true;
}

//��λ����
LinkList GetElem(LinkList L, int SearchPos) {
	int j = 0;	//���ڶ�λ
	if (SearchPos < 0) { return NULL; }
	while (L && j < SearchPos) {
		L = L->next;
		j++;
	}
	return L;
}

//��ֵ����
LinkList LocateElem(LinkList L, ElemType SearchVal) {
	while (L) {
		if (L->data == SearchVal) { return L; }
		L = L->next;
	}
	return NULL;
}

//��λ����
//����L�������ڵ�iλ��ֵΪInsertVal
bool ListInsert(LinkList L, int i, ElemType InsertVal) {	
	LinkList p = GetElem(L, i - 1);	//�ҵ�ǰ�ӵ�
	if (NULL == p) { return false; }
	LinkList q;	//�½ڵ�
	q = (LinkList)malloc(sizeof(LNode));
	q->data = InsertVal;
	q->next = p->next;
	p->next = q;
	return true;
}

//��λɾ��
//����ɾ��ʱL���ᷢ���仯��������������
bool ListDelete(LinkList L, int i) {	
	LinkList p = GetElem(L, i - 1);	//�ҵ�Ҫɾ��λ�õ�ǰһλ
	if (NULL == p) { return false; }
	LinkList q = p->next;	//�õ�ɾ��λ
	p->next = q->next;	//����
	free(q);	//�ǵ�free
	return true;
}

int main() {
	LinkList L, search;
    //list_head_insert(L);
	list_tail_insert(L);
	ListPrint(L);
    ////��λ�ò���
    //search=GetElem(L,2);
    //if(search!=NULL)
    //{
    //    printf("Succeeded in searching by serial number\n");
    //    printf("%d\n",search->data);
    //}
	////��ֵ��ѯ
    //search=LocateElem(L,6);
    //if(search!=NULL)
    //{
    //    printf("Search by value succeeded\n");
    //    printf("%d\n",search->data);
    //}
    //bool ret;
    //ret=ListInsert(L,2,99);//�½������i��λ��
    //ListPrint(L);
	ListDelete(L, 5);	//ɾ�������λ��
	ListPrint(L);
	return 0;
}