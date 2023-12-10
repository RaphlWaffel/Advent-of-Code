#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <regex>
#include <iterator>

int textToInt(std::string text) {
    static const std::map<std::string, int> num_map = {
        {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
        {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}
    };

    auto num_str = text;
    std::transform(num_str.begin(), num_str.end(), num_str.begin(), ::tolower);

    if (num_map.count(num_str)) {
        return num_map.at(num_str);
    } else if (num_str.size() == 1 && std::isdigit(num_str[0])) {
        return num_str[0] - '0';
    } else {
        return 0;
    }
}

int main() {
  std::fstream f;
  f.open("input.txt");
  std::regex rule("(one)|(two)|(three)|(four)|(five)|(six)|(seven)|(eight)|(nine)|([0-9]?)");
  std::string result;
  std::smatch res;
  std::string row;
  int first = 0;
  int second = 0;
  while (std::getline(f, row)) {
    std::string::const_iterator searchStart(row.begin());
    while (std::regex_search(row, res, rule))
        for (size_t i = 1; i < res.size(); i++)
            std::cout << res[i] << std::endl;
    first = second;
    second = first;
  }
}