#include "SingleList.h"
//打印链表
void SLTPrint(SLTNode* phead)
{
	SLTNode* pcur = phead;
	while (pcur!=NULL)
	{
		printf("%d -> ", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL\n");
}
//创建新结点
SLTNode* SLTBuyNode(SLTDatatype x)
{
	SLTNode* node = (SLTNode*)malloc(sizeof(SLTNode));
	if (node == NULL)
	{
		printf("malloc fail!\n");
		exit(1);
	}
	node->data = x;
	node->next = NULL;

	return node;
}
//尾插
void SLTPushBack(SLTNode** pphead, SLTDatatype x)
{
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x);//创建要尾插的结点
	if (*pphead == NULL)
		*pphead = newnode;//如果是空链表，直接成为头节点
	else
	{
		SLTNode* ptail = *pphead;
		while (ptail->next != NULL)
		{
			ptail = ptail->next;//如果不是空结点，则遍历链表找到尾结点
		}
		ptail->next = newnode;//尾结点与新结点连接
	}
}
//头插
void SLTPushFront(SLTNode** pphead, SLTDatatype x)
{
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x);//创建要头插的结点
	newnode->next = *pphead;//将其与原来的头节点连接
	*pphead = newnode;//将头结点变为头插的结点
}
//尾删
void SLTPopBack(SLTNode** pphead)
{
	assert(pphead&&*pphead);//*pphead用于确保不是空链表
	if ((*pphead)->next == NULL)//只有一个结点的情况
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* prev = *pphead;
		SLTNode* ptail = *pphead;
		while (ptail->next != NULL)
		{
			prev = ptail;
			ptail =ptail->next;//prev标记删后的尾结点，ptail标记要尾删的结点
		}
		prev->next = NULL;
		free(ptail);
		ptail = NULL;
	}
}
//头删
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead && *pphead);//*pphead用于确保不是空链表

	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
	//如果只有一个头结点，则next本就是NULL，一样可以赋给*pphead
}
//查找(只能查找到第一次出现的）
SLTNode* SLTFind(SLTNode* phead,SLTDatatype x)
{
	assert(phead);
	
	SLTNode* pcur = phead;
	while (pcur->next != NULL)
	{
		if (pcur->data == x)
			return pcur;
		pcur = pcur->next;
	}
	return NULL;//未找到
}
//指定位置前插入
void SLTInsertBefore(SLTNode** pphead, SLTNode* pos, SLTDatatype x)
{
	assert(pphead&&pos);

	if (*pphead == pos)
		SLTPushFront(pphead,x);//指定位置为首结点，相当于头插
	else
	{
		SLTNode* newnode = SLTBuyNode(x);
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;//找到pos前的结点
		}
		prev->next = newnode;//前一个连上新结点
		newnode->next = pos;//新结点连上pos结点
	}
}
//指定位置后插入
void SLTInsertAfter(SLTNode** pphead, SLTNode* pos, SLTDatatype x)
{
	assert(pphead&&pos);

	SLTNode* newnode = SLTBuyNode(x);
	newnode->next = pos->next;//新结点连上pos结点的下一个结点（如果pos是尾结点，同样可以置NULL）
	pos->next = newnode;//pos结点重新连接上新结点
}
//删除pos结点
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead && pos);

	if (*pphead == pos)
		SLTPopFront(pphead);
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}
//删除pos之后的结点
void SLTEraseAfter(SLTNode** pphead,SLTNode* pos)
{
	assert(pphead && pos && pos->next);

	SLTNode* del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;
}
//销毁链表
void SLTDestroy(SLTNode** pphead)
{
	SLTNode* pcur = *pphead;
	while (pcur != NULL)
	{
		SLTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	*pphead = NULL;
}