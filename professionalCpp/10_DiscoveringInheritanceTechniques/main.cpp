#include <iostream>

class BaseNoVirtual {
 public:
  void print() const { std::cout << "BaseNoVirtual class: " << std::endl; }

  ~BaseNoVirtual() { std::cout << "BaseNoVirtual destructor: " << std::endl; }
};

class DerivedNoVirtual : public BaseNoVirtual {
 public:
  void print() const { std::cout << "DerivedNoVirtual class: " << std::endl; }
  ~DerivedNoVirtual() {
    std::cout << "DerivedNoVirtual destructor: " << std::endl;
  }
};

class BaseVirtual {
 public:
  virtual void print() const {
    std::cout << "BaseVirtual class: " << std::endl;
  }

  virtual ~BaseVirtual() {
    std::cout << "BaseVirtual destructor: " << std::endl;
  }
};

class DerivedVirtual : public BaseVirtual {
 public:
  void print() const override {
    std::cout << "DerivedVirtual class: " << std::endl;
  }
  ~DerivedVirtual() override {
    std::cout << "DerivedVirtual destructor: " << std::endl;
  }
};

int main(int, char**) {
  std::cout
      << "Testing what happens when the keyword virtual is not used. Notice "
         "that the base pointer does not call the derived class function \n";
  {
    BaseNoVirtual baseNoVirtual;
    DerivedNoVirtual derivedNoVirtual;
    BaseNoVirtual* baseNoVirtualPtr = new DerivedNoVirtual();
    baseNoVirtual.print();
    derivedNoVirtual.print();
    baseNoVirtualPtr->print();

    delete baseNoVirtualPtr;
  }

  std::cout << "\n\n virtual implementation \n\n";

  {
    BaseVirtual baseVirtual;
    DerivedVirtual derivedVirtual;
    BaseVirtual* baseVirtualPtr = new DerivedVirtual();
    baseVirtual.print();
    derivedVirtual.print();
    baseVirtualPtr->print();

    delete baseVirtualPtr;
  }

  return 0;
}
