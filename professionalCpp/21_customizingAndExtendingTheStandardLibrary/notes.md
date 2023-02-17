## Insert Iterators

There are three types of insert iterators
* insert_iterator: calls insert(position, element) on the container
* back_insert_iterator: calls push_back(element) on the container
* front_insert_iterator: calls push_front(element) on the container

## Move Iterators
 Use a move iterator to move objects instead of copying them.

## Iterator Traits
You can use std::iterator_traits to get the following information
* difference_type
* value_type:   The underlying type the iterator points to. Ex T
* pointer:      The pointer type of the underlying type. Ex T*
* reference:    The reference type of the underlying type. Ex T&
* iterator_category: forward, backward, bidirection, random, etc

## Creating Your Own Standard Library

### Required Type Aliases
* **value_type** The element type stored in the container
* **reference** A reference to the element type stored in the container
* **const_reference** A const reference to the element type stored in the container
* **iterator** The type for iterating over elements of the container
* **const_iterator** A version of iterator for iterating over const elements of the container
* **size_type** A type that can represent the number of elements in the container; this is usually just size_t (from <cstddef>).
* **difference_type** A type that can represent the difference of two iterators for the container; this is usually just ptrdiff_t (from <cstddef>).

### Required Methods
A standard library has certain methods that it must implement. 
See [here](https://en.cppreference.com/w/cpp/named_req/Container)