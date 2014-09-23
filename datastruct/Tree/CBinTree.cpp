
/*---------------------------------------------

FileName : CBinTree.cpp
 Version : 0.10
  Author : Wenxue Liu
    Date : 09-19-2012
    Time : 16:05
 Comment : 

--------------------------------------------*/

#include <iostream>
#include "BinTree.h"

using namespace std;

typedef char ElemType;

// the visit()  = PrintElement()
static void PrintElement(const ElemType &data)
{
    cout<< data;
}


int main()
{
    CBTNode<ElemType>* pRoot;
    CBTNode<ElemType>* pLeftChild1;
    CBTNode<ElemType>* pRightChild1;

    CBTNode<ElemType>* pLeftChild21;
    CBTNode<ElemType>* pRightChild21;

    CBTNode<ElemType>* pLeftChild22;
    CBTNode<ElemType>* pRightChild22;

    CBTNode<ElemType>* pLeftChild31;
    CBTNode<ElemType>* pRightChild31;

    CBTNode<ElemType>* pLeftChild32;
    CBTNode<ElemType>* pRightChild32;
    
    CBTNode<ElemType>* pLeftChild41;
    CBTNode<ElemType>* pRightChild41;

    CBinTree<ElemType> CBTree ;
  
    pRoot = new CBTNode<ElemType>;
    if(NULL == pRoot)
    {
        cout<<"the inply is error!"<<endl;
        return 1;
    }
    
    pLeftChild1= new CBTNode<ElemType>;
    if(NULL == pLeftChild1)
    {
        cout<<"the inply is error!"<<endl;
        return 1;
    }

    pRightChild1 = new CBTNode<ElemType>;
    if(NULL == pRightChild1)
    {
        cout<<"the inply is error!"<<endl;
        return 1;
    }

    
    pLeftChild21= new CBTNode<ElemType>;
    if(NULL == pLeftChild21)
    {
        cout<<"the inply is error!"<<endl;
        return 1;
    }

    pRightChild21 = new CBTNode<ElemType>;
    if(NULL == pRightChild21)
    {
        cout<<"the inply is error!"<<endl;
        return 1;
    }

    
    pLeftChild22 = new CBTNode<ElemType>;
    if(NULL == pLeftChild22)
    {
        cout<<"the inply is error!"<<endl;
        return 1;
    }

    pRightChild22 = new CBTNode<ElemType>;
    if(NULL == pRightChild22)
    {
        cout<<"the inply is error!"<<endl;
        return 1;
    }

    
    pLeftChild31 = new CBTNode<ElemType>;
    if(NULL == pLeftChild31)
    {
        cout<<"the inply is error!"<<endl;
        return 1;
    }

    pRightChild31 = new CBTNode<ElemType>;
    if(NULL == pRightChild31)
    {
        cout<<"the inply is error!"<<endl;
        return 1;
    }

    
    pLeftChild32 = new CBTNode<ElemType>;
    if(NULL == pLeftChild32)
    {
        cout<<"the inply is error!"<<endl;
        return 1;
    }

    pRightChild32 = new CBTNode<ElemType>;
    if(NULL == pRightChild32)
    {
        cout<<"the inply is error!"<<endl;
        return 1;
    }

    
    pLeftChild41 = new CBTNode<ElemType>;
    if(NULL == pLeftChild41)
    {
        cout<<"the inply is error!"<<endl;
        return 1;
    }

    pRightChild41 = new CBTNode<ElemType>;
    if(NULL == pRightChild41)
    {
        cout<<"the inply is error!"<<endl;
        return 1;
    }

    pRoot->pParent = NULL;
    pRoot->pLeft   = pLeftChild1;
    pRoot->pRight  = pRightChild1;
    pRoot->data    = '+';

    pLeftChild1->pParent = pRoot; 
    pLeftChild1->pLeft   = pLeftChild21; 
    pLeftChild1->pRight  = pRightChild21; 
    pLeftChild1->data    = '+';

    pLeftChild21->pParent = pLeftChild1; 
    pLeftChild21->pLeft   = NULL; 
    pLeftChild21->pRight  = NULL; 
    pLeftChild21->data    = 'a';

    pRightChild21->pParent = pLeftChild1;
    pRightChild21->pLeft   = pLeftChild31;
    pRightChild21->pRight  = pRightChild31;
    pRightChild21->data    = '*';
    
    pLeftChild31->pParent = pRightChild21;
    pLeftChild31->pLeft   = NULL;
    pLeftChild31->pRight  = NULL;
    pLeftChild31->data    = 'b';

    pRightChild31->pParent = pRightChild21;
    pRightChild31->pLeft   = NULL;
    pRightChild31->pRight  = NULL;
    pRightChild31->data    = 'c';

    pRightChild1->pParent = pRoot; 
    pRightChild1->pLeft   = pLeftChild22; 
    pRightChild1->pRight  = pRightChild22;
    pRightChild1->data    = '*';


    pLeftChild22->pParent = pRightChild1; 
    pLeftChild22->pLeft   = pLeftChild32; 
    pLeftChild22->pRight  = pRightChild32;
    pLeftChild22->data    = '+';

    pRightChild22->pParent = pRightChild1; 
    pRightChild22->pLeft   = NULL;
    pRightChild22->pRight  = NULL;
    pRightChild22->data    = 'g';
                  
    pLeftChild32->pParent = pLeftChild22; 
    pLeftChild32->pLeft   = pLeftChild41; 
    pLeftChild32->pRight  = pRightChild41;
    pLeftChild32->data    = '*';
    
    pRightChild32->pParent = pLeftChild22; 
    pRightChild32->pLeft   = NULL;
    pRightChild32->pRight  = NULL;
    pRightChild32->data    = 'f';
                  
                  
    pLeftChild41->pParent = pLeftChild32;
    pLeftChild41->pLeft   = NULL;
    pLeftChild41->pRight  = NULL;
    pLeftChild41->data    = 'd';

    pRightChild41->pParent = pLeftChild32;
    pRightChild41->pLeft   = NULL;
    pRightChild41->pRight  = NULL;
    pRightChild41->data    = 'e';




    CBTree.AssignTo(pRoot);
    cout<<"the root data: "<<CBTree.GetNodeData( CBTree.GetRoot() )<<endl;
    cout<<"the parent of pLeftChild1: "<<CBTree.GetNodeData(
                                                          CBTree.GetParent(pLeftChild1)
						         )<<endl;
    cout<<"the parent of pLeftChild21: "<<CBTree.GetNodeData(
                                                          CBTree.GetParent(pLeftChild21)
						         )<<endl;
    cout<<"the parent of pLeftChild31: "<<CBTree.GetNodeData(
                                                          CBTree.GetParent(pLeftChild31)
						         )<<endl;
    cout<<"the leftchild of pLeftChild1: "<<CBTree.GetNodeData(
                                                         CBTree.GetLeftChild(pLeftChild1)
							 )<<endl;
    cout<<"the rightchild of pLeftChild1: "<<CBTree.GetNodeData(
                                                         CBTree.GetRightChild(pLeftChild1)
							 )<<endl;
    cout<<"the right sibling of pLeftChild1: "<<CBTree.GetNodeData(
                                                         CBTree.GetRightSibling(pLeftChild1)
							 )<<endl;
    cout<<"the left sibling of pRigthChild1: "<<CBTree.GetNodeData(
                                                         CBTree.GetLeftSibling(pRightChild1)
							 )<<endl;
    cout<<"PreOrderTraverse: ";
    CBTree.PreOrderTraverse(PrintElement);
    cout<<endl;
    cout<<"InOrderTraverse: ";
    CBTree.InOrderTraverse(PrintElement);
    cout<<endl;
    cout<<"PostOrderTraverse: ";
    CBTree.PostOrderTraverse(PrintElement);
    cout<< endl;
    cout<<"Height of Tree: "<<CBTree.GetHeight()<<endl;
    cout<<"NodeCount: "<<CBTree.GetNodeCount()<<endl;
    cout<<"LeafCount: "<<CBTree.GetLeafCount()<<endl;
    CBTree.AssignTo(CBTree.Copy(pLeftChild1));
    cout<<"PreOrderTraverse: ";
    CBTree.PreOrderTraverse(PrintElement);
    cout<<endl;
    CBTree.Destory();
    if(CBTree.IsEmpty())
    {
       cout<< "the Tree is empty!!"<<endl;
    }
    return 0;
}
