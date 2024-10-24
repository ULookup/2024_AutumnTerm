#include "Queue.h"
//初始化队列
void InitQueue(Queue* pq)
{
	assert(pq);

	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}
//创建新结点
QueueNode* QueueBuyNode()
{
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	return newnode;
}
//队列判空
bool IsQueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->phead == NULL;
}
//入队列
void QueuePush(Queue* pq, QEDataType x)
{
	assert(pq);
	QueueNode* newnode = QueueBuyNode();
	if (newnode == NULL)
	{
		perror("malloc fail!\n");
		exit(1);
	}
	newnode->next = NULL;
	newnode->data = x;

	if (IsQueueEmpty(pq))
	{
		pq->phead = pq->ptail = newnode;
	}
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = pq->ptail->next;
	}
	pq->size++;
}
//出队列
void QueuePop(Queue* pq)
{
	assert(pq&&(!IsQueueEmpty(pq)));

	if (pq->phead == pq->ptail)
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else
	{
		QueueNode* next = pq->phead->next;
		free(pq->phead);
		pq->phead = next;
	}
	pq->size--;
}
//取队头数据
QEDataType QueueHead(Queue* pq)
{
	assert(pq && (!IsQueueEmpty(pq)));

	return pq->phead->data;
}
//取队尾数据
QEDataType QueueTail(Queue* pq)
{
	assert(pq && (!IsQueueEmpty(pq)));

	return pq->ptail->data;
}
//有效元素个数
int QueueSize(Queue* pq)
{
	assert(pq);

	return pq->size;
}
//销毁队列
void DestroyQueue(Queue* pq)
{
	assert(pq);
	QueueNode* pcur = pq->phead;
	while (pcur)
	{
		QueueNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}
//打印队列
void PrintQueue(Queue* pq)
{
	assert(pq && (!IsQueueEmpty(pq)));

	QueueNode* pcur = pq->phead;
	while (pcur)
	{
		printf("%d", pcur->data);
		pcur = pcur->next;
	}
	printf("\n");
}