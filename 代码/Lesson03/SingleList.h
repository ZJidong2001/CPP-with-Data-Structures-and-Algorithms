#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDateType;

typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SLTNode;

SLTNode* BuySListNode(SLTDateType x);  // 创建新结点

void SListPrint(SLTNode* phead);  // 单链表打印

void SListPushBack(SLTNode** pphead, SLTDateType x);  // 二级指针
void SListPushBack(SLTNode*& phead, SLTDateType x);  // 一级指针的引用