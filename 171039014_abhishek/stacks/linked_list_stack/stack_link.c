#include "list.h"


 LL* create_list ()
 {
   LL *new_list ;

   new_list = (LL*) malloc (sizeof(LL)) ;
   new_list->top = NULL ;
   new_list->count = 0 ;
   new_list->stack_empty = 1 ;

   return new_list ;
 }

 void push_node (int push_data , LL *stack_list)
 {
   Node *node_ptr ;
   
   node_ptr = (Node*) malloc (sizeof(Node)) ;//create_node(push_data) ;
   node_ptr->n_data = push_data ;
   node_ptr->n_ptr = stack_list->top ;
   stack_list->top = node_ptr ;
   stack_list->count = stack_list->count +1 ;
   stack_list->stack_empty = 0 ;
 }

 int peek_node (LL *stack_list)
 {
   return stack_list->top->n_data ;
 }

 int pop_node (LL *stack_list)
 {
   int pop_data ;
   Node *free_node ;

   if (NULL==stack_list->top) 
   {
     stack_list->stack_empty = 1 ;
     pop_data = 0 ;
   }
   else
   {
     pop_data = peek_node(stack_list) ; //stack_list->top->data ;
     
     free_node = stack_list->top ;
     stack_list->top = stack_list->top->n_ptr ;
     free(free_node) ;
     stack_list->count-- ;
   }

   return pop_data ;
 }

  bool is_empty (LL *stack_list)
  {
    return stack_list->stack_empty ;
  }
