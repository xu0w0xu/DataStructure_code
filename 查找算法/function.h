#ifndef FUNCTION_H
#define FUNCTION_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;
typedef int ElemType;

//表结构
typedef struct {
	ElemType* elem;	//整型指针，申请的堆空间的起始地址存入elem
	int TableLen;	//存储动态数组里面元素的个数
}SSTable;

//表初始化
void ST_Init(SSTable& ST, int len);

//打印表
void ST_Print(SSTable ST);

//顺序查找
int sequential_search(SSTable ST, ElemType key);

//二分查找
int binary_Search(SSTable L, ElemType key);

//qsort需要的compare函数
int compare(const void* left, const void* right);

#endif // !FUNCTION_H
