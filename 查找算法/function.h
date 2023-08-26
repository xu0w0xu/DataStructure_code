#ifndef FUNCTION_H
#define FUNCTION_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;
typedef int ElemType;

//��ṹ
typedef struct {
	ElemType* elem;	//����ָ�룬����Ķѿռ����ʼ��ַ����elem
	int TableLen;	//�洢��̬��������Ԫ�صĸ���
}SSTable;

//���ʼ��
void ST_Init(SSTable& ST, int len);

//��ӡ��
void ST_Print(SSTable ST);

//˳�����
int sequential_search(SSTable ST, ElemType key);

//���ֲ���
int binary_Search(SSTable L, ElemType key);

//qsort��Ҫ��compare����
int compare(const void* left, const void* right);

#endif // !FUNCTION_H
