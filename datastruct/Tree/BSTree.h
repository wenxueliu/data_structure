/*------------------------------------------------------------------
 
         FileName : BSTree.h
         Version : 0.10
          Author : Wenxue Liu
            Date : 09-17-2012
            Time : 20:35
         comment : Binary Search Tree operator;
                   
        	there is a function datacmp,which is a param of function 
	and need to be define in .cpp file.
------------------------------------------------------------*/
template <typename T>
struct TNode
{
              T  data;
       TNode<T>* pLeft;
       TNode<T>* pRight;
};

/*-----------------------------------
call the function two times because of 
the safe of data
------------------------------------*/
template <typename T>
class BSTree:
{
	private:
		TNode<T> *pRootNode;

	private:
		TNode<T>* find(const T &data,
				TNode<T> *p,
				COMPARE datacmp) const;
		TNode<T>* findmin(TNode<T> *p) const;
		TNode<T>* findmax(TNode<T> *p) const;
		TNode<T>* insert(const T &data,
				TNode<T> *p,
				COMPARE datacmp) ;
		TNode<T>* deletenode(const T &data,
				TNode<T> *p,
				COMPARE datacmp) ;
		TNode<T>* Delete(TNode<T> *p);
	           
	public:  
		TNode<T>* find(const T &data,COMPARE datacmp) const;
		TNode<T>* findmin() const;
		TNode<T>* findmax() const;
		TNode<T>* insert(const T &data,COMPARE datacmp) ;
		TNode<T>* deletenode(const T &data,COMPARE datacmp) ;

};

template <typename T>
inline TNode<T>* BSTree<T>::find(const T &data,COMPARE datacmp) const
{
	return find(data,pRootNode,datacmp);
}
///*
/*----------------------------------
Function: Find the point of data
 ＠param: data 
 ＠param: pRootNode
  Return: Point of TNode
   other: don't recursive
       datacmp is a function which cmpare data and pTmpNode->data 
-----------------------------------*/
template <typename T>
inline TNode<T>* BSTree<T>::find(const T &data,
		TNode<T>*pRootNode,
		COMPARE datacmp) const
{
        /* copy-constructor  */
	TNode<T> *pTmpNode = pRootNode;
	int nRet = 0; 
	while(NULL != pTmpNode)
	{
	 nRet = (*datacmp)(data,pTmpNode->data);
	// data < pTmpNode->data
		if(nRet < 0)
		{
			pTmpNote = pTmpNode->pLeft;
		}
	// data > pTmpNode->data
		else if(nRet > 0)
		{
			pTmpNote = pTmpNode->pRight;
		}
	// data = pTmpNode->data
		else
		{
			return pTmpNode;
		}
	}    
	return NULL;
}
//  */


/*----------------------------------
Function: Find the point of data
  @param: data   pRootNode
  Return: Point of TNode
   other: Recursive 
          datacmp is a function which cmpare data and pTmpNode->data 
-----------------------------------
template <typename T>
inline TNode<T>* BSTree<T>::find(const T &data,
		TNode<T>*pRootNode,
		COMPARE datacmp) const
{
        // copy-constructor
	TNode<T> *pTmpNode = pRootNode;
	if(NULL == pTmpNode)
	{
	   return 0;
	}
	
	int nRet = (*datacmp)(data,pTmpNode->data);
	// data < pTmpNode->data
	if(nRet < 0)  
	{
	pTmpNote = find(data,pTmpNode->pLeft,datacmp);
	}
	// data > pTmpNode->data
	else if(nRet > 0)
	{
	pTmpNote = find(data,pTmpNode->pRight,datacmp);
	}
	// data = pTmpNode->data
	else
	{
	return pTmpNode;
	}
}
 */

template <typename T>
inline TNode<T>* BSTree<T>::findmin() const
{
	return findmin(pRootNode);
}

/*----------------------------------
Function: findmin 
  @param: pRootNode
  Return: Point of MinData
   other: don't Recursive 
----------------------------------*/
template <typename T>
inline TNode<T>* BSTree<T>::findmin(TNode<T>* pRootNode) const
{
        /* copy-constructor  */
	TNode<T> *pTmpNode = pRootNode;
	if(NULL != pTmpNode)
	{
		while(NULL != pTmpNode->pLeft)
		{
			pTmpNote = pTmpNode->pLeft;
		}    
	}
	return pTmpNode;

}

/*----------------------------------
Function: findmin 
  @param: pRootNode
  Return: Point of MinData
   other: Recursive 
          every case must have return,otherwise the 
	  recursive will terminal;
----------------------------------
template <typename T>
inline TNode<T>* BSTree<T>::findmin(TNode<T>* pRootNode) const
{
        //  copy-constructor  
	TNode<T> *pTmpNode = pRootNode;
	if(NULL != pTmpNode)
	{
	     if(NULL != pTmpNode->pLeft)
	     {
		return findmin( pTmpNode->pLeft);
	     }
	     else
	     {
	        return pTmpNode;
	     }
	}
	else
	{
	     return NULL;
        }
}
*/

template <typename T>
inline TNode<T>* BSTree<T>::findmax() const
{
	return findmax(pRootNode);
}

/*----------------------------------
Function: findmax
  @param: pRootNode
  Return: Point of MaxData
   other: don't Recursive 
----------------------------------*/
template <typename T>
inline TNode<T>* BSTree<T>::findmax(TNode<T>*p) const
{
        /* copy-constructor  */
	TNode<T> *pTmpNode = pRootNode;
	if(NULL != pTmpNode)
	{
		while(NULL != pTmpNode->pRight)
		{
			pTmpNote = pTmpNode->pRight;
		}    
	}
	return pTmpNode;
}

/*----------------------------------
Function: findmax 
  @param: pRootNode
  Return: Point of MaxData
   other: Recursive 
          every case must have return,otherwise the 
	  recursive will terminal;
----------------------------------
template <typename T>
inline TNode<T>* BSTree<T>::findmax(TNode<T>* pRootNode) const
{
        //  copy-constructor  
	TNode<T> *pTmpNode = pRootNode;
	if(NULL != pTmpNode)
	{
	     if(NULL != pTmpNode->pRight)
	     {
		return findmax(pTmpNode->pRight);
	     }
	     else
	     {
	        return pTmpNode;
	     }
	}
	else
	{
	     return NULL;
        }
}
*/


template <typename T>
inline TNode<T>* BSTree<T>::insert(const T &data,COMPARE datacmp) const
{
	return insert(data,pRootNode,datacmp);
}

/*----------------------------------
Function: insert data to the leafNode 
  @param: pRootNode 
  @param: data
  @param: pTmpNode1--record the currNode point
  @param: pTmpNode2--record the perNode point
  @param: pNewNode--the point which the data will be insert
  Return: position of the Point of insert 
   other: don't Recursive 
          why need pTmpNode2:
	     the pTmpNode1 is NULL when search to the leafNode. However we
	     need the preNode which point to the pNewNode; we cannot insert
	     the pNewNode without the pTmpNode2.
----------------------------------*/
template <typename T>
inline TNode<T>* BSTree<T>::insert(
                         const T &data, 
			 TNode<T>*pRootNode,
			 COMPARE datacmp) const
{
	//  copy-constructor  
	TNode<T> *pTmpNode1 = pRootNode;
	TNode<T> *pTmpNode2 = pRootNode;
	TNode<T> *pNewNode;
	int nRet = 0;

	pNewNode = new TNode<T>;
	if(NULL == NewNode)
	{
	    assert(0);
	    //throw error
	}
	//if the pRootNode2 is not empty
	if(NULL != pTmpNode1)
	{
		while(NULL != pTmpNode1)
		{
			nRet = (*datacmp)(data,pTmpNode1->data);
			// data < pTmpNode->data
			if(nRet < 0)
			{
				pTmpNode2 = pTmpNode1;
				pTmpNote1 = pTmpNode1->pLeft;
			}
			// data >= pTmpNode->data
			else
			{
				pTmpNode2 = pTmpNode1;
				pTmpNote1 = pTmpNode1->pRight;
			} 
		}
		//now pTmpNode1 is point to NULL,
		//pTmpNode2 is point to pTmpNode1->parent;
		pNewNode->pLeft = NULL:
		pNewNode->pRight = NULL;
		pNewNode->data = data;

		if(nRet < 0)
		{
			pTmpNode2->pLeft = pNewNode;
		}
		else
		{
			pTmpNode2->pRight = pNewNode;
		}
	        return pNewNode;
	}
	//if the pRootNode2 is empty
	else
	{
		pNewNode->pLeft = NULL:
		pNewNode->pRight = NULL;
		pNewNode->data = data;
	        return pRootNode; 
	}
}

/*----------------------------------
Function: Insert data to the leafNode 
  @param: pRootNode
  @param: data
  @param: datacmp() function compare the data and pTmpNode->data 
  Return: Point of the position of insert 
   other: Recursive 
          
----------------------------------/
template <typename T>
inline TNode<T>* BSTree<T>::insert(
                         const T &data, 
			 TNode<T>*pRootNode,
			 COMPARE datacmp) const
{
	//  copy-constructor  
	TNode<T> *pTmpNode = pRootNode;
	TNode<T> *pNewNode;
	int nRet = 0;

	//if the pRootNode2 is not empty
	if(NULL != pTmpNode)
	{
		nRet = (*datacmp)(data,pTmpNode->data);
		// data < pTmpNode->data
		if(nRet < 0)
		{
			pTmpNote = insert(data,pTmpNode->pLeft,datacmp);
		}
		// data >= pTmpNode->data
		else
		{
			pTmpNote = insert(data,pTmpNode->pRight,datacmp);
		} 
	        return pTmpNode; 
	}
	//if the pRootNode2 is empty
	else
	{
	        pNewNode = new TNode<T>;
		if(pNewNode == NULL)
		{
		   assert(0);
		   //throw the inplay error
		}
		pNewNode->pLeft = NULL:
		pNewNode->pRight = NULL;
		pNewNode->data = data;
	        return pTmpNode; 
	}
}
*/

template <typename T>
inline TNode<T>* BSTree<T>::deletenode(const T &data,COMPARE datacmp) const
{
	return deletenode(data,pRootNode,datacmp);
}

/*----------------------------------
Function: Delete node to the leaf node 
  @param: pNode--the pNode which need to delete
  Return: the pNode-- this maybe meaningless 
   other: this function is use for delete the node when 
         find the node which you want to delete
-------------------------------------*/
template <typename T>
inline TNode<T>* BSTree<T>::Delete(TNode<T> *pNode)
{
	TNode<T> *pTmpNode;
	TNode<T> *pTmpNode1;
	TNode<T> *pTmpNode2;

	//both the pleft and pRigth aren't NULL 
	if((NULL != pNode->pLeft) && (NULL != pNode->pRigth))
	{
		//= operator of class
		pTmpNode1 = pNode->pRight;
		//if pTmpNode1->pLeft is not NULL
		if(NULL != pTmpNode1->pLeft)
		{
			//find the min of right subtree; 
			//if TmpNode1->pLeft is empty,find the min 
			//the pTmpNode2 record the parent of pTmpNode1;
			while(NULL != pTmpNode1->pLeft) 
			{
				//= operator of class
				pTmpNode2 = pTmpNode1; 
				pTmpNode1 = pTmpNode1->pLeft; 
			}
			// !!!!!!!this is decide the data must support = operator
			pNode->data = pTmpNode1->data;
			//whether the pTmpNode1->pRight is NULL or not
			pTmpNode2->pLeft = pTmpNode1->pRight;
			delete pTmpNode1;
		}
		//if pTmpNode1->pLeft is NULL,
		//as it is the pNode only have one pRight node;
		else
		{
			// whether the pTmpNode1->pRight is NULL or not
			pNode->pRight = pTmpNode1->pRight;
			delete pTmpNode1;
		}
		return pNode;
	}
	// either the pLeft is NULL or pRight is NULL 
	else
	{
		pTmpNode = pNode;
		// the pLeft isn't  NULL, the pRight is NULL
		if(pNode->pLeft != NULL)
		{
			pNode = pNode->pLeft;  
		}
		// the pRigth isn't  NULL,the pLeft is NULL
		else if(pNode->pRight != NULL)
		{
			pNode = pNode->pRight;  
		}
		//both the pRigth and pLeft are NULL,the tree only have one node
		else
		{
			pNode = NULL;
		}
		delete pTmpNode;
	}
	return pNode;
}
/*----------------------------------
Function: Delete data to the leafNode 
  @param: pRootNode 
  @param: data
  @param: datacmp() function compare the data and pTmpNode->data 
  @param: pTmpNode--record the currNode point
  Return: position of the Point of insert 
   other: don't Recursive 
          
----------------------------------*/
template <typename T>
inline TNode<T>* BSTree<T>::deletenode( const T &data,
		     TNode<T>*p,
		     COMPARE datacmp) const
{
        //  copy-constructor  
	TNode<T> *pTmpNode = pRootNode;
	int nRet = 0;

	//if the pRootNode2 is not NULL 
	if(NULL != pTmpNode)
	{
	        //try to find the  pTmpNode->data is equal to data
		while(NULL != pTmpNode)
		{
			nRet = (*datacmp)(data,pTmpNode->data);
			// data < pTmpNode->data
			if(nRet < 0)
			{
				pTmpNote = pTmpNode->pLeft;
			}
			// data >= pTmpNode->data
			else if(nRet > 0)
			{
				pTmpNote = pTmpNode->pRight;
			} 
			else
			{
			        //delete the node
		                return Delete(pTmpNode);	
			}
		}
		//if the pTmpNode is not exist;
                cout<<"the pNode isn't in the tree!"<<endl;
	        return NULL;
	}
	//if the pRootNode2 is empty
	else
	{
		cout<<"the tree is empty"<<endl;
	        assert(0);
	}
       
}


/*----------------------------------
Function: Delete data to the leafNode 
  @param: pRootNode 
  @param: data
  @param: datacmp() function compare the data and pTmpNode->data 
  @param: pTmpNode--record the currNode point
  Return: position of the Point of insert 
   other: Recursive 
----------------------------------/
template <typename T>
inline TNode<T>* BSTree<T>::deletenode( const T &data,
		     TNode<T>*pNode,
		     COMPARE datacmp) const
{
        //  copy-constructor  
	TNode<T> *pTmpNode;
	int nRet = 0;

	//if the pRootNode2 is not empty
	if(NULL != pNode)
	{
		nRet = (*datacmp)(data,pTmpNode1->data);
		// data < pTmpNode->data
		if(nRet < 0)
		{
			pNode->pLeft = deletenode(data,
			                         pTmpNode1->pLeft,
						 datacmp);
		}
		// data >= pTmpNode->data
		else if(nRet > 0)
		{
			pNode->pRight = deletenode(data,
			                           pTmpNode1->pRight,
						   datacmp);
		} 
		else
		{
		       if(pNode->pLeft && pNode->pRight)
		       {
		       //find the min of right 
		       	pTmpNode = findmin(pNode->pRight); 
			pNode->data = pTmpNode->data;
                        //it take me so much time to understand it!
			//why? because I don't recongnise the pNode->data 
			// is equal pTmpNode->data; 
			// firstly, I write like this 
			// pNode = deletenode(pTmpNode->data,pTmpNode,datacmp);
			// oh,my god, it is more effective.
			pNode->Right = deletenode(pNode->data,
			                      pNode->pRight,
					      datacmp);	
		       }
		       //if either pNode->pLeft or pNode->pRight is empty
		       //here the method is different from the Delete(),campare!!
		       else
		       {
		         pTmpNode = pNode;
			 //the pleft is NULL or both the pleft and pright
			 if(pNode->pLeft == NULL)
			 {
			    pNode = pNode->pRight;
			 }
			 //the pright is NULL or both the pleft and pright
			 else if(pNode->pRigth == NULL)
			 {
			    pNode = pNode->pLeft;
			 }
			 delete pTmpNode;
		       }
		}

	        return pNode;
	}
	//if the data is not in the tree;
	else
	{
		cout<<"the data isn't in the Tree or the tree is empty!"<<endl;
		assert(0);
	}
       
}
*/
