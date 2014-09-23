//////////////////////////////////////
// 
//  FileName  :   slist.h
//  Version   :   0.10
//  Author    :   Wenxueliu
//  Data      :   09-13-2012 20:35
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
   CNode<T> *next;
   CNode():data(T()),next(NULL){}
   CNode(const T &initdata):data(initdata),next(NULL){}
   CNode(const T &initdata, CNode<T> *p):data(initdata),next(p){}
};

template<typename T>
class CSList
{
protected:
    int m_nCount;
    CNode<T> *m_pNodeHead;

public:
    CSList();
    CSList(const T &initdata);
    ~CSList();

public:
    int  IsEmpty() const;
    int  GetCount()const;
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
};

template<typename T>
inline  CSList<T>::CSList():m_nCount(0),m_pNodeHead(NULL)
{ 
}
 
template<typename T>
inline  CSList<T>::CSList(const T& initdata):m_nCount(0),m_pNodeHead(NULL)
{
   AddHead(initdata); 
}


template<typename T>
inline  CSList<T>::~CSList()
{
   RemoveAll(); 
}

template<typename T>
inline int  CSList<T>::IsEmpty() const
{
   return 0 == m_nCount;
}

template<typename T>
inline int  CSList<T>::GetCount() const
{
   return m_nCount;
}

template<typename T>
inline int  CSList<T>::InsertBefore(const int pos, const T data)
{
   CNode<T> *pNewNode;
   int nRetPos = 0;
   CNode<T> *pNewNode1;
   CNode<T> *pNewNode2;
   
   pNewNode = new CNode<T>;
   if(NULL == pNewNode)
   {
     return nRetPos;
    }
   
   pNewNode->data = data;
   if(NULL == m_pNodeHead)// I think it is not needed;
   {
     pNewNode->next  = NULL;
     m_pNodeHead = pNewNode;
     ++m_nCount;
     nRetPos = 1;
     return nRetPos;
   }
   
 //  ASSERT(1 <= pos);
 //  ASSERT(pos <= m_nCount);

   if(1 == pos)
   {
     pNewNode->next  = m_pNodeHead;
     m_pNodeHead = pNewNode;
     ++m_nCount;
     nRetPos = 1;
     return nRetPos;
   }
   
   int i;
   pNewNode1 = m_pNodeHead;
   for(i = 1; i < pos; ++i)
   { 
   pNewNode2 = pNewNode1;
   pNewNode1 = pNewNode1->next; 
   }
   pNewNode->next = pNewNode1;
   pNewNode2->next = pNewNode;
/*
   if only pTmpNode without pNewNode1 or pNewNode2,it will make like this: 

   pTmpNode = m_pNodeHead;
   for(i = 1; i < pos; ++i)
   { 
   pTmpNode = pTmpNode->next; 
   }
   pNewNode->next = pTmpNode;
   pTmpNode->next = pNewNode;
*/
   ++m_nCount;
   nRetPos = pos;
   return m_nCount;
}


template<typename T>
inline int  CSList<T>::InsertAfter(const int pos, const T data)
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
     m_pNodeHead = pNewNode;
     ++m_nCount;
     nRetPos = 1;
     return nRetPos;
   }
   
 //  ASSERT(1 <= pos);
 //  ASSERT(pos <= m_nCount);
   
   int i;
   pTmpNode = m_pNodeHead;
   for(i = 1; i < pos; ++i)
   { 
   pTmpNode = pTmpNode->next; 
   }
   pNewNode->next = pTmpNode->next;
   pTmpNode->next = pNewNode;
   ++m_nCount;
   nRetPos = pos + 1;
   return m_nCount;
}


template<typename T>
inline int  CSList<T>::AddHead(const T data)
{
  CNode<T> *pNewNode;

  pNewNode = new CNode<T>;
  if(NULL == pNewNode)
  {
      return 0;
  }
  
  pNewNode->data = data;
  pNewNode->next = m_pNodeHead;
  m_pNodeHead = pNewNode;

  ++m_nCount;
  return 1;
}

template<typename T>
inline int  CSList<T>::AddTail(const T data)
{
   return InsertAfter(GetCount(),data); 
}

template<typename T>
inline void CSList<T>::RemoveAt(const int pos)
{
  // ASSERT(1 <= pos);
  // ASSERT(pos <= m_nCount);

   int i;
   CNode<T> *pNewNode1;
   CNode<T> *pNewNode2;   

   pNewNode1 = m_pNodeHead;
   if(1 == pos)
   {
      m_pNodeHead = m_pNodeHead->next;
      delete pNewNode1; 
      --m_nCount;
   }

   for(i = 1; i < pos; ++i)
   {
     pNewNode2 = pNewNode1; 
     pNewNode1 = pNewNode1->next;
   }
   pNewNode2->next = pNewNode1->next;
   delete pNewNode1;
   --m_nCount;
    
}

template<typename T>
inline int CSList<T>::RemoveRange(const int pos1,const int pos2)
{
 //  ASSERT(1 <= pos1);
 //  ASSERT(pos1 < pos2);
 //  ASSERT(pos2 <= m_nCount);

   int i;
   CNode<T> *pNewNode1;
   CNode<T> *pNewNode2;   

   pNewNode1 = m_pNodeHead;
   if(1 == pos1)
   {
      int k = 0;
      while(k < (pos2 - pos1))
      {
      m_pNodeHead = m_pNodeHead->next;
      delete pNewNode1; 
      pNewNode1 = m_pNodeHead;
      }
      m_nCount -= (pos2 - pos1);
      return 1;
   }

   for(i = 1; i < pos1; ++i)
   {
     pNewNode1 = pNewNode1->next;
     pNewNode2 = pNewNode1; 
   }
   int h = 0;
   while(h < (pos2 - pos1))
   {
   pNewNode2 = pNewNode2->next;
   delete pNewNode1;
   pNewNode1 = pNewNode2;
   }
   m_nCount -= (pos2 - pos1);
   return 1;  // if remove is sucess,it return 1;else exit; 
}

template<typename T>
inline void CSList<T>::RemoveHead()
{
  // ASSERT(0 != m_nCount);
   RemoveAt(1);
}

template<typename T>
inline void CSList<T>::RemoveTail()
{
  // ASSERT(0 != m_nCount);
   RemoveAt(m_nCount);
}

template<typename T>
inline void CSList<T>::RemoveAll()
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
   
   m_nCount = 0;
}

template<typename T>
inline T& CSList<T>::GetHead()
{
  // ASSERT(0 != m_nCount);
   return m_pNodeHead->data;
}

template<typename T>
inline T CSList<T>::GetHead() const
{
 //  ASSERT(0 != m_nCount);
   return m_pNodeHead->data;
}

template<typename T>
inline T& CSList<T>::GetTail()
{
  // ASSERT(0 != m_nCount);
   
   int i;
   int nCount;
   CNode<T> *pTmpNode = m_pNodeHead;
   
   nCount = m_nCount;
   for(i = 1; i < nCount; ++i)
   {
     pTmpNode = pTmpNode->next;
   }
   return pTmpNode->data;
}

template<typename T>
inline T CSList<T>::GetTail() const
{
  // ASSERT(0 != m_nCount);
   
   int i;
   int nCount;
   CNode<T> *pTmpNode = m_pNodeHead;
   
   nCount = m_nCount;
   for(i = 1; i < nCount; ++i)
   {
     pTmpNode = pTmpNode->next;
   }
   return pTmpNode->data;
}

template<typename T>
inline T& CSList<T>::GetAt(const int pos)
{
  //  ASSERT(1 <= pos);
  //  ASSERT(pos <= m_nCount);
    int i;
    CNode<T> *pTmpNode = m_pNodeHead;
    
    for(i = 1; i < pos; ++i)
    {
      pTmpNode = pTmpNode->next;
    }
    return pTmpNode->data;
}

template<typename T>
inline T CSList<T>::GetAt(const int pos) const
{
  //  ASSERT(1 <= pos);
  //  ASSERT(pos <= m_nCount);

    int i;
    CNode<T> *pTmpNode = m_pNodeHead;
    
    for(i = 1; i < pos; ++i)
    {
      pTmpNode = pTmpNode->next;
    }
    return pTmpNode->data;
}

template<typename T>
inline void CSList<T>::SetAt(const int pos, T data)
{
 //  ASSERT(1 <= pos)；
 //  ASSERT(pos <= m_nCount);

    int i;
    CNode<T> *pTmpNode = m_pNodeHead;
    
    for(i = 1; i < pos; ++i)
    {
      pTmpNode = pTmpNode->next;
    }
    pTmpNode->data = data;

}
/*
  if find
      return the pos(position),
  else 
      return 0;
*/
template<typename T>
inline int CSList<T>::Find(const T data) const
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


//#endif //__SINGLE_LIST_H_
