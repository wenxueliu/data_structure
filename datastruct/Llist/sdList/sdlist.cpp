//////////////////////////////////////////////////
//
//   FileName  : dlist.cpp
//   Version   : 0.10
//   Author    : Wenxue liu
//   Date      : 9-15-2012
//   Comment   : from www.luocong.com
////////////////////////////////////////////////

#include<iostream>
#include"sdlist.h"
using namespace std;

int main()
{
   int i;
   int nCount;
   CDList<int> dlist;

#ifdef _DEBUG
   _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

   dlist.AddTail(1);
   dlist.AddTail(3);
   dlist.InsertBefore(2,2);
   dlist.AddHead(4);
   dlist.RemoveTail();

   nCount = dlist.GetCount();
   for(i = 1; i <= nCount;)
   {
     cout<<dlist.GetNext(i)<<endl;
   }
   return 0; 
}
