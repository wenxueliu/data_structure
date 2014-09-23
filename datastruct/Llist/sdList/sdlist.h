///////////////////////////////////
// 
//  FileName  :   sdlist.h
//  Version   :   0.10
//  Author    :   Wenxueliu
//  Data      :   09-14-2012 20:35
//  comment   :   from www.luocong.com
/////////////////////////////////////////
/*
#ifndef __SINGLE_LIST_H__
#define __SINGLE_LIST_H__

#include <assert.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define DEBUG_NEW new (_NORMAL_BLOCK, THIS_FILE, __LINE__)
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#ifdef _DEBUG
#ifndef ASSERT
#define ASSERT  assert
#endif
#else
#ifndef ASSERT
#define ASSERT
#endif
#endif
*/
template <typename T>
class CNode
{
public:
   T data;
   CNode<T> *prior;
   CNode<T> *next;
   CNode():data(T()),prior(NULL),next(NULL){}
   CNode(const T &initdata):data(initdata),prior(NULL),next(NULL){}
};

template<typename T>
class CDList
{
protected:
    int m_nCount;// does it need to be static
    CNode<T> *m_pNodeHead;
    CNode<T> *m_pNodeTail;

public:
    CDList();
    CDList(const T &initdata);
    ~CDList();

public:
    int  IsEmpty() const;
    int  GetCount() const;
    int  InsertBefore(const int pos,const T data);
    int  InsertAfter(const int pos, const T data);
    int  AddHead(const T data);
    int  AddTail(const T data);
    int   RemoveRange(const int pos1, const int pos2);
    void  RemoveAt(const int pos);
    void  RemoveHead();
    void  RemoveTail();
    void  RemoveAll();
    T&    GetHead();
    T     GetHead() const;
    T&    GetTail();
    T     GetTail() const;
    T&    GetAt(const int pos);
    T     GetAt(const int pos) const;
    void  SetAt(const int pos, T data);
    int   Find(const T data) const;
    T&    GetPrev(int &pos);
    T&    GetNext(int &pos);
};

template<typename T>
inline  CDList<T>::CDList():m_nCount(0),m_pNodeHead(NULL),m_pNodeTail(NULL)
{ 
}
 
template<typename T>
inline  CDList<T>::CDList(const T& initdata):m_nCount(0),m_pNodeHead(NULL),m_pNodeTail(NULL)
{
   AddHead(initdata); 
}


template<typename T>
inline  CDList<T>::~CDList()
{
   RemoveAll(); 
}

template<typename T>
inline int  CDList<T>::IsEmpty() const
{
   return 0 == m_nCount;
}

template<typename T>
inline int  CDList<T>::GetCount() const
{
   return m_nCount;
}

template<typename T>
inline int  CDList<T>::InsertBefore(const int pos, const T data)
{
   CNode<T> *pNewNode;
   int nRetPos = 0;
   CNode<T> *pTmpNode;
   
   pNewNode = new CNode<T>;
   if(NULL == pNewNode)
   {
     return nRetPos;
    }
   
   pNewNode->data = data;
   if(NULL == m_pNodeHead)
   {
     pNewNode->next  = NULL;
     pNewNode->prior = NULL;
     m_pNodeHead = pNewNode;
     m_pNodeTail = pNewNode;
     ++m_nCount;
     nRetPos = 1;
     return nRetPos;
   }
   
   //ASSERT(1 <= pos);
  // ASSERT(pos <= m_nCount);

   if(1 == pos)
   {
     pNewNode->next  = m_pNodeHead;
     pNewNode->prior = NULL;

     m_pNodeHead->prior = pNewNode;
     m_pNodeHead = pNewNode;
     ++m_nCount;
     nRetPos = 1;
     return nRetPos;
   }
   
   int i;
   pTmpNode = m_pNodeHead;
   for(i = 1; i < pos; ++i)
   { 
    pTmpNode = pTmpNode->next; 
   }
   /*
now I understand the method of  insert a node;
the first: change the point at of new node;
the second: change the point at of node  whose  position need to change;
   */
   pNewNode->prior = pTmpNode->prior;
   pNewNode->next = pTmpNode;

   pTmpNode->prior->next = pNewNode;
   pTmpNode->prior = pNewNode;
/*
whether the node is the last before; if it is,
we must change point at of the tail node before;
*/
   if(NULL == pNewNode->next)// I think there is a probelm;
   {
      m_pNodeTail = pNewNode;
   }
   ++m_nCount;
   nRetPos = pos;
   return m_nCount;
}


template<typename T>
inline int  CDList<T>::InsertAfter(const int pos, const T data)
{
   CNode<T> *pNewNode;
   int nRetPos = 0;
   CNode<T> *pTmpNode;
   
   pNewNode = new CNode<T>;
   if(NULL == pNewNode)
   {
     return nRetPos;
    }
   
   pNewNode->data = data;
   if(NULL == m_pNodeHead)
   {
     pNewNode->next  = NULL;
     pNewNode->prior = NULL;
     m_pNodeHead = pNewNode;
     m_pNodeTail = pNewNode;
     ++m_nCount;
     nRetPos = 1;
     return nRetPos;
   }
   
   //ASSERT(1 <= pos);
   //ASSERT(pos <= m_nCount);
   
   int i;
   pTmpNode = m_pNodeHead;
   for(i = 1; i < pos; ++i)
   { 
   pTmpNode = pTmpNode->next; 
   }
   pNewNode->next = pTmpNode->next;
   pNewNode->prior = pTmpNode;
   if(pTmpNode->next == m_pNodeTail)
   {
     m_pNodeTail->prior = pNewNode;
   }
   pTmpNode->next = pNewNode;

   if(NULL == pTmpNode->next)
   {
     m_pNodeTail = pNewNode;
   }
   //pTmpNode->next-prior = pNewNode;//I think this is needed;
   
   ++m_nCount;
   nRetPos = pos + 1;
   return m_nCount;
}


template<typename T>
inline int  CDList<T>::AddHead(const T data)
{
   return InsertBefore(1,data);
}

template<typename T>
inline int  CDList<T>::AddTail(const T data)
{
   return InsertAfter(GetCount(),data); 
}

template<typename T>
inline void CDList<T>::RemoveAt(const int pos)
{
   //ASSERT(1 <= pos);
   //ASSERT(pos <= m_nCount);

   int i;
   CNode<T> *pTmpNode;

   pTmpNode = m_pNodeHead;
   if(1 == pos)
   {
      m_pNodeHead = m_pNodeHead->next;
      goto Exit1;     
   }

   for(i = 1; i < pos; ++i)
   {
     pTmpNode = pTmpNode->next;
   }
  // pTmpNode->next->prior = pTmpNode->prio;
   pTmpNode->prior->next = pTmpNode->next;
   /*
   if(pTmpNode == m_pNodeHead)
   {
      m_pNodeTail = pTmpNode->prior;
   }
   */
Exit1:
   delete pTmpNode;
   --m_nCount;
  if(0 == m_nCount)
  {
       m_pNodeTail = NULL;
  }
}

template<typename T>
inline int CDList<T>::RemoveRange(const int pos1,const int pos2)
{
   //ASSERT(1 <= pos1);
   //ASSERT(pos1 < pos2);
   //ASSERT(pos2 <= m_nCount);

   int i;
   CNode<T> *pTmpNode1;   
   CNode<T> *pTmpNode2;   
   CNode<T> *pTmpNode3;   

   pTmpNode1 = m_pNodeHead;
   if(1 == pos1)
   {
      int k = 0;
      while(k < (pos2 - pos1))
      {
      m_pNodeHead = m_pNodeHead->next;
      delete pTmpNode1; 
      pTmpNode1 = m_pNodeHead;
      } // whether it need to change the position;
      m_nCount -= (pos2 - pos1);
      return 1;
   }

   for(i = 1; i < pos1; ++i)
   {
     pTmpNode2 = pTmpNode1; 
     pTmpNode1 = pTmpNode1->next;
   }
   pTmpNode3 = pTmpNode2;
   int h = 0;
   while(h < (pos2 - pos1))
   {
   pTmpNode2 = pTmpNode1->next;
   delete pTmpNode1;
   pTmpNode1 = pTmpNode2;
   }
   pTmpNode3->next = pTmpNode1;
   pTmpNode1->prior = pTmpNode3;
   m_nCount -= (pos2 - pos1);
   return 1;  // if remove is sucess,it return 1;else exit; 
}

template<typename T>
inline void CDList<T>::RemoveHead()
{
   //ASSERT(0 != m_nCount);
   RemoveAt(1);
}

template<typename T>
inline void CDList<T>::RemoveTail()
{
   //ASSERT(0 != m_nCount);
   RemoveAt(m_nCount);
}

template<typename T>
inline void CDList<T>::RemoveAll()
{
   int i;
   int m_nCount;
   CNode<T> *pTmpNode;

   pTmpNode = m_pNodeHead;
   for(i = 0; i < m_nCount; ++i)
   {
      pTmpNode = m_pNodeHead->next;
      /*the follow two sentences are important, but you must understand 
      what does it do when delete m_pNodeHead.*/
      delete m_pNodeHead;             
      m_pNodeHead = pTmpNode;         
   }
   m_pNodeHead->next = NULL; 
   m_pNodeTail->prior = NULL;
   m_nCount = 0;
}

template<typename T>
inline T& CDList<T>::GetHead()
{
   //ASSERT(0 != m_nCount);
   return m_pNodeHead->data;
}

template<typename T>
inline T CDList<T>::GetHead() const
{
   //ASSERT(0 != m_nCount);
   return m_pNodeHead->data;
}

template<typename T>
inline T& CDList<T>::GetTail()
{
   //ASSERT(0 != m_nCount);
   
   return m_pNodeTail->data;
}

template<typename T>
inline T CDList<T>::GetTail() const
{
   //ASSERT(0 != m_nCount);
   
   return m_pNodeTail->data;
}

template<typename T>
inline T& CDList<T>::GetAt(const int pos)
{
   // ASSERT(1 <= pos);
   // ASSERT(pos <= m_nCount);
    int i;
    CNode<T> *pTmpNode = m_pNodeHead;
    
    for(i = 1; i < pos; ++i)
    {
      pTmpNode = pTmpNode->next;
    }
    return pTmpNode->data;
}

template<typename T>
inline T CDList<T>::GetAt(const int pos) const
{
    //ASSERT(1 <= pos);
    //ASSERT(pos <= m_nCount);

    int i;
    CNode<T> *pTmpNode = m_pNodeHead;
    
    for(i = 1; i < pos; ++i)
    {
      pTmpNode = pTmpNode->next;
    }
    return pTmpNode->data;
}

template<typename T>
inline void CDList<T>::SetAt(const int pos, T data)
{
   //ASSERT(1 <= pos)；
   //ASSERT(pos <= m_nCount);

    int i;
    CNode<T> *pTmpNode = m_pNodeHead;
    
    for(i = 1; i < pos; ++i)
    {
      pTmpNode = pTmpNode->next;
    }
    pTmpNode->data = data;

}

template<typename T>
inline T& CDList<T>::GetPrev(int &pos)
{
   //ASSERT(0 != m_nCount);
   //ASSERT(1 <= pos)；
   //ASSERT(pos <= m_nCount);
    int i;
    CNode<T> *pTmpNode = m_pNodeHead;
    
    for(i = 1; i < pos - 1; ++i)
    {
      pTmpNode = pTmpNode->next;
    }
    --pos;
    return pTmpNode->data;

}

template<typename T>
inline T& CDList<T>::GetNext(int &pos)
{
    //ASSERT(0 != m_nCount);
   //ASSERT(1 <= pos)；
   //ASSERT(pos <= m_nCount);
    int i;
    CNode<T> *pTmpNode = m_pNodeHead;
    
    for(i = 1; i <= pos; ++i)
    {
      pTmpNode = pTmpNode->next;
    }
    ++pos;
    return pTmpNode->data;


}
/*
  if find
      return the pos(position),
  else 
      return 0;
*/
template<typename T>
inline int CDList<T>::Find(const T data) const
{
    int i;
    int nCount;
    CNode<T> *pTmpNode = m_pNodeHead;

    nCount = m_nCount;
    for(i = 1; i <= nCount; ++i)
    {
       if(pTmpNode->data == data)
       {
          return i;
       }
       pTmpNode = pTmpNode->next;
    }
    return 0;
}

//endif //__SINGLE_LIST_H_
