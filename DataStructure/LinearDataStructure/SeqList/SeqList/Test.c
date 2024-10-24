#include "Seqlist.h"
int main()
{
	SL s;
	SL* ps=&s;
	InitSL(ps);
	SLInsertBack(ps,1);
	SLPrint(ps);
	SLInsertBack(ps,2);
	SLPrint(ps);
	SLInsertBack(ps,3);
	SLPrint(ps);
	SLInsertFront(ps, 0);
	SLPrint(ps);
	SLPopback(ps);
	SLPrint(ps);
	SLPopFront(ps);
	SLPrint(ps);
	SLInsert(ps, 1, 3);
	SLPrint(ps);
	SLErase(ps, 0);
	SLPrint(ps);
	SLErase(ps, 1);
	SLPrint(ps);
	SLDestroy(ps);
	
	return 0;
}
