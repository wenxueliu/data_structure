
/*---------------------------------------------
   
    FileName : VarBinNode.h 
     Version : 0.10
      Author : Wenxue Liu
        Date : 09-19-2012
        Time : 09:21
     Comment : VarBinNode, the VarBinNode is a base class,
               the LeafNode is a subclass;
	       the IntlNode is a subclass;
               
	       here,the type of  LeafNode and IntlNode are
	       different by subclas,and virtual function.
----------------------------------------------*/

template <typename T>
class VarBinNode
{
	public:
		virtual bool isLeaf() = 0;
};

template <typename LeafType>
class LeafNode : public VarBinNode
{
	private:
		LeafType  var;
	public:
		LeafNode(const LeafType &val);
		bool isLeaf() const; 
		LeafType& value() const;
};

template <typename LeafType>
inline LeafNode<LeafType>::LeafNode(const T &val):var(val)
{}

template <typename LeafType>
inline 	bool LeafNode<LeafType>::isLeaf() const; 
{
	return true;
}

template <typename LeafType>
inline LeafType& LeafNode<T>::value() const;
{
	return var;
}

/*-----------another class----------------------*/
		
template <typename IntlType>
class IntlNode : public VarBinNode
{
	private:
		VarBinNode<IntlType> *pLeft;
		VarBinNode<IntlType> *pRight;
		IntlType   opx;

	public:
		IntlNode(const IntlType &op, 
				VarBinNode<IntlType>* l, 
				VarBinNode<IntlType> *r);
		bool isLeaf() const;
		VarBinNode* leftChild() const;
		VarBinNode* rightChlid() const;
		IntlType  &value() const;
};

template <typename IntlType>
inline IntlNode<IntlType>::IntlNode(const IntlType &op, 
		VarBinNode<IntlType>* l, 
		VarBinNode<IntlType> *r):pLeft(l),pRight(r),opx(op)
{}
template <typename IntlType>
inline bool IntlNode<IntlType>::isLeaf() const 
{
	return false;
}
template <typename IntlType>
inline VarBinNode* IntlNode<IntlType>::leftChild() const
{
	return pLeft;
}
template <typename IntlType>
inline VarBinNode* IntlNode<IntlType>::rightChild() const
{
	return pRight;
}
template <typename IntlType>
inline IntlType& IntlNode<IntlType>::value() const
{
	return opx;
}

/*--------------------------------
Function: traverse
 @parama: subroot
  Return: void
   other: preoder traverse
--------------------------------*/
template <typename T,typename LeafType,typename IntlType>
void traverse (VarBinNode<T>* subroot)
{
    if(NULL == subroota) return;
    if(subroot->isLeaf())
    {
       cout<<"Leaf:"<<((LeafNode<LeafType>*)subroot)->value()<<endl;
    }
    else
    {
       cout<<"IntlNode:"<<((IntlNode<IntlType>*)subroot)->value()<<endl;
    }
    traverse(((VarBinNode<T>*)subroot)->leftChild());
    traverse(((VarBinNode<T>*)subroot)->rightChild());
}








/*---------------------------------------------
   
    FileName : VarBinTree 
     Version : 0.10
      Author : Wenxue Liu
        Date : 09-19-2012
        Time : 09:21
     Comment : VarBinNode, the VarBinNode is a base class,
               the LeafNode is a subclass;
	       the IntlNode is a subclass;
               
	       here,the type of  LeafNode and IntlNode are
	       different by subclas,and virtual function.
----------------------------------------------*/

template <typename T>
class VarBinNode
{
	public:
		virtual bool isLeaf() = 0;
		virtual void trav()   = 0;
};

template <typename LeafType>
class LeafNode : public VarBinNode
{
	private:
		LeafType  var;
	public:
		LeafNode(const LeafType &val);
	            bool   isLeaf() const; 
		LeafType&  value()  const;
                    void   trav();
             
};

template <typename LeafType>
inline LeafNode<LeafType>::LeafNode(const T &val):var(val)
{}

template <typename LeafType>
inline 	bool LeafNode<LeafType>::isLeaf() const; 
{
	return true;
}

template <typename LeafType>
inline LeafType& LeafNode<T>::value() const;
{
	return var;
}
template <typename LeafType>
inline void LeafNode<T>::trav() const;
{
        cout<< "Leaf: " << value() <<endl;
}

/*-----------another class----------------------*/
		
template <typename IntlType>
class IntlNode : public VarBinNode
{
	private:
		VarBinNode<IntlType> *pLeft;
		VarBinNode<IntlType> *pRight;
		IntlType   opx;

	public:
		IntlNode(const IntlType &op, 
				VarBinNode<IntlType>* l, 
				VarBinNode<IntlType> *r);
		       bool isLeaf() const;
		VarBinNode* leftChild() const;
		VarBinNode* rightChlid() const;
		  IntlType& value() const;
                      void  trav();
};

template <typename IntlType>
inline IntlNode<IntlType>::IntlNode(const IntlType &op, 
		VarBinNode<IntlType>* l, 
		VarBinNode<IntlType> *r):pLeft(l),pRight(r),opx(op)
{}
template <typename IntlType>
inline bool IntlNode<IntlType>::isLeaf() const 
{
	return false;
}
template <typename IntlType>
inline VarBinNode* IntlNode<IntlType>::leftChild() const
{
	return pLeft;
}
template <typename IntlType>
inline VarBinNode* IntlNode<IntlType>::rightChild() const
{
	return pRight;
}
template <typename IntlType>
inline IntlType& IntlNode<IntlType>::value() const
{
	return opx;
}
// preorder traversal
template <typename IntlType>
inline void IntlNode<IntlType>::trav() 
{
	cout<<"IntlNode: "<< value()<<endl;
	if(NULL != pLeft) 
	{
		pLeft->trav();
	}
	if(NULL != right)
	{
		pRight->trav();
	}
}

/*--------------------------------
Function: traverse
 @parama: subroot
  Return: void
   other: preoder traverse
--------------------------------*/
template <typename T,typename LeafType,typename IntlType>
void traverse (VarBinNode<T>* root)
{
   if(NULL != root) 
   {
      root->trav();
   }
}



