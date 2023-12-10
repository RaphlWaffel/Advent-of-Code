#include "Cube.h"
#include <iostream>
#include <string>
#include <fstream>

int main(void) {
  std::fstream f;
  f.open("input.txt");
  std::string string;
  while (getline(f, string)) {
    int space_counter = 0;
    bool game = false;
    std::string id;
    std::string blue;
    std::string red;
    std::string green;
    std::string number_buffer;
    for (size_t i = 5; i < string.size(); i++) {
      switch (space_counter) {
        case 0:
          if (string.at(i) == ' ') {
            space_counter++;
            continue;
          }
          id += string.at(i);
          break;
        case 1:
      }
    }
  }
}