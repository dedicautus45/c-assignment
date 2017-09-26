 #include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

typedef struct _node_
{
	int32_t data;
	struct _node_ *ptr;


}Node;

typedef struct _Linkedlist_
{
	Node *head,*tail;
	int32_t count;

}List;

List * Intialize(List *);
Node * getNode(int32_t);
void InsertAtBeg(List *,int32_t);
void InsertAtEnd(List *,int32_t);
void InsertAfterAnElement(List *,int32_t,int32_t);
void InsertAfterPosition(List *,int32_t,int32_t);
void display(List *);
Node * search(List *,int32_t);
void DeleteAtBeg(List *);
void DeleteAtEnd(List *);
void DeleteAnElement(List *,int32_t);
void DeleteAfterPosition(List *,int32_t);
