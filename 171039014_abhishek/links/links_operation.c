#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include"links.h"

List * Intialize(List * mylist)
{
	mylist = (List *)malloc(sizeof(List));
	mylist->head=mylist->tail=NULL;
	mylist->count=0;
	return mylist;


}

Node * getNode(int32_t data)
{
	Node *newNode=(Node *)malloc(sizeof(Node));
	newNode->data = data;
	newNode->ptr = NULL;
	return newNode;
}

void InsertAtBeg(List *mylist,int32_t data)
{
	Node *newNode;
	newNode = getNode(data);
	if (mylist->head == NULL)
	
		mylist->head=mylist->tail=newNode;
	
	else 
	{
		newNode->ptr=mylist->head;
		mylist->head=newNode;
	}
	mylist->count++;
	

}

void InsertAtEnd(List *mylist,int32_t data)
{
	Node *newNode;
	newNode=getNode(data);
	if (mylist->tail == NULL)
		mylist->head=mylist->tail=newNode;
	else 
	{
		mylist->tail->ptr=newNode;
		mylist->tail=newNode;
	}

	mylist->count++;

}

void InsertAfterAnElement(List *mylist,int32_t data,int32_t element)
{
	if(NULL == mylist->head)
	return;
	
	Node *temp,*node_element;
	Node *newNode;
	newNode=getNode(data); 
	temp= mylist->head;
	
	while(NULL != temp && temp->data != element)
		temp=temp->ptr;
	node_element=temp;
	if (NULL != temp)
	{
		temp=node_element->ptr;
		node_element->ptr=newNode;
		newNode->ptr=temp;
		mylist->count++;		

	}		
	
}

void InsertAfterPosition(List *mylist,int32_t position,int32_t data)
{
	if(NULL == mylist->head || position > mylist->count)
	return;
	

	Node *temp,*node_element;
	Node *newNode;
	newNode=getNode(data); 
	temp= mylist->head;
	
	while(position >1)
	{
		temp=temp->ptr;
		position--;
	}
	node_element=temp;
	if (NULL != temp)
	{
		temp=node_element->ptr;
		node_element->ptr=newNode;
		newNode->ptr=temp;
		mylist->count++;		

	}		
	
}


void DeleteAtBeg(List *mylist)
{
	Node *temp;
	if(mylist->count == 1)
	{
		temp=mylist->head;
		mylist->head=mylist->tail=NULL;
		free(temp);
		mylist->count--;	
	}
	else if(mylist->count > 1)
	{
		Node *temp;
		temp=mylist->head;
		mylist->head=mylist->head->ptr;
		free(temp);
		mylist->count--;
	}
}



void DeleteAtEnd(List *mylist)
{
	Node *temp,*x;
	if(mylist->count == 1)
	{
		temp=mylist->head;
		mylist->head=mylist->tail=NULL;
		free(temp);
		mylist->count--;	
	}
		
		temp=mylist->head;
		
	while (temp->ptr != mylist->tail && NULL != temp)
	{
		temp=temp->ptr;
	}	
		x=mylist->tail;		
		mylist->tail=temp;
		mylist->tail->ptr=NULL;
		free(x);
	
}

void display(List *mylist)
{
	Node *temp;
	temp=mylist->head;
	while(temp != NULL)
	{
		printf("val %d\n",temp->data);
		temp=temp->ptr;
	}
}

Node * search(List *mylist,int32_t data)
{
	Node *temp;
	temp=mylist->head;
	while(temp != NULL)
	{
		if (temp->data == data)
		break;
		temp=temp->ptr;
	}
	return temp;

}

void DeleteAnElement(List * mylist,int32_t element)
{
	if (mylist->count == 0)
	return;
	
	if(element == mylist->head->data)
	{
		DeleteAtBeg(mylist);
		return;
	}
	
	if(element == mylist->tail->data)
	{
		DeleteAtEnd(mylist);
		return;
	}
	
	Node  *temp = mylist->head->ptr;
	Node *node_element = mylist->head;
	while(NULL != temp->ptr && element != temp->data)
	{
		node_element=temp;
		temp=temp->ptr;
	}
	node_element->ptr=temp->ptr;
	free(temp);
	mylist->count--;

}


void DeleteAfterPosition(List *mylist,int32_t position)
{
	if(position > mylist->count && position <= 0)
	return;
	if(position == 1)
	{
		DeleteAtBeg(mylist);
		return;

	}
	if(position == mylist->count)
	{
		DeleteAtEnd(mylist);
		return;

	}
	
	Node *temp=mylist->head->ptr;
	Node *node_element=mylist->head;
	int i;
	for(i=0;i < position;i++)
	{
		node_element=temp;
		temp=temp->ptr;
	}
	node_element->ptr=temp->ptr;
	free(temp);
	mylist->count--;


}













