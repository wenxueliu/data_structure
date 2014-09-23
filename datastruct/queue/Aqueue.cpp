/*-----------------------------------------

    FlieNaem : Aqueue.cpp
     Version : 0.10
        Date : 9-16-2012  
        Time : 18:47
    comment  :  as it is template,so it is useful to many types,
                here,we use  int as an  example.
-----------------------------------------*/

#include <iostream>
#include "Aqueue.h"
using namespace std;

int main()
{
  Aqueue<int> queue;
  int i;
  cout<<"the queue capcity is "<<queue.capcity()<<endl;
  cout<<"the queue size is "<<queue.arrysize()<<endl;
  if(queue.isEmpty())
  { 
    cout<<"the queue is empty!"<<endl; 
  }  

  for(i = 0; i < 10; ++i)
  { 
     queue.enqueue(i);
  }
  cout<<"the queue size is "<<queue.arrysize()<<endl;
  for(i = 10; i > 0; --i)
  {
    cout<<queue.frontVal()<<endl;
  queue.dequeue();
  }
  cout<<"the queue size is "<<queue.arrysize()<<endl;
  if(queue.isEmpty())
  { 
    cout<<"the queue is empty!"<<endl; 
  }  

  for(i = 0; i < 3; ++i)
  { 
  queue.enqueue(i);
  }
  
  cout<<"the queue size is "<<queue.arrysize()<<endl;
  if(queue.dispose())
  { 
    cout<<"the queue is empty!"<<endl; 
  }  
  cout<<"the queue size is "<<queue.arrysize()<<endl;
  return 0;
}
