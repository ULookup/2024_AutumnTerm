#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
typedef int StackDataType;
typedef struct Stack
{
	StackDataType* arr;
	int top;
	int capacity;
}ST;

//初始化
void InitST(ST* ps);

//销毁
void DestroyST(ST* ps);

//入栈
void StackPush(ST* ps, StackDataType x);

//栈是否为空
bool IsStackEmpty(ST* ps);

//出栈
void StackPop(ST* ps);

//取栈顶元素
StackDataType StackTop(ST* ps);

//获取栈中有效元素个数
int StackSize(ST* ps);

//打印
void PrintStack(ST* ps);

//销毁
void StackDestroy(ST* ps);