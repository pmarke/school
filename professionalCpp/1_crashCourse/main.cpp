#include <iostream>
#include <vector>
#include <optional>
#include <array>
#include <initializer_list>
#include <algorithm>

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
void sayHi([[maybeunused]] int num)
{
    std::cout << "hi" << std::endl;
}

// The depricated attribute tells the user that they can still use the function
// but its use is discouraged
[[deprecated]] void deprecatedHi()
{
    std::cout << "deprecated hi" << std::endl;
}

// The optional object indicates that a parameter or return value are optional
std::optional<int> getValue(std::optional<bool> giveIt)
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

int main(int, char **)
{

    sayHi(5);

    deprecatedHi();

    // zero initialization
    int zero{};

    // digit separator
    int bigNum = 1'000; // This is 1,000

    int five{5};
    int sum{One::Two::add(zero, five)};

    // Initializer for if statement. The scope of the initialized variable is the if statment.
    if (int tmp{4 + 2}; tmp > zero)
    {
        std::cout << "tmp: " << tmp << std::endl;
    }

    // Initializer for switch statments
    switch (int tmp{0}; zero)
    {
    case 0:
        std::cout << "switch zero: " << zero << std::endl;
        [[fallthrough]] // Used to tell the compiler that fallthrough is intended.
            default : std::cout
                      << "switch tmp: "
                      << tmp
                      << std::endl;
        break;
    }

    // // Strong and weak ordering for three way comparison.
    // auto strongResul =0<=>1;

    // The command \n does not flush the buffer while
    // the command std::endl does.
    std::cout << "sum: " << sum << std::endl;
    std::cout << "big num: " << bigNum << std::endl;

    // get the size of an array and initialize all elements to zero.
    int myArray[10]{};
    std::cout << "size of array: " << std::size(myArray) << std::endl;

    // An example of optional
    std::optional<int> opt;
    opt = getValue(std::nullopt);
    if (opt)
    {

        std::cout << "null optional value: " << opt.value() << std::endl;
    }
    else
    {
        std::cout << "no value: " << std::endl;
    }

    opt = getValue(true);
    if (opt)
    {

        std::cout << "null optional value: " << opt.value() << std::endl;
    }
    else
    {
        std::cout << "no value: " << std::endl;
    }

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

    // Structured binding intialization of a struct
    Turtles turtles{1, 2, 3, 4};

    // Uniform initialization to set all the values to the same one.
    Turtles turtlesUniform{1};
}
