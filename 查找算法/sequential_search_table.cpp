#include "function.h"

//顺序查找表

//表初始化
void ST_Init(SSTable& ST, int len) {
	//多申请一个位置，保存哨兵
	ST.TableLen = len + 1;
	ST.elem = (ElemType*)malloc(sizeof(ElemType) * ST.TableLen);
	int i;
	srand(time(NULL));	//随机数生成
	for (i = 1; i < ST.TableLen; i++) {	//第0个是哨兵，所以从1随机
		ST.elem[i] = rand() % 100;	//使生成的数都在0-99内
	}
}

//打印顺序表
void ST_Print(SSTable ST) {
	int i;
	for (int i = 1; i < ST.TableLen; i++) {
		printf("%3d", ST.elem[i]);
	}
	printf("\n");
}