#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
typedef int QEDataType;
typedef struct QueueNode
{
	QEDataType data;
	struct QueueNode* next;

}QueueNode;
typedef struct Queue
{
	QueueNode* phead;
	QueueNode* ptail;
	int size;
}Queue;
//初始化队列
void InitQueue(Queue* pq);
//创建新结点
QueueNode* QueueBuyNode();
//队列判空
bool IsQueueEmpty(Queue* pq);
//入队
void QueuePush(Queue* pq, QEDataType x);
//出队列
void QueuePop(Queue* pq);
//取队头数据
QEDataType QueueHead(Queue* pq);
//取队尾数据
QEDataType QueueTail(Queue* pq);
//销毁队列
void DestroyQueue(Queue* pq);
//打印队列
void PrintQueue(Queue* pq);
//有效元素个数
int QueueSize(Queue* pq);