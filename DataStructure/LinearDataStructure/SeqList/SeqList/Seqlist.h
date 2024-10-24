#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
typedef int SLDataType;
typedef struct Seqlist
{
	int size;//有效大小
	int capacity;//容量
	SLDataType* arr;//动态顺序表
}SL;
void InitSL(SL* s);//初始化顺序表

void CheckCapacity(SL* ps);//检查容量够不够

void SLInsertBack(SL* ps, SLDataType x);//尾插

void SLInsertFront(SL* ps, SLDataType x);//头插

void SLPopback(SL* ps);//尾删

void SLPopFront(SL* ps);//头删

void SLPrint(SL* ps);//打印

void SLInsert(SL* ps, int pos,SLDataType x);//指定位置前插入

void SLErase(SL* ps, int pos);//删除指定位置的数据

void SLDestroy(SL* ps);//销毁顺序表