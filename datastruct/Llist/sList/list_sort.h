

/*-------------------------------
  FileName : Sort.h
  Version  : 0.10
  Author   : Wenxue Liu
  Date     : 09-23-2012
  Time     : 20:34
  
--------------------------------*/

template <typename T>
inline void CSList<T>::insertSort(CSList<T> pNode,int (*cmp)(T &data1,T &data2))
{
	if(pNode == NULL || cmp == NULL)
	{
		cout<<"the insert parmater is wrong!!"<<endl;
		assert(0);
	}
	if(m_pNodeHead == NULL)
	{
		cout<<"the list is empty!!"<<endl;
		return false;
	}

	if(NULL == m_pNodeHead->next)
	{
		return true;
	}
        // if m_pNodeHead->next != NULL
	pNextNode = m_pNodeHead;
	while(NULL != pNextNode->next)
	{
		pPreNode = pNextNode;
		pNextNode = pNextNode->next;
		// if pPreNext->data > pNextNode->data
		if(cmp(pNextNode->data,pPreNode->data) < 0)
		{
			pCurNode = m_pNodeHead;
			//if the list only have two node;
			if(pNextNode == m_pNodeHead)
			{
				pCurNode->next = NULL;
				pNextNode->next = pCurNode;
				m_pNodeHead = pNextNode; 
			}
			// more than two nodes
			else
			{
				// if the pNextNode is small than m_pNodeHead,must change the head node
				if(cmp(pNextNode->data, pCurNode->data) < 0)
				{
					pNextNode->next = m_pNodeHead;
					pPreNode = NULL;
				}
				else
				{
					//untill find the data of node which bigger than pNextNode->data
					while(cmp(pCurNode->next->data,pNextNode->data) < 0)
					{
						pCurNode = pCurNode->next;
					}
					pNextNode->next = pCurNode->next;
					pCurNode->next = pNextNode;
					pPreNode = NULL;			  
				}
			}
		}
	return true;

}
