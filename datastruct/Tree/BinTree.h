/*---------------------------------------------

FileName : BinTree.h
 Version : 0.10
  Author : Wenxue Liu
    Date : 09-17-2012
    Time : 19:27
 Comment : the BST(Binary Search Tree) operation

----------------------------------------------*/
#include <iostream>
#include <cassert>

using namespace std;

template <typename T>
class CBTNode
{
	public:  
		T   data;
		CBTNode<T>* pLeft;
		CBTNode<T>* pRight;
		CBTNode<T>* pParent; 
	public:
		CBTNode(
				T data = T(),
				CBTNode<T> *parent = NULL,
				CBTNode<T> *left   = NULL,
				CBTNode<T> *right  = NULL
		       ):data(data),pParent(parent),pLeft(left),pRight(right){}
};



template <typename T>
class CBinTree
{
	protected:
		//class CBTNode
		CBTNode<T>* m_pRootNode;

	public:
		CBinTree(CBTNode<T> *initroot = NULL);
		~CBinTree();
		void AssignTo(CBTNode<T> *pNode);
		void Copy(CBTNode<T> &pNode);

	private:
		void PreOrderTraverse( 
				const CBTNode<T> *pNode,
				void (*visit)(const T &data)) const;

		void InOrderTraverse( 
				const CBTNode<T> *pNode,
				void (*visit)(const T &data)) const;

		void PostOrderTraverse( 
				const CBTNode<T> *pNode,
				void (*visit)(const T &data)) const;

		unsigned int GetNodeCount(
				const CBTNode<T> *pNode,
				unsigned int *unCount) const;

		 void        GetLeafCount( 
				const CBTNode<T> *pNode,
				unsigned int *unCount ) const;

		unsigned int GetHeight(const CBTNode<T> *pNode) const;
		void DestoryNode( CBTNode<T> *pNode);

	public:
	        
		CBTNode<T> *Copy(CBTNode<T> *pNode);
		T&    GetNodeData(CBTNode<T> *pNode);
		T     GetNodeData(const CBTNode<T> *pNode) const;
		void  SetNodeData(CBTNode<T> *pNode,
				const T&  data);
		CBTNode<T>*& GetRoot();
		CBTNode<T>*  GetRoot() const;
		CBTNode<T>*& GetParent(CBTNode<T> *pNode);
		CBTNode<T>*  GetParent(const CBTNode<T> *pNode) const;

		CBTNode<T>*& GetLeftChild(CBTNode<T> *pNode);
		CBTNode<T>*  GetLeftChild(const CBTNode<T> *pNode) const;

		CBTNode<T>*& GetRightChild(CBTNode<T> *pNode);
		CBTNode<T>*  GetRightChild(const CBTNode<T> *pNode) const;

		CBTNode<T>*& GetLeftSibling(CBTNode<T> *pNode);
		CBTNode<T>*  GetLeftSibling(const CBTNode<T> *pNode) const;

		CBTNode<T>*& GetRightSibling(CBTNode<T> *pNode);
		CBTNode<T>*  GetRightSibling(const CBTNode<T> *pNode) const;

	public:
		bool   IsEmpty() const;
		void   Destory();
		void   PreOrderTraverse(void(*visit)(const T &data)) const; 
		void   InOrderTraverse(void(*visit)(const T &data)) const; 
		void   PostOrderTraverse(void(*visit)(const T &data)) const; 

		unsigned int GetNodeCount() const;
		unsigned int GetLeafCount() const;
		unsigned int GetHeight() const;

};

//constructor
template <typename T>
inline CBinTree<T>::CBinTree(CBTNode<T> *initroot):m_pRootNode(initroot)
{
}

//deconstructor
	template <typename T>
inline CBinTree<T>::~CBinTree()
{
	Destory();
}

// assign to m_pRootNode
template <typename T>
inline void CBinTree<T>::AssignTo(CBTNode<T> *pNode)
{
	assert(pNode);
	m_pRootNode = pNode;
}

//copy tree
template <typename T>
inline CBTNode<T>* CBinTree<T>::Copy(CBTNode<T> *pNode)
{
	if(pNode)
	{
		CBTNode<T>* pNewNode = new CBTNode<T>;
		if(pNewNode)
		{
			pNewNode->data    = pNode->data;
			pNewNode->pParent = pNode->pParent;
			pNewNode->pLeft   = Copy(pNode->pLeft);
			pNewNode->pRight  = Copy(pNode->pRight);
			return pNewNode;
		}
		else
		{
			assert(0);
			return NULL;
		}
	}
	else
	{
		return NULL;
	}
}


//get the data
	template <typename T>
inline T& CBinTree<T>::GetNodeData(CBTNode<T> *pNode)
{
	assert(pNode);
	return pNode->data;
}

template <typename T>
inline T CBinTree<T>::GetNodeData(const CBTNode<T> *pNode) const
{
	assert(pNode);
	return pNode->data;
}


//set the data
	template <typename T>
inline void CBinTree<T>::SetNodeData(CBTNode<T> *pNode,const T& data) 
{
	assert(pNode);
	pNode->data = data;
}



//get the parent
template <typename T>
inline CBTNode<T>*& CBinTree<T>::GetParent(CBTNode<T> *pNode)
{
	assert(pNode);
	return *(&(pNode->pParent));
}

template <typename T>
inline CBTNode<T>* CBinTree<T>::GetParent(const CBTNode<T> *pNode) const 
{
	assert(pNode);
	return pNode->pParent;
}



//get root
template <typename T>
inline CBTNode<T>*& CBinTree<T>::GetRoot()
{
	return *(&(m_pRootNode));
}

template <typename T>
inline CBTNode<T>* CBinTree<T>::GetRoot() const 
{
	return m_pRootNode; 
}



//get the left chlid
template <typename T>
inline CBTNode<T>*& CBinTree<T>::GetLeftChild(CBTNode<T> *pNode)
{
	assert(pNode);
	return *(&(pNode->pLeft));
}

template <typename T>
inline CBTNode<T>* CBinTree<T>::GetLeftChild(const CBTNode<T> *pNode) const 
{
	assert(pNode);
	return pNode->pLeft;
}

//get the right child
template <typename T>
inline CBTNode<T>*& CBinTree<T>::GetRightChild(CBTNode<T> *pNode)
{
	assert(pNode);
	return *(&(pNode->pRight));
}
template <typename T>
inline CBTNode<T>* CBinTree<T>::GetRightChild(const CBTNode<T> *pNode) const
{
	assert(pNode);
	return pNode->pRight;
}



//get the left sibling
template <typename T>
inline CBTNode<T>*& CBinTree<T>::GetLeftSibling(CBTNode<T> *pNode)
{
	assert(pNode);

	if(pNode->pParent)
	{
		return *(&(pNode->pParent->pLeft));
	}
	else
	{
		return *(&(pNode->pParent));
	}
}

template <typename T>
inline CBTNode<T>* CBinTree<T>::GetLeftSibling(const CBTNode<T> *pNode) const
{
	assert(pNode);

	if(pNode->pParent)
	{
		return pNode->pParent->pLeft;
	}
	else
	{
		return pNode->pParent;
	}
}



//get the rigth sibling
template <typename T>
inline CBTNode<T>*& CBinTree<T>::GetRightSibling(CBTNode<T> *pNode)
{
	assert(pNode);

	if(pNode->pParent)
	{
		return *(&(pNode->pParent->pRight));
	}
	else
	{
		return *(&(pNode->pParent));
	}
}

template <typename T>
inline CBTNode<T>* CBinTree<T>::GetRightSibling(const CBTNode<T> *pNode) const
{
	assert(pNode);

	if(pNode->pParent)
	{
		return pNode->pParent->pRight;
	}
	else
	{
		return pNode->pParent;
	}
}


// is it empty?
template <typename T>
inline bool CBinTree<T>::IsEmpty() const
{
	return NULL == m_pRootNode;
}

	template <typename T>
inline void CBinTree<T>::DestoryNode(CBTNode<T> *pNode)
{
	if(pNode)
	{
		DestoryNode(pNode->pLeft);
		DestoryNode(pNode->pRight);
		delete pNode;
	}
}

template <typename T>
inline void CBinTree<T>::Destory()
{
	DestoryNode(m_pRootNode);
	m_pRootNode = NULL;
}

//PreOrderTraverse
template <typename T>
inline void CBinTree<T>::PreOrderTraverse(void(*visit)(const T &data)) const
{
	PreOrderTraverse(m_pRootNode,visit);
}

template <typename T>
inline void CBinTree<T>::PreOrderTraverse(
		const  CBTNode<T> *pNode,
		void (*visit)(const T &data)) const
{
	if(pNode)
	{
		visit(pNode->data);
		PreOrderTraverse(pNode->pLeft,visit);
		PreOrderTraverse(pNode->pRight,visit);
	}
}

/*-----------------------------------------------------------
  
Function : PreOrderTraverse
@parama  : pNode
@parama  : (*visit)()
Return   : void
Other    : don't recursive
           
------------------------------------------------------------*/
/*
template <typename T>
inline void CBinTree<T>::PreOrderTraverse(
		const  CBTNode<T> *pNode,
		void (*visit)(const T &data)) const
{
	if(pNode)
	{
		// the end of case
		while(NULL != pNode)
		{
			visit(pNode->data);
		        while(NULL != pNode->pLeft)
		        {
			        pNode = pNode->pLeft;
			        visit(pNode->data);
		        }
			if(NULL != pNode->pRight)
			{
				pNode = pNode->pRight;
				{
					pNode = pNode->pLeft;
			                visit(pNode->data);
				}

			}
			//if pNode->pRight  == NULL
			// there is a little diffcult, cheer!!!
			else
			{
				
				// if the pNode->pParent have been visit,then node up to grandparent
				while((NULL != pNode->pParent) && (pNode == pNode->pParent->pRight))
				{
					pNode = pNode->pParent;
				}
				pNode = pNode->pParent->pRight;
			}
		}
	}
	else
	{
		return; 
	}
}

*/



//InOrderTraverse
template <typename T>
inline void CBinTree<T>::InOrderTraverse(void(*visit)(const T &data)) const
{
	InOrderTraverse(m_pRootNode,visit);
}
/*
template <typename T>
inline void CBinTree<T>::InOrderTraverse(
		const  CBTNode<T> *pNode,
		void (*visit)(const T &data)) const
{
	if(pNode)
	{
		InOrderTraverse(pNode->pLeft,visit);
		visit(pNode->data);
		InOrderTraverse(pNode->pRight,visit);
	}
}
*/
/*-----------------------------------------------------------
  
Function : InOrderTraverse
@parama  : pNode
@parama  : (*visit)()
Return   : void
Other    : don't recursive
           
------------------------------------------------------------*/

template <typename T>
inline void CBinTree<T>::InOrderTraverse(
		const  CBTNode<T> *pNode,
		void (*visit)(const T &data)) const
{
         
	if(NULL != pNode)
	{
		// find the min node; then begin with this node;
		while(NULL != pNode->pLeft)
		{
			pNode = pNode->pLeft;
		}
		// the end of case
		while(NULL != pNode)
		{
			visit(pNode->data);
			if(NULL != pNode->pRight)
			{
				pNode = pNode->pRight;
				while(NULL != pNode->pLeft)
				{
					pNode = pNode->pLeft;
				}

			}
			//if pNode->pRight  == NULL
			// there is a little diffcult; cherry up!!
			else
			{
				// if the pNode->pParent have been visit,then node up to grandparent
				while((NULL != pNode->pParent) && (pNode == pNode->pParent->pRight))
				{
					pNode = pNode->pParent;
				}
				pNode = pNode->pParent;
			}
		}
	}
	else
	{
		return; 
	}
}






//PostOrderTraverse
template <typename T>
inline void CBinTree<T>::PostOrderTraverse(void(*visit)(const T &data)) const
{
	PostOrderTraverse(m_pRootNode,visit);
}

template <typename T>
inline void CBinTree<T>::PostOrderTraverse(
		const  CBTNode<T> *pNode,
		void (*visit)(const T &data)) const
{
	if(pNode)
	{
		PostOrderTraverse(pNode->pLeft,visit);
		PostOrderTraverse(pNode->pRight,visit);
		visit(pNode->data);
	}
}


/*-----------------------------------------------------------
  
Function : PostOrderTraverse
@parama  : pNode
@parama  : (*visit)()
Return   : void
Other    : don't recursive
           
------------------------------------------------------------*/
/*
template <typename T>
inline void CBinTree<T>::PostOrderTraverse(
		const  CBTNode<T> *pNode,
		void (*visit)(const T &data)) const
{
	if(pNode)
	{
		// the end of case
		while(NULL != pNode)
		{
		        while(NULL != pNode->pLeft)
			{
			       pNode = pNode->pLeft;
			}
			if(NULL != pNode->pRight)
			{
				pNode = pNode->pRight;
				while(pNode->pLeft)
				{
					pNode = pNode->pLeft;
				}

			}
			//if pNode->pRight  == NULL
			// there is a little diffcult, cheer!!!
			else
			{
			        visit(pNode->data);
				// if the pNode->pParent have been visit,then node up to grandparent
				while((NULL != pNode->pParent) && (pNode == pNode->pParent->pRight))
				{
					pNode = pNode->pParent;
			                visit(pNode->data);
				}
				pNode = pNode->pParent->pRight;
			}
		}
	}
	else
	{
		return; 
	}
}
*/



//get the count of node include leaf
template <typename T>
inline unsigned int CBinTree<T>::GetNodeCount() const
{
	unsigned int unCount = 0;
	GetNodeCount(m_pRootNode,&unCount);
	return unCount;
}

template <typename T>
inline unsigned int CBinTree<T>::GetNodeCount(
		const  CBTNode<T> *pNode,
		unsigned int *unCount) const
{
	assert(unCount);

	unsigned int unLeftCount;
	unsigned int unRightCount;
	if(NULL == pNode)
	{
		*unCount = 0;
	}
	else if((NULL == pNode->pLeft)&&(NULL == pNode->pRight))
	{
		*unCount = 1;
	}
	else
	{
		GetNodeCount(pNode->pLeft,&unLeftCount);
		GetNodeCount(pNode->pRight,&unRightCount);
		*unCount = 1 + unLeftCount + unRightCount;
	}
}

/*//get the node in second method;
template <typename T>
inline unsigned int CBinTree<T>::GetNodeCount( const  CBTNode<T> *pNode) const
{
	unsigned int unLeftCount = 0;
	unsigned int unRightCount = 0;
	unsigned int uncount = 0;
	if(pNode)
	{
	      unLeftCount = GetNodeCount(pNode->pLeft);
	      unRightCount = GetNodeCount(pNode->pRight);
              //this is very important
	      uncount = unLeftCount + unRightCount;
	      uncount = uncount + 1;
	      cout<< uncount <<endl;
	      return uncount;
	}
        return 0;
}
*/

//get the count leaves
template <typename T>
inline unsigned int CBinTree<T>::GetLeafCount() const
{
	unsigned int unCount = 0;
	GetLeafCount(m_pRootNode,&unCount);
	return unCount;
}

template <typename T>
inline void CBinTree<T>::GetLeafCount(
		const  CBTNode<T> *pNode,
		unsigned int *unCount)const
{
	assert(unCount);
	if(pNode)
	{
		if((NULL == pNode->pLeft)&&(NULL == pNode->pRight))
		{
			++(*unCount);
		}
                /* 
		fisrt &unCount  which converse int* to int**,make a mistake.
		*/
		GetLeafCount(pNode->pLeft,unCount);
		GetLeafCount(pNode->pRight,unCount);
	}
}

//get the count depth 
template <typename T>
inline unsigned int CBinTree<T>::GetHeight() const
{
       return GetHeight(m_pRootNode) - 1;
}

template <typename T>
inline unsigned int CBinTree<T>::GetHeight( const  CBTNode<T> *pNode) const
{
	unsigned int unLeftCount = 0;
	unsigned int unRightCount = 0;
	unsigned int uncount = 0;
	if(pNode)
	{
	      unLeftCount = GetHeight(pNode->pLeft);
	      unRightCount = GetHeight(pNode->pRight);
              //this is very important
	      /* here,it take me some time.
	      first, I write like this 
	      return 1 + (unLeftCount >= unRightCount) ? unLeftCount : unRightCount;
	      it always return 0; why? I don't know now.
	      */
              uncount = (unLeftCount >= unRightCount) ? unLeftCount : unRightCount;
	      uncount = uncount + 1;
	      return uncount;
	}
        return 0;
}

