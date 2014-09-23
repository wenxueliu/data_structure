/*----------------------------------

      FlieName: ALstack.h
       Versio : 0.10
        Author: Wenxueliu
          Date: 09-17-2012
          Time: 13:39
       Comment: this is the base of Lstack.h and ArryStack.h

----------------------------------*/
template <typename T>
class ALstack
{
  virtual ~ALstack(){}//is it necessary?
  virtual bool isEmpty() const = 0;
  virtual push(const T data) = 0;
  virtual pop() = 0;
  virtual unsigned int size() const = 0;
  virtual int capcity() const = 0; 
  virtual T topData() = 0;
}
