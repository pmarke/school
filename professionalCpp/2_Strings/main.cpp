#include <iostream>
#include <string>
#include <string_view>
#include <charconv>
#include <array>

// A string view acts like a const std::string&
// Use std::string_view when passing read only strings. No copy is done
// and you can use string or char array.
void printString(std::string_view str) {

    std::cout << str << std::endl;

}

int main(int, char**) {

    // using this namespace to use s and vs literals
    using namespace std::literals;

    printString("Hello World");

    std::string stringText("String text");
    char charText[]{"char text"};

    // String view can accept a std::string or a char without a copy.
    printString(stringText);
    printString(charText);

    // To convert a std::string_view to a string or a char you have to use the data() member function
    std::string_view stringView("string_view text");

    std::string stringConversion = stringView.data();
    printString(stringConversion);


    // The literal s tells the compiler that it is a string
    auto myString = "This is a string"s;

    // The literal sv tells the compiler that it is a string view.
    auto myStringView = "This is a string_view"sv;

    // Raw string, can improve the readability.
    std::string filepath = R"(path/to/file/is/this)";
    printString(filepath);

    // Fast conversions. For fast float conversions the compiler gcc-11 is needed. 
    const float floatVal{180.0f};
    const int intVal{180};
    char conversion[10];
    std::to_chars_result convResult = std::to_chars(&conversion[0], &conversion[10],floatVal);
    if(convResult.ec == std::errc()) {
        std::cout << "conversion succesfull" << std::endl;
        printString(conversion);
    }

    // Auto drops constness and makes a copy.
    const float a{};
    const float&b = a;
    auto c = b;
    c = 5; // You can do this becuase it makes a copy.
    const auto& d = b; // Keeps the const and the reference.
    // d = 5; // Can't do this.

}
