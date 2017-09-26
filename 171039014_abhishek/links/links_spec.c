#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"links.h"

 main()
{
	List *mylist;
	mylist=Intialize(mylist);
	assert(mylist->head==NULL);

	InsertAtBeg(mylist,3);
	InsertAtBeg(mylist,5);
	InsertAtBeg(mylist,9);
	InsertAtBeg(mylist,8);
	//display(mylist);
	InsertAtEnd(mylist,4);
	InsertAtEnd(mylist,2);
	InsertAtEnd(mylist,1);
	InsertAtEnd(mylist,7);
	//display(mylist);

	InsertAfterPosition(mylist,3,10);
	
	InsertAfterAnElement(mylist,20,5);
	DeleteAtBeg(mylist);
	DeleteAtEnd(mylist);
	DeleteAnElement(mylist,9);
	DeleteAfterPosition(mylist,4);
	display(mylist);
	
	assert(mylist->count = 8);

	assert(search(mylist,5) != NULL);



}
