#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ostream>
#include <sstream>
#include <vector>

using namespace std;

int main(int, char**) {
  //////////////////////
  // Stream iterators
  //////////////////////

  // Take int values from a stream and push them into a vector.
  istringstream str("1 2 3 4 5 6 7 8 9 10");
  istream_iterator<int> streamIterator(str);

  vector<int> myVector(10);
  for (int ii = 0; ii < 10; ++ii) {
    myVector.push_back(*streamIterator);
    streamIterator++;
  }

  // Print the contents of the vector.
  copy(cbegin(myVector), cend(myVector), ostream_iterator<int>(cout, " "));
  std::cout << std::endl;

  /////////////////////////
  // Back inserter
  ////////////////////////////
  vector<int> vectorOne(10), vectorTwo;
  iota(vectorOne.begin(), vectorOne.end(), static_cast<int>(95));

  back_insert_iterator<vector<int>> inserter(vectorTwo);
  copy_if(cbegin(vectorOne), cend(vectorOne), inserter,
          [](int i) { return i != 100; });

  copy(cbegin(vectorTwo), cend(vectorTwo), ostream_iterator<int>(cout, " "));
}
