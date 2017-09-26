#include "list.h"
#include <assert.h>
#include <stdio.h>

 main()
 {
   LL *my_stack ;
   int temp_data ;

   my_stack = create_list() ;

   push_node(10,my_stack);
   push_node(20,my_stack);
   push_node(30,my_stack);
   push_node(40,my_stack);

   assert(my_stack->stack_empty == 0);

   assert(my_stack->count == 4);
   
   assert(pop_node(my_stack) == 40);
   assert(my_stack->count == 3);
   
   assert(pop_node(my_stack) == 30);
   assert(pop_node(my_stack) == 20);
   assert(pop_node(my_stack) == 10);

   temp_data = pop_node(my_stack);
   assert(temp_data==0);
   assert(my_stack->stack_empty == 1);

 }
