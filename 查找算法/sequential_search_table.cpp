#include "function.h"

//˳����ұ�

//���ʼ��
void ST_Init(SSTable& ST, int len) {
	//������һ��λ�ã������ڱ�
	ST.TableLen = len + 1;
	ST.elem = (ElemType*)malloc(sizeof(ElemType) * ST.TableLen);
	int i;
	srand(time(NULL));	//���������
	for (i = 1; i < ST.TableLen; i++) {	//��0�����ڱ������Դ�1���
		ST.elem[i] = rand() % 100;	//ʹ���ɵ�������0-99��
	}
}

//��ӡ˳���
void ST_Print(SSTable ST) {
	int i;
	for (int i = 1; i < ST.TableLen; i++) {
		printf("%3d", ST.elem[i]);
	}
	printf("\n");
}