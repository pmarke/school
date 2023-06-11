#pragma once

#include <cstdint>
#include <iterator>
// #include <cstdeff>

class Integers {
 public:
  Integers() = default;

  // An iterator is usually declared inside the class it belongs to.
  // std::iterator is the base class provided to simplify definitions of the
  // required types for iterators.
  struct Iterator : public std::iterator<std::bidirectional_iterator_tag, int,
                                         int, int*, int&> {
    // std::iterator<
    // the iterator_category,
    // the value type,
    // a type that can be used to identify distance between iterators ,
    // defines a pointer to the type iterated over ,
    // defines a reference to the type iterated over,
    // >

    // all iterators must be constructible, copy-constructile, copy-assignable,
    // destructible and swappable.
    Iterator(pointer ptr) : m_ptr(ptr) {}

    // It is a bidirectional iterator so we must support dereference, increment,
    // and decrement
    reference operator*() const { return *m_ptr; }
    pointer operator->() { return m_ptr; }

    // Prefix increment
    Iterator& operator++() {
      m_ptr++;
      return *this;
    }

    // Postfix increment
    Iterator operator++(int) {
      Iterator tmp = *this;
      ++(*this);
      return tmp;
    }

    // Prefix decrement
    Iterator& operator--() {
      m_ptr--;
      return *this;
    }

    // Postfix decrement
    Iterator operator--(int) {
      Iterator tmp = *this;
      --(*this);
      return tmp;
    }

    friend bool operator==(const Iterator& a, const Iterator& b) {
      return a.m_ptr == b.m_ptr;
    }
    friend bool operator!=(const Iterator& a, const Iterator& b) {
      return a.m_ptr != b.m_ptr;
    }

   private:
    pointer m_ptr = nullptr;
  };

  // Prepare the container
  Iterator begin() { return Iterator(&m_data[0]); }
  Iterator end() { return Iterator(&m_data[200]); }

 private:
  static const uint32_t DATA_SIZE{200};
  int m_data[DATA_SIZE];
};