#include <iostream>
#include <vector>
#include <optional>
#include <array>
#include <initializer_list>
#include <algorithm>
#include <optional>

// #include <compare>

// Nested namespaces
namespace One::Two
{
    // using the no discard attribute to tell the compiler to warn the user if
    // the returned value is not used.
    [[nodiscard]] int add(int a, int b)
    {
        // specify the name with predefined identifier
        std::cout << __func__ << std::endl;
        return a + b;
    }
}

// Initializer list
int sumValues(std::initializer_list<int> values)
{
    int sum{};
    for (auto val : values)
    {
        sum += val;
    }
    return sum;
}

// The attribute maybeunused tells the compiler that
// the parameter does not have to be used.
void unusedHi([[maybeunused]] int num)
{
    std::cout << "unused hi" << std::endl;
}

// The depricated attribute tells the user that they can still use the function
// but its use is discouraged
[[deprecated]] void deprecatedHi()
{
    std::cout << "deprecated hi" << std::endl;
}

// The optional object indicates that a parameter or return value are optional
std::optional<int> getOptionalValue(std::optional<bool> giveIt)
{

    // If it has a value and that value is true, return the number.
    if (giveIt && giveIt.value())
    {
        return 42;
    }
    return std::nullopt;
}

// Enum class with different underlying type
enum class Color : unsigned int
{
    BLUE
};

struct Turtles
{

    int m;
    int d;
    int t;
    int v;
};

struct BigData {
    BigData() {
        data.resize(100,2);
    }
    const std::vector<int>& getDataConstRef() const {return data;}
    std::vector<int>& getDataRef() {return data;}
    std::vector<int> data;
};

int main(int, char **)
{

    /////////////////////////////////
    // Initializers
    /////////////////////////////////

    // Zero initializer
    int zero{};
    std::cout << "zero initializer: " << zero << std::endl;

    // Digit separator
    int bigNum = 1'000; // This is 1,000
    std::cout << "digit separator: " << bigNum << std::endl;

    // Curly brace initializer
    // * does not allow narrowing
    int five{5};

    // Initializer for if statement. The scope of the initialized variable is the if statment.
    if (int tmp{4 + 2}; tmp > zero)
    {
        std::cout << "if statement initializer: " << tmp << std::endl;
    }

    // Initializer for switch statments
    switch (int tmp{0}; zero)
    {
    case 0:
        std::cout << "switch statement initializer: " << zero << std::endl;
            break;
            default :
        break;
    }

    // get the size of an array and initialize all elements to zero.
    int myArray[10]{};
    std::cout << "size of array: " << std::size(myArray) << std::endl;

    // Structured binding intialization of a struct.
    // I think this is scary. What if the struct changes or the order changes.
    Turtles turtles{1, 2, 3, 4};

    // Uniform initialization to set all the values to the same one.
    Turtles turtlesUniform{1};

    /////////////////////////////////
    // Testing attributes
    /////////////////////////////////

    // Attribute: maybe_unused
    unusedHi(5);

    // Attribute: deprecated
    deprecatedHi();

    // Attribute: fallthrough
    switch (0)
    {
    case 0:
        [[fallthrough]]
    default:
        std::cout << "fallthrough hi" << std::endl;
        break;
    }

    // Attribute: nodiscard
    // Sub namespace
    int sum{One::Two::add(zero, five)};

    ////////////////////////////
    // Optional
    ////////////////////////////
    std::optional<int> opt;
    opt = getOptionalValue(std::nullopt);
    if (opt)
    {

        std::cout << "null optional value: " << opt.value() << std::endl;
    }
    else
    {
        std::cout << "no value: " << std::endl;
    }

    opt = getOptionalValue(true);
    if (opt)
    {

        std::cout << "null optional value: " << opt.value() << std::endl;
    }
    else
    {
        std::cout << "no value: " << std::endl;
    }

    ///////////////////////////////////
    // auto keyword
    ///////////////////////////////////

    // Compiler deduces the type
    int num {5};
    auto autoNum = num;
    std::cout << "auto Num: " << autoNum << std::endl;

    // Removes reference
    int & numRef = num;
    auto notRefNum = numRef;
    notRefNum = 10;
    std::cout << "num ref: " << numRef << std::endl;
    std::cout << "auto ref num: " << notRefNum << std::endl;

    auto & autoNumRef = numRef;
    autoNumRef = 10;
    std::cout << "num ref: " << numRef << std::endl;
    std::cout << "auto ref num: " << notRefNum << std::endl;

    // Removes constness
    const int constNum{5};
    auto notConstNum = constNum;
    notConstNum *=2;
    std::cout << "constNum: " << constNum << std::endl;
    std::cout << "notConstNum: " << notConstNum << std::endl;

    const auto autoConstNum = constNum;
    std::cout << "constNum: " << constNum << std::endl;
    std::cout << "autoConstNum: " << autoConstNum << std::endl;

    // Danger!! Auto will create a copy.
    BigData bigData;
    auto dataCpy = bigData.getDataConstRef();
    dataCpy.clear();
    std::cout << "big data size: " << bigData.getDataConstRef().size() << std::endl;
    std::cout << "auto data: " << dataCpy.size() << std::endl;

    const auto& dataConstRef = bigData.getDataConstRef();
    bigData.getDataRef().clear();
    std::cout << "big data size: " << bigData.getDataConstRef().size() << std::endl;
    std::cout << "auto data: " << dataConstRef.size() << std::endl;

    bigData = BigData();
    auto& dataRef = bigData.getDataRef();
    dataRef.push_back(1);
    std::cout << "big data size: " << bigData.getDataConstRef().size() << std::endl;
    std::cout << "auto data: " << dataRef.size() << std::endl;

    // for range auto loops
    for (auto i : bigData.getDataConstRef()) {
        //pass
    }

    for (const auto i : bigData.getDataConstRef()) {
        //pass
    }

    for (const auto& i : bigData.getDataConstRef()) {
        //pass
    }

    ////////////////////////////
    // String view
    ////////////////////////////

    std::string_view strView = "Hi";
    char myString[]{"This is a secret Message!"};
    std::string_view strView2(myString,5);
    const char* myString2 = strView2.data();

    std::cout << strView << std::endl;
    std::cout << strView2 << std::endl;
    std::cout << myString2 << std::endl;

    // Structured bindings can be used from elements of an array, pair, struct, and some others. You must
    // use the keyword auto.
    // This is also showing template type deduction for the array template class.
    std::array structuredExample{1, 2, 3};
    auto [a1, a2, a3] = structuredExample;
    printf("%d, %d, %d \n", a1, a2, a3);

    // Initializers with range based for loops
    for (std::array vals{1, 2, 3}; auto i : vals)
    {
        std::cout << i << " \n";
    }

    // Initializer list
    std::cout << "sum values: " << sumValues({a1, a2, a3}) << std::endl;


}
