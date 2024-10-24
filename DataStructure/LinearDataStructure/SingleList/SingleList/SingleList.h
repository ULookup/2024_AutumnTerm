#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLTDatatype;
typedef struct SListNode
{ 
	SLTDatatype data;
	struct SListNode* next;
}SLTNode;


//打印链表
void SLTPrint(SLTNode* phead);
//创造结点
SLTNode* SLTBuyNode(SLTDatatype x);
//尾插
void SLTPushBack(SLTNode** pphead,SLTDatatype x);
//头插
void SLTPushFront(SLTNode** pphead, SLTDatatype x);
//尾删
void SLTPopBack(SLTNode** pphead);
//头删
void SLTPopFront(SLTNode** pphead);
//查找
SLTNode* SLTFind(SLTNode* phead, SLTDatatype x);
//指定位置前插入
void SLTInsertBefore(SLTNode** pphead, SLTNode* pos, SLTDatatype x);
//指定位置后插入
void SLTInsertAfter(SLTNode** pphead, SLTNode* pos, SLTDatatype x);
//删除pos结点
void SLTErase(SLTNode** pphead, SLTNode* pos);
//删除pos之后的结点
void SLTEraseAfter(SLTNode** pphead, SLTNode* pos);
//销毁链表
void SLTDestroy(SLTNode** pphead);