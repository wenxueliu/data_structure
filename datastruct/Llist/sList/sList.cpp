#include <iostream>
#include "sList.h"
using namespace std;

int main()
{
   int i;
   int nCount;
   CSList<int> slist;
/*
#ifdef _DEBUG
     _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
*/
/*
   slist.InsertAfter(slist.InsertAfter(slist.AddHead(1),2),3);
   slist.InsertAfter(slist.InsertAfter(slist.GetCount(),4),3);
   slist.InsertAfter(slist.GetCount(),6);
   slist.AddTail(10);
   slist.InsertAfter(slist.InsertBefore(slist.GetCount(),7),8);
   slist.SetAt(slist.GetCount(),9);
   slist.RemoveHead();
   slist.RemoveRange(2,5);
   slist.RemoveTail();

   nCount = slist.GetCount();
   for(i = 0; i < nCount; ++i)
   {
      cout<<slist.GetAt(i + 1) <<endl;
   }
*/
   cout<<slist.IsEmpty()<<endl;
}
