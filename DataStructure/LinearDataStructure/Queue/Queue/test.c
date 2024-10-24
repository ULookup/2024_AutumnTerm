#include "Queue.h"
int main()
{
	Queue q;
	Queue* pq = &q;
	InitQueue(pq);
	QueuePush(pq, 0);
	PrintQueue(pq);
	QueuePush(pq, 1);
	PrintQueue(pq);
	QueuePush(pq, 2);
	PrintQueue(pq);
	QueuePush(pq, 3);
	PrintQueue(pq);
	QueuePop(pq);
	PrintQueue(pq);
	printf("head=%d\n",QueueHead(pq));
	printf("tail=%d\n", QueueTail(pq));
	printf("size=%d\n", QueueSize(pq));
	DestroyQueue(pq);
}