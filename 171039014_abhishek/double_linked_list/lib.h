#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

 struct _node_
 {
   int data ;
   struct _node_ *prev ;
   struct _node_ *next ;
 };

 typedef struct _node_ Node ;
 
 struct _linked_list_
 {
   Node *head;
   Node *tail;
   int count ;
 };

 typedef struct _linked_list_ LL ;

 LL* CreateList ();
 void AddNode (LL* my_list, int data, bool h_t); 

