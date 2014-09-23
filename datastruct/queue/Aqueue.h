/*-----------------------------------
  
     FlieName : Aqueue.h
     Version  : Wenxue Liu
        Date  : 09-16-2012
        Time  : 16:06 
     Comment  : there are two methods to achieve;
                first: with list;
                second: with arry;
                here, we use the second;
            队存在的一个问题是：当队中没有元素的时候，rear = front，加入一些元素，当元素为满
     时，rear + 1 = front,看似没问题。但是,此时却有一个问题，怎么判断队列是否为空，
            此时,当把元素逐个退出队后,如果仍然认为rear = front是空的话就有问题了，
     因为此时，队中仍有一个元素,你怎么能说是空呢？于是就现有下面的讨论：

    满队和空队的判断：一、记录队中元素的个数。用一个变量来记录数组的大小。这个方法最简单，此处不讨论。
                      二、至少用一个布尔变量来指示队列是否为空；
                      三、设置数组的大小为n+1，但是只需存储n个元素。这里采用这种方法。
                          这里有两种情况
                                         1、front = 1; rear = 0;
                                           (rear+2)%size == front 满
                                            rear+1 = front        空
                                         2、front = 0; rear = 0;
                                            front = rear + 1 满 
                                            front = rear 空  
                     注： 最后一个 rear中不记录数据，如果记录，你就会无法判断为空。
    数组实现队列，有非环形和环形，这里是环形的实现方法。非环形的实现非常简单，参考栈的数组实现。 
----------------------------------*/
#ifndef __ARRY_QUEUE_H_
#define __ARRY_QUEUE_H_

#include <iostream>
#include <cassert>
#include "queue.h"

using namespace std;

//const unsigned int CAPCITY = 11;

template <typename T>
class Aqueue:public Queue<T> //the class Queue is not necessary
{
protected:
   T *ArryQueue;
   static unsigned int size;
   static unsigned int front;
   static unsigned int rear;
   static const unsigned int CAPCITY = 11;// see the effective C++ 3rd item3;
public:
   Aqueue();
   ~Aqueue(); 
public:
   bool isEmpty() const;
   bool isFull() const;
   bool enqueue(const T data);
   bool dequeue();
   bool dispose();
   unsigned  int arrysize() const;
   unsigned  int capcity() const;
   T frontVal() const; 
};

//these three var show which method you use to judge the queue is full or empty;
template <typename T>
//unsigned int Aqueue<T>::front = 0;
unsigned int Aqueue<T>::front = 1;
template <typename T>
unsigned int Aqueue<T>::rear= 0;
template <typename T>
unsigned int Aqueue<T>::size = 0;


template <typename T>
inline Aqueue<T>::Aqueue():ArryQueue(new T[CAPCITY])
{ }

template <typename T>
inline Aqueue<T>::~Aqueue()
{ delete []ArryQueue;}

template <typename T>
inline bool Aqueue<T>::isEmpty() const
{
  return ((rear - front + 1) % CAPCITY == 0);
//   return front == rear;
}

template <typename T>
inline bool Aqueue<T>::isFull() const
{
  // return ((rear + 1) == front);
     return ((rear + 2) == front);
}

template <typename T>
inline bool Aqueue<T>::enqueue(const T data) //don't check the data is right
{
     if(!isFull())
     {
   //   ArryQueue[rear] = data;
      rear = (rear + 1) % CAPCITY;
      ArryQueue[rear] = data;
      ++size;
      return true;
     }
     else
     {
       cout<<"the queue is full!"<<endl;     
       return false;
     }
}

template <typename T>
inline bool  Aqueue<T>::dequeue()
{
   if(!isEmpty())
   {
     front = (front + 1) % CAPCITY;
     --size;
   }
   return true;
}

template <typename T>
inline bool Aqueue<T>::dispose()
{
   while(!isEmpty())
   {
      front = (front + 1) % CAPCITY;
      --size;
   } 
   return true;
}

template <typename T>
inline unsigned int  Aqueue<T>::arrysize() const
{
   return size;
}

template <typename T>
inline unsigned int  Aqueue<T>::capcity() const
{
   return CAPCITY - 1;
}

template <typename T>
inline T  Aqueue<T>::frontVal() const 
{
   if(!isEmpty())
   {
     return ArryQueue[front];
   }
   else
   {
     cout<<"the queue is empty"<<endl;
     assert(0);
   }
}

#endif //__LIST_QUEUE_H_
