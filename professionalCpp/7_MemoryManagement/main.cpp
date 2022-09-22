#include <iostream>

struct Boo {
  int j;
};

struct Foo : public Boo {
  int i;
};

// The array is not copied, rather passed by reference.
void doubleInts(int theArray[], size_t size) {
  for (size_t i = 0; i < size; i++) {
    theArray[i] *= 2;
  }
}

int main(int, char**) {
  // Malloc and new
  Foo* myFoo = (Foo*)malloc(sizeof(
      Foo));  // Not a proper object because the constructor wasn't called.
  Foo* myOtherFoo = new Foo();  // Proper object.

  // free and delete
  free(myFoo);  // Does not call the destructor.
  delete myOtherFoo;

  // Instead of throwing an exeption, it will return a nullptr.
  int* ptr = new (std::nothrow) int;
  delete ptr;

  // You can use static cast on pointers for related types.
  Foo* fooPtr = new Foo();
  Boo* booPtr = static_cast<Foo*>(fooPtr);

  std::cout << "Hello, world!\n";
}
