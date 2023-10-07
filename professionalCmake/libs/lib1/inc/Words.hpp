#pragma once

#include <string>
#include <vector>

class Words {
 public:
  std::string getFirstWord();
  std::string getSecondWord();

  std::vector<std::string> m_strings;
};