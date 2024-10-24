#include "Stack.h"
int main()
{
	ST s;
	ST* ps = &s;

	InitST(ps);
	StackPush(ps, 0);
	PrintStack(ps);
	StackPush(ps, 1);
	PrintStack(ps);
	StackPush(ps, 2);
	PrintStack(ps);
	StackPush(ps, 3);
	PrintStack(ps);
	StackPop(ps);
	PrintStack(ps);
	printf("%d", StackTop(ps));
	StackDestroy(ps);
	return 0;
}