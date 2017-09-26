#include <stdlib.h>
#include <stdbool.h>

 struct _node_ 
 {
   int n_data ;
   struct _node_ *n_ptr ;
 } ;
 typedef struct _node_ Node ;

 struct _linked_list_ 
 {
   Node *top ;
   int count ;
   bool stack_empty ;
 } ;
 typedef struct _linked_list_ LL ;


 LL* create_list () ;

 void push_node (int , LL*) ;

 int peek_node (LL*) ;

 int pop_node (LL*) ;

 bool is_empty (LL*) ;
