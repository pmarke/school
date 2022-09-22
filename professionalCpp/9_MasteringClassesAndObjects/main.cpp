#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

class RuleOfFive {
 public:
  RuleOfFive(size_t size, std::string name) : m_name{name}, m_size{size} {
    std::cout << "Basic Constructor" << std::endl;
    m_numPtr = new (std::nothrow) int[size];
  }

  // Copy constructor uses delegating constructor.
  RuleOfFive(const RuleOfFive& other) : RuleOfFive(other.m_size, other.m_name) {
    std::cout << "copy constructor" << std::endl;
    if (m_numPtr != nullptr) {
      for (int ii = 0; ii < other.m_size; ++ii) {
        m_numPtr[ii] = other.m_numPtr[ii];
      }
    }
    m_name = other.m_name;
  }

  // copy and swap idiom which is exception safe. If the construction
  // goes wrong, you do not corrupt this object, but rather a temporary object.
  RuleOfFive& operator=(const RuleOfFive& other) {
    std::cout << "assignment operator" << std::endl;
    if (this == &other) {
      return *this;
    }

    RuleOfFive temp(other);  // Question: This can throw an exception if there
                             // is not enough memeory. I tried to fix it with
                             // std::nothrow. Let me know what you think?
    if (temp.m_numPtr == nullptr && other.m_numPtr != nullptr) {
      // something went wrong.
      std::cout << "something went wrong when allocating the memory. Not "
                   "copying the data."
                << std::endl;
    } else {
      swap(*this, temp);  // this is exception safe.
    }

    return *this;
  }

  RuleOfFive(RuleOfFive&& other) {
    std::cout << "move constructor" << std::endl;
    swap(*this, other);
  }

  RuleOfFive& operator=(RuleOfFive&& other) {
    std::cout << "move assignment" << std::endl;
    if (this == &other) {
      return *this;
    }

    RuleOfFive temp(std::move(other));
    swap(*this, temp);
    return *this;
  }

  ~RuleOfFive() {
    if (m_numPtr) {
      delete m_numPtr;
    }
  }

  int& at(size_t index) {
    if (index > m_size) {
      throw std::out_of_range("Invalid range");
    }
    return m_numPtr[index];
  }

  bool operator==(const RuleOfFive& rhs) const {
    if (m_name != rhs.m_name) {
      return false;
    }
    if (m_size != rhs.m_size) {
      return false;
    }
    for (size_t ii = 0; ii < m_size; ++ii) {
      if (m_numPtr[ii] != rhs.m_numPtr[ii]) {
        return false;
      }
    }
    return true;
  }

 private:
  std::string m_name;
  int* m_numPtr{nullptr};
  size_t m_size{0};

  static void swap(RuleOfFive& lhs, RuleOfFive& other) noexcept {
    std::swap(lhs.m_name, other.m_name);
    std::swap(lhs.m_size, other.m_size);
    std::swap(lhs.m_numPtr, other.m_numPtr);
  }
};

class RuleOfZero {
 public:
  RuleOfZero(size_t size, std::string name) : m_name{name}, m_size{size} {
    m_numArray.resize(size);
  }

  int& at(size_t index) {
    if (index > m_size) {
      throw std::out_of_range("Invalid range");
    }
    return m_numArray[index];
  }

  bool operator==(const RuleOfZero& rhs) const {
    if (m_name != rhs.m_name) {
      return false;
    }
    if (m_size != rhs.m_size) {
      return false;
    }
    for (size_t ii = 0; ii < m_size; ++ii) {
      if (m_numArray[ii] != rhs.m_numArray[ii]) {
        return false;
      }
    }
    return true;
  }

 private:
  std::string m_name;
  std::vector<int> m_numArray;
  size_t m_size{0};
};

int main(int, char**) {
  std::cout << "Testing rule of five !!!" << std::endl << std::endl;

  // Custom constructor.
  std::cout << "Testing Custom Constructor!" << std::endl;
  RuleOfFive ruleOfFive1(10, "one");
  std::cout << std::endl << std::endl;

  for (int ii = 0; ii < 10; ++ii) {
    ruleOfFive1.at(ii) = ii;
  }

  // Copy Constructor
  std::cout << "Testing Copy Constructor!" << std::endl;

  RuleOfFive ruleOfFive2(ruleOfFive1);
  std::cout << "are same: " << (ruleOfFive2 == ruleOfFive1) << std::endl;
  std::cout << std::endl << std::endl;

  // Copy Assignment
  std::cout << "Testing Assignment Operator!" << std::endl;
  RuleOfFive ruleOfFive3(5, "three");

  std::cout << "not same: " << (ruleOfFive3 == ruleOfFive1) << std::endl;
  ruleOfFive3 = ruleOfFive1;
  std::cout << "are same: " << (ruleOfFive3 == ruleOfFive1) << std::endl;
  std::cout << std::endl << std::endl;

  // Testing Move Constructor
  std::cout << "Testing Move Constructor!" << std::endl;
  RuleOfFive ruleOfFive4(RuleOfFive(8, "four"));
  std::cout << std::endl << std::endl;

  // Testing Move Assignment
  std::cout << "Testing Move Assignement!" << std::endl;
  RuleOfFive ruleOfFive5(5, "five");
  ruleOfFive5 = std::move(ruleOfFive4);
  std::cout << "not same: " << (ruleOfFive5 == ruleOfFive4) << std::endl;
  try {
    ruleOfFive4.at(1);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  //////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////

  std::cout << std::endl
            << std::endl
            << "Testing rule of zero " << std::endl
            << std::endl;

  // Custom constructor.
  std::cout << "Testing Custom Constructor!" << std::endl;
  RuleOfZero ruleOfZero1(10, "one");
  std::cout << std::endl << std::endl;

  for (int ii = 0; ii < 10; ++ii) {
    ruleOfZero1.at(ii) = ii;
  }

  // Copy Constructor
  std::cout << "Testing Copy Constructor!" << std::endl;

  RuleOfZero ruleOfZero2(ruleOfZero1);
  std::cout << "are same: " << (ruleOfZero2 == ruleOfZero1) << std::endl;
  std::cout << std::endl << std::endl;

  // Copy Assignment
  std::cout << "Testing Assignment Operator!" << std::endl;
  RuleOfZero ruleOfZero3(5, "three");

  std::cout << "not same: " << (ruleOfZero3 == ruleOfZero1) << std::endl;
  ruleOfZero3 = ruleOfZero1;
  std::cout << "are same: " << (ruleOfZero3 == ruleOfZero1) << std::endl;
  std::cout << std::endl << std::endl;

  // Testing Move Constructor
  std::cout << "Testing Move Constructor!" << std::endl;
  RuleOfZero ruleOfZero4(RuleOfZero(8, "four"));
  std::cout << std::endl << std::endl;

  // Testing Move Assignment
  std::cout << "Testing Move Assignement!" << std::endl;
  RuleOfZero ruleOfZero5(5, "five");
  ruleOfZero5 = std::move(ruleOfZero4);
  std::cout << "not same: " << (ruleOfZero5 == ruleOfZero4) << std::endl;
  try {
    ruleOfZero4.at(1);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}
