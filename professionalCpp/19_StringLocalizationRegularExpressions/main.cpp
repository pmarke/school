#include <iostream>
#include <locale>
#include <regex>
#include <string>

int main(int, char**) {
  //   ////////////////////
  //   // Localization
  //   ////////////////////

  //   // wchar_t do not have a standardized size. Most compilers will use
  //   // either 16 or 32 bits.
  //   // You use the literal 'L' to indicate that a character should be a
  //   // wide character.
  //   wchar_t myWideCharacter = L'm';

  //   // there are wide-versions of many of the libraries you use.
  //   std::wcout << myWideCharacter << std::endl;
  //   std::wcout << L"I am a wide-character string literal." << std::endl;

  //   // Raw tells the program to not process escape characters.
  //   // A char string literal with UTF-8 encoding
  //   const char* sl = u8R"(Raw UTF-8 encoded string literal)";
  //   const wchar_t* s2 = LR"(Raw wide string literal)";
  //   // A char16_6 string literal, which can be UTF-16.
  //   const char16_t* s3 = uR"(Raw char16_t string literal)";
  //   // A char32_t string literal, which can be UTF-32.
  //   const char32_t* s4 = UR"(Raw char32_t string literal)";

  //   using string = std::basic_string<char>;
  //   using wstring = std::basic_string<wchar_t>;
  //   using u16string = std::basic_string<char16_t>;
  //   using u32string = std::basic_string<char32_t>;

  //   std::wcout.imbue(std::locale(""));
  //   std::wcout << 32767 << std::endl;

  //   std::wcout.imbue(std::locale("C"));
  //   std::wcout << 32767 << std::endl;
  //   std::wcout.imbue(std::locale(""));

  /////////////////////////
  // Regular Expressions
  ////////////////////////

  // Note that there are no groups in this expression
  std::regex dateFormat(
      R"(\d{4}/(?:0?[1-9]|1[0-2])/(?:0?[1-9]|[1-2][0-9]|3[01]))");
  std::string validDate = "1991/08/23";
  std::string invalidDate = "8/23/1991";
  std::cout << "is data valid: "
            << (bool)std::regex_match(validDate, dateFormat) << std::endl;
  std::cout << "is data valid: "
            << (bool)std::regex_match(invalidDate, dateFormat) << std::endl;

  // We add groups in this expression so that we can extract the
  // year, month, and date
  std::regex dateFormatGroups(
      R"((\d{4})/(0?[1-9]|1[0-2])/(0?[1-9]|[1-2][0-9]|3[01]))");
  std::smatch m;
  std::regex_match(validDate, m, dateFormatGroups);

  std::cout << "birthday: " << m[0].str() << std::endl;
  std::cout << "year: " << stoi(m[1]) << std::endl;
  std::cout << "month: " << stoi(m[2]) << std::endl;
  std::cout << "day: " << stoi(m[3]) << std::endl;

  // There exists regex_search and regex_replace

  const std::string str("<body><h1>Header</h1><p>Some text</p></body>");
  std::regex r("<h1>(.*)</h1><p>(.*)</p>");

  const std::string format("H1=$1   and P=$2");  // See above table
  std::string result = std::regex_replace(str, r, format);

  std::cout << "Original string: '" << str << "'" << std::endl;
  std::cout << "New string : '" << result << "'" << std::endl;

  return 0;
}
