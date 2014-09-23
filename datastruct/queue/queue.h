#include <iostream>

using namespace std;

template <typename T>
class Queue
{
public:
  virtual Queue(){}
  virtual ~Queue(){}
  virtual bool isEmpty() const = 0;
  virtual bool enqueue(const T data) = 0;
  virtual bool dequeue() = 0;
  virtual bool dispose() = 0;
  virtual unsigned int capcity() const = 0;
  virtual T frontVal() const = 0;
}
