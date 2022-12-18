#include <cstddef>
#include <iostream>
#include <new>

using namespace std;

class PrePost {
 public:
  // Prefix
  PrePost& operator++() {
    val++;
    return *this;
  }

  PrePost operator++(int) {
    PrePost tmp = *this;
    val++;
    return tmp;
  }

  int val{0};
};

// The corresponding delete operators will only be called if the new operator
// throws an exception.

class MemoryDemo {
 public:
  virtual ~MemoryDemo() = default;

  void* operator new(size_t size);
  //   void operator delete(void* ptr) noexcept;
  // You can replace the delete operator with one that takes the size to get the
  // size. But you cant have both.
  void operator delete(void* ptr, size_t size) noexcept;

  void* operator new[](size_t size);
  void operator delete[](void* ptr) noexcept;

  void* operator new(size_t size, const std::nothrow_t&) noexcept;
  void operator delete(void* ptr, const std::nothrow_t&) noexcept;

  void* operator new[](size_t size, const std::nothrow_t&) noexcept;
  void operator delete[](void* ptr, const std::nothrow_t&) noexcept;

  // Overload with additional parameters.
  void* operator new(size_t size, int extra);
  void operator delete(void* ptr, int extra) noexcept;
};

void* MemoryDemo::operator new(size_t size) {
  cout << "operator new" << endl;
  return ::operator new(size);
}
// void MemoryDemo::operator delete(void* ptr) noexcept {
//   cout << "operator delete" << endl;
//   ::operator delete(ptr);
// }

void MemoryDemo::operator delete(void* ptr, size_t size) noexcept {
  cout << "operator delete with size " << size << endl;
  ::operator delete(ptr);
}

void* MemoryDemo::operator new[](size_t size) {
  cout << "operator new[]" << endl;
  return ::operator new[](size);
}
void MemoryDemo::operator delete[](void* ptr) noexcept {
  cout << "operator delete[]" << endl;
  ::operator delete[](ptr);
}
void* MemoryDemo::operator new(size_t size, const nothrow_t&) noexcept {
  cout << "operator new nothrow" << endl;
  return ::operator new(size, nothrow);
}
void MemoryDemo::operator delete(void* ptr, const nothrow_t&) noexcept {
  cout << "operator delete nothrow" << endl;
  ::operator delete(ptr, nothrow);
}
void* MemoryDemo::operator new[](size_t size, const nothrow_t&) noexcept {
  cout << "operator new[] nothrow" << endl;
  return ::operator new[](size, nothrow);
}
void MemoryDemo::operator delete[](void* ptr, const nothrow_t&) noexcept {
  cout << "operator delete[] nothrow" << endl;
}

void* MemoryDemo::operator new(size_t size, int extra) {
  cout << "operator new with extra int: " << extra << endl;
  return ::operator new(size);
}
void MemoryDemo::operator delete(void* ptr, int extra) noexcept {
  cout << "operator delete with extra int: " << extra << endl;
  return ::operator delete(ptr);
}

int main(int, char**) {
  MemoryDemo* mem = new MemoryDemo();
  delete mem;
  mem = new MemoryDemo[10];
  delete[] mem;
  mem = new (nothrow) MemoryDemo();
  delete mem;
  mem = new (nothrow) MemoryDemo[10];
  delete[] mem;

  MemoryDemo* memp = new (5) MemoryDemo();
  delete memp;
}
