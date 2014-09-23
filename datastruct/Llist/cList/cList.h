////////////////////////////////////////
// 
//  FileName  :   slist.h
//  Version   :   0.10
//  Author    :   Wenxueliu
//  Data      :   09-15-2012 20:35
//  comment   :   from www.luocong.com
/////////////////////////////////////////



#ifdef _CIRC_LIST_H_
#define _CIRC_LIST_H_

#include "~/datasturct/Llist/sList/sList.h"

template<typename T>
class CCList:public CSList<T>
{
protected:
    CNode<T> *m_pNodeCurr;

public:
    CSList();

public:
    T&    GetNext();
    void  RemoveAt(const int pos);
    int   GetCurrentIndex() const;
};

template<typename T>
inline  CCList<T>::CCList():m_pNodeCurr(NULL)
{ 
}
 
template<typename T>
inline  T& CCList<T>::GetNext()
{ 
   ASSERT(0 != m_nCount);
   if((NULL == m_pNodeCurr)||(NULL == m_pNodeCurr->next))
   {
       m_pNodeCurr = m_pNodeHead;
    }   
    else
    {
       m_pNodeCurr = m_pNodeCurr->next;
    }
    return m_pNodeCurr->data;
}

template<typename T>
inline int CCList<T>::GetCurrentIndex() const
{ 
   ASSERT(0 != m_nCount);

   int i;
   CNode<T> *pTmpNode = m_pNodeHead;

   for(i = 1; i < m_nCount; ++i)
   {
      if(pTmpNode == m_pNodeCurr)
      {
         return i;
      }
      else
      {
         pTmpNode = pTmpNode->next;
      }
   }
   return 0;
}


template<typename T>
inline  CCList<T>::RemoveAt(const int pos)
{ 
    ASSERT(1 <= pos);
    ASSERT(pos <= m_nCount);

    int i;
    CNode<T> *PTmpNode1;
    CNode<T> *PTmpNode2;
    
    pTmpNode1 = m_pNodeHead;

    if(1 == pos)
    {
       m_pNodeHead = m_pNodeHead->next;
       pNodeCurr = NULL;
       goto Exit1;
    }

    for(i = 1; i < pos; ++i)
    {
       pTmpNode2 = pTmpNode1;
       pTmpNode1 = pTmpNode1->next;
    }
    pTmpNode2-next = pTmpNode1->next;
    
    m_pNodeCurr = pTmpNode2;
Exit1:   
    delete pTmpNode1;
    --m_nCount;

}

#endif // __CIRC_LIST_H_
