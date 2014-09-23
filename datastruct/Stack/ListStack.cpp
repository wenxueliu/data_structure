/*-----------------------------------------

    FlieNaem : ListStack.cpp
    Version  : 0.10
    Date     : 9-15-2012  21:43
    comment  : achieve the stack by list
-----------------------------------------*/

#include <iostream>
#include "ListStack.h"
using namespace std;

int main()
{
  Stack<int> stack;
  int i;
  cout<<"the stack size is "<<stack.size()<<endl;
  if(stack.isEmpty())
  { 
    cout<<"the stack is empty!"<<endl; 
  }  

  for(i = 0; i < 10; ++i)
  { 
  stack.push(i);
  }
  cout<<"the stack size is "<<stack.size()<<endl;
  for(i = 10; i > 0; --i)
  {
  cout<<stack.topData()<<endl;
  stack.pop();
  }
  cout<<"the stack size is "<<stack.size()<<endl;
  if(stack.isEmpty())
  { 
    cout<<"the stack is empty!"<<endl; 
  }  

  for(i = 0; i < 3; ++i)
  { 
  stack.push(i);
  }
  
  cout<<"the stack size is "<<stack.size()<<endl;
  if(stack.dispose())
  { 
    cout<<"the stack is empty!"<<endl; 
  }  
  cout<<"the stack size is "<<stack.size()<<endl;
  return 0;
}
