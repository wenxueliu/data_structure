/*-----------------------------------------

    FlieNaem : ArryStack.cpp
    Version  : 0.10
    Date     : 9-16-2012 
       TIME  : 00:19 
    comment  : achieve the stack by array
-----------------------------------------*/

#include <iostream>
#include "ArryStack.h"
using namespace std;

int main()
{
  Stack<int> stack;
  int i;
  
  for(i = 0; i < 10; ++i)
  { 
  stack.push(i);
  }
  cout<<stack.size()<<endl;
  cout<<stack.capcity()<<endl;
  if(stack.isFull())
  {
    cout<<"the stack is full!!"<<endl;
  }
  for(i = 10; i > 0; --i)
  {
  cout<<stack.topData()<<endl;
  stack.pop();
  }
  cout<<stack.size()<<endl;
  cout<<stack.capcity()<<endl;
  if (stack.isEmpty())
   {
     cout<<"the stack is empty!"<<endl;
   }
  return 0;
}
