#include "function.h"

//ǰ�������Ҳ�����������Ҳ��������ȱ���
void PreOrder(BiTree p) {
	if (p != NULL) {
		printf("%c", p->c);
		PreOrder(p->lchild);	//��ӡ������
		PreOrder(p->rchild);	//��ӡ������
	}
}

//�������
void InOrder(BiTree p) {
	if (p != NULL) {
		InOrder(p->lchild);
		printf("%c", p->c);
		InOrder(p->rchild);
	}
}

//�������
void PostOrder(BiTree p) {
	if (p != NULL) {
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		printf("%c", p->c);
	}
}

//�������
//��α���,���������������ȱ���
void LevelOrder(BiTree T) {
	LinkQueue Q;
	InitQueue(Q);
	BiTree p;	//�洢���ӵĽڵ�
	EnQueue(Q, T);	//�Ѹ����
	while (!IsEmpty(Q)) {
		DeQueue(Q, p);
		putchar(p->c);	//�ȼ���printf("%c",p->c);
		if (p->lchild) {
			EnQueue(Q, p->lchild);	//���Ӳ�Ϊ�վ����
		}
		if (p->rchild) {
			EnQueue(Q, p->rchild);	//�Һ��Ӳ�Ϊ�վ����
		}
	}
}

int main() {
	BiTree pnew;	//����ָ������������ڵ�
	BiTree tree = NULL;	//treeָ��������������
	BiElemType c;
	ptag_t phead = NULL, ptail = NULL, listpnew = NULL, pcur = NULL;
	//abcdefghij,��ν���
	while (scanf("%c", &c)) {
		if (c == '\n') {
			break;	//��������break
		}
		//calloc����Ŀռ��С����������ֱ����ˣ����Կռ���г�ʼ������ֵΪ0
		pnew = (BiTree)calloc(1, sizeof(BiTNode));
		pnew->c = c;
		listpnew = (ptag_t)calloc(1, sizeof(tag_t));//�����н������ռ�
		listpnew->p = pnew;
		//��������ĵ�һ�����
		if (NULL == tree) {
			tree = pnew;	// treeָ�����ĸ����
			phead = listpnew;	//��һ����㼴�Ƕ���ͷ��Ҳ�Ƕ���β
			ptail = listpnew;
			pcur = listpnew;
		}
		else {
			//��Ԫ���������
			ptail->pnext = listpnew;
			ptail = listpnew;
			//�������ѽ���������
			if (NULL == pcur->p->lchild) {
				pcur->p->lchild = pnew;	//����Ϊ�գ���������
			}
			else if (NULL == pcur->p->rchild) {
				pcur->p->rchild = pnew;	//�Һ���Ϊ�գ������Һ���
				pcur = pcur->pnext;//�����Һ��Ӷ����ˣ�pcurָ����һ��
			}
		}
	}

	printf("--------PreOrder----------\n");//Ҳ������������ȴ�ӡ��ǰ��㣬��ӡ���ӣ���ӡ�Һ���
	PreOrder(tree);
	printf("\n--------InOrder------------\n");//�ȴ�ӡ���ӣ���ӡ���ף���ӡ�Һ���
	InOrder(tree);
	printf("\n--------PostOrder------------\n");//�ȴ�ӡ���ӣ���ӡ�Һ��ӣ�����ӡ����
	PostOrder(tree);
	printf("\n--------LevelOrder------------\n");
	LevelOrder(tree);
	return 0;
}