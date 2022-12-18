#include <exception>
#include <iostream>
#include <memory>
#include <string>

// You can create your own exception class that returns as much information as
// you would like.
class myException : public std::exception {
 public:
  myException(const std::string& msg, int moreInfo) {
    m_msg = msg;
    m_moreInfo = moreInfo;
  }

  const char* what() const noexcept override { return m_msg.c_str(); }

  int getMoreInfo() const { return m_moreInfo; }

  std::string m_msg;
  int m_moreInfo;
};

class BadConstructor {
 public:
  BadConstructor() {
    ptr = new int[50];
    throw "memory leak";
  }

  ~BadConstructor() {
    std::cout << "destructor never called:" << std::endl;
    delete[] ptr;
  }

  int* ptr;
};

class GoodConstructor {
 public:
  GoodConstructor() {
    ptr = std::make_unique<int[]>(50);
    throw "no memory leak";
  }

  ~GoodConstructor() {
    std::cout << "destructor never called, but that's ok. The smart pointer's "
                 "destructor was called."
              << std::endl;
  }

  std::unique_ptr<int[]> ptr;
};

int main(int, char**) {
  try {
    try {
      throw myException("hmm", 44);
    } catch (const std::exception& e) {
      // use this to throw it again to a higher level.
      throw;
      /// Never do this. This could cause slicing
      //   throw e;
    }
  } catch (const myException& e) {
    std::cerr << e.what() << '\n';
    std::cerr << e.getMoreInfo() << '\n';
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    BadConstructor bad;
  } catch (const char* msg) {
    std::cerr << msg << std::endl;
  }

  try {
    GoodConstructor good;
  } catch (const char* msg) {
    std::cerr << msg << std::endl;
  }
}
