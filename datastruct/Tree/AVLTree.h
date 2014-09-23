/*----------------------------------------------------
      
      FileName : AVLTree.h
      Version  : 0.10
      Author   : Wenxue Liu
      Date     : 09-20
      Time     : 00:30
      comment  : AVLTree; include SingleRotateRight
                                  SingleRotateLeft
				  DoubleRotateRight
				  DoubleRotateLeft
                                  Insert
				  Delete
-----------------------------------------------------*/
template <typename T>
class CAVLTree:public CBinTree
{
	private:
                CBTNode<T>* Insert(const T &data,CBTNode<T> *pNode);

	public:
		CAVLTree(CBTNode<T> *initroot = NULL);
		~CAVLTree();

                CBTNode<T>* SingleRotateRight(CBTNode<T> *pNode);
                CBTNode<T>* SingleRotateLeft(CBTNode<T> *pNode);
                CBTNode<T>* DoubleRotateRight(CBTNode<T> *pNode);
                CBTNode<T>* DoubleRotateRight(CBTNode<T> *pNode);
                CBTNode<T>* Insert(const T &data);
                CBTNode<T>* Delete(const T &data);
                
};

//constructor  
template <typename T>
inline CAVLTree<T>::CAVLTree(CBTNode<T> *initroot):CBinTree(initroot)
{
}

//deconstructor
template <typename T>
inline CAVLTree<T>::~CAVLTree()
{
}

/*-----------------------------------
 Function : SingleRotateRight
 @parama  : pNode -- the node which will be begin  rotate  
 Return   : pNode -- the point bigin to rotate 
 Other    : if you want to be add pParent,you should 
            consider every nodes which you change it.

	    the right right
-----------------------------------*/
template <typename T>
inline CBTNode<T>* CAVLTree<T>::SingleRotateRight(CBTNode<T> *pNode)
{
      CBTNode<T> *pTmpNode;
      pTmpNode = pNode->Right;
      pTNode->Right = pTmpNode->pLeft;
      if(pTmpNode->pLeft != NULL)
      {
          pTmpNode->pLeft->pParent = pNode;
      }

      pTmpNode->pParent = pNode->pParent;
      if(pNode == m_pRootNode)
      {
          m_pRootNode = pTmpNode;
      }
      else if(pNode == pNode->pParent->pLeft)
      {
          pNode->pParent->pLeft = pNode;
      }
      else
      {
          pNode->pParent->pRight = pNode;
      }
     
      pTmpNode->pLeft = pNode;
      pNode->pParent = pTmpNode;
      
      return TmpNode;
}
/*-----------------------------------
 Function : SingleRotateLeft
 @parama  : pNode -- the node which will be begin  rotate  
 Return   : pNode -- the point bigin to rotate 
 Other    : if you want to be add pParent,you should 
            consider every nodes which you change it.

            the left left
-----------------------------------*/
template <typename T>
inline CBTNode<T>* CAVLTree<T>::SingleRotateLeft(CBTNode<T> *pNode)
{
      CBTNode<T> *pTmpNode;
      pTmpNode = pNode->pLeft;
      pNode->pLeft = pTmpNode->pRight;
      if(pTmpNode->pRight != NULL)
      {
          pTmpNode->pRight->pParent = pNode;
      }

      pTmpNode->pParent = pNode->pParent;
      if(pNode == m_pRootNode)
      {
         pTmpNode = m_pRootNode;
      }
      else if(pNode == pNode->pParent->Left)
      {
         pNode->pParent->pLeft = pTmpNode;
      }
      else 
      {
         pNode->pParent->pRight = pTmpNode;
      }

      pTmpNode->pRight = pNode; 
      pNode->pParnt = pTmpNode;

      return pTmpNode;
}


/*-----------------------------------
 Function : DoubleRotateRight
 @parama  : pNode -- the node which will be begin  rotate  
 Return   : node -- the point bigin to rotate 
 Other    : it is so simple that you can get it; 

           the 
-----------------------------------*/
template <typename T>
inline CBTNode<T>* CAVLTree<T>::DoubleRotateRight(CBTNode<T> *pNode)
{
  pNode->pRight = SingleRotateLeft(pNode->pRigth);
  pNode = SingleRotateRight(pNode);
}


/*-----------------------------------
 Function : DoubleRotateLeft
 @parama  : pNode -- the node which will be begin  rotate  
 Return   : pNode -- the point bigin to rotate 
 Other    : it is so simple that you can get it; 
-----------------------------------*/
template <typename T>
inline CBTNode<T>* CAVLTree<T>::DoubleRotateLeft(CBTNode<T> *pNode)
{
  pNode->pLeft= SingleRotateRight(pNode->pLeft);
  pNode = SingleRotateLeft(pNode);
}

/*-----------------------------------
 Function : Insert 
 @parama  : pNode -- the node which will be begin  rotate  
 Return   : pNode -- the point bigin to rotate 
 Other    : it is so simple that you can get it; 
-----------------------------------*/
template <typename T>
inline CBTNode<T>* CAVLTree<T>::Insert(const T &data,CBTNode<T> *pNode)
{
     if(pNode == NULL)
     {
	     pNode = new CBTNode<T>;
	     if(pNode != NULL)
	     {
		  pNode->data = data;
		  pNode->pLeft = NULL;
		  pNode->pRight = NULL;
	     }
	     else
	     {
		     cout<<"inply the memory failed!!"<<endl;
		     assert(0);
	     }
     }
     // pNode != NULL
     else
     {
            if(data < pNode->data)
            {
                 pNode->pLeft = Insert(data,pNode->pLeft);
		 
		 if(pNode->pLeft)
		 {
		     pNode->pLeft->pParent = pNode;
		 }

	         if(2 == (GetHeight(pNode->left) 
		          - GetHeight(pNode->pRight)))	 
		 {
		    //the left left
		    if(data < pNode->pLeft->data)
		    {
		    pNode->pLeft = SingleRotateLeft(pNode->pLeft);
                    }
		    //the left right
		    else
		    {
		    pNode->pLeft = DoubleRotateRight(pNode->pLeft);
		    }
		 } 
            }
            // data >= pNode->data 
            else
	    {
	         pNode->pRight = Insert(data,pNode->pLeft); 

	         if(pNode->pRight)
		 {
		    pNode->pRight->pParent = pNode;
		 }

		 if(2 == (GetHeight(pNode->pRight) - GetHeight(pNode->pLeft)))
		 {
		    //the right right 
		    if(data > pNode->pRight->data)
		    {
		    pNode->pRight = SingleRotateRight(pNode->pRight);
		    }
		    //the right left
		    else
		    {
		      pNode->pRight = DoubleRotateRight(pNode->pRight);
		    }
		 }
		 
	    }
      }
      return pNode;
}


