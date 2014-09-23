/*-----------------------------------
  
     FlieName : Lqueue.h
     Version  : Wenxue Liu
        Date  : 09-16-2012
        Time  : 10:56 
     Comment  : there are two methods to achieve;
                first: with list;
                second: with arry;
                here, we use the first;
----------------------------------*/
#ifndef __LIST_QUEUE_H_
#define __LIST_QUEUE_H_

#include <iostream>
#include <cassert>
#include "queue.h"

using namespace std;
template <typename T>
class QNode
{
public:
   T  data;
   QNode<T> *next;
   QNode():data(T()),next(NULL){}
};

template <typename T>
class Lqueue:public Queue<T>
{
protected:
   QNode<T> *rear;
   QNode<T> *front;
   static unsigned int  LqueueSize;
public:
   Lqueue();
   ~Lqueue(); 
public:
   bool isEmpty() const;
   bool enqueue(const T data);
   bool dequeue();
   bool dispose();
   unsigned  int listSize() const;
   T frontVal() const; 
};

template <typename T>
unsigned int Lqueue<T>::LqueueSize = 0;

template <typename T>
inline Lqueue<T>::Lqueue():front(NULL),rear(NULL)
{ }

template <typename T>
inline Lqueue<T>::~Lqueue()
{ }

template <typename T>
inline bool Lqueue<T>::isEmpty() const
{
   if(rear != NULL || front != NULL)
    {
      return false;
    }
   else 
     {
      return true;
    }
}

template <typename T>
inline bool Lqueue<T>::enqueue(const T data) //don't check the data is right
{
   QNode<T> *pNewNode;
   pNewNode = new QNode<T>;     
   if(NULL == pNewNode)
   {
    cout<<"the memory is not success"<<endl;
    assert(0);//this is not best;   
    }
   else
   {
/*
the LqueueSize is more likely equal to 0;
so this is more effective
*/
     pNewNode->data = data;
     if(!isEmpty()) //if the queue is not  empty
     {
// I make a mistake here,because I write with pNewNode = rear->next
// in fact, the rear->next is anywhere,so it's wrong;
// However the pNewNode is somewhere in heap,so the rigth is rear->next = pNewNode
     rear->next = pNewNode;
     rear = pNewNode;
     }
     else
     {
     front = pNewNode;
     rear  = pNewNode;
     }
     ++LqueueSize;
     return true;
   }
}

template <typename T>
inline bool  Lqueue<T>::dequeue()
{
   T data;
   QNode<T> *pTmpNode;
   if(isEmpty())
   {
//       throw out_of_range("the Pop is failed,the stack is empty!");
     cout<<"out of range, the stack is empty"<<endl;
    } 
/*
the LqueueSize is more likely equal to 0;
so this is more effective
*/
 // if the queue have more than  one member;
   if(rear != front)// if(LqueueSize != 1)
   {
      pTmpNode = front->next;
      delete front;
      front = pTmpNode;
      --LqueueSize;
   }
   else
   {
      delete front;
      rear = NULL;
      front = NULL;
      --LqueueSize;
   }   
   return true;
}

template <typename T>
inline bool Lqueue<T>::dispose()
{
   QNode<T> *pTmpNode;
   while(!isEmpty())
   {
/*
the LqueueSize is more likely equal to 0;
so this is more effective
*/
      if(LqueueSize > 1)
      {
      pTmpNode = front->next;
      delete front;
      front = pTmpNode;
      --LqueueSize;
      }
      else 
      {
        delete front;
        rear = NULL;
        front = NULL;
        --LqueueSize;
      }
   }
   return true;
}

template <typename T>
inline unsigned int  Lqueue<T>::listSize() const
{
   return LqueueSize;
}

template <typename T>
inline T  Lqueue<T>::frontVal() const 
{
   if(isEmpty())
   {
      assert(0);
   }
   return front->data;
}

#endif //__LIST_QUEUE_H_
