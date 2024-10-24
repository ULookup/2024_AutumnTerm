#include "SingleList.h"
int main()
{
	SLTNode* plist = NULL;
	SLTNode** pl = &plist;
	SLTPushBack(pl,1);
	SLTPrint(plist);
	SLTPushBack(pl,2);
	SLTPrint(plist);
	SLTPushBack(pl,3);
	SLTPrint(plist);
	SLTPushFront(pl, 0);
	SLTPrint(plist);
	SLTPopBack(pl);
	SLTPrint(plist);
	SLTPopFront(pl);
	SLTPrint(plist);
	SLTInsertAfter(pl, SLTFind(plist, 1),2);
	SLTPrint(plist);
	SLTInsertBefore(pl, SLTFind(plist, 1), 0);
	SLTPrint(plist);
	SLTInsertBefore(pl, SLTFind(plist, 1), 1);
	SLTPrint(plist);
	SLTErase(pl, SLTFind(plist, 1));
	SLTPrint(plist);
	SLTEraseAfter(pl, SLTFind(plist,1));
	SLTPrint(plist);
	SLTDestroy(pl);
	SLTPrint(plist);

	return 0;
}