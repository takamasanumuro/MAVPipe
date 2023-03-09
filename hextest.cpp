#include <iostream>
#include <fstream>
#include <array>
#include <stdexcept>

int main() {
  // Test printing hex values to stream
  std::array<int16_t, 10> test_array = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09};
  for (int i = 0; i< test_array.size(); i++) {
    std::cout << "Index[" << i << "]: " <<
    std::hex << (test_array.at(i)) << '\n';
  }
}