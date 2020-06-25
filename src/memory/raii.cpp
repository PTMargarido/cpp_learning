#include <iostream>
#include <mutex>


class memHandler
{
    public:
    explicit memHandler(int* arrPointer) 
        : arrHolder(arrPointer)
    {
    };

    ~memHandler()
    {
        std::cout << "Deleted array in " << arrHolder << std::endl;
        delete arrHolder;
    }

    private:
    int* arrHolder;
};

void memAlloc(bool shouldThrow) {

  int *pArr = new int(1500);
  std::cout << "Allocation memory in address " << pArr << std::endl;
  memHandler memHandle(pArr);

  // Could also imagine this as an early return. If you use a plain old
  // mutex, you have to remember to manually unlock before every return...
  // and it's quite easy to forget.
  if (shouldThrow) {
    std::cout << "Throwing exception" << std::endl;
    throw 1;
  }
}

void memAllocBadExample() {
  try {
    memAlloc(true);
  } catch (...) {
    std::cout << "Caught exception" << std::endl;
  }
  memAlloc(false);
} 

int main ()
{
    memAllocBadExample();
}
