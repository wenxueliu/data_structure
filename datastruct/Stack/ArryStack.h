/*-----------------------------------
  
     FlieName : ArryStack.h
     Version  : Wenxue Liu
        Date  : 09-15-2012 
        Time  : 23:30
     Comment  : achieve the stack by array

----------------------------------*/
#ifndef __STACK_H_
#define __STACK_H_
#endif
#include <cassert>
#include <iostream>
using namespace std;

const int CAPCITY = 10;
template <typename T>
class ArryStack:public ALstack<T>
{
protected:
     T *arryStack;
     static  unsigned  int  StackCapcity;
     static  unsigned  int  top; // is it right?

public:
   ArryStack();
   ~ArryStack(); 
public:
   bool isEmpty() const;
   bool isFull() const;
   bool push(const T data);
   bool pop();
   unsigned int size() const;
   unsigned int capcity() const;
   T topData(); 
};

template <typename T>
unsigned int ArryStack<T>::StackCapcity = CAPCITY;
template <typename T>
unsigned int ArryStack<T>::top = 0;

template <typename T>
inline ArryStack<T>::ArryStack():arryStack(new T[CAPCITY])//,StackCapcity(CAPCITY),top(0)
{ }

template <typename T>
inline ArryStack<T>::~ArryStack()
{ delete []arryStack;}

template <typename T>
inline bool ArryStack<T>::isEmpty() const
{
   return NULL == arryStack;
}

template <typename T>
inline bool ArryStack<T>::isFull() const
{
   return top == StackCapcity; 
}

template <typename T>
inline bool ArryStack<T>::push(const T data) //don't check the data is right
{
   ++top;
   if(top > StackCapcity)
   {
     assert(0);
    }
   else
   {
   arryStack[top - 1] = data;
   }
   return true;
}

template <typename T>
inline bool  ArryStack<T>::pop()
{
   T data;
   if(isEmpty())
   {
//   throw out_of_range("the Pop is failed,the stack is empty!");
     cout<<"out of range, the stack is empty"<<endl;
    } 

   arryStack[top - 1] = 0;   
   --top;
   if(0 == top)
   {
      arryStack = NULL;    
   }
   return true;
}

template <typename T>
inline unsigned int  ArryStack<T>::size() const
{
   return top;
}

template <typename T>
inline unsigned int ArryStack<T>::capcity() const
{
    return StackCapcity;
}

template <typename T>
inline T  ArryStack<T>::topData()
{
   if(isEmpty())
   {
     assert(0);
   }
   return arryStack[top - 1];
}
