#include "lib.h"

main()
{
  LL *list1 ;

  list1 = CreateList() ;

  AddNode(list1,4,0);
  AddNode(list1,5,0);
  AddNode(list1,10,1);
  AddNode(list1,2,1);


  assert(list1->tail->data==2);
}
