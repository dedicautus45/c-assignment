#include "lib.h"

 LL* CreateList ()
 {
   LL *new_list ;

   new_list = (LL*) malloc (sizeof(LL)) ;

   new_list->head = new_list->tail = NULL ;

   new_list->count = 0 ;

   return new_list ;
 }

 void AddNode (LL* my_list, int data, bool h_t) 
 {
   
   Node *new_node ;

   new_node = (Node*) malloc (sizeof(Node)) ;
   new_node->data = data ;
   if (NULL==my_list->head && NULL==my_list->tail)
   {
     my_list->head = my_list->tail = new_node ;
     new_node->prev = new_node->next = NULL ;
   }

   else if(0==h_t)
   {
     my_list->head->next = new_node ;
     new_node->prev = my_list->head ;
     new_node->next = NULL ;
     my_list->head = new_node ;
   }
   else if(1==h_t)
   {
     my_list->tail->prev = new_node ;
     new_node->next = my_list->tail ;
     new_node->prev = NULL ;
     my_list->tail = new_node ;
   }

   my_list->count++ ;
 }
