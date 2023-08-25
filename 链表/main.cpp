#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
//定义链表结构
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;

//头插法新建链表(带头结点)
bool list_head_insert(LNode*& L) {
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	ElemType x;
	scanf("%d", &x);
	LNode* s; //s结构用于申请新的节点
	while (x != 9999) {
		s = (LinkList)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;	//从头部插入
		scanf("%d", &x);
	}
	return true;
}

//尾插法新建链表(带头结点)
bool list_tail_insert(LNode*& L) {
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	ElemType x;
	scanf("%d", &x);
	LNode* s, * r = L;	//r指针用于指向尾部
	while (x != 9999) {
		s = (LinkList)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;	//将链表与s链接
		r = s;	//把尾部指针移动到s
		scanf("%d", &x);
	}
	r->next = NULL;	//尾部指针next指向NULL
	return true;
}

//打印链表
bool ListPrint(LinkList L) {
	L = L->next;	//跳过头结点
	while (L != NULL) {	//依次输出直到为空
		printf("%3d", L->data);
		L = L->next;
	}
	printf("\n");
	return true;
}

//按位查找
LinkList GetElem(LinkList L, int SearchPos) {
	int j = 0;	//用于定位
	if (SearchPos < 0) { return NULL; }
	while (L && j < SearchPos) {
		L = L->next;
		j++;
	}
	return L;
}

//按值查找
LinkList LocateElem(LinkList L, ElemType SearchVal) {
	while (L) {
		if (L->data == SearchVal) { return L; }
		L = L->next;
	}
	return NULL;
}

//按位插入
//链表L，插入在第i位，值为InsertVal
bool ListInsert(LinkList L, int i, ElemType InsertVal) {	
	LinkList p = GetElem(L, i - 1);	//找到前接点
	if (NULL == p) { return false; }
	LinkList q;	//新节点
	q = (LinkList)malloc(sizeof(LNode));
	q->data = InsertVal;
	q->next = p->next;
	p->next = q;
	return true;
}

//按位删除
//由于删除时L不会发生变化，所以无需引用
bool ListDelete(LinkList L, int i) {	
	LinkList p = GetElem(L, i - 1);	//找到要删除位置的前一位
	if (NULL == p) { return false; }
	LinkList q = p->next;	//拿到删除位
	p->next = q->next;	//断链
	free(q);	//记得free
	return true;
}

int main() {
	LinkList L, search;
    //list_head_insert(L);
	list_tail_insert(L);
	ListPrint(L);
    ////按位置查找
    //search=GetElem(L,2);
    //if(search!=NULL)
    //{
    //    printf("Succeeded in searching by serial number\n");
    //    printf("%d\n",search->data);
    //}
	////按值查询
    //search=LocateElem(L,6);
    //if(search!=NULL)
    //{
    //    printf("Search by value succeeded\n");
    //    printf("%d\n",search->data);
    //}
    //bool ret;
    //ret=ListInsert(L,2,99);//新结点插入第i个位置
    //ListPrint(L);
	ListDelete(L, 5);	//删除第五个位置
	ListPrint(L);
	return 0;
}