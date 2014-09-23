#include <iostream>
using namespace std;


template <typename T>
class CSort
{
	private:
                /* 
		cmp -- cmp_lt()  if data1 < data2 return ture  up 
                       cmp_gt()  if data1 > data2 return ture  down 
                */
		int  cmp_gt(T &data1, T &data2);
                int  cmp_lt(T &data1, T &data2);                
		// the swap is decided by cases; 
                void Swap(&A[],int index1,int index2);
		void MSort(T &A[],T tmp[], int left, int right);
		void Merge(T &A[],T tmp[], int lpos, int rpos, int rend);
	public:
		//three O(n2) sort
		void InsertSort(T &A[], const int N, int (*cmp)(T &data1, T &data2));
		void SelectSort(T &A[], const int N, int (*cmp)(T &data1, T &data2));    
		void BubbleSort(T &A[], const int N, int (*cmp)(T &data1, T &data2));

                //the O(NlogN) sort
		void ShellSort(T &A[], const int N);
		void HeapSort(T &A[], const int N);



		void MergeSort(T A[], int N);
		void QuickSort(T A[], int left,int right);

};



/*-------------------------------------
   Function : three O(n2) sorts
   @parama  : A[] -- an arrry  wait for being sorted;
   @parama  : N -- the size of A[]  
   @parama  : cmp-- cmp_lt()  if data1 < data2 return ture  up 
                    cmp_gt()  if data1 > data2 return ture  down 
   @parama  : Swap(A, i, j) -- switch A[i] and A[j]
   @parama  : record the lowest mark
---------------------------------------*/

//Select sort
template <typename T>
inline void CSort<T>::SelectSort(T &A[],const int N,int (*cmp)(T &data1, T &data2))
{
	if(NULL == A || N <= 0 || NULL == cmp)
	{
	    cout<<"your input is wrong!"<<endl;
	    return;
	}
	int i,j;
	int lowindex;
	// if N == 1,needn't sort; so here we do nothing;
	for(i = 0; i < N - 1; i++)
	{
                lowindex = i;
		for(j = N - 1; j > i; j--)
		{
                    if(cmp(A[j],A[lowindex]))
                    {
                       lowindex = j;
                    }
		}                       
		//whether the lowindex == i or not, switch them, do we need a if?
                Swap(A,i,lowindex);
	}
}

//Bubble sort
template <typename T>
inline void CSort<T>::BubbleSort(T &A[],const int N, int(*cmp)(T &data1, T &data2))
{
	if(NULL == A || N <= 0 || NULL == cmp)
	{
	    cout<<"your input is wrong!"<<endl;
	    return;
	}
	
	int i,j;
	// if  N == 1,needn't sort; so here we do nothing;
	for(i = 0; i < N - 1; i++)
	{
		for(j = N - 1; j > i; j--)
		{
                    if(cmp(A[j],A[j - 1]))
                    {
		       Swap(A,j,j - 1);
                    }
		}
	}

}


//insert sort 
template <typename T>
inline void CSort<T>::InsertSort(T &A[],const int N,int (*cmp)(T &data1, T &data2))
{
	if(NULL == A || N <= 0 || NULL == cmp)
	{
	    cout<<"your input is wrong!"<<endl;
	    return;
	}

	int i,j;
	T tmp;
	// if  N == 1,needn't sort; so here we do nothing;
	for(i = 1; i < N; i++)
	{
		tmp = A[i];
		//this also can like this,it more readable;
		/*
		   for(j = i; j > 0; j--)
		   {
		   if(tmp < A[j - 1])
		   {
		   A[j] = A[j - 1];	 
		   }
		   else
		   {
		   break;
		   }
		   }
		 */
		for(j = i; j > 0 && cmp(tmp, A[j - 1]); j--)
		{
			A[j] = A[j - 1];	  
		}
		A[j] = tmp;    
	}
}



/*----------------------------
 
   Function : the Shell sort   
    Invector: Donsld Shell
   @parama  : A[] -- an arrry  wait for being sorted;
   @parama  : N -- the size of A[]  
   @parama  : inc is short for increment 
   @parama  : cmp()  cmp_lt()  if data1 < data2 return ture  up 
                     cmp_gt()  if data1 > data2 return ture  down 
-----------------------------*/

template <typename T>
inline void CSort<T>::ShellSort( T A[],
	                   const int n, 
			   int (*cmp)(T &data1, T &data2))
{
	if(NULL == A || N <= 0 || NULL == cmp)
	{
	    cout<<"your input is wrong!"<<endl;
	    return;
	}

	int i,j;
	// inc is short for increment
	int inc;
	T tmp;
	// if  N == 1,needn't sort; so here we do nothing;
	for(inc = N / 2; inc > 0; inc /= 2)
	{
		for(i = inc; i < N; i++)
		{
			tmp = A[i];
			//this also can be like this,it's more readable;
			/*
			   for(j = i; j > 0; j-= inc)
			   {
			       if(tmp < A[j])
			               A[j] = A[j - inc];	 
			       else
			               break;
			   }
			 */
			for(j = i; j >= inc && cmp(tmp, A[j - inc]); j -= inc)
			{
				A[j] = A[j - inc];	  
			}

			A[j] = tmp;    
			/*
			for(j = i; j >= inc && cmp(tmp, A[j - inc]); j -= inc)
                        {
			        swap(A[j],A[j - inc]);
			}

			*/
		}//end for
	}//end for
}



/*------------------------------------------

  Function : MergeSort
  @parama  : A[]  -- the arry waiting for being sort;
  @parama  : tmp[] -- a copy of A[]
  @parama  : N -- the sizeof(A)
  @parama  : left -- begin with A[left];
  @parama  : right -- end with the last element A[right]
  @parama  : cmp()  cmp_lt()  if data1 < data2 return ture  up 
                    cmp_gt()  if data1 > data2 return ture  down
  Return   : void
  Other    :

-------------------------------------------*/
//the MergeSort
void MergeSort(T A[], int N)
{
     if(NULL == A || N <= 0)
     {
        cout<<"your input is wrong!"<<endl;
	return;
     }

     T *tmp;
     tmp = new (T[sizof(T)*N]);
     if(NULL != tmp)
     {
     //careful,it is between 0 and N - 1;
        MSort(A,tmp,0,N-1);
	delete []tmp;
     }
     else
     {
        cout<<" allocate memory is failed!!";
	assert(0);
     }
}

//mergesort 
void Msort(T A[], T tmp[], int left, int right)
{
   if(A == NULL || tmp == NULL || left > right)
   {
      cout<<"your input is wrong!"<<endl;
      return;
   }

   int center;
   // if  N == 1,needn't sort; so here we do nothing;
   if(left < right)
   {
      center = (left + right) / 2;
      MSort(A,tmp,left,center);
      MSort(A,tmp,center + 1,right);
      Merge(A,tmp,left,center,right);
   }
}
/*------------------------------------
// left begin with  lpos;
// center + 1 begin with rpos;
// center end with rend;
--------------------------------------*/
/*
void Merge(T A[],T tmp[],int lpos,int mpos,int rend)
{
    
    int lend = mpos;
    int rpos = mpos + 1;
    int rend = rpos;
    int tmppos = 0;
    //merge process
    while(lpos <= lend && rpos <= rend)
    {
         if(A[lpos] < A[rpos])
	 {
	    tmp[tmppos++] = A[lpos++];
	 }
	 else
	 {
	    tmp[tmppos++] = A[rpos++];
	 }
    }
    //when lpos sublist is exhausted or rpos sublist is exhausted
    while(lpos < lend)
    {
         tmp[tmppos++] = A[lpos++];
    }

    while(rpos < rend)
    {
         tmp[tmppos++] = A[rpos++];
    }

    while(0 <= rend)
    {
         A[rend] = tmp[rend];
    }
}*/



/*---------------------------------
// it is more effective

// lpos begin with A[lpos]; maybe 0
// mpos end with A[mpos];
// mpos + 1 begin with A[mpos + 1] ;
// rpos end with A[rpos]; maybe N-1
-----------------------------------*/
void Merge(T A[],T tmp[],int lpos,int mpos,int rpos)
{
	int cur;
	//care the smart!!! 
	/*-------------------
	  lops  mpos  rpos
	   0     0     1
	   0     1     2
	   0     1     3
	   0     2     4
	 you must make them right;
	-------------------*/
	for(i = lpos; i <= mpos; i++)
	{
		tmp[i] = A[i]
	}
	while(mpos - rpos < 1)
	{
		tmp[mpos  + 1] = A[rpos]
		++mpos;
		--rpos;
	}
	//
	for(i = lpos, j = rpos, cur = lpos; cur <= rpos; ++cur )
	{
		if(tmp[i] < tmp[j]) 
		{
			A[cur] = tmp[i++];
		}
		else
		{
			A[cur] = tmp[j--]
		}
	}
}

/*
//  don't recursive

template <typename T>
void MergeSort(T A[], T tmp[], int N)
{
    if(NULL == A || NULL == tmp || N <= 0)
    {
        cout<<"your input is wrong!!"<<endl;
	return;
    }

    int lbegin,rbegin,k;
    int pos,lc,rc;
    int len;
    for(k = 0; pow(2,k) < N; k++)
    {
            
	    for(lbegin = 0, rbegin = 1 ; lbegin < N - 1, rbegin < N;
	                            lbegin += pow(2,k+1), rbegin += pow(2,k+1))
	    {
	            lc = lbegin;
		    rc = rbegin;
                    len = rbegin - lbegin;		    
	            while(lc < lbegin && rc < rbegin + len + 1)
		    {
			    if(A[lc] < A[rc])
			    {
				    tmp[pos++] = A[lc++];
			    }
			    else if(A[rc] >= A[lc])
			    {
				    tmp[pos++] = A[rc++];
			    }
		    } 
		    while(lc < rbegin)
		    {
		           tmp[pos++] = A[lc++];
		    }
		    while(rc < rbegin + (rbegin - lbegin) + 1)
		    {
		           tmp[pos++] = A[rc++];
		    }
	    } 
	    while(pos)
	    {
		    A[--pos] = tmp[--pos];
	    }
    }
}
*/

/*------------------------------------------
   
    Function : QuickSort
    Invector : C.A.R. Hoare 1962
    @parama  : A[] -- the arry 
    @parama  : left -- the begin of A[] maybe zero.
    @parama  : right -- the end of A[]
    @parama  : cutoff -- if right - left < cutoff 
                            insertsort()
    return   : 
    other    : it is not easy,you must try you best to 
              understand the key and analysis the O(NlogN)
	   
-------------------------------------------*/


template <typename T>
inline void QuickSort(T &A[], int left, int right)
{
   if(NULL = A || left > right || left < 0 || right < 0)
   {
        cout<<"your input is wrong!"<<endl;
	    return;
   }

   int i,j;
   T pivot;
   int cutoff = 3;
   if(right - left >= cutoff)
   {
        pivot = median3(A,left,right);
        i = left; 
        j = right - 1;
        for(;;)
        {
            while(A[++i] < pivot){}
	        while(A[--j] > pivot){}
            if(i < j)
            {
                swap(&A,&i,&j);
            }
            else
            {
                break;
            }
        }
        QuickSort(A,left,qiovt - 1);
        QuickSort(A,qiovt,right);
    }
    //if have right - left < cutoff and right - left > 0;
    else if(right - left > 0)
    {
        T tmp;
        for(i = left + 1; i <= right; i++)
        {
        tmp = A[i];
            for(j = i; j > left && tmp < A[j - 1]; j--)
        {
            A[j] = A[j - 1];
        }
        A[j] = tmp;
        }
    }
    // if left == right.do nothing 
    else
    {}
}
