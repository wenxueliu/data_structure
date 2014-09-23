/*-----------------------------------
  
     FlieName : ListStack.h
     Version  : Wenxue Liu
        Date  : 09-15-2012
     Comment  : achieve by list.

----------------------------------*/
#ifndef __STACK_H_
#define __STACK_H_
#endif
#include <cassert>
#include <iostream>
using namespace std;
template <typename T>
class SNode
{
public:
   T  data;
   SNode<T> *next;
   SNode():data(T()),next(NULL){}
};

template <typename T>
class ListStack:public ALstack<T>
{
protected:
   SNode<T> *Top;
   static unsigned int  StackSize;
public:
   ListStack();
   ~ListStack(); 
public:
   bool isEmpty() const;
   bool push(const T data);
   bool pop();
   bool dispose();
   unsigned  int size();
   T topData() const; 
};

template <typename T>
unsigned int ListStack<T>::StackSize = 0;

template <typename T>
inline ListStack<T>::ListStack():Top(NULL)
{ }

template <typename T>
inline ListStack<T>::~ListStack()
{ }

template <typename T>
inline bool ListStack<T>::isEmpty() const
{
   return NULL == Top;
}

template <typename T>
inline bool ListStack<T>::push(const T data) //don't check the data is right
{
   SNode<T> *pNewNode;
   pNewNode = new SNode<T>;     
   if(NULL == pNewNode)
   {
      assert(0);   
   }
   else
   {
     pNewNode->data = data;
     pNewNode->next = Top;
     Top = pNewNode;
     ++StackSize;
   }
   return true;
}

template <typename T>
inline bool  ListStack<T>::pop()
{
   T data;
   SNode<T> *pTmpNode;
   if(isEmpty())
   {
//       throw out_of_range("the Pop is failed,the stack is empty!");
     cout<<"out of range, the stack is empty"<<endl;
    } 

      pTmpNode = Top;
      Top = Top->next;
      delete pTmpNode;
      --StackSize;
      return true;
}

template <typename T>
inline bool ListStack<T>::dispose()
{
   SNode<T> *pTmpNode;
   while(!isEmpty())
   {
      pTmpNode = Top->next;
      delete Top;
      Top = pTmpNode;
      --StackSize;
   }
   return true;
}

template <typename T>
inline unsigned int  ListStack<T>::size()
{
   return StackSize;
}

template <typename T>
inline T  ListStack<T>::topData() const 
{
   if(isEmpty())
   {
      assert(0);
   }
   return Top->data;
}
