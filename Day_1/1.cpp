#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {
  std::string string;
  std::fstream f;
  f.open("input.txt");
  std::ostringstream buffer;
  buffer << f.rdbuf();
  string = buffer.str();
  bool first = true;
  size_t result = 0;
  size_t number = 0;
  char last = 0;
  for (size_t i = 0; i < string.size(); i++) {
    if (string[i] >= '0' && string[i] <= '9') {
      if (first) {
        number = 10 * (string[i] - '0');
        last = string[i];
        first = false;
      } else
        last = string[i];
    } else if (string[i] == '\n') {
      int add = number + (last - '0');
      std::cout << add << std::endl;
      result += add;
      number = 0;
      last = 0;
      first = true;
    }
  }
  result += number + (last - '0');
  std::cout << result << std::endl;
  return 0;
}